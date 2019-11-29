#pragma once
#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include <string>
#include <iostream>
#include "igvCamara.h"
#include "igvPunto3D.h"

/*
Clase que encapsula el comportamiento del personaje que se moverá dentro del laberinto
*/
class igvPersonaje
{
protected:
	igvPunto3D posicion;
	igvPunto3D apunta;
	float velocidad;
	bool transpasar;

	// ángulo de rotación de la dirección de la cámara 
	float angulo;
public:
	igvPersonaje();
	~igvPersonaje();
	// metodos para modificar la posicion del personaje 
	double getX() { return posicion[X]; };
	double getY() { return posicion[Y]; };
	double getZ() { return posicion[Z]; };
	void modificarPosicionX(double valor) { posicion[X] += valor; };
	void modificarPosicionY(double valor) { posicion[Y] += valor; };
	void modificarPosicionZ(double valor) { posicion[Z] += valor; };
	// metodos para modificar la direccion hacia la que mira el personaje
	double getXApunta() { return apunta[X]; };
	double getYApunta() { return apunta[Y]; };
	double getZApunta() { return apunta[Z]; };
	void modificarPosicionXApunta(double valor) { apunta[X] = valor; };
	void modificarPosicionYApunta(double valor) { apunta[Y] += valor; };
	void modificarPosicionZApunta(double valor) { apunta[Z] = valor; };
	void setPosicionXApunta(double valor) { apunta[X] = valor; };
	void setPosicionYApunta(double valor) { apunta[Y] = valor; };
	void setPosicionZApunta(double valor) { apunta[Z] = valor; };
	void modificarAngulo(float valor) { angulo += valor; };
	float getAngulo() { return angulo; };
	float getVelocidad() { return velocidad; };
	bool comprobarMovimiento();
	bool comprobarVictoria();
	bool getTranspasar() { return transpasar; };
	void setTranspasar(bool valor) { transpasar = valor; };
};

