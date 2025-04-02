#ifndef QUANTUM_CIRC3_H
#define QUANTUM_CIRC3_H

#include <iostream>
#include <algorithm>
#include <cstdint>
#include "NCT.h"

namespace qcirc3 {
const int aux_num = 34;
qubit x[8], y[8], aux[aux_num] = {0};

/**
 * CNOT：12，NOT：4
 * 电路深度：8
 */
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

/**
 * CNOT：12，NOT：4
 * 电路深度：8
 */
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
 * Toffoli：14，CNOT：52
 * Toffoli深度：2
 * 电路深度：18
 */
void qt3(qubit *a, qubit *b, qubit *d) {
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
    ccx(d[4], d[5], d[0]);
    ccx(d[6], d[7], d[1]);
    ccx(d[8], d[9], d[2]);
    ccx(d[12], d[13], d[3]);
    ccx(d[10], d[11], d[14]);
    ccx(a[3], b[3], d[15]);
    ccx(a[2], b[2], d[16]);
    ccx(a[1], b[1], d[17]);
    ccx(a[0], b[0], d[18]);
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
    ccx(a[0], b[0], d[18]);
    ccx(a[1], b[1], d[17]);
    ccx(a[2], b[2], d[16]);
    ccx(a[3], b[3], d[15]);
    ccx(d[10], d[11], d[14]);
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
 * Toffoli：14，CNOT：52
 * Toffoli深度：2
 * 电路深度：18
 */
void qt3_inv(qubit *a, qubit *b, qubit *d) {
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
    ccx(d[10], d[11], d[14]);
    ccx(a[3], b[3], d[15]);
    ccx(a[2], b[2], d[16]);
    ccx(a[1], b[1], d[17]);
    ccx(a[0], b[0], d[18]);
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
    ccx(a[0], b[0], d[18]);
    ccx(a[1], b[1], d[17]);
    ccx(a[2], b[2], d[16]);
    ccx(a[3], b[3], d[15]);
    ccx(d[10], d[11], d[14]);
    ccx(d[12], d[13], d[3]);
    ccx(d[8], d[9], d[2]);
    ccx(d[6], d[7], d[1]);
    ccx(d[4], d[5], d[0]);
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

/**
 * CNOT：3
 * 电路深度：3
 */
void qt4(qubit *a) {
	cx(a[2], a[0]);
	cx(a[3], a[1]);
	cx(a[0], a[1]);
	std::swap(a[2], a[3]);
	std::swap(a[0], a[2]);
	std::swap(a[1], a[3]);
}

/**
 * CNOT：3
 * 电路深度：3
 */
void qt4_inv(qubit *a) {
	std::swap(a[1], a[3]);
	std::swap(a[0], a[2]);
	std::swap(a[2], a[3]);
	cx(a[0], a[1]);
	cx(a[3], a[1]);
	cx(a[2], a[0]);
}

/**
 * Toffoli：9，CNOT：29
 * Toffoli深度：2
 * 电路深度：18
 */
void qt8(qubit *a, qubit *d) {
	cx(a[2], d[2]);
    cx(a[3], d[2]);
    cx(a[0], d[1]);
    cx(a[2], d[1]);
    cx(a[1], d[0]);
    cx(a[3], d[0]);
    cx(d[1], d[3]);
    cx(d[0], d[3]);
    ccx(d[3], d[2], d[4]);
    ccx(d[1], a[2], d[5]);
    ccx(d[0], a[3], d[6]);
    cx(d[4], d[6]);
    cx(a[1], d[6]);
    cx(d[4], d[5]);
    cx(a[1], d[5]);
    cx(a[0], d[5]);
    cx(a[0], d[1]);
    cx(a[2], d[1]);
    cx(d[6], d[1]);
    cx(a[1], d[0]);
    cx(a[3], d[0]);
    cx(d[5], d[0]);
    cx(d[3], d[2]);
    cx(a[0], a[2]);
    cx(a[1], a[3]);
    cx(d[6], d[7]);
    cx(d[5], d[7]);
    cx(d[7], d[8]);
    ccx(d[7], d[2], d[9]);
    ccx(d[6], a[0], d[10]);
    ccx(d[5], a[1], d[11]);
    ccx(d[8], d[3], d[12]);
    ccx(d[1], a[2], d[13]);
    ccx(d[0], a[3], d[14]);
    cx(d[11], d[9]);
    cx(d[11], d[10]);
    cx(d[14], d[12]);
    cx(d[14], d[13]);
    std::swap(d[13], a[3]);
    std::swap(d[12], a[2]);
    std::swap(d[10], a[1]);
    std::swap(d[9], a[0]);
}

/**
 * Toffoli：9，CNOT：29
 * Toffoli深度：2
 * 电路深度：18
 */
void qt8_inv(qubit *a, qubit *d) {
	std::swap(d[9], a[0]);
    std::swap(d[10], a[1]);
    std::swap(d[12], a[2]);
    std::swap(d[13], a[3]);
    cx(d[14], d[13]);
    cx(d[14], d[12]);
    cx(d[11], d[10]);
    cx(d[11], d[9]);
    ccx(d[0], a[3], d[14]);
    ccx(d[1], a[2], d[13]);
    ccx(d[8], d[3], d[12]);
    ccx(d[5], a[1], d[11]);
    ccx(d[6], a[0], d[10]);
    ccx(d[7], d[2], d[9]);
    cx(d[7], d[8]);
    cx(d[5], d[7]);
    cx(d[6], d[7]);
    cx(a[1], a[3]);
    cx(a[0], a[2]);
    cx(d[3], d[2]);
    cx(d[5], d[0]);
    cx(a[3], d[0]);
    cx(a[1], d[0]);
    cx(d[6], d[1]);
    cx(a[2], d[1]);
    cx(a[0], d[1]);
    cx(a[0], d[5]);
    cx(a[1], d[5]);
    cx(d[4], d[5]);
    cx(a[1], d[6]);
    cx(d[4], d[6]);
    ccx(d[0], a[3], d[6]);
    ccx(d[1], a[2], d[5]);
    ccx(d[3], d[2], d[4]);
    cx(d[0], d[3]);
    cx(d[1], d[3]);
    cx(a[3], d[0]);
    cx(a[1], d[0]);
    cx(a[2], d[1]);
    cx(a[0], d[1]);
    cx(a[3], d[2]);
    cx(a[2], d[2]);
}

/**
 * Toffoli：14，CNOT：55
 * Toffoli深度：2
 * 电路深度：18
 */
void qt10(qubit *a, qubit *b, qubit *t, qubit *d) {
    cx(t[3], t[2]);
	cx(t[2], t[0]);
	cx(t[1], t[0]);
	// qt3
	cx(a[1], d[2]);
    cx(a[3], d[2]);
    cx(b[1], d[3]);
    cx(b[3], d[3]);
    cx(a[2], d[4]);
    cx(a[3], d[4]);
    cx(b[2], d[5]);
    cx(b[3], d[5]);
    cx(a[0], d[6]);
    cx(a[2], d[6]);
    cx(b[0], d[7]);
    cx(b[2], d[7]);
    cx(d[6], d[0]);
    cx(d[2], d[0]);
    cx(d[7], d[1]);
    cx(d[3], d[1]);
    cx(a[0], d[8]);
    cx(a[1], d[8]);
    cx(b[0], d[9]);
    cx(b[1], d[9]);
    ccx(d[0], d[1], t[0]);
    ccx(d[2], d[3], t[1]);
    ccx(d[4], d[5], t[2]);
    ccx(d[8], d[9], t[3]);
    ccx(d[6], d[7], d[10]);
    ccx(a[3], b[3], d[11]);
    ccx(a[2], b[2], d[12]);
    ccx(a[1], b[1], d[13]);
    ccx(a[0], b[0], d[14]);
    cx(t[1], t[0]);
    cx(t[2], t[0]);
    cx(d[11], t[0]);
    cx(d[10], t[1]);
    cx(d[11], t[1]);
    cx(d[12], t[1]);
    cx(t[3], t[2]);
    cx(d[11], t[2]);
    cx(d[14], t[2]);
    cx(d[11], t[3]);
    cx(d[12], t[3]);
    cx(d[13], t[3]);
    ccx(a[0], b[0], d[14]);
    ccx(a[1], b[1], d[13]);
    ccx(a[2], b[2], d[12]);
    ccx(a[3], b[3], d[11]);
    ccx(d[6], d[7], d[10]);
    cx(b[0], d[9]);
    cx(b[1], d[9]);
    cx(a[0], d[8]);
    cx(a[1], d[8]);
    cx(d[7], d[1]);
    cx(d[3], d[1]);
    cx(d[6], d[0]);
    cx(d[2], d[0]);
    cx(b[0], d[7]);
    cx(b[2], d[7]);
    cx(a[0], d[6]);
    cx(a[2], d[6]);
    cx(b[2], d[5]);
    cx(b[3], d[5]);
    cx(a[2], d[4]);
    cx(a[3], d[4]);
    cx(b[1], d[3]);
    cx(b[3], d[3]);
    cx(a[1], d[2]);
    cx(a[3], d[2]);
}

/**
 * CNOT：14
 * 电路深度：9
 */
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

/**
 * CNOT：14
 * 电路深度：8
 */
void qt12() {
	std::swap(y[6], y[4]);
	std::swap(y[2], y[4]);
	std::swap(y[1], y[4]);
	std::swap(y[3], y[4]);
	std::swap(y[7], y[4]);
	std::swap(y[5], y[4]);
	std::swap(y[0], y[4]);
	cx(y[0], y[1]);
	cx(y[1], y[3]);
	cx(y[4], y[6]);
	cx(y[6], y[0]);
	cx(y[0], y[5]);
	cx(y[3], y[0]);
	cx(y[5], y[7]);
	cx(y[7], y[0]);
	cx(y[2], y[5]);
	cx(y[3], y[2]);
	cx(y[5], y[1]);
	cx(y[4], y[3]);
	cx(y[7], y[4]);
	cx(y[6], y[2]);
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
	qubit *t2 = aux + 19;

	qubit *d1 = y;
	qubit *d0 = y + 4;
	// begin
	qt1();
    qt12();

	for (int i = 0; i < 4; i++) {
		cx(a0[i], a1[i]);
	}
	qt3(a1, a0, t0);

	{
		for (int i = 4; i < 19; i++) {
			if (t0[i] != 0) {
				puts("can't recover [4, 19) auxiliary qubit");
				exit(-1);
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		cx(a1[i], a0[i]);
	}
	qt4(a0);
	for (int i = 0; i < 4; i++) {
		cx(a0[i], t0[i]);
	}
	qt4_inv(a0);
	qt8(t0, t1);
	qt10(a0, t0, d1, t2);
	{
		for (int i = 0; i < 15; i++) {
			if (t2[i] != 0) {
				puts("can't recover [19, 34) auxiliary qubit");
				exit(-1);
			}
		}
	}
	qt10(a1, t0, d0, t2);
	{
		for (int i = 0; i < 15; i++) {
			if (t2[i] != 0) {
				puts("can't recover [19, 34) auxiliary qubit");
				exit(-1);
			}
		}
	}
	qt8_inv(t0, t1);

	{
		for (int i = 0; i < 15; i++) {
			if (t1[i] != 0) {
				puts("can't recover [19, 34) auxiliary qubit");
				exit(-1);
			}
		}
	}

	qt4(a0);
	for (int i = 0; i < 4; i++) {
		cx(a0[i], t0[i]);
	}
	qt4_inv(a0);
	for (int i = 0; i < 4; i++) {
		cx(a1[i], a0[i]);
	}
	qt3_inv(a1, a0, t0);
	for (int i = 0; i < 4; i++) {
		cx(a0[i], a1[i]);
	}
	qt1_inv();
	qt11();
	// end
	uint8_t ans = 0;
	for (int i = 0; i < 8; i++) {
		ans = (ans << 1) | y[i];
	}
	return ans;
}

void get_qunatum_sbox3(uint8_t sbox[256], uint8_t delta = 0) {
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