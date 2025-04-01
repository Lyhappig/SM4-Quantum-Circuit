#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cstdint>

void cx(int &x, int &y) {
    y ^= x;
}

void ccx(int &x, int &y, int &z) {
    z ^= (x & y);
}

void QAND(int &x, int &y, int &z1, int &z2) {
	assert(z1 == 0);
	assert(z2 == 0);
	z1 = x & y;
}

void QAND_1(int &x, int &y, int &z) {
	assert(z == (x & y));
	z = 0;
}

// 恢复前4个比特
// 9个QAND，9个QAND_1，56个CNOT
void qt14(int a[4], int b[4], int c[4], int d[28]) {
    cx(a[1], d[6]);
    cx(a[3], d[6]);
    cx(b[1], d[7]);
    cx(b[3], d[7]);
    cx(a[2], d[8]);
    cx(a[3], d[8]);
    cx(b[2], d[9]);
    cx(b[3], d[9]);
    cx(a[0], d[10]);
    cx(a[2], d[10]);
    cx(b[0], d[11]);
    cx(b[2], d[11]);
    cx(d[10], d[4]);
    cx(d[6], d[4]);
    cx(d[11], d[5]);
    cx(d[7], d[5]);
    cx(a[0], d[12]);
    cx(a[1], d[12]);
    cx(b[0], d[13]);
    cx(b[1], d[13]);
    QAND(d[4], d[5], d[0], d[19]);
    QAND(d[6], d[7], d[1], d[20]);
    QAND(d[8], d[9], d[2], d[21]);
    QAND(d[12], d[13], d[3], d[22]);
    QAND(d[10], d[11], d[14], d[23]);
    QAND(a[3], b[3], d[15], d[24]);
    QAND(a[2], b[2], d[16], d[25]);
    QAND(a[1], b[1], d[17], d[26]);
    QAND(a[0], b[0], d[18], d[27]);
	cx(d[3], c[3]);
	cx(d[2], c[2]);
	cx(d[1], c[1]);
	cx(d[0], c[0]);
    cx(d[1], c[0]);
    cx(d[2], c[0]);
    cx(d[15], c[0]);
    cx(d[14], c[1]);
    cx(d[15], c[1]);
    cx(d[16], c[1]);
    cx(d[3], c[2]);
    cx(d[15], c[2]);
    cx(d[18], c[2]);
    cx(d[15], c[3]);
    cx(d[16], c[3]);
    cx(d[17], c[3]);
    QAND_1(d[12], d[13], d[3]);
	QAND_1(d[8], d[9], d[2]);
	QAND_1(d[6], d[7], d[1]);
	QAND_1(d[4], d[5], d[0]);
    QAND_1(a[0], b[0], d[18]);
    QAND_1(a[1], b[1], d[17]);
    QAND_1(a[2], b[2], d[16]);
    QAND_1(a[3], b[3], d[15]);
    QAND_1(d[10], d[11], d[14]);
    cx(b[0], d[13]);
    cx(b[1], d[13]);
    cx(a[0], d[12]);
    cx(a[1], d[12]);
    cx(d[11], d[5]);
    cx(d[7], d[5]);
    cx(d[10], d[4]);
    cx(d[6], d[4]);
    cx(b[0], d[11]);
    cx(b[2], d[11]);
    cx(a[0], d[10]);
    cx(a[2], d[10]);
    cx(b[2], d[9]);
    cx(b[3], d[9]);
    cx(a[2], d[8]);
    cx(a[3], d[8]);
    cx(b[1], d[7]);
    cx(b[3], d[7]);
    cx(a[1], d[6]);
    cx(a[3], d[6]);
}

bool check_delta(uint8_t delta = 0) {
	for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            int a[4] = { (i >> 3) & 1, (i >> 2) & 1, (i >> 1) & 1, (i >> 0) & 1 };
            int b[4] = { (j >> 3) & 1, (j >> 2) & 1, (j >> 1) & 1, (j >> 0) & 1 };
			int c[4] = { (delta >> 3) & 1, (delta >> 2) & 1, (delta >> 1) & 1, (delta >> 0) & 1 };
			const int n = 28;
            int d1[n] = {0};

            qt14(a, b, c, d1);

            for (int k = 0; k < 4; k++) {
                int expected_a = (i >> (3 - k)) & 1;
                int expected_b = (j >> (3 - k)) & 1;
                if (a[k] != expected_a) {
                    printf("output X not match\n");
                    return false;
                }
                if (b[k] != expected_b) {
                    printf("output Y not match\n");
                    return false;
                }
            }
            int d2[4] = {0};
            d2[0] = ((a[0] ^ a[1] ^ a[2] ^ a[3]) & (b[0] ^ b[1] ^ b[2] ^ b[3])) ^ ((a[1] ^ a[3]) & (b[1] ^ b[3])) ^ ((a[2] ^ a[3]) & (b[2] ^ b[3])) ^ (a[3] & b[3]);
			d2[1] = ((a[0] ^ a[2]) & (b[0] ^ b[2])) ^ ((a[1] ^ a[3]) & (b[1] ^ b[3])) ^ (a[2] & b[2]) ^ (a[3] & b[3]);
			d2[2] = ((a[0] ^ a[1]) & (b[0] ^ b[1])) ^ (a[0] & b[0]) ^ ((a[2] ^ a[3]) & (b[2] ^ b[3])) ^ (a[3] & b[3]);
			d2[3] = ((a[0] ^ a[1]) & (b[0] ^ b[1])) ^ (a[1] & b[1]) ^ (a[2] & b[2]) ^ (a[3] & b[3]);
			int ans1 = 0, ans2 = 0;
            for (int k = 0; k < 4; k++) {
                ans1 = (ans1 << 1) | c[k];
				ans2 = (ans2 << 1) | d2[k];
            }
			if (ans1 != (delta ^ ans2)) {
				printf("answer not match\n");
				return false;
			}
			for (int k = 0; k < n; k++) {
				if (d1[k] != 0) {
					printf("can't recover other bits\n");
                    return false;
				}
			}
        }
    }
	return true;
}

int main() {
    for (uint8_t k = 0; k < 16; k++) {
		if (!check_delta(k)) {
			puts("\"d = d ^ a\" qc error");
			return 0;
		}
	}
    printf("OK\n");
    return 0;
}