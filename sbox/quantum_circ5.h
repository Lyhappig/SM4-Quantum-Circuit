#ifndef QUANTUM_CIRC5_H
#define QUANTUM_CIRC5_H

#include <iostream>
#include <algorithm>
#include <cstdint>
#include "Clifford_T.h"

namespace qcirc5 {
const int aux_num = 37;
qubit x[8], y[8], aux[aux_num] = {0};

void qt1() {
	cx(x[6], x[7]);
    cx(x[2], x[6]);
    cx(x[0], x[5]);
    cx(x[7], x[0]);
    cx(x[2], x[7]);
    cx(x[0], x[4]);
    cx(x[3], x[0]);
    cx(x[3], x[2]);
    cx(x[5], x[3]);
    cx(x[4], x[2]);
    cx(x[2], x[1]);
    cx(x[1], x[5]);
    std::swap(x[0], x[3]);
    std::swap(x[0], x[5]);
	qx(x[0]);
	qx(x[2]);
	qx(x[4]);
	qx(x[6]);
}

void qt1_inv() {
	qx(x[6]);
	qx(x[4]);
	qx(x[2]);
	qx(x[0]);
	std::swap(x[0], x[5]);
	std::swap(x[0], x[3]);
	cx(x[1], x[5]);
	cx(x[2], x[1]);
	cx(x[4], x[2]);
	cx(x[5], x[3]);
	cx(x[3], x[2]);
	cx(x[3], x[0]);
	cx(x[0], x[4]);
	cx(x[2], x[7]);
	cx(x[7], x[0]);
	cx(x[0], x[5]);
	cx(x[2], x[6]);
	cx(x[6], x[7]);
}

/**
 * (a[4], b[4], d[28] = 0) -> (a[4], b[4], [a * b][4], d[24] = 0)
 */
void qt12(qubit *a, qubit *b, qubit *d) {
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
    cx(d[1], d[0]);
    cx(d[2], d[0]);
    cx(d[15], d[0]);
    cx(d[14], d[1]);
    cx(d[15], d[1]);
    cx(d[16], d[1]);
    cx(d[3], d[2]);
    cx(d[15], d[2]);
    cx(d[18], d[2]);
    cx(d[15], d[3]);
    cx(d[16], d[3]);
    cx(d[17], d[3]);
    QAND_inv(a[0], b[0], d[18]);
    QAND_inv(a[1], b[1], d[17]);
    QAND_inv(a[2], b[2], d[16]);
    QAND_inv(a[3], b[3], d[15]);
    QAND_inv(d[10], d[11], d[14]);
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

/**
 * (a[4], b[4], [a * b][4], d[24] = 0) -> (a[4], b[4], d[28] = 0)
 */
void qt12_inv(qubit *a, qubit *b, qubit *d) {
	cx(a[3], d[6]);
    cx(a[1], d[6]);
    cx(b[3], d[7]);
    cx(b[1], d[7]);
    cx(a[3], d[8]);
    cx(a[2], d[8]);
    cx(b[3], d[9]);
    cx(b[2], d[9]);
    cx(a[2], d[10]);
    cx(a[0], d[10]);
    cx(b[2], d[11]);
    cx(b[0], d[11]);
    cx(d[6], d[4]);
    cx(d[10], d[4]);
    cx(d[7], d[5]);
    cx(d[11], d[5]);
    cx(a[1], d[12]);
    cx(a[0], d[12]);
    cx(b[1], d[13]);
    cx(b[0], d[13]);
    QAND(d[10], d[11], d[14], d[19]);
    QAND(a[3], b[3], d[15], d[20]);
    QAND(a[2], b[2], d[16], d[21]);
    QAND(a[1], b[1], d[17], d[22]);
    QAND(a[0], b[0], d[18], d[23]);
    cx(d[17], d[3]);
    cx(d[16], d[3]);
    cx(d[15], d[3]);
    cx(d[18], d[2]);
    cx(d[15], d[2]);
    cx(d[3], d[2]);
    cx(d[16], d[1]);
    cx(d[15], d[1]);
    cx(d[14], d[1]);
    cx(d[15], d[0]);
    cx(d[2], d[0]);
    cx(d[1], d[0]);
    QAND_inv(a[0], b[0], d[18]);
    QAND_inv(a[1], b[1], d[17]);
    QAND_inv(a[2], b[2], d[16]);
    QAND_inv(a[3], b[3], d[15]);
    QAND_inv(d[10], d[11], d[14]);
    QAND_inv(d[12], d[13], d[3]);
    QAND_inv(d[8], d[9], d[2]);
    QAND_inv(d[6], d[7], d[1]);
    QAND_inv(d[4], d[5], d[0]);
    cx(b[1], d[13]);
    cx(b[0], d[13]);
    cx(a[1], d[12]);
    cx(a[0], d[12]);
    cx(d[7], d[5]);
    cx(d[11], d[5]);
    cx(d[6], d[4]);
    cx(d[10], d[4]);
    cx(b[2], d[11]);
    cx(b[0], d[11]);
    cx(a[2], d[10]);
    cx(a[0], d[10]);
    cx(b[3], d[9]);
    cx(b[2], d[9]);
    cx(a[3], d[8]);
    cx(a[2], d[8]);
    cx(b[3], d[7]);
    cx(b[1], d[7]);
    cx(a[3], d[6]);
    cx(a[1], d[6]);
}

void qt4(qubit *a) {
	cx(a[2], a[0]);
	cx(a[3], a[1]);
	cx(a[0], a[1]);
	std::swap(a[2], a[3]);
	std::swap(a[0], a[2]);
	std::swap(a[1], a[3]);
}

void qt4_inv(qubit *a) {
	std::swap(a[1], a[3]);
	std::swap(a[0], a[2]);
	std::swap(a[2], a[3]);
	cx(a[0], a[1]);
	cx(a[3], a[1]);
	cx(a[2], a[0]);
}

/**
 * (a[4], c[6] = 0) -> (a'[4], d[4], c'[1], 0)
 */
void qt13(qubit *a, qubit *c) {
	qx(a[1]);
	cx(a[2], a[1]);
	QAND(a[0], a[1], c[0], c[5]);
	cx(a[2], a[1]);
	qx(a[1]);
	cx(a[1], c[4]);
	cx(a[2], c[4]);
	cx(a[2], c[3]);
	cx(a[3], c[3]);
	cx(a[1], a[2]);
	cx(a[3], a[2]);
	cx(c[0], a[2]);
	qx(a[1]);
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
	qx(a[1]);
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

/**
 * (a'[4], d[4], c'[1]) -> (a[4], c[5] = 0)
 */
void qt13_inv(qubit *a, qubit *c) {
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
	QAND_inv(a[1], a[2], c[4]);
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
	QAND_inv(a[0], a[1], c[3]);
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
	qx(a[1]);
	cx(c[0], a[1]);
	cx(a[0], a[1]);
	cx(c[1], a[1]);
	cx(c[3], a[1]);
	cx(c[1], c[4]);
	QAND_inv(a[1], c[4], c[2]);
	cx(c[1], c[4]);
	cx(c[1], a[1]);
	cx(c[3], a[1]);
	QAND_inv(a[1], a[2], c[1]);
	cx(c[0], a[1]);
	cx(a[0], a[1]);
	qx(a[1]);
	cx(c[0], a[2]);
	cx(a[3], a[2]);
	cx(a[1], a[2]);
	cx(a[3], c[3]);
	cx(a[2], c[3]);
	cx(a[2], c[4]);
	cx(a[1], c[4]);
	qx(a[1]);
	cx(a[2], a[1]);
	QAND_inv(a[0], a[1], c[0]);
	cx(a[2], a[1]);
	qx(a[1]);
}

/**
 * (a[4], b[4], c[4], d[28] = 0) -> (a[4], b[4], [c ^ (a * b)][4], d[28] = 0)
 */
void qt14(qubit *a, qubit *b, qubit *c, qubit *d) {
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
	QAND_inv(d[12], d[13], d[3]);
	QAND_inv(d[8], d[9], d[2]);
	QAND_inv(d[6], d[7], d[1]);
	QAND_inv(d[4], d[5], d[0]);
	QAND_inv(a[0], b[0], d[18]);
	QAND_inv(a[1], b[1], d[17]);
	QAND_inv(a[2], b[2], d[16]);
	QAND_inv(a[3], b[3], d[15]);
	QAND_inv(d[10], d[11], d[14]);
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

void qt11() {
	cx(y[6], y[2]);
	cx(y[7], y[4]);
	cx(y[4], y[3]);
	cx(y[5], y[1]);
	cx(y[3], y[2]);
	cx(y[2], y[5]);
	cx(y[7], y[0]);
	cx(y[5], y[7]);
	cx(y[3], y[0]);
	cx(y[0], y[5]);
	cx(y[6], y[0]);
	cx(y[4], y[6]);
	cx(y[1], y[3]);
	cx(y[0], y[1]);
	std::swap(y[0], y[4]);
	std::swap(y[5], y[4]);
	std::swap(y[7], y[4]);
	std::swap(y[3], y[4]);
	std::swap(y[1], y[4]);
	std::swap(y[2], y[4]);
	std::swap(y[6], y[4]);
	qx(y[0]);
	qx(y[1]);
	qx(y[3]);
	qx(y[6]);
	qx(y[7]);
}

int solve(uint8_t alpha, uint8_t delta) {
	for (int i = 0; i < 8; i++) {
		x[i] = (alpha >> (7 - i)) & 1;
		y[i] = (delta >> (7 - i)) & 1;
	}
	qubit *a1 = x;
	qubit *a0 = x + 4;

	qubit *t0 = aux;
	qubit *t1 = aux + 4;
	qubit *t2 = aux + 9;

	qubit *d1 = y;
	qubit *d0 = y + 4;
	// begin
	qt1();

	cx(a0[0], a1[0]);
	cx(a0[1], a1[1]);
	cx(a0[2], a1[2]);
	cx(a0[3], a1[3]);

	qt12(a1, a0, t0);

	{
		for (int i = 4; i < 28; i++) {
			if (t0[i] != 0) {
				puts("can't recover [4, 28) auxiliary qubit");
				exit(-1);
			}
		}
	}

	cx(a1[0], a0[0]);
	cx(a1[1], a0[1]);
	cx(a1[2], a0[2]);
	cx(a1[3], a0[3]);

	qt4(a0);
	cx(a0[0], aux[0]);
	cx(a0[1], aux[1]);
	cx(a0[2], aux[2]);
	cx(a0[3], aux[3]);
	qt4_inv(a0);

	qt13(t0, t1);

	{
		if (t1[5] != 0) {
			puts("can't recover aux[9]");
			exit(-1);
		}
	}

	qt14(a0, t1, d1, t2);

	{
		for (int i = 0; i < 28; i++) {
			if (t2[i] != 0) {
				puts("can't recover [9, 37) auxiliary qubit");
				exit(-1);
			}
		}
	}

	qt14(a1, t1, d0, t2);

	{
		for (int i = 0; i < 28; i++) {
			if (t2[i] != 0) {
				puts("can't recover [9, 37) auxiliary qubit");
				exit(-1);
			}
		}
	}

	qt13_inv(t0, t1);

	{
		for (int i = 0; i < 5; i++) {
			if (t1[i] != 0) {
				puts("can't recover [4, 9) auxiliary qubit");
				exit(-1);
			}
		}
	}

	qt4(a0);
	
	cx(a0[0], aux[0]);
	cx(a0[1], aux[1]);
	cx(a0[2], aux[2]);
	cx(a0[3], aux[3]);

	qt4_inv(a0);
	
	cx(a1[0], a0[0]);
	cx(a1[1], a0[1]);
	cx(a1[2], a0[2]);
	cx(a1[3], a0[3]);

	qt12_inv(a1, a0, t0);

	{
		for (int i = 0; i < 28; i++) {
			if (t0[i] != 0) {
				puts("can't recover [0, 28) auxiliary qubit");
				exit(-1);
			}
		}
	}
	
	cx(a0[0], a1[0]);
	cx(a0[1], a1[1]);
	cx(a0[2], a1[2]);
	cx(a0[3], a1[3]);

	qt1_inv();
	qt11();
	// end
	uint8_t ans = 0;
	for (int i = 0; i < 8; i++) {
		ans = (ans << 1) | y[i];
	}
	return ans;
}

void get_qunatum_sbox5(uint8_t sbox[256], uint8_t delta = 0) {
	printf("Location: %s\n", __func__);
	for (int i = 0; i < 256; ++i) {
		sbox[i] = solve(i, delta);
		int val = 0;
		for (int j = 0; j < 8; j++) {
			val = (val << 1) | x[j];
		}
		if (val != i) {
			puts("can't recover input qubit");
			exit(-1);
		}
		for (int j = 0; j < aux_num; j++) {
			if (aux[j] != 0) {
				puts("can't recover auxiliary qubit");
				exit(-1);
			}
		}
	}
}
}

#endif