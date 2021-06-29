#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <gl/glut.h>

const double PI = 3.141592653589793;
int i;



void lingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah) {
	glBegin(GL_POLYGON);
	for (i = 0;i <= 360;i++) {
		float sudut = i * (2 * PI / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + radius * sin(sudut);
		glVertex2f(x, y);
	}
	glEnd();
}
void renderProgram() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	//back();
	glColor3f(1.0, 0.0, 0.0);
	lingkaran(30, 100, 300, 400);
	
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(50,0);
		glVertex2f(100, 100);
		glVertex2f(150, 150);
		glVertex2f(100, 0);
	glEnd();
	
	glColor3f(1.0, 0.0, 0.5);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2i(250, 400);
	glVertex2i(390, 230);
	glEnd();

	glColor3f(1.0, 0.7, 0.9);
    glPointSize(10);
    glBegin(GL_POINTS);
        glVertex2i(170, 170);
    glEnd();
	glFlush();

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Contoh Baru");
	glutDisplayFunc(renderProgram);
	gluOrtho2D(0, 500, 0, 500);

	//Selesai

	glutMainLoop();

	return 0;
}