#include "igvMaterial.h"

// Metodos constructores 

igvMaterial::igvMaterial () {
	
}

igvMaterial::~igvMaterial () {

}

igvMaterial::igvMaterial (const igvMaterial& p) {	//de copia
	Ka = p.Ka;
	Kd = p.Kd;
	Ks = p.Ks;
	Ns = p.Ns;
}

igvMaterial::igvMaterial(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}

// Metodos publicos 

void igvMaterial::aplicar(void) {

// APARTADO C
// Aplicar los valores de los atributos del objeto igvMaterial:
// - coeficiente de reflexión de la luz ambiental
// - coeficiente de reflexión difuso
// - coeficiente de reflesión especular
// - exponente de Phong
	GLfloat coeficienteAmbiental[3] = {Ka[R], Ka[G], Ka[B]};
	GLfloat coeficienteReflexionDifuso[3] = {Kd[R], Kd[G], Kd[B]};
	GLfloat coeficienteReflexionEspecular[3] = {Ks[R], Ks[G], Ks[B]};

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, coeficienteAmbiental);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, coeficienteReflexionDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, coeficienteReflexionEspecular);
	// es glMaterialf en lugar de fv porque no se le pasa un array si no un solo atributo
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, Ns);

// establecer como color de emisión (0.0, 0.0, 0.0) (el objeto no es una fuente de luz)
	GLfloat emision[3] = { 0.0, 0.0, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emision);
}

void igvMaterial::set(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}



