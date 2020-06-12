#define _USE_MATH_DEFINES
#include <iostream>
#include <GL/glut.h>
#include <math.h>

double radMerkurius = 0;
double radVenus = 0;
double radBumi = 0;
double radBulan = 0;
double radMars = 0;
double radPhobos = 0;
double radDeimos = 0;

void DrawSun(double r, int vertex) {
	double ngon = (double)vertex;
	//Algoritma Matahari
	glBegin(GL_POLYGON);
	glColor3ub(255, 175, 0);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / vertex);
		double y = r * sin(2 * M_PI * i / vertex);
		glVertex2d(x + 350, y + 350);
	}
	glEnd();

}

void Orbit(double r, int vertex) {
	double ngon = (double)vertex;
	//Algoritma Orbit
	glBegin(GL_LINE_LOOP);
	glColor3ub(169, 169, 169);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / vertex);
		double y = r * sin(2 * M_PI * i / vertex);
		glVertex2d(x + 350, y + 350);
	}
	glEnd();
}

void RenderProgram(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	//Matahari
	DrawSun(25, 100);
	//Orbit - Merkurius
	Orbit(70, 258);
	//Orbit - Venus
	Orbit(120, 258);
	//Orbit - Bumi
	Orbit(180, 258);
	//orbit mars
	Orbit(270, 258);

	//Merkurius
	glPointSize(6);
	glColor3ub(222, 184, 135);
	glBegin(GL_POINTS);

	glVertex2f(sin(radMerkurius) * 70 + 350, cos(radMerkurius) * 70 + 350);

	glEnd();

	//Venus//
	glPointSize(8);
	glColor3ub(255, 255, 102);
	glBegin(GL_POINTS);

	glVertex2f(sin(radVenus) * 120 + 350, cos(radVenus) * 120 + 350);

	glEnd();

	//Bumi//
	glPointSize(12);
	glColor3ub(102, 102, 255);
	glBegin(GL_POINTS);

	glVertex2f(sin(radBumi) * 180 + 350, cos(radBumi) * 180 + 350);

	glEnd();

	//Bumi Satelit - Moon//
	glPointSize(5);
	glColor3ub(128, 128, 128);
	glBegin(GL_POINTS);

	glVertex2f(sin(radBulan) * 20 + sin(radBumi) * 180 + 350, cos(radBulan) * 20 + cos(radBumi) * 180 + 350);

	glEnd();

	//Mars
	glPointSize(8);
	glColor3ub(255, 140, 0);
	glBegin(GL_POINTS);

	glVertex2f(sin(radMars) * 270 + 350, cos(radMars) * 270 + 350);

	glEnd();

	//Mars Satelit - Phobos
	glPointSize(3);
	glColor3ub(128, 128, 128);
	glBegin(GL_POINTS);

	glVertex2f(sin(radPhobos) * 10 + sin(radMars) * 270 + 350, cos(radPhobos) * 10 + cos(radMars) * 270 + 350);

	glEnd();

	//Mars Satelit - Deimos
	glPointSize(3);
	glColor3ub(128, 128, 128);
	glBegin(GL_POINTS);

	glVertex2f(sin(radDeimos) * 20 + sin(radMars) * 270 + 350, cos(radDeimos) * 20 + cos(radMars) * 270 + 350);

	glEnd();

	//Garis Merkurius
	glColor3ub(255, 254, 254);
	glBegin(GL_LINES);

	glVertex2f(sin(radMerkurius) * 25 + 350, cos(radMerkurius) * 25 + 350);
	glVertex2f(sin(radMerkurius) * 67 + 350, cos(radMerkurius) * 67 + 350);

	glEnd();

	//Garis Venus
	glColor3ub(255, 254, 254);
	glBegin(GL_LINES);

	glVertex2f(sin(radVenus) * 25 + 350, cos(radVenus) * 25 + 350);
	glVertex2f(sin(radVenus) * 116 + 350, cos(radVenus) * 116 + 350);

	glEnd();

	//Garis Bumi
	glColor3ub(255, 254, 254);
	glBegin(GL_LINES);

	glVertex2f(sin(radBumi) * 25 + 350, cos(radBumi) * 25 + 350);
	glVertex2f(sin(radBumi) * 174 + 350, cos(radBumi) * 174 + 350);

	glEnd();

	//Garis Mars
	glColor3ub(255, 254, 254);
	glBegin(GL_LINES);

	glVertex2f(sin(radMars) * 25 + 350, cos(radMars) * 25 + 350);
	glVertex2f(sin(radMars) * 266 + 350, cos(radMars) * 266 + 350);

	glEnd();

	glFlush();
}

void Pergerakan(int) {
	glutPostRedisplay();
	glutTimerFunc(7, Pergerakan, 1);
	//Kecepatan dan Pergerakan
	radMerkurius += 0.025f;
	radVenus += 0.012f;
	radBumi += 0.0051f;
	radBulan += 0.05f;
	radMars += 0.0025f;
	radPhobos += 0.067f;
	radDeimos += 0.055f;
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(700, 700);

	glutCreateWindow("Setengah Tata Surya");

	gluOrtho2D(0, 700, 700, 0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_POINT_SMOOTH);
	glutTimerFunc(7, Pergerakan, 1);
	glutDisplayFunc(RenderProgram);
	glutMainLoop();

	return(0);
}