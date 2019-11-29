#include <cstdlib>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "igvEscena3D.h"
#include "igvMaterial.h"
#include "igvTextura.h"

// Metodos constructores 

igvEscena3D::igvEscena3D () {
	modoCamara = true;
	bloquearRaton = true;
}

igvEscena3D::~igvEscena3D() {
}


// Metodos publicos 


void igvEscena3D::visualizar(void) {

	glPushMatrix(); // guarda la matriz de modelado

	lab.mostrar();

	glPopMatrix (); // restaura la matriz de modelado
}
