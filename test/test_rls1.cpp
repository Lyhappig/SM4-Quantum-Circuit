#include <bits/stdc++.h>

using namespace std;

void cx(int a, int &b) {
	b ^= a;
}

void simulate_swap(int *x) {
	int y[32];
	int pos[32] = {
		10, 11, 20, 21, 30, 31, 24, 25, 2, 3, 12, 13, 14, 15, 8, 9,
		18, 19, 4, 5, 22, 23, 0, 1, 26, 27, 28, 29, 6, 7, 16, 17
	};
	for (int i = 0; i < 32; i++) {
		y[i] = x[pos[i]];
	}
	memcpy(x, y, 32 * sizeof(int));
}

void get_L(int *x) {
    cx(x[30], x[6]);
    cx(x[8], x[16]);
    cx(x[20], x[28]);
    cx(x[2], x[26]);
    cx(x[18], x[2]);
    cx(x[10], x[18]);
    cx(x[22], x[30]);
    cx(x[16], x[10]);
    cx(x[0], x[16]);
    cx(x[6], x[0]);
    cx(x[14], x[6]);
    cx(x[24], x[8]);
    cx(x[6], x[22]);
    cx(x[16], x[24]);
    cx(x[12], x[14]);
    cx(x[28], x[6]);
    cx(x[20], x[14]);
    cx(x[4], x[20]);
    cx(x[18], x[4]);
    cx(x[28], x[4]);
    cx(x[30], x[16]);
    cx(x[20], x[30]);
    cx(x[12], x[20]);
    cx(x[18], x[12]);
    cx(x[2], x[28]);
    cx(x[24], x[2]);
    cx(x[26], x[20]);
    cx(x[0], x[24]);
    cx(x[10], x[26]);
    cx(x[26], x[18]);
    cx(x[8], x[26]);
    cx(x[22], x[8]);
    cx(x[14], x[22]);
    cx(x[30], x[14]);
    cx(x[8], x[0]);
    cx(x[16], x[8]);
    cx(x[2], x[10]);
    cx(x[6], x[30]);
    cx(x[28], x[12]);
    cx(x[20], x[28]);
    cx(x[26], x[2]);
    cx(x[31], x[7]);
    cx(x[9], x[17]);
    cx(x[21], x[29]);
    cx(x[3], x[27]);
    cx(x[19], x[3]);
    cx(x[11], x[19]);
    cx(x[23], x[31]);
    cx(x[17], x[11]);
    cx(x[1], x[17]);
    cx(x[7], x[1]);
    cx(x[15], x[7]);
    cx(x[25], x[9]);
    cx(x[7], x[23]);
    cx(x[17], x[25]);
    cx(x[13], x[15]);
    cx(x[29], x[7]);
    cx(x[21], x[15]);
    cx(x[5], x[21]);
    cx(x[19], x[5]);
    cx(x[29], x[5]);
    cx(x[31], x[17]);
    cx(x[21], x[31]);
    cx(x[13], x[21]);
    cx(x[19], x[13]);
    cx(x[3], x[29]);
    cx(x[25], x[3]);
    cx(x[27], x[21]);
    cx(x[1], x[25]);
    cx(x[11], x[27]);
    cx(x[27], x[19]);
    cx(x[9], x[27]);
    cx(x[23], x[9]);
    cx(x[15], x[23]);
    cx(x[31], x[15]);
    cx(x[9], x[1]);
    cx(x[17], x[9]);
    cx(x[3], x[11]);
    cx(x[7], x[31]);
    cx(x[29], x[13]);
    cx(x[21], x[29]);
    cx(x[27], x[3]);

	simulate_swap(x);
}

void simulate_swap_inv(int *x) {
	int y[32];
	int pos[32] = {
		22, 23, 8, 9, 18, 19, 28, 29, 14, 15, 0, 1, 10, 11, 12, 13,
		30, 31, 16, 17, 2, 3, 20, 21, 6, 7, 24, 25, 26, 27, 4, 5
	};
	for (int i = 0; i < 32; i++) {
		y[i] = x[pos[i]];
	}
	memcpy(x, y, 32 * sizeof(int));
}

void get_L_reverse(int *x) {
	simulate_swap_inv(x);

    cx(x[27], x[3]);
    cx(x[21], x[29]);
    cx(x[29], x[13]);
    cx(x[7], x[31]);
    cx(x[3], x[11]);
    cx(x[17], x[9]);
    cx(x[9], x[1]);
    cx(x[31], x[15]);
    cx(x[15], x[23]);
    cx(x[23], x[9]);
    cx(x[9], x[27]);
    cx(x[27], x[19]);
    cx(x[11], x[27]);
    cx(x[1], x[25]);
    cx(x[27], x[21]);
    cx(x[25], x[3]);
    cx(x[3], x[29]);
    cx(x[19], x[13]);
    cx(x[13], x[21]);
    cx(x[21], x[31]);
    cx(x[31], x[17]);
    cx(x[29], x[5]);
    cx(x[19], x[5]);
    cx(x[5], x[21]);
    cx(x[21], x[15]);
    cx(x[29], x[7]);
    cx(x[13], x[15]);
    cx(x[17], x[25]);
    cx(x[7], x[23]);
    cx(x[25], x[9]);
    cx(x[15], x[7]);
    cx(x[7], x[1]);
    cx(x[1], x[17]);
    cx(x[17], x[11]);
    cx(x[23], x[31]);
    cx(x[11], x[19]);
    cx(x[19], x[3]);
    cx(x[3], x[27]);
    cx(x[21], x[29]);
    cx(x[9], x[17]);
    cx(x[31], x[7]);
    cx(x[26], x[2]);
    cx(x[20], x[28]);
    cx(x[28], x[12]);
    cx(x[6], x[30]);
    cx(x[2], x[10]);
    cx(x[16], x[8]);
    cx(x[8], x[0]);
    cx(x[30], x[14]);
    cx(x[14], x[22]);
    cx(x[22], x[8]);
    cx(x[8], x[26]);
    cx(x[26], x[18]);
    cx(x[10], x[26]);
    cx(x[0], x[24]);
    cx(x[26], x[20]);
    cx(x[24], x[2]);
    cx(x[2], x[28]);
    cx(x[18], x[12]);
    cx(x[12], x[20]);
    cx(x[20], x[30]);
    cx(x[30], x[16]);
    cx(x[28], x[4]);
    cx(x[18], x[4]);
    cx(x[4], x[20]);
    cx(x[20], x[14]);
    cx(x[28], x[6]);
    cx(x[12], x[14]);
    cx(x[16], x[24]);
    cx(x[6], x[22]);
    cx(x[24], x[8]);
    cx(x[14], x[6]);
    cx(x[6], x[0]);
    cx(x[0], x[16]);
    cx(x[16], x[10]);
    cx(x[22], x[30]);
    cx(x[10], x[18]);
    cx(x[18], x[2]);
    cx(x[2], x[26]);
    cx(x[20], x[28]);
    cx(x[8], x[16]);
    cx(x[30], x[6]);
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
        auto ans = t ^ rotl(t, 2) ^ rotl(t, 10) ^ rotl(t, 18) ^ rotl(t, 24);
        if (ans != Li || t != Li_inv) {
			printf("Error t = %u, ans = %u, L(i) = %u, reverse_L(i) = %u", t, ans, Li, Li_inv);
            exit(-1);
		}
	}
    puts("OK");
	return 0;
}