#ifndef NCT_H
#define NCT_H

#include <algorithm>
#include <cstdint>
typedef bool qubit;

void qx(qubit &x) {
	x ^= 1;
}

void qx32(uint32_t val, qubit *X) {
    for (int i = 0; i < 32; i++) {
        if ((val >> (31 - i)) & 1) {
            X[i] ^= 1;
        }
    }
}

void cx(qubit x, qubit &y) {
    y ^= x;
}

void ccx(qubit x, qubit y, qubit &z) {
    z ^= (x & y);
}

void ccx32(qubit *C, qubit *X) {
	for (int i = 0; i < 32; i++) {
		X[i] = X[i] ^ C[i];
	}
}

void qswap(qubit *x, qubit *y, size_t n) {
    for (int i = 0; i < n; i++) {
        std::swap(x[i], y[i]);
    }
}

#endif