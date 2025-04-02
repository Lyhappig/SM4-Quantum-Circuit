#ifndef QUANTUM_CIRC7_H
#define QUANTUM_CIRC7_H

#include <iostream>
#include <algorithm>
#include <cstdint>
#include "Clifford_T.h"

namespace qcirc7 {
const int aux_num = 102;
qubit x[8], p[27], q[9], r[6], c[3], z[4], k[5], u[18], v[30], y[8];


int solve(uint8_t alpha, uint8_t delta) {
	for (int i = 0; i < 8; i++) {
		x[i] = (alpha >> (7 - i)) & 1;
		y[i] = (delta >> (7 - i)) & 1;
	}
    // part1;
    cx(x[7], p[13]);
    qx(p[13]);
    cx(x[2], p[15]);
    cx(x[6], p[15]);
    cx(x[7], p[17]);
    cx(p[15], p[17]);
    cx(x[0], p[19]);
    cx(x[5], p[19]);
    cx(x[3], p[11]);
    cx(p[19], p[11]);
    cx(p[17], p[5]);
    cx(p[11], p[5]);
    cx(x[1], p[20]);
    cx(p[19], p[20]);
    cx(x[2], p[22]);
    cx(x[4], p[22]);
    cx(x[7], p[12]);
    cx(p[22], p[12]);
    cx(x[0], p[3]);
    cx(p[12], p[3]);
    cx(p[5], p[1]);
    cx(p[3], p[1]);
    cx(p[20], p[2]);
    cx(p[3], p[2]);
    cx(x[7], p[7]);
    cx(p[1], p[7]);
    cx(p[19], p[6]);
    cx(p[7], p[6]);
    cx(p[12], p[0]);
    cx(p[6], p[0]);
    cx(p[15], p[9]);
    cx(p[3], p[9]);
    qx(p[9]);
    cx(x[6], p[10]);
    cx(p[2], p[10]);
    cx(p[6], p[8]);
    cx(p[10], p[8]);
    cx(x[6], p[14]);
    cx(p[6], p[14]);
    cx(p[19], p[18]);
    cx(p[22], p[18]);
    cx(x[1], p[21]);
    cx(p[22], p[21]);
    cx(p[5], p[4]);
    cx(p[21], p[4]);
    cx(p[10], p[16]);
    cx(p[4], p[16]);
    cx(x[3], p[23]);
    cx(p[10], p[23]);
    qx(p[23]);
    cx(p[11], p[24]);
    cx(p[10], p[24]);
    cx(x[1], p[25]);
    cx(p[24], p[25]);
    qx(p[25]);
    cx(x[4], p[26]);
    cx(p[6], p[26]);
    qx(p[7]);
    qx(p[15]);
    qx(p[19]);
    qx(p[22]);
    QAND(p[0], p[1], q[0], u[0]);
    QAND(p[2], p[3], q[1], u[1]);
    QAND(p[4], p[5], q[2], u[2]);
    QAND(p[6], p[7], q[3], u[3]);
    QAND(p[8], p[9], q[4], u[4]);
    QAND(p[10], p[11], q[5], u[5]);
    QAND(p[12], p[13], q[6], u[6]);
    QAND(p[14], p[15], q[7], u[7]);
    QAND(p[16], p[17], q[8], u[8]);
    cx(q[0], r[0]);
    cx(q[2], r[0]);
    cx(q[1], r[1]);
    cx(q[2], r[1]);
    cx(q[3], r[2]);
    cx(q[4], r[2]);
    cx(q[3], r[3]);
    cx(q[5], r[3]);
    cx(q[6], r[4]);
    cx(q[8], r[4]);
    cx(q[7], r[5]);
    cx(q[8], r[5]);
    cx(r[4], r[0]);
    cx(r[5], r[1]);
    cx(r[4], r[2]);
    cx(r[5], r[3]);
    cx(p[26], r[0]);
    cx(p[25], r[1]);
    cx(p[20], r[2]);
    cx(p[18], r[3]);
    cx(q[8], r[5]);
    cx(q[7], r[5]);
    cx(q[8], r[4]);
    cx(q[6], r[4]);
    // part2;
    cx(r[1], v[0]);
    cx(r[2], v[0]);
    cx(r[0], v[1]);
    cx(r[1], v[1]);
    cx(r[2], v[2]);
    cx(r[3], v[2]);
    cx(r[0], v[3]);
    cx(r[2], v[3]);
    cx(r[1], v[4]);
    cx(r[3], v[4]);
    cx(v[0], v[5]);
    qx(v[5]);
    QAND(r[0], v[5], c[0], u[0]);
    cx(v[0], v[6]);
    cx(r[3], v[6]);
    cx(v[6], v[7]);
    cx(c[0], v[7]);
    cx(v[1], v[8]);
    cx(c[0], v[8]);
    qx(v[8]);
    QAND(v[7], v[8], c[1], u[0]);
    cx(v[8], v[9]);
    cx(v[2], v[9]);
    cx(c[1], v[9]);
    cx(v[0], v[10]);
    cx(c[1], v[10]);
    QAND(v[9], v[10], c[2], u[0]);
    cx(v[3], v[11]);
    cx(c[2], v[11]);
    cx(v[11], v[12]);
    cx(r[3], v[12]);
    cx(v[6], v[17]);
    cx(c[2], v[17]);
    QAND(v[12], v[17], r[4], u[0]);
    cx(v[11], v[18]);
    cx(c[0], v[18]);
    cx(c[1], v[18]);
    cx(v[1], v[19]);
    cx(r[3], v[19]);
    cx(c[1], v[19]);
    QAND(v[18], v[19], r[5], u[0]);
    cx(c[2], v[20]);
    cx(r[4], v[20]);
    cx(v[7], z[0]);
    cx(v[20], z[0]);
    cx(r[5], z[0]);
    cx(v[4], z[1]);
    cx(c[2], z[1]);
    cx(r[5], z[1]);
    cx(v[9], z[2]);
    cx(r[4], z[2]);
    qx(z[2]);
    cx(v[8], z[3]);
    cx(v[20], z[3]);
    qx(z[3]);
    cx(r[4], v[20]);
    cx(c[2], v[20]);
    cx(c[1], v[19]);
    cx(r[3], v[19]);
    cx(v[1], v[19]);
    cx(c[1], v[18]);
    cx(c[0], v[18]);
    cx(v[11], v[18]);
    cx(c[2], v[17]);
    cx(v[6], v[17]);
    cx(r[3], v[12]);
    cx(v[11], v[12]);
    cx(c[2], v[11]);
    cx(v[3], v[11]);
    cx(c[1], v[10]);
    cx(v[0], v[10]);
    cx(c[1], v[9]);
    cx(v[2], v[9]);
    cx(v[8], v[9]);
    qx(v[8]);
    cx(c[0], v[8]);
    cx(v[1], v[8]);
    cx(c[0], v[7]);
    cx(v[6], v[7]);
    cx(r[3], v[6]);
    cx(v[0], v[6]);
    qx(v[5]);
    cx(v[0], v[5]);
    cx(r[3], v[4]);
    cx(r[1], v[4]);
    cx(r[2], v[3]);
    cx(r[0], v[3]);
    cx(r[3], v[2]);
    cx(r[2], v[2]);
    cx(r[1], v[1]);
    cx(r[0], v[1]);
    cx(r[2], v[0]);
    cx(r[1], v[0]);
    // part3;
    cx(z[0], k[0]);
    cx(z[2], k[0]);
    cx(z[1], k[1]);
    cx(z[3], k[1]);
    cx(z[0], k[2]);
    cx(z[1], k[2]);
    cx(z[2], k[3]);
    cx(z[3], k[3]);
    cx(k[0], k[4]);
    cx(k[1], k[4]);
    QAND(p[18], k[4], u[0], v[0]);
    QAND(p[20], k[0], u[1], v[1]);
    QAND(p[21], k[1], u[2], v[2]);
    QAND(p[19], k[2], u[3], v[3]);
    QAND(p[23], z[0], u[4], v[4]);
    QAND(p[24], z[1], u[5], v[5]);
    QAND(p[22], k[3], u[6], v[6]);
    QAND(p[25], z[2], u[7], v[7]);
    QAND(p[26], z[3], u[8], v[8]);
    QAND(p[0], k[4], u[9], v[9]);
    QAND(p[2], k[0], u[10], v[10]);
    QAND(p[4], k[1], u[11], v[11]);
    QAND(p[6], k[2], u[12], v[12]);
    QAND(p[8], z[0], u[13], v[13]);
    QAND(p[10], z[1], u[14], v[14]);
    QAND(p[12], k[3], u[15], v[15]);
    QAND(p[14], z[2], u[16], v[16]);
    QAND(p[16], z[3], u[17], v[17]);
    cx(u[9], v[0]);
    cx(u[12], v[0]);
    cx(u[11], v[1]);
    cx(u[14], v[1]);
    cx(u[16], v[2]);
    cx(v[0], v[2]);
    cx(v[1], v[3]);
    cx(v[2], v[3]);
    cx(u[15], y[0]);
    cx(v[3], y[0]);
    cx(u[13], v[5]);
    cx(u[17], v[5]);
    cx(u[12], v[6]);
    cx(v[3], v[6]);
    cx(v[5], y[4]);
    cx(v[6], y[4]);
    cx(u[5], v[8]);
    cx(u[6], v[8]);
    cx(u[7], v[9]);
    cx(v[8], v[9]);
    cx(u[4], v[10]);
    cx(v[9], v[10]);
    cx(v[5], y[6]);
    cx(v[6], y[6]);
    cx(v[10], y[6]);
    qx(y[6]);
    cx(u[10], v[12]);
    cx(v[2], v[12]);
    cx(v[5], v[13]);
    cx(v[12], v[13]);
    cx(v[10], y[3]);
    cx(v[13], y[3]);
    cx(u[0], v[15]);
    cx(u[3], v[15]);
    cx(v[9], v[16]);
    cx(v[15], v[16]);
    cx(u[2], v[17]);
    cx(v[16], v[17]);
    cx(v[10], v[18]);
    cx(v[13], v[18]);
    cx(v[17], v[18]);
    cx(u[15], y[7]);
    cx(v[3], y[7]);
    cx(v[18], y[7]);
    qx(y[7]);
    cx(u[13], v[20]);
    cx(v[0], v[20]);
    cx(u[11], v[21]);
    cx(v[20], v[21]);
    cx(v[17], y[5]);
    cx(v[21], y[5]);
    cx(v[13], v[23]);
    cx(v[16], v[23]);
    cx(u[1], v[24]);
    cx(v[23], v[24]);
    cx(u[8], v[25]);
    cx(v[24], v[25]);
    cx(u[7], y[2]);
    cx(v[25], y[2]);
    cx(v[17], v[27]);
    cx(v[21], v[27]);
    cx(v[24], v[27]);
    cx(u[15], v[28]);
    cx(v[3], v[28]);
    cx(v[27], v[28]);
    cx(u[5], v[29]);
    cx(v[28], v[29]);
    cx(u[3], y[1]);
    cx(v[29], y[1]);
    qx(y[1]);
    qx(y[0]);
    qx(y[3]);

	/* reverse */

    cx(v[28], v[29]);
    cx(u[5], v[29]);
    cx(v[27], v[28]);
    cx(v[3], v[28]);
    cx(u[15], v[28]);
    cx(v[24], v[27]);
    cx(v[21], v[27]);
    cx(v[17], v[27]);
    cx(v[24], v[25]);
    cx(u[8], v[25]);
    cx(v[23], v[24]);
    cx(u[1], v[24]);
    cx(v[16], v[23]);
    cx(v[13], v[23]);
    cx(v[20], v[21]);
    cx(u[11], v[21]);
    cx(v[0], v[20]);
    cx(u[13], v[20]);
    cx(v[17], v[18]);
    cx(v[13], v[18]);
    cx(v[10], v[18]);
    cx(v[16], v[17]);
    cx(u[2], v[17]);
    cx(v[15], v[16]);
    cx(v[9], v[16]);
    cx(u[3], v[15]);
    cx(u[0], v[15]);
    cx(v[12], v[13]);
    cx(v[5], v[13]);
    cx(v[2], v[12]);
    cx(u[10], v[12]);
    cx(v[9], v[10]);
    cx(u[4], v[10]);
    cx(v[8], v[9]);
    cx(u[7], v[9]);
    cx(u[6], v[8]);
    cx(u[5], v[8]);
    cx(v[3], v[6]);
    cx(u[12], v[6]);
    cx(u[17], v[5]);
    cx(u[13], v[5]);
    cx(v[2], v[3]);
    cx(v[1], v[3]);
    cx(v[0], v[2]);
    cx(u[16], v[2]);
    cx(u[14], v[1]);
    cx(u[11], v[1]);
    cx(u[12], v[0]);
    cx(u[9], v[0]);
    QAND_inv(p[16], z[3], u[17]);
    QAND_inv(p[14], z[2], u[16]);
    QAND_inv(p[12], k[3], u[15]);
    QAND_inv(p[10], z[1], u[14]);
    QAND_inv(p[8], z[0], u[13]);
    QAND_inv(p[6], k[2], u[12]);
    QAND_inv(p[4], k[1], u[11]);
    QAND_inv(p[2], k[0], u[10]);
    QAND_inv(p[0], k[4], u[9]);
    QAND_inv(p[26], z[3], u[8]);
    QAND_inv(p[25], z[2], u[7]);
    QAND_inv(p[22], k[3], u[6]);
    QAND_inv(p[24], z[1], u[5]);
    QAND_inv(p[23], z[0], u[4]);
    QAND_inv(p[19], k[2], u[3]);
    QAND_inv(p[21], k[1], u[2]);
    QAND_inv(p[20], k[0], u[1]);
    QAND_inv(p[18], k[4], u[0]);
    cx(k[1], k[4]);
    cx(k[0], k[4]);
    cx(z[3], k[3]);
    cx(z[2], k[3]);
    cx(z[1], k[2]);
    cx(z[0], k[2]);
    cx(z[3], k[1]);
    cx(z[1], k[1]);
    cx(z[2], k[0]);
    cx(z[0], k[0]);

    cx(r[1], v[0]);
    cx(r[2], v[0]);
    cx(r[0], v[1]);
    cx(r[1], v[1]);
    cx(r[2], v[2]);
    cx(r[3], v[2]);
    cx(r[0], v[3]);
    cx(r[2], v[3]);
    cx(r[1], v[4]);
    cx(r[3], v[4]);
    cx(v[0], v[5]);
    qx(v[5]);
    cx(v[0], v[6]);
    cx(r[3], v[6]);
    cx(v[6], v[7]);
    cx(c[0], v[7]);
    cx(v[1], v[8]);
    cx(c[0], v[8]);
    qx(v[8]);
    cx(v[8], v[9]);
    cx(v[2], v[9]);
    cx(c[1], v[9]);
    cx(v[0], v[10]);
    cx(c[1], v[10]);
    cx(v[3], v[11]);
    cx(c[2], v[11]);
    cx(v[11], v[12]);
    cx(r[3], v[12]);
    cx(v[6], v[17]);
    cx(c[2], v[17]);
    cx(v[11], v[18]);
    cx(c[0], v[18]);
    cx(c[1], v[18]);
    cx(v[1], v[19]);
    cx(r[3], v[19]);
    cx(c[1], v[19]);
    cx(c[2], v[20]);
    cx(r[4], v[20]);
    qx(z[3]);
    cx(v[20], z[3]);
    cx(v[8], z[3]);
    qx(z[2]);
    cx(r[4], z[2]);
    cx(v[9], z[2]);
    cx(r[5], z[1]);
    cx(c[2], z[1]);
    cx(v[4], z[1]);
    cx(r[5], z[0]);
    cx(v[20], z[0]);
    cx(v[7], z[0]);
    cx(r[4], v[20]);
    cx(c[2], v[20]);
    QAND_inv(v[18], v[19], r[5]);
    cx(c[1], v[19]);
    cx(r[3], v[19]);
    cx(v[1], v[19]);
    cx(c[1], v[18]);
    cx(c[0], v[18]);
    cx(v[11], v[18]);
    QAND_inv(v[12], v[17], r[4]);
    cx(c[2], v[17]);
    cx(v[6], v[17]);
    cx(r[3], v[12]);
    cx(v[11], v[12]);
    cx(c[2], v[11]);
    cx(v[3], v[11]);
    QAND_inv(v[9], v[10], c[2]);
    cx(c[1], v[10]);
    cx(v[0], v[10]);
    cx(c[1], v[9]);
    cx(v[2], v[9]);
    cx(v[8], v[9]);
    QAND_inv(v[7], v[8], c[1]);
    qx(v[8]);
    cx(c[0], v[8]);
    cx(v[1], v[8]);
    cx(c[0], v[7]);
    cx(v[6], v[7]);
    cx(r[3], v[6]);
    cx(v[0], v[6]);
    QAND_inv(r[0], v[5], c[0]);
    qx(v[5]);
    cx(v[0], v[5]);
    cx(r[3], v[4]);
    cx(r[1], v[4]);
    cx(r[2], v[3]);
    cx(r[0], v[3]);
    cx(r[3], v[2]);
    cx(r[2], v[2]);
    cx(r[1], v[1]);
    cx(r[0], v[1]);
    cx(r[2], v[0]);
    cx(r[1], v[0]);

    cx(q[6], r[4]);
    cx(q[8], r[4]);
    cx(q[7], r[5]);
    cx(q[8], r[5]);
    cx(p[18], r[3]);
    cx(p[20], r[2]);
    cx(p[25], r[1]);
    cx(p[26], r[0]);
    cx(r[5], r[3]);
    cx(r[4], r[2]);
    cx(r[5], r[1]);
    cx(r[4], r[0]);
    cx(q[8], r[5]);
    cx(q[7], r[5]);
    cx(q[8], r[4]);
    cx(q[6], r[4]);
    cx(q[5], r[3]);
    cx(q[3], r[3]);
    cx(q[4], r[2]);
    cx(q[3], r[2]);
    cx(q[2], r[1]);
    cx(q[1], r[1]);
    cx(q[2], r[0]);
    cx(q[0], r[0]);
    QAND_inv(p[16], p[17], q[8]);
    QAND_inv(p[14], p[15], q[7]);
    QAND_inv(p[12], p[13], q[6]);
    QAND_inv(p[10], p[11], q[5]);
    QAND_inv(p[8], p[9], q[4]);
    QAND_inv(p[6], p[7], q[3]);
    QAND_inv(p[4], p[5], q[2]);
    QAND_inv(p[2], p[3], q[1]);
    QAND_inv(p[0], p[1], q[0]);
    qx(p[22]);
    qx(p[19]);
    qx(p[15]);
    qx(p[7]);
    cx(p[6], p[26]);
    cx(x[4], p[26]);
    qx(p[25]);
    cx(p[24], p[25]);
    cx(x[1], p[25]);
    cx(p[10], p[24]);
    cx(p[11], p[24]);
    qx(p[23]);
    cx(p[10], p[23]);
    cx(x[3], p[23]);
    cx(p[4], p[16]);
    cx(p[10], p[16]);
    cx(p[21], p[4]);
    cx(p[5], p[4]);
    cx(p[22], p[21]);
    cx(x[1], p[21]);
    cx(p[22], p[18]);
    cx(p[19], p[18]);
    cx(p[6], p[14]);
    cx(x[6], p[14]);
    cx(p[10], p[8]);
    cx(p[6], p[8]);
    cx(p[2], p[10]);
    cx(x[6], p[10]);
    qx(p[9]);
    cx(p[3], p[9]);
    cx(p[15], p[9]);
    cx(p[6], p[0]);
    cx(p[12], p[0]);
    cx(p[7], p[6]);
    cx(p[19], p[6]);
    cx(p[1], p[7]);
    cx(x[7], p[7]);
    cx(p[3], p[2]);
    cx(p[20], p[2]);
    cx(p[3], p[1]);
    cx(p[5], p[1]);
    cx(p[12], p[3]);
    cx(x[0], p[3]);
    cx(p[22], p[12]);
    cx(x[7], p[12]);
    cx(x[4], p[22]);
    cx(x[2], p[22]);
    cx(p[19], p[20]);
    cx(x[1], p[20]);
    cx(p[11], p[5]);
    cx(p[17], p[5]);
    cx(p[19], p[11]);
    cx(x[3], p[11]);
    cx(x[5], p[19]);
    cx(x[0], p[19]);
    cx(p[15], p[17]);
    cx(x[7], p[17]);
    cx(x[6], p[15]);
    cx(x[2], p[15]);
    qx(p[13]);
    cx(x[7], p[13]);

	uint8_t ans = 0;
	for (int i = 0; i < 8; i++) {
		ans = (ans << 1) | y[i];
	}
	// printf("%02X %02X\n", delta, ans);
	return ans;
}

void get_qunatum_sbox7(uint8_t sbox[256], uint8_t delta = 0) {
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
		for (int j = 0; j < 27; ++j) {
			if (p[j] != 0) {
				puts("can't recover auxiliary qubit p[27]");
				exit(-1);
			}
		}
		for (int j = 0; j < 9; ++j) {
			if (q[j] != 0) {
				puts("can't recover auxiliary qubit q[9]");
				exit(-1);
			}
		}
		for (int j = 0; j < 6; ++j) {
			if (r[j] != 0) {
				puts("can't recover auxiliary qubit r[6]");
				exit(-1);
			}
		}
		for (int j = 0; j < 3; ++j) {
			if (c[j] != 0) {
				puts("can't recover auxiliary qubit c[3]");
				exit(-1);
			}
		}
		for (int j = 0; j < 4; ++j) {
			if (z[j] != 0) {
				puts("can't recover auxiliary qubit z[4]");
				exit(-1);
			}
		}
		for (int j = 0; j < 5; ++j) {
			if (k[j] != 0) {
				puts("can't recover auxiliary qubit k[5]");
				exit(-1);
			}
		}
		for (int j = 0; j < 18; ++j) {
			if (u[j] != 0) {
				puts("can't recover auxiliary qubit u[18]");
				exit(-1);
			}
		}
		for (int j = 0; j < 30; ++j) {
			if (v[j] != 0) {
				puts("can't recover auxiliary qubit v[30]");
				exit(-1);
			}
		}
	}
}
}

#endif