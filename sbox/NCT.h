#ifndef NCT_H
#define NCT_H

typedef bool qubit;

void qx(qubit &x) {
	x ^= 1;
}

void cx(qubit x, qubit &y) {
    y ^= x;
}

void ccx(qubit x, qubit y, qubit &z) {
    z ^= (x & y);
}

#endif