#pragma once
#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include "igvTextura.h"
#include<iostream>

class laberinto
{
private:
	void pintarSuelo();

	void pintarParedes();

	void pintarMuro(float x, float y, float z);

	bool llave1, llave2;

	float seleccionado[3];

	igvTextura pared;
public:
	void mostrar();
	laberinto();
	~laberinto();
	bool getLlave1() { return llave1; };
	bool getLlave2() { return llave2; };
	void setLlave1(bool valor) { llave1 = valor; };
	void setLlave2(bool valor) { llave2 = valor; };

};

