#ifndef CLIFFORD_T_H
#define CLIFFORD_T_H

#include <assert.h>
#include "NCT.h"
typedef bool qubit;

void QAND(qubit &x, qubit &y, qubit &z1, qubit z2) {
	assert(z1 == 0);
	assert(z2 == 0);
	z1 = x & y;
}

void QAND_inv(qubit &x, qubit &y, qubit &z) {
	assert(z == (x & y));
	z = 0;
}

#endif