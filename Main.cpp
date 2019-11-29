#include <cstdlib>

#include "igvInterfaz.h"

// Objetos globales
// objeto que contiene la configuraci�n y la interacci�n con la ventana de visualizaci�n
igvInterfaz interfaz;

int main (int argc, char** argv) {
	// inicializa la ventana de visualizaci�n
	interfaz.configura_entorno(argc,argv,
		                         900,700, // tama�o de la ventana
														 300,120, // posicion de la ventana
														 "Inform�tica Gr�fica y Visualizaci�n. Proyecto final. Laberinto" // t�tulo de la ventana
														 );

	// establece las funciones callbacks para la gesti�n de los eventos
	interfaz.inicializa_callbacks();

	// inicia el bucle de visualizaci�n de OpenGL
	interfaz.inicia_bucle_visualizacion();

	return(0);
}