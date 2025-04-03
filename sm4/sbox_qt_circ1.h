#ifndef SBOX_QUANTUM_CIRC1_H
#define SBOX_QUANTUM_CIRC1_H

#include <iostream>
#include <algorithm>
#include <cstdint>
#include "NCT.h"

namespace sbox_circ1 {
void qt1(qubit *x) {
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

void qt1_inv(qubit *x) {
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

void qt2(qubit *a, qubit *b, qubit *d) {
	cx(a[3], a[1]);
    cx(b[3], b[1]);
    cx(a[2], a[0]);
    cx(b[2], b[0]);
    cx(a[3], a[2]);
    cx(b[3], b[2]);
    cx(a[1], a[0]);
    cx(b[1], b[0]);
    ccx(a[0], b[0], d[0]);
    ccx(a[1], b[1], d[1]);
    ccx(a[2], b[2], d[2]);
    ccx(a[3], b[3], d[3]);
    cx(b[1], b[0]);
    cx(a[1], a[0]);
    cx(a[3], a[2]);
    cx(b[3], b[2]);
    cx(a[2], a[0]);
    cx(b[2], b[0]);
    cx(a[3], a[1]);
    cx(b[3], b[1]);
    cx(d[3], d[2]);
    ccx(a[2], b[2], d[3]);
    cx(d[3], d[1]);
    cx(d[3], d[2]);
    cx(d[1], d[0]);
    cx(d[2], d[0]);
    cx(a[0], a[2]);
    cx(b[0], b[2]);
    cx(a[1], a[0]);
    cx(b[1], b[0]);
    ccx(a[2], b[2], d[1]);
    ccx(a[0], b[0], d[3]);
    cx(a[1], a[0]);
    cx(b[1], b[0]);
    cx(a[0], a[2]);
    cx(b[0], b[2]);
    cx(d[3], d[2]);
    ccx(a[0], b[0], d[2]);
    ccx(a[1], b[1], d[3]);
}

void qt2_inv(qubit *a, qubit *b, qubit *d) {
	ccx(a[1], b[1], d[3]);
    ccx(a[0], b[0], d[2]);
    cx(d[3], d[2]);
    cx(b[0], b[2]);
    cx(a[0], a[2]);
    cx(b[1], b[0]);
    cx(a[1], a[0]);
    ccx(a[0], b[0], d[3]);
    ccx(a[2], b[2], d[1]);
    cx(b[1], b[0]);
    cx(a[1], a[0]);
    cx(b[0], b[2]);
    cx(a[0], a[2]);
    cx(d[2], d[0]);
    cx(d[1], d[0]);
    cx(d[3], d[2]);
    cx(d[3], d[1]);
    ccx(a[2], b[2], d[3]);
    cx(d[3], d[2]);
    cx(b[3], b[1]);
    cx(a[3], a[1]);
    cx(b[2], b[0]);
    cx(a[2], a[0]);
    cx(b[3], b[2]);
    cx(a[3], a[2]);
    cx(a[1], a[0]);
    cx(b[1], b[0]);
    ccx(a[3], b[3], d[3]);
    ccx(a[2], b[2], d[2]);
    ccx(a[1], b[1], d[1]);
    ccx(a[0], b[0], d[0]);
    cx(b[1], b[0]);
    cx(a[1], a[0]);
    cx(b[3], b[2]);
    cx(a[3], a[2]);
    cx(b[2], b[0]);
    cx(a[2], a[0]);
    cx(b[3], b[1]);
    cx(a[3], a[1]);
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

void qt6(qubit *a, qubit &g) {
	std::swap(a[1], a[2]);
    std::swap(a[2], a[3]);
    ccx(a[3], a[1], a[2]);
    ccx(a[2], a[0], a[3]);
    cx(a[1], a[2]);
    cx(a[3], a[0]);
    cx(a[2], a[3]);
    ccx(a[0], a[1], g);
    ccx(a[3], g, a[2]);
    ccx(a[0], a[1], g);
    ccx(a[3], g, a[2]);
    ccx(a[3], a[2], a[1]);
    ccx(a[1], a[0], a[3]);
    cx(a[2], a[1]);
    cx(a[3], a[2]);
    cx(a[0], a[1]);
    std::swap(a[1], a[2]);
}

void qt9(qubit *a, qubit *b, qubit *d) {
	cx(d[3], d[2]);
    cx(d[2], d[0]);
    cx(d[1], d[0]);
    cx(d[3], d[1]);
	cx(a[3], a[1]);
    cx(b[3], b[1]);
    cx(a[2], a[0]);
    cx(b[2], b[0]);
    cx(a[3], a[2]);
    cx(b[3], b[2]);
    cx(a[1], a[0]);
    cx(b[1], b[0]);
    ccx(a[0], b[0], d[0]);
    ccx(a[1], b[1], d[1]);
    ccx(a[2], b[2], d[2]);
    ccx(a[3], b[3], d[3]);
    cx(b[1], b[0]);
    cx(a[1], a[0]);
    cx(a[3], a[2]);
    cx(b[3], b[2]);
    cx(a[2], a[0]);
    cx(b[2], b[0]);
    cx(a[3], a[1]);
    cx(b[3], b[1]);
    cx(d[3], d[2]);
    ccx(a[2], b[2], d[3]);
    cx(d[3], d[1]);
    cx(d[3], d[2]);
    cx(d[1], d[0]);
    cx(d[2], d[0]);
    cx(a[0], a[2]);
    cx(b[0], b[2]);
    cx(a[1], a[0]);
    cx(b[1], b[0]);
    ccx(a[2], b[2], d[1]);
    ccx(a[0], b[0], d[3]);
    cx(a[1], a[0]);
    cx(b[1], b[0]);
    cx(a[0], a[2]);
    cx(b[0], b[2]);
    cx(d[3], d[2]);
    ccx(a[0], b[0], d[2]);
    ccx(a[1], b[1], d[3]);
}

void qt11(qubit *y) {
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

void qt12(qubit *y) {
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

void S(qubit *x, qubit *y, qubit *aux) {
	qubit *a1 = x;
	qubit *a0 = x + 4;
	qubit *d1 = y;
	qubit *d0 = y + 4;
	// begin
	qt1(x);
	qt12(y);

	cx(a0[0], a1[0]);
	cx(a0[1], a1[1]);
	cx(a0[2], a1[2]);
	cx(a0[3], a1[3]);

	qt2(a1, a0, aux);

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
	qt6(aux, x[7]);
	qt9(a0, aux, d1);
	qt9(a1, aux, d0);
	qt6(aux, x[7]);
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

	qt2_inv(a1, a0, aux);
	
	cx(a0[0], a1[0]);
	cx(a0[1], a1[1]);
	cx(a0[2], a1[2]);
	cx(a0[3], a1[3]);

	qt1_inv(x);
	qt11(y);
}
}

#endif