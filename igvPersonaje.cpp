#include "igvPersonaje.h"



igvPersonaje::igvPersonaje()
{
	posicion[X] = 49.0;
	posicion[Y] = 1.0;
	posicion[Z] = 49.0;

	apunta[X] = 30.0;
	apunta[Y] = 1.0;
	apunta[Z] = 43.0;

	angulo = 0.0;

	velocidad = 0.5;

	transpasar = false;
}


igvPersonaje::~igvPersonaje()
{
}

bool igvPersonaje::comprobarMovimiento() {
	bool legal = true;
	if (posicion[X] > 49.9 ) {
		legal = false;
		posicion[X] = 49.5;
	}
	if (posicion[X] < -49.9) {
		legal = false;
		posicion[X] = -49.5;
	}
	if (posicion[Z] > 49.9) {
		legal = false;
		posicion[Z] = 49.5;
	}
	if (posicion[Z] < -49.9) {
		legal = false;
		posicion[Z] = -49.5;
	}

	if (!transpasar) {
		// 1
		if (posicion[Z] < 41.5 && posicion[Z] > 39 && (posicion[X] > 20 || posicion[X] < 10) && (posicion[X] > -21)) {
			legal = false;
			posicion[Z] = 41.5;
		}
		// 2
		if (posicion[X] < -29 && posicion[X] > -31 && (posicion[Z] > 0)) {
			legal = false;
			posicion[X] = -28.5;
		}
		// 3
		if (posicion[X] > -21.5 && posicion[X] < -19.5 && (posicion[Z] < 41.5 && posicion[Z] > -7.5)) {
			legal = false;
			posicion[X] = -22;
		}
		// 4
		if (posicion[Z] > -0.5 && posicion[Z] < 1.5 && (posicion[X] < -29)) {
			legal = false;
			posicion[Z] = -1;
		}
		// 5
		if (posicion[Z] < -7.5 && posicion[Z] > -8.5 && (posicion[X] < -21)) {
			legal = false;
			posicion[Z] = -7;
		}
		// 6
		if (posicion[X] < 11 && posicion[X] > 9 && (posicion[Z] < 41.5 && posicion[Z] > 10)) {
			legal = false;
			posicion[X] = 11;
		}
		// 7
		if (posicion[X] < 11 && posicion[X] > 9 && (posicion[Z] > -19 && posicion[Z] < 2)) {
			legal = false;
			posicion[X] = 11;
		}
		// 8
		if (posicion[X] > 19 && posicion[X] < 21 && (posicion[Z] < 41.5 && posicion[Z] > 10)) {
			legal = false;
			posicion[X] = 19;
		}
		// 9
		if (posicion[X] > 19 && posicion[X] < 21 && (posicion[Z] > -19 && posicion[Z] < 2)) {
			legal = false;
			posicion[X] = 19;
		}
		// 10
		if (posicion[Z] < 2 && posicion[Z] > 0 && (posicion[X] < 11 && posicion[X] > -7)) {
			legal = false;
			posicion[Z] = 2;
		}
		// 11
		if (posicion[Z] > 10 && posicion[Z] < 12 && (posicion[X] < 11 && posicion[X] > -1.5)) {
			legal = false;
			posicion[Z] = 10;
		}
		// 12
		if (posicion[X] > -1.5 && posicion[X] < 0 && (posicion[Z] > 10 && posicion[Z] < 30)) {
			legal = false;
			posicion[X] = -2;
		}
		// 13
		if (posicion[X] < -7 && posicion[X] > -9 && (posicion[Z] > 2 && posicion[Z] < 30)) {
			legal = false;
			posicion[X] = -6.5;
		}
		// 14
		if (posicion[Z] > 30 && posicion[Z] < 32 && (posicion[X] < -1.5 && posicion[X] > -7)) {
			legal = false;
			posicion[Z] = 30;
		}
		// 15
		if (posicion[Z] > 10 && posicion[Z] < 12 && (posicion[X] < 31.5 && posicion[X] > 20)) {
			legal = false;
			posicion[Z] = 10;
		}
		// 16
		if (posicion[X] < 32 && posicion[X] > 30 && (posicion[Z] > 10 && posicion[Z] < 31)) {
			legal = false;
			posicion[X] = 32.5;
		}
		// 17
		if (posicion[Z] > 30 && posicion[Z] < 32 && (posicion[X] > 31 && posicion[X] < 40)) {
			legal = false;
			posicion[Z] = 30;
		}
		// 18
		if (posicion[X] > 37.5 && posicion[X] < 39 && (posicion[Z] > 2 && posicion[Z] < 31)) {
			legal = false;
			posicion[X] = 37;
		}
		// 19
		if (posicion[Z] > -20 && posicion[Z] < -17 && (posicion[X] < 11 && posicion[X] > -29)) {
			legal = false;
			posicion[Z] = -20;
		}
		// 20
		if (posicion[Z] < -28 && posicion[Z] > -30 && (posicion[X] < 29 && posicion[X] > -27)) {
			legal = false;
			posicion[Z] = -28;
		}
		// 21
		if (posicion[X] < -27 && posicion[X] > -29 && (posicion[Z] > -29 && posicion[Z] < -19)) {
			legal = false;
			posicion[X] = -26.5;
		}
		// 22
		if (posicion[X] < 22 && posicion[X] > 21 && (posicion[Z] > -19 && posicion[Z] < 2)) {
			legal = false;
			posicion[X] = 22;
		}
		// 23
		if (posicion[X] > 29 && posicion[X] < 30 && (posicion[Z] > -27 && posicion[Z] < -7)) {
			legal = false;
			posicion[X] = 29;
		}
		// 24
		if (posicion[Z] < -7 && posicion[Z] > -9 && (posicion[X] > 29)) {
			legal = false;
			posicion[Z] = -7;
		}
		// 25 
		if (posicion[Z] > -0.5 && posicion[Z] < 0 && (posicion[X] > 20)) {
			legal = false;
			posicion[Z] = -0.5;
		}
		// 26
		if (posicion[Z] < 2.5 && posicion[Z] > 0 && (posicion[X] > 20 && posicion[Z] < 37.5)) {
			legal = false;
			posicion[Z] = 2.5;
		}


	}
	
	return legal;
}

bool igvPersonaje::comprobarVictoria() {
	bool legal = true;
	if (posicion[X] < -29 && posicion[X] > -31 && (posicion[Z] > -7.5)) {
		legal = false;
		posicion[X] = -28.5;
	}
	return legal;
}