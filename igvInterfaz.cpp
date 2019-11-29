#include <cstdlib>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "igvInterfaz.h"

extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
                             // ellos a las variables de la clase

// Metodos constructores -----------------------------------

igvInterfaz::igvInterfaz () {
	ratonX = 0.0;
	ratonY = 0.0;
	ganar = false;
}

igvInterfaz::~igvInterfaz () {}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {
	// crear cámaras
	// Al iniciarse la cámara es en primera persona
	if (interfaz.escena.getModoCamara() == true) {
		interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(interfaz.escena.personaje.getX(), 1.0, interfaz.escena.personaje.getZ()),
			igvPunto3D(interfaz.escena.personaje.getXApunta() + interfaz.escena.personaje.getX(),
				1.0,
				interfaz.escena.personaje.getZApunta() + interfaz.escena.personaje.getZ()),
			igvPunto3D(0, 1.0, 0), 45, 1.333, 0.1, 100);
	}
}

void igvInterfaz::configura_entorno(int argc, char** argv,
			                              int _ancho_ventana, int _alto_ventana,
			                              int _pos_X, int _pos_Y,
													          string _titulo){
	// inicialización de las variables de la interfaz																	
	ancho_ventana = _ancho_ventana;
	alto_ventana = _alto_ventana;

	// inicialización de la ventana de visualización
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(_ancho_ventana,_alto_ventana);
  glutInitWindowPosition(_pos_X,_pos_Y);
	glutCreateWindow(_titulo.c_str());

	glEnable(GL_DEPTH_TEST); // activa el ocultamiento de superficies por z-buffer
  glClearColor(1.0,1.0,1.0,0.0); // establece el color de fondo de la ventana

	glEnable(GL_LIGHTING); // activa la iluminacion de la escena
  glEnable(GL_NORMALIZE); // normaliza los vectores normales para calculo iluminacion

	glEnable(GL_TEXTURE_2D); // activa el uso de texturas

	crear_mundo(); // crea el mundo a visualizar en la ventana
}

void igvInterfaz::inicia_bucle_visualizacion() {
	glutMainLoop(); // inicia el bucle de visualizacion de OpenGL
}

void igvInterfaz::set_glutSpecialFunc(int key, int x, int y) {
	if (interfaz.escena.getModoCamara() == true) {
		switch (key) {
		case GLUT_KEY_UP:
			if (interfaz.escena.personaje.comprobarMovimiento()) {
				if (!interfaz.ganar) {
					if (interfaz.escena.personaje.comprobarVictoria()) {
						interfaz.escena.personaje.modificarPosicionX(interfaz.escena.personaje.getXApunta()*interfaz.escena.personaje.getVelocidad());
						interfaz.escena.personaje.modificarPosicionZ(interfaz.escena.personaje.getZApunta()*interfaz.escena.personaje.getVelocidad());
					}
				}
				else {
					interfaz.escena.personaje.modificarPosicionX(interfaz.escena.personaje.getXApunta()*interfaz.escena.personaje.getVelocidad());
					interfaz.escena.personaje.modificarPosicionZ(interfaz.escena.personaje.getZApunta()*interfaz.escena.personaje.getVelocidad());
					if (interfaz.escena.personaje.getX() < -29 && interfaz.escena.personaje.getX() > -31 && (interfaz.escena.personaje.getZ() > -7.5)) {
						cout << "¡Enhorabuena!" << endl;
						exit(1);
					}
				}
				
			}
			cout << "Z :" <<  interfaz.escena.personaje.getZ() << endl;
			cout << "X :" << interfaz.escena.personaje.getX() << endl;
			cout << "--------------------------------------------------------------------" << endl;
			interfaz.comprobar();
			
			break;
		case GLUT_KEY_DOWN:
			if (interfaz.escena.personaje.comprobarMovimiento()) {
				if (!interfaz.ganar) {
					if (interfaz.escena.personaje.comprobarVictoria()) {
						interfaz.escena.personaje.modificarPosicionX(-interfaz.escena.personaje.getXApunta()*interfaz.escena.personaje.getVelocidad());
						interfaz.escena.personaje.modificarPosicionZ(-interfaz.escena.personaje.getZApunta()*interfaz.escena.personaje.getVelocidad());
					}
				}
				else {
					interfaz.escena.personaje.modificarPosicionX(-interfaz.escena.personaje.getXApunta()*interfaz.escena.personaje.getVelocidad());
					interfaz.escena.personaje.modificarPosicionZ(-interfaz.escena.personaje.getZApunta()*interfaz.escena.personaje.getVelocidad());
					if (interfaz.escena.personaje.getX() < -29 && interfaz.escena.personaje.getX() > -31 && (interfaz.escena.personaje.getZ() > -7.5)) {
						cout << "¡Enhorabuena!" << endl;
						exit(1);
					}
				}

			}
			cout << "Z :" << interfaz.escena.personaje.getZ() << endl;
			cout << "X :" << interfaz.escena.personaje.getX() << endl;
			cout << "--------------------------------------------------------------------" << endl;
			interfaz.comprobar();
				
			break;
		}
	}
	interfaz.crear_mundo();
	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutKeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
	case 'v':
		// Cámara cenital
		if (interfaz.escena.getModoCamara() == true) {
			interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(0.1, 125.0, 0.0),
				igvPunto3D(0.0, -1.0, 0.0), igvPunto3D(0, 1.0, 0), 45, 1.333, 0.1, 130);
			interfaz.escena.setModoCamara(false);
		}
		else {
			// Cámara en primera persona
			interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(interfaz.escena.personaje.getX(), 1.0, interfaz.escena.personaje.getZ()),
				igvPunto3D(interfaz.escena.personaje.getXApunta() + interfaz.escena.personaje.getX(),
					1.0,
					interfaz.escena.personaje.getZApunta() + interfaz.escena.personaje.getZ()),
				igvPunto3D(0, 1.0, 0), 45, 1.333, 0.1, 100);
			interfaz.escena.setModoCamara(true);
			interfaz.crear_mundo();
		}
		break;
    case 27: // tecla de escape para SALIR
      exit(1);
    break;
	/*
	 * Tecla para intercalar entre captar el movimiento del ratón y no hacerlo
	 */
	case 'c':
		if (interfaz.escena.getBloquearRaton())
			interfaz.escena.setBloquearRaton(false);
		else
			interfaz.escena.setBloquearRaton(true);
		break;
	case't':
		if (interfaz.escena.personaje.getTranspasar())
			interfaz.escena.personaje.setTranspasar(false);
		else
			interfaz.escena.personaje.setTranspasar(true);
		break;
	}
	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutReshapeFunc(int w, int h) {
  // dimensiona el viewport al nuevo ancho y alto de la ventana
  // guardamos valores nuevos de la ventana de visualizacion
  interfaz.set_ancho_ventana(w);
  interfaz.set_alto_ventana(h);

	// establece los parámetros de la cámara y de la proyección
	interfaz.camara.aplicar();
}

void igvInterfaz::set_glutDisplayFunc() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer

	// se establece el viewport
	glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());

	// establece los parámetros de la cámara y de la proyección
	interfaz.camara.aplicar();

	//visualiza la escena
	interfaz.escena.visualizar();

	// refresca la ventana
	glutSwapBuffers(); // se utiliza, en vez de glFlush(), para evitar el parpadeo
}

/*
Función para detectar el movimiento que hace el ratón y calcular la posición a la que se mira
*/
void igvInterfaz::set_glutPassiveMotionFunc(int x, int y) {
	cout << "X: " << x << "     Y: " << y << endl;
	cout << "X RATON: " << interfaz.ratonX << "          Y RATON: " << interfaz.ratonY << endl;
	if ((interfaz.ratonX - x) > 0 && interfaz.escena.getBloquearRaton()) {
		cout << "MOVIMIENTO HACIA LA IZQUIERDA" << endl;
		interfaz.escena.personaje.modificarAngulo(-0.05);
		interfaz.escena.personaje.modificarPosicionXApunta(sin(interfaz.escena.personaje.getAngulo()));
		interfaz.escena.personaje.modificarPosicionZApunta(-cos(interfaz.escena.personaje.getAngulo()));
		cout << "Z :" << interfaz.escena.personaje.getZ() << endl;
		cout << "X :" << interfaz.escena.personaje.getX() << endl;
		cout << "--------------------------------------------------------------------" << endl;
	}
	if ((interfaz.ratonX - x) < 0 && interfaz.escena.getBloquearRaton()) {
		cout << "MOVIMIENTO HACIA LA DERECHA" << endl;
		interfaz.escena.personaje.modificarAngulo(0.05);
		interfaz.escena.personaje.modificarPosicionXApunta(sin(interfaz.escena.personaje.getAngulo()));
		interfaz.escena.personaje.modificarPosicionZApunta(-cos(interfaz.escena.personaje.getAngulo()));
		cout << "Z :" << interfaz.escena.personaje.getZ() << endl;
		cout << "X :" << interfaz.escena.personaje.getX() << endl;
		cout << "--------------------------------------------------------------------" << endl;
	}
	cout << "-----------------------------------------------------------------" << endl;
	interfaz.ratonX = x;
	interfaz.ratonY = y;
	cout << "Angulo: " << interfaz.escena.personaje.getAngulo() << endl;


	interfaz.crear_mundo();
	glutPostRedisplay();
}

void igvInterfaz::comprobar() {
	if (interfaz.escena.lab.getLlave1() && interfaz.escena.lab.getLlave1())
		ganar = true;
}

// Funcion para leer el color del pixel sobre el que se hace click y saber si se selecciona la caja adecuada
void igvInterfaz::set_glutMouseFunc(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		unsigned char pixel[4];
		// Hay que invertir el eje y ya que la orden ReadPixels devuelve el pixel invertido 
		glReadPixels(x, interfaz.alto_ventana-y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
		cout << "R: " << (int)pixel[0] << endl;
		cout << "G: " << (int)pixel[1] << endl;
		cout << "B: " << (int)pixel[2] << endl;
		cout << endl;
		if (pixel[1] == 255 && pixel[0] == 0 && pixel[2] == 0)
			interfaz.escena.lab.setLlave1(true);
		if (pixel[1] == 252 && pixel[0]==0 && pixel[2] == 0)
			interfaz.escena.lab.setLlave2(true);

	}
}

void igvInterfaz::inicializa_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);
	glutSpecialFunc(set_glutSpecialFunc);
	glutPassiveMotionFunc(set_glutPassiveMotionFunc);
	glutMouseFunc(set_glutMouseFunc);
}
