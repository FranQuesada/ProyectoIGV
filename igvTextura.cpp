#include "igvTextura.h"
#include <iostream>
using namespace std;

// Metodos constructores y destructor
igvTextura::igvTextura() {
	
}

igvTextura::igvTextura(const char *fichero) {
  GLubyte *imagen;

	imagen = loadBMPRaw(fichero, alto, ancho);
 
	cout << "Entra en el constructor" << endl;
	/* Apartado G: A�adir aqu� el c�digo para cargar como textura OpenGL el BMP imagen */
 
	// - Generar el identificador de textura y asignarlo al atributo idTextura
	glGenTextures(1, &idTextura);
	// - Enlazar el identificador creado a GL_TEXTURE_2D
	glBindTexture(GL_TEXTURE_2D, idTextura);
    // - Especificar la textura, asign�dole como textura el array imagen
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ancho, alto, 0, GL_RGB, GL_UNSIGNED_BYTE, imagen);
    // - Modo de aplicaci�n de la textura
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	// - Par�metros de la textura: repetici�n y filtros
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	delete imagen;
}

void igvTextura::aplicar(void) {
  glBindTexture(GL_TEXTURE_2D, idTextura);
}

igvTextura::~igvTextura() {
  glDeleteTextures(1, &idTextura); 
}
