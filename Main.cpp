#include <cstdlib>

#include "igvInterfaz.h"

// Objetos globales
// objeto que contiene la configuración y la interacción con la ventana de visualización
igvInterfaz interfaz;

int main (int argc, char** argv) {
	// inicializa la ventana de visualización
	interfaz.configura_entorno(argc,argv,
		                         900,700, // tamaño de la ventana
														 300,120, // posicion de la ventana
														 "Informática Gráfica y Visualización. Proyecto final. Laberinto" // título de la ventana
														 );

	// establece las funciones callbacks para la gestión de los eventos
	interfaz.inicializa_callbacks();

	// inicia el bucle de visualización de OpenGL
	interfaz.inicia_bucle_visualizacion();

	return(0);
}
