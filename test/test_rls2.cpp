#include <bits/stdc++.h>

using namespace std;

void cx(int a, int &b) {
	b ^= a;
}

void key_rotl_swap(int *x) {
	int y[32];
	int pos[32] = {
		0, 1, 28, 16, 4, 5, 6, 7, 8, 9, 11, 2, 3, 13, 14, 15,
		25, 17, 18, 10, 20, 21, 19, 23, 24, 12, 26, 27, 31, 29, 30, 22
	};
	for (int i = 0; i < 32; i++) {
		y[i] = x[pos[i]];
	}
	memcpy(x, y, 32 * sizeof(int));
}

void get_L(int *x) {
	cx(x[31], x[9]);
    cx(x[9], x[28]);
    cx(x[3], x[16]);
    cx(x[28], x[15]);
    cx(x[25], x[3]);
    cx(x[19], x[25]);
    cx(x[31], x[22]);
    cx(x[21], x[31]);
    cx(x[11], x[2]);
    cx(x[12], x[3]);
    cx(x[12], x[2]);
    cx(x[10], x[29]);
    cx(x[12], x[22]);
    cx(x[11], x[21]);
    cx(x[0], x[10]);
    cx(x[19], x[10]);
    cx(x[11], x[19]);
    cx(x[1], x[11]);
    cx(x[14], x[1]);
    cx(x[24], x[1]);
    cx(x[15], x[24]);
    cx(x[12], x[15]);
    cx(x[6], x[12]);
    cx(x[0], x[6]);
    cx(x[13], x[0]);
    cx(x[23], x[0]);
    cx(x[14], x[23]);
    cx(x[5], x[14]);
    cx(x[28], x[5]);
    cx(x[27], x[14]);
    cx(x[19], x[28]);
    cx(x[4], x[23]);
    cx(x[13], x[19]);
    cx(x[4], x[13]);
    cx(x[17], x[4]);
    cx(x[25], x[28]);
    cx(x[27], x[4]);
    cx(x[8], x[27]);
    cx(x[18], x[27]);
    cx(x[26], x[13]);
    cx(x[9], x[18]);
    cx(x[12], x[9]);
    cx(x[16], x[12]);
    cx(x[26], x[16]);
    cx(x[17], x[26]);
    cx(x[8], x[17]);
    cx(x[30], x[17]);
    cx(x[31], x[8]);
    cx(x[25], x[31]);
    cx(x[7], x[26]);
    cx(x[7], x[25]);
    cx(x[30], x[7]);
    cx(x[21], x[30]);
    cx(x[21], x[31]);
    cx(x[2], x[21]);
    cx(x[15], x[2]);
    cx(x[20], x[7]);
    cx(x[9], x[15]);
    cx(x[6], x[9]);
    cx(x[29], x[6]);
    cx(x[20], x[29]);
    cx(x[11], x[20]);
    cx(x[10], x[11]);
    cx(x[19], x[11]);
    cx(x[22], x[19]);
    cx(x[3], x[19]);
    cx(x[10], x[6]);
    cx(x[31], x[19]);
    cx(x[28], x[31]);
    cx(x[2], x[28]);
    cx(x[24], x[2]);
    cx(x[22], x[9]);
    cx(x[5], x[24]);
    cx(x[3], x[12]);
    cx(x[18], x[5]);
    cx(x[12], x[25]);
    cx(x[6], x[25]);
    cx(x[0], x[11]);

	key_rotl_swap(x);
}

void key_rotl_inv_swap(int *x) {
	int y[32];
	int pos[32] = {
		0, 1, 11, 12, 4, 5, 6, 7, 8, 9, 19, 10, 25, 13, 14, 15,
		3, 17, 18, 22, 20, 21, 31, 23, 24, 16, 26, 27, 2, 29, 30, 28
	};
	for (int i = 0; i < 32; i++) {
		y[i] = x[pos[i]];
	}
	memcpy(x, y, 32 * sizeof(int));
}

void get_L_reverse(int *x) {
	key_rotl_inv_swap(x);

	cx(x[0], x[11]);
    cx(x[6], x[25]);
    cx(x[12], x[25]);
    cx(x[18], x[5]);
    cx(x[3], x[12]);
    cx(x[5], x[24]);
    cx(x[22], x[9]);
    cx(x[24], x[2]);
    cx(x[2], x[28]);
    cx(x[28], x[31]);
    cx(x[31], x[19]);
    cx(x[10], x[6]);
    cx(x[3], x[19]);
    cx(x[22], x[19]);
    cx(x[19], x[11]);
    cx(x[10], x[11]);
    cx(x[11], x[20]);
    cx(x[20], x[29]);
    cx(x[29], x[6]);
    cx(x[6], x[9]);
    cx(x[9], x[15]);
    cx(x[20], x[7]);
    cx(x[15], x[2]);
    cx(x[2], x[21]);
    cx(x[21], x[31]);
    cx(x[21], x[30]);
    cx(x[30], x[7]);
    cx(x[7], x[25]);
    cx(x[7], x[26]);
    cx(x[25], x[31]);
    cx(x[31], x[8]);
    cx(x[30], x[17]);
    cx(x[8], x[17]);
    cx(x[17], x[26]);
    cx(x[26], x[16]);
    cx(x[16], x[12]);
    cx(x[12], x[9]);
    cx(x[9], x[18]);
    cx(x[26], x[13]);
    cx(x[18], x[27]);
    cx(x[8], x[27]);
    cx(x[27], x[4]);
    cx(x[25], x[28]);
    cx(x[17], x[4]);
    cx(x[4], x[13]);
    cx(x[13], x[19]);
    cx(x[4], x[23]);
    cx(x[19], x[28]);
    cx(x[27], x[14]);
    cx(x[28], x[5]);
    cx(x[5], x[14]);
    cx(x[14], x[23]);
    cx(x[23], x[0]);
    cx(x[13], x[0]);
    cx(x[0], x[6]);
    cx(x[6], x[12]);
    cx(x[12], x[15]);
    cx(x[15], x[24]);
    cx(x[24], x[1]);
    cx(x[14], x[1]);
    cx(x[1], x[11]);
    cx(x[11], x[19]);
    cx(x[19], x[10]);
    cx(x[0], x[10]);
    cx(x[11], x[21]);
    cx(x[12], x[22]);
    cx(x[10], x[29]);
    cx(x[12], x[2]);
    cx(x[12], x[3]);
    cx(x[11], x[2]);
    cx(x[21], x[31]);
    cx(x[31], x[22]);
    cx(x[19], x[25]);
    cx(x[25], x[3]);
    cx(x[28], x[15]);
    cx(x[3], x[16]);
    cx(x[9], x[28]);
	cx(x[31], x[9]);
}

uint32_t rotl(uint32_t a, uint8_t n) {
    return (a << n) | (a >> (32 - n));
}

void uint2bits(int *x, uint32_t num) {
    for (int i = 0; i < 32; i++) {
		x[i] = (num >> (31 - i)) & 1;
	}
}

uint32_t bits2uint(int *x) {
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++) {
		ans = (ans << 1) | x[i];
	}
    return ans;
}

int main() {
	int x[32];
	srand(time(0));
	const int maxn = 100000;
    for (int i = 0; i < maxn; ++i) {
		uint32_t t = (static_cast<uint32_t>(rand()) << 16) | rand();
		uint2bits(x, t);
        get_L(x);
        auto Li = bits2uint(x);
        get_L_reverse(x);
		auto Li_inv = bits2uint(x);
		auto ans = t ^ rotl(t, 13) ^ rotl(t, 23);
        if (ans != Li || t != Li_inv) {
			printf("Error t = %u, ans = %u, L(i) = %u, reverse_L(i) = %u", t, ans, Li, Li_inv);
            exit(-1);
		}
	}
    puts("OK");
	return 0;
}