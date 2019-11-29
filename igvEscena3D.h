#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include "igvMallaTriangulos.h"
#include "igvPersonaje.h"
#include "laberinto.h"

class igvEscena3D {
	protected:
		// Atributos
		bool modoCamara; // true = modo primera persona ; false = modo visi�n desde arriba
		bool bloquearRaton; // true = raton centrado, false = movimiento libre del rat�n
		

	public:
		// atributos p�blicos
		igvMallaTriangulos *malla; // malla de tri�ngulos asociada a la escena

		igvPersonaje personaje;

		// Constructores por defecto y destructor
		igvEscena3D();
		~igvEscena3D();

		// Laberinto
		laberinto lab;

		// Metodos est�ticos

		// M�todos
		// m�todo con las llamadas OpenGL para visualizar la escena
		void visualizar();
		bool getModoCamara() { return modoCamara; };
		void setModoCamara(bool valor) { modoCamara = valor; };
		bool getBloquearRaton() { return bloquearRaton; };
		void setBloquearRaton(bool valor) { bloquearRaton = valor; };
};

#endif
