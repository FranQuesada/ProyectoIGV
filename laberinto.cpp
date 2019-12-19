#include "laberinto.h"



laberinto::laberinto()
{
	llave1 = false;
	llave2 = false;
	seleccionado[0] = 1;
	seleccionado[1] = 1;
	seleccionado[2] = 1;
}


laberinto::~laberinto()
{
}

void laberinto::mostrar() {
	pintarSuelo();
	pintarParedes();
}

void laberinto::pintarSuelo() {
	glDisable(GL_LIGHTING);
	igvTextura suelo("./imagenes/suelo.bmp");
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0, 1, 0);
	// Esquina inferior izquierda
	glTexCoord2f(0, 0);
	glVertex3f(-50.0, -0.5, 50.0);
	// Esquina superior izquierda
	glTexCoord2f(0, 15);
	glVertex3f(-50.0, -0.5, -50.0);
	// Esquina superior derecha
	glTexCoord2f(15, 15);
	glVertex3f(50.0, -0.5, -50.0);
	// Esquina inferior derecha
	glTexCoord2f(15, 0);
	glVertex3f(50.0, -0.5, 50.0);
	glEnd();  
	suelo.aplicar();
}

void laberinto::pintarParedes() {
	// Paredes externas
	glPushMatrix();
	glTranslatef(51, 0, 0);
	pintarMuro(2, 4, 100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-51, 0, 0);
	pintarMuro(2, 4, 100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, 51);
	glRotatef(90, 0, 1, 0);
	pintarMuro(2, 4, 100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, -51);
	glRotatef(90, 0, 1, 0);
	pintarMuro(2, 4, 100);

	// Paredes internas
	// Primera fila en vertical
	glPopMatrix();
	glPushMatrix();
	glTranslatef(35, 0, 40);
	glRotatef(90, 0, 1, 0);
	pintarMuro(2, 4, 30);
	glTranslatef(0, 0, -40);
	pintarMuro(2, 4, 30);
	// Primera fila en horizontal
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-30, 0, 25);
	pintarMuro(2, 4, 50);
	glTranslatef(10, 0, -10);
	pintarMuro(2, 4, 50);
	glTranslatef(30, 0, 10);
	pintarMuro(2, 4, 30);
	glTranslatef(10, 0, 0);
	pintarMuro(2, 4, 30);
	glTranslatef(-20, 0, -5);
	pintarMuro(2, 4, 20);
	glTranslatef(-8, 0, -5);
	pintarMuro(2, 4, 30);
	glTranslatef(47, 0, 0);
	pintarMuro(2, 4, 30);
	glTranslatef(-8, 0, 5);
	pintarMuro(2, 4, 20);
	// Segunda fila vertical
	glPopMatrix();
	glPushMatrix();
	glTranslatef(5, 0, 11);
	glRotatef(90, 0, 1, 0);
	pintarMuro(2, 4, 10);
	glTranslatef(10, 0, -4);
	pintarMuro(2, 4, 20);
	glTranslatef(-30, 0, -5);
	pintarMuro(2, 4, 10);
	glTranslatef(20, 0, 30);
	pintarMuro(2, 4, 10);
	glTranslatef(10, 0, 3);
	pintarMuro(2, 4, 20);
	glTranslatef(-30, 0, 6);
	pintarMuro(2, 4, 10);
	// Tercera fila horizontal
	glPopMatrix();
	glPushMatrix();
	glTranslatef(10, 0, -10);
	pintarMuro(2, 4, 20);
	glTranslatef(10, 0, 0);
	pintarMuro(2, 4, 20);
	glTranslatef(10, 0, -8);
	pintarMuro(2, 4, 20);
	glTranslatef(-60, 0, -6);
	pintarMuro(2, 4, 10);
	// Tercera fila vertical
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-9, 0, -19);
	glRotatef(90, 0, 1, 0);
	pintarMuro(2, 4, 40);
	glTranslatef(10, 0, 9.75);
	pintarMuro(2, 4, 60);
	glTranslatef(-20, 0, 40);
	pintarMuro(2, 4, 18);
	glTranslatef(-10, 0, 5);
	pintarMuro(2, 4, 10);
	glTranslatef(10, 0, -80);
	pintarMuro(2, 4, 30);
	glTranslatef(-10, 0, -5);
	pintarMuro(2, 4, 20);
	
	// Cartel de salida
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,1,1);
	igvTextura cartel("./imagenes/a.bmp");
	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	glPushMatrix();
	glTranslatef(-40, 0, -3);
	glScalef(1, 4, 9);
	glutSolidCube(1);
	glPopMatrix();
	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);
	cartel.~igvTextura();

	// Cambiar color de las cajas cuando se seleccionan
	if (getLlave1()) {
		glColor3f(seleccionado[0], seleccionado[1], seleccionado[2]);
	}
	else {
		glColor3f(0, 1, 0);
	}
	glTranslatef(45, 0, -5);
	glutSolidCube(2);

	if (getLlave2()) {
		glColor3f(seleccionado[0], seleccionado[1], seleccionado[2]);
	}
	else {
		glColor3f(0, 0.99, 0);
	}
	glTranslatef(-50, 0, 30);
	glutSolidCube(2);
}

void laberinto::pintarMuro(float x, float y, float z) {
	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	glPushMatrix();
	glColor3f(0.647059, 0.164706, 0.164706);
	glScalef(x, y, z);
	glutSolidCube(1);
	glPopMatrix();
	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);
}

void laberinto::pintarPersonaje(float x, float y, float z) {
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.9);
	glTranslatef(x+4, 0.0f, z-28);
	glutSolidSphere(2.0, 5, 5);
	glPopMatrix();
}