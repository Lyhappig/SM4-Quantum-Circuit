#ifndef SM4_QUANTUM_CIRC1_H
#define SM4_QUANTUM_CIRC1_H

#include "sbox_qt_circ1.h"

#define SM4_SIZE 128
#define ROUND_SIZE 32
#define AUX_NUM 4

namespace sm4_circ1 {
static const uint32_t FK[4] = {0xa3b1bac6, 0x56aa3350, 0x677d9197, 0xb27022dc};

static const uint32_t CK[32] = {
	0x00070E15, 0x1C232A31, 0x383F464D, 0x545B6269,
	0x70777E85, 0x8C939AA1, 0xA8AFB6BD, 0xC4CBD2D9,
	0xE0E7EEF5, 0xFC030A11, 0x181F262D, 0x343B4249,
	0x50575E65, 0x6C737A81, 0x888F969D, 0xA4ABB2B9,
	0xC0C7CED5, 0xDCE3EAF1, 0xF8FF060D, 0x141B2229,
	0x30373E45, 0x4C535A61, 0x686F767D, 0x848B9299,
	0xA0A7AEB5, 0xBCC3CAD1, 0xD8DFE6ED, 0xF4FB0209,
	0x10171E25, 0x2C333A41, 0x484F565D, 0x646B7279
};

static qubit aux[AUX_NUM];

void key_rotl_swap(qubit *x) {
	qubit y[32];
	int pos[32] = {
		0, 1, 28, 16, 4, 5, 6, 7, 8, 9, 11, 2, 3, 13, 14, 15,
		25, 17, 18, 10, 20, 21, 19, 23, 24, 12, 26, 27, 31, 29, 30, 22
	};
	for (int i = 0; i < 32; i++) {
		y[i] = x[pos[i]];
	}
	memcpy(x, y, 32 * sizeof(qubit));
}

void key_rotl_inv_swap(qubit *x) {
	qubit y[32];
	int pos[32] = {
		0, 1, 11, 12, 4, 5, 6, 7, 8, 9, 19, 10, 25, 13, 14, 15,
		3, 17, 18, 22, 20, 21, 31, 23, 24, 16, 26, 27, 2, 29, 30, 28
	};
	for (int i = 0; i < 32; i++) {
		y[i] = x[pos[i]];
	}
	memcpy(x, y, 32 * sizeof(qubit));
}

void enc_rotl_swap(qubit *x) {
	qubit y[32];
	int pos[32] = {
		10, 11, 20, 21, 30, 31, 24, 25, 2, 3, 12, 13, 14, 15, 8, 9,
		18, 19, 4, 5, 22, 23, 0, 1, 26, 27, 28, 29, 6, 7, 16, 17
	};
	for (int i = 0; i < 32; i++) {
		y[i] = x[pos[i]];
	}
	memcpy(x, y, 32 * sizeof(qubit));
}

void enc_rotl_inv_swap(qubit *x) {
	qubit y[32];
	int pos[32] = {
		22, 23, 8, 9, 18, 19, 28, 29, 14, 15, 0, 1, 10, 11, 12, 13,
		30, 31, 16, 17, 2, 3, 20, 21, 6, 7, 24, 25, 26, 27, 4, 5
	};
	for (int i = 0; i < 32; i++) {
		y[i] = x[pos[i]];
	}
	memcpy(x, y, 32 * sizeof(qubit));
}

void key_L(qubit *x) {
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

void key_L_inv(qubit *x) {
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

void enc_L(qubit *x) {
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

	enc_rotl_swap(x);
}

void enc_L_inv(qubit *x) {
	enc_rotl_inv_swap(x);

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

void sm4_key_round(qubit *K0, qubit *K1, qubit *K2, qubit *K3, uint32_t CKi) {
	qubit *a0 = K1;
	qubit *a1 = K1 + 8;
	qubit *a2 = K1 + 16;
	qubit *a3 = K1 + 24;
	qubit *b0 = K0;
	qubit *b1 = K0 + 8;
	qubit *b2 = K0 + 16;
	qubit *b3 = K0 + 24;

	qx32(CKi, K1);
	ccx32(K2, K1);
	ccx32(K3, K1);
	key_L_inv(K0);
	sbox_circ1::S(a0, b0, aux);
	sbox_circ1::S(a1, b1, aux);
	sbox_circ1::S(a2, b2, aux);
	sbox_circ1::S(a3, b3, aux);
	key_L(K0);
	ccx32(K3, K1);
	ccx32(K2, K1);
	qx32(CKi, K1);

	qswap(K0, K1, ROUND_SIZE);
	qswap(K1, K2, ROUND_SIZE);
	qswap(K2, K3, ROUND_SIZE);
}

void sm4_key_schedule(qubit *mk, qubit (*key)[32]) {
	qubit *a = mk;
	qubit *b = mk + 32;
	qubit *c = mk + 64;
	qubit *d = mk + 96;

	qx32(FK[0], a);
	qx32(FK[1], b);
	qx32(FK[2], c);
	qx32(FK[3], d);
	for (int i = 0; i < 32; ++i) {
		sm4_key_round(a, b, c, d, CK[i]);
		// rk[i] = K4
		for (int j = 0; j < 32; j++) {
			key[i][j] = d[j];
		}
	}
}

void sm4_enc_round(qubit *X0, qubit *X1, qubit *X2, qubit *X3, qubit *rk) {
	qubit *a0 = X1;
	qubit *a1 = X1 + 8;
	qubit *a2 = X1 + 16;
	qubit *a3 = X1 + 24;
	qubit *b0 = X0;
	qubit *b1 = X0 + 8;
	qubit *b2 = X0 + 16;
	qubit *b3 = X0 + 24;

	ccx32(rk, X1);
	ccx32(X2, X1);
	ccx32(X3, X1);
	enc_L_inv(X0);
	sbox_circ1::S(a0, b0, aux);
	sbox_circ1::S(a1, b1, aux);
	sbox_circ1::S(a2, b2, aux);
	sbox_circ1::S(a3, b3, aux);
	enc_L(X0);
	ccx32(X3, X1);
	ccx32(X2, X1);
	ccx32(rk, X1);

	qswap(X0, X1, ROUND_SIZE);
	qswap(X1, X2, ROUND_SIZE);
	qswap(X2, X3, ROUND_SIZE);
}

void sm4_encrypt(qubit *x, qubit (*key)[32]) {
	qubit *a = x;
	qubit *b = x + 32;
	qubit *c = x + 64;
	qubit *d = x + 96;
	for (int i = 0; i < 32; ++i) {
		sm4_enc_round(a, b, c, d, key[i]);
	}
	qswap(a, d, ROUND_SIZE);
	qswap(b, c, ROUND_SIZE);
}

void sm4_union_round(qubit *X0, qubit *X1, qubit *X2, qubit *X3, qubit *K0, qubit *K1, qubit *K2, qubit *K3, uint32_t CKi) {
	qubit *a0 = X1;
	qubit *a1 = X1 + 8;
	qubit *a2 = X1 + 16;
	qubit *a3 = X1 + 24;
	qubit *b0 = X0;
	qubit *b1 = X0 + 8;
	qubit *b2 = X0 + 16;
	qubit *b3 = X0 + 24;
	qubit *c0 = K1;
	qubit *c1 = K1 + 8;
	qubit *c2 = K1 + 16;
	qubit *c3 = K1 + 24;
	qubit *d0 = K0;
	qubit *d1 = K0 + 8;
	qubit *d2 = K0 + 16;
	qubit *d3 = K0 + 24;

	
	ccx32(K3, X1);
	ccx32(X2, X1);
	ccx32(X3, X1);
	enc_L_inv(X0);

	qx32(CKi, K1);
	ccx32(K2, K1);
	ccx32(K3, K1);
	key_L_inv(K0);

	{
		sbox_circ1::S(a0, b0, aux);
		sbox_circ1::S(a1, b1, aux);
		sbox_circ1::S(a2, b2, aux);
		sbox_circ1::S(a3, b3, aux);
		sbox_circ1::S(c0, d0, aux);
		sbox_circ1::S(c1, d1, aux);
		sbox_circ1::S(c2, d2, aux);
		sbox_circ1::S(c3, d3, aux);
	}

	key_L(K0);
	ccx32(K3, K1);
	ccx32(K2, K1);
	qx32(CKi, K1);

	enc_L(X0);
	ccx32(X3, X1);
	ccx32(X2, X1);
	ccx32(K3, X1);

	qswap(X0, X1, ROUND_SIZE);
	qswap(X1, X2, ROUND_SIZE);
	qswap(X2, X3, ROUND_SIZE);
	qswap(K0, K1, ROUND_SIZE);
	qswap(K1, K2, ROUND_SIZE);
	qswap(K2, K3, ROUND_SIZE);
}

void sm4_subroutine_quantum(qubit *x, qubit *mk) {
	qubit *X0 = x;
	qubit *X1 = x + 32;
	qubit *X2 = x + 64;
	qubit *X3 = x + 96;
	qubit *K0 = mk;
	qubit *K1 = mk + 32;
	qubit *K2 = mk + 64;
	qubit *K3 = mk + 96;
	qx32(FK[0], K0);
	qx32(FK[1], K1);
	qx32(FK[2], K2);
	qx32(FK[3], K3);
	sm4_key_round(K0, K1, K2, K3, CK[0]);
	for (int i = 1; i < 32; ++i) {
		sm4_union_round(X0, X1, X2, X3, K0, K1, K2, K3, CK[i]);
	}
	sm4_enc_round(X0, X1, X2, X3, K3);
	qswap(X0, X3, ROUND_SIZE);
	qswap(X1, X2, ROUND_SIZE);
}
}
#endif