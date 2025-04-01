#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>

int get_bit(int x, int i) {
    return (x >> i) & 1;
}

void sbox(const int a[4], int z[4]) {
    int a0 = a[1] ^ a[2];
    int a1 = a[0] ^ a[1];
    int a2 = a[2] ^ a[3];
    int a3 = a[0] ^ a[2];
    int a4 = a[1] ^ a[3];
    int a5 = a[3];
    int b0 = a[0];
    int b1 = a0 ^ 1;
    int c0 = b0 & b1;
    int d0 = a0 ^ a5;
    int b2 = d0 ^ c0;
    int b3 = a1 ^ c0 ^ 1;
    int c1 = b2 & b3;
    int b4 = b3 ^ a2 ^ c1;
    int b5 = a0 ^ c1;
    int c2 = b4 & b5;
    int d1 = a3 ^ c2;
    int b6 = d1 ^ a5;
    int b7 = d0 ^ c2;
    int c3 = b6 & b7;
    int b8 = d1 ^ c0 ^ c1;
    int b9 = a1 ^ a5 ^ c1;
    int c4 = b8 & b9;
    int c5 = c2 ^ c3;
    z[0] = b2 ^ c5 ^ c4;
    z[1] = a4 ^ c2 ^ c4;
    z[2] = b4 ^ c3 ^ 1;
    z[3] = b3 ^ c5 ^ 1;
}

void x(int &x) {
	x ^= 1;
}

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

// 5个QAND，69个CNOT
void qt13(int a[4], int c[6]) {
	x(a[1]);
	cx(a[2], a[1]);
	QAND(a[0], a[1], c[0], c[5]);
	cx(a[2], a[1]);
	x(a[1]);
	cx(a[1], c[4]);
	cx(a[2], c[4]);
	cx(a[2], c[3]);
	cx(a[3], c[3]);
	cx(a[1], a[2]);
	cx(a[3], a[2]);
	cx(c[0], a[2]);
	x(a[1]);
	cx(a[0], a[1]);
	cx(c[0], a[1]);
	QAND(a[1], a[2], c[1], c[5]);
	cx(c[3], a[1]);
	cx(c[1], a[1]);
	cx(c[1], c[4]);
	QAND(a[1], c[4], c[2], c[5]);
	cx(c[1], c[4]);
	cx(c[3], a[1]);
	cx(c[1], a[1]);
	cx(a[0], a[1]);
	cx(c[0], a[1]);
	x(a[1]);
	cx(a[1], a[2]);
	cx(a[3], a[2]);
	cx(c[0], a[2]);
	cx(a[2], c[3]);
	cx(a[3], c[3]);
	cx(a[1], c[4]);
	cx(a[2], c[4]);
	cx(a[2], a[0]);
	cx(a[3], a[0]);
	cx(c[2], a[0]);
	cx(a[2], a[1]);
	cx(a[3], a[1]);
	cx(c[2], a[1]);
	QAND(a[0], a[1], c[3], c[5]);
	cx(a[2], a[1]);
	cx(a[3], a[1]);
	cx(c[2], a[1]);
	cx(a[2], a[0]);
	cx(a[3], a[0]);
	cx(c[2], a[0]);
	cx(a[0], a[2]);
	cx(c[0], a[2]);
	cx(c[1], a[2]);
	cx(c[2], a[2]);
	cx(a[0], a[1]);
	cx(a[3], a[1]);
	cx(c[1], a[1]);
	QAND(a[1], a[2], c[4], c[5]);
	cx(a[0], a[1]);
	cx(a[3], a[1]);
	cx(c[1], a[1]);
	cx(a[0], a[2]);
	cx(c[0], a[2]);
	cx(c[1], a[2]);
	cx(c[2], a[2]);
	cx(c[0], a[0]);
	cx(c[3], a[0]);
	cx(a[1], c[0]);
	cx(a[2], c[0]);
	cx(a[3], c[0]);
	cx(c[2], c[0]);
	cx(c[3], c[0]);
	cx(c[4], c[0]);
	cx(a[1], c[4]);
	cx(a[3], c[4]);
	cx(c[2], c[4]);
	cx(a[0], c[1]);
	cx(a[1], c[1]);
	cx(a[2], c[1]);
	cx(a[3], c[1]);
	cx(a[0], c[2]);
	cx(a[1], c[2]);
	std::swap(c[2], c[3]);
	std::swap(c[2], c[1]);
	std::swap(c[1], c[4]);
}

// 5个QAND_1，69个CNOT
void qt13_inv(int a[4], int c[6]) {
	std::swap(c[1], c[4]);
	std::swap(c[2], c[1]);
	std::swap(c[2], c[3]);
	cx(a[1], c[2]);
	cx(a[0], c[2]);
	cx(a[3], c[1]);
	cx(a[2], c[1]);
	cx(a[1], c[1]);
	cx(a[0], c[1]);
	cx(c[2], c[4]);
	cx(a[3], c[4]);
	cx(a[1], c[4]);
	cx(c[4], c[0]);
	cx(c[3], c[0]);
	cx(c[2], c[0]);
	cx(a[3], c[0]);
	cx(a[2], c[0]);
	cx(a[1], c[0]);
	cx(c[3], a[0]);
	cx(c[0], a[0]);
	cx(c[2], a[2]);
	cx(c[1], a[2]);
	cx(c[0], a[2]);
	cx(a[0], a[2]);
	cx(c[1], a[1]);
	cx(a[3], a[1]);
	cx(a[0], a[1]);
	QAND_1(a[1], a[2], c[4]);
	cx(c[1], a[1]);
	cx(a[3], a[1]);
	cx(a[0], a[1]);
	cx(c[2], a[2]);
	cx(c[1], a[2]);
	cx(c[0], a[2]);
	cx(a[0], a[2]);
	cx(c[2], a[0]);
	cx(a[3], a[0]);
	cx(a[2], a[0]);
	cx(c[2], a[1]);
	cx(a[3], a[1]);
	cx(a[2], a[1]);
	QAND_1(a[0], a[1], c[3]);
	cx(c[2], a[1]);
	cx(a[3], a[1]);
	cx(a[2], a[1]);
	cx(c[2], a[0]);
	cx(a[3], a[0]);
	cx(a[2], a[0]);
	cx(a[2], c[4]);
	cx(a[1], c[4]);
	cx(a[3], c[3]);
	cx(a[2], c[3]);
	cx(c[0], a[2]);
	cx(a[3], a[2]);
	cx(a[1], a[2]);
	x(a[1]);
	cx(c[0], a[1]);
	cx(a[0], a[1]);
	cx(c[1], a[1]);
	cx(c[3], a[1]);
	cx(c[1], c[4]);
	QAND_1(a[1], c[4], c[2]);
	cx(c[1], c[4]);
	cx(c[1], a[1]);
	cx(c[3], a[1]);
	QAND_1(a[1], a[2], c[1]);
	cx(c[0], a[1]);
	cx(a[0], a[1]);
	x(a[1]);
	cx(c[0], a[2]);
	cx(a[3], a[2]);
	cx(a[1], a[2]);
	cx(a[3], c[3]);
	cx(a[2], c[3]);
	cx(a[2], c[4]);
	cx(a[1], c[4]);
	x(a[1]);
	cx(a[2], a[1]);
	QAND_1(a[0], a[1], c[0]);
	cx(a[2], a[1]);
	x(a[1]);
}

// gf16_sbox = [0x0, 0x1, 0x3, 0x2, 0xf, 0xc, 0x9, 0xb, 0xa, 0x6, 0x8, 0x7, 0x5, 0xe, 0xd, 0x4]
int main() {
	for (int i = 0; i < 16; i++) {
		int a[4] = {0}, z[4] = {0}, c[6] = {0};
		a[0] = get_bit(i, 3);
		a[1] = get_bit(i, 2);
		a[2] = get_bit(i, 1);
		a[3] = get_bit(i, 0);
		sbox(a, z);
		qt13(a, c);
		int y1 = (z[0] << 3) | (z[1] << 2) | (z[2] << 1) | z[3];
		// int y2 = (c[0] << 3) | (c[4] << 2) | (c[1] << 1) | c[2];
		int y2 = (c[0] << 3) | (c[1] << 2) | (c[2] << 1) | c[3];
		printf("%d %d\n", y1, y2);
		if (c[5] != 0) {
			puts("qt13: can't recover c[5]");
			exit(0);
		}
		if (y1 != y2) {
			puts("qt13: answer doesn't match");
			exit(0);
		}
		qt13_inv(a, c);
		int k = (a[0] << 3) | (a[1] << 2) | (a[2] << 1) | a[3];
		for (int j = 0; j < 6; j++) {
			if (c[j] != 0) {
				puts("qt13_inv: can't recover qubit");
				exit(0);
			}
		}
		if (k != i) {
			puts("qt13_inv: can't recover input");
			exit(0);
		}
	}
	puts("OK");
	return 0;
}