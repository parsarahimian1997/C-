/*
	This Code Is Written By Amir Parsa Rahimian
	Language C++	
	Opengl
	More Code And Project https://github.com/parsarahimian1997/Amir-Parsa-Rahimian#amir-parsa-rahimian
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <dos.h>
#include <vector>
#include <conio.h>
#include <utility>
#include <gl/glut.h>
#include <SOIL.h>
//3d
#include <fstream>
#include <sstream>
using std::ostringstream;
#include <Windows.h>
#include <gl/glfw3.h>
#include <time.h>
#include <string>
#include "imageloader.h"
#include "mmsystem.h"
using namespace std;
int win;
float _angle = 0.0;
GLuint _textureBrick, _textureDoor, _textureGrass, _textureRoof, _textureWindow, _textureSky;

// angle of rotation for the camera direction
float angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;

static float x = 0.0f, z = 5.0f;

const int NUM_SECONDS = 10;

GLfloat updateRate = 60; // Change this later  72.5
GLfloat whiteSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat blackAmbientLight[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat whiteDiffuseLight[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light0Position[] = { 0.0, 50.0, 0.0, 1.0 };
GLfloat light1Position[] = { 50.0, 0.0, 0.0, 1.0 };
GLfloat light2Position[] = { 0.0, 0.0, 50.0, 1.0 };
GLfloat light3Position[] = { 25.0, 50.0, 0.0, 1.0 };
GLfloat light4Position[] = { 0.0, 50.0, 25.0, 1.0 };
GLfloat light5Position[] = { 25.0, 50.0, 25.0, 1.0 };
static int pass;
static GLfloat rotX = 0.0;
static GLfloat rotY = 0.0;
static GLfloat rotZ = 0.0;
float scale = 1;
int lsource = 2;
int rotate = 0, rx = 0, ry = 0, rz = 0, xct = 0, yct = 0, zct = 0;
unsigned char kee = 0;
int lcount = 0;
int mesh = 0;
static int spin = 0;//todo
static float cy = 2, ey = 2;
float an = 0;
float t = 0;
float g = 0.2;
float v = 0.05;
float h = 0.5;
int Mode = 0;
float td = 0;

static long font = (long)GLUT_BITMAP_8_BY_13;
char sas[50] = "Would you like to access the central site? D/A";
class Vertex
{
public:
	GLfloat x, y, z;
	Vertex(GLfloat a, GLfloat b, GLfloat c) :x(a), y(b), z(c)
	{}
};
class Material
{
public:
	int n;
	//string Name;
	GLfloat shiny, transparency;
	GLfloat sr, sg, sb, ar, ag, ab, dr, dg, db, er, eg, eb;
	Material(int a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i, GLfloat j, GLfloat k, GLfloat l, GLfloat m, GLfloat z, GLfloat o)
	{
		n = a;
		shiny = b;
		transparency = c;
		ar = d; ag = e; ab = f;
		dr = g; dg = h; db = i;
		sr = j; sg = k; sb = l;
		er = m; eg = z; eb = o;
	}
};

class Face
{
public:
	int facen[3];
	int faces[3];
	int mat;
	Face(int facen1, int facen2, int facen3, int f1, int f2, int f3, int m)
	{
		facen[0] = facen1;
		facen[1] = facen2;
		facen[2] = facen3;
		faces[0] = f1;
		faces[1] = f2;
		faces[2] = f3;
		mat = m;
	}

};
vector<Vertex>VX;
vector<Face>FC;
vector<Vertex>VN;
vector<Material>materials;


void setMaterial(int materialId)
{
	GLfloat specular[4];
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat emmisive[4];
	GLfloat shiny;

	// Ugly but works

	ambient[0] = materials[materialId].ar;
	ambient[1] = materials[materialId].ag;
	ambient[2] = materials[materialId].ab;
	ambient[3] = 1 - materials[materialId].transparency;
	//cout<<ambient[0]<<" "<<ambient[1]<<" "<<ambient[2]<<" "<<ambient[3]<<endl;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

	diffuse[0] = materials[materialId].dr;
	diffuse[1] = materials[materialId].dg;
	diffuse[2] = materials[materialId].db;
	diffuse[3] = 1 - materials[materialId].transparency;
	//cout<<diffuse[0]<<" "<<diffuse[1]<<" "<<diffuse[2]<<" "<<diffuse[3]<<endl;
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);

	specular[0] = materials[materialId].sr;
	specular[1] = materials[materialId].sg;
	specular[2] = materials[materialId].sb;
	specular[3] = 1 - materials[materialId].transparency;
	// cout<<specular[0]<<" "<<specular[1]<<" "<<specular[2]<<" "<<specular[3]<<endl;
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);

	emmisive[0] = materials[materialId].er;
	emmisive[1] = materials[materialId].eg;
	emmisive[2] = materials[materialId].eb;
	emmisive[3] = 1 - materials[materialId].transparency;

	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emmisive);

	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &materials[materialId].shiny);
}

int Read()
{
	ifstream ifs1("jet.mtl");
	cout.precision(4);
	int count = 0;
	while (ifs1)
	{
		int n, check = 0;
		float Ns, Ni, Ka[3], Kd[3], Ks[3], Ke[3];
		string header;
		ifs1 >> header;
		if (header == string("newmtl"))
		{
			count++; check = 1;

			ifs1 >> n;

		}
		else if (header == string("Ns"))
		{
			count++; check = 1;

			ifs1 >> Ns;

		}
		else if (header == string("Tr"))
		{
			count++; check = 1;

			ifs1 >> Ni;

		}
		else if (header == string("Ka"))
		{
			count++; check = 1;

			ifs1 >> Ka[0] >> Ka[1] >> Ka[2];

		}
		else if (header == string("Kd"))
		{
			count++; check = 1;

			ifs1 >> Kd[0] >> Kd[1] >> Kd[2];

		}
		else if (header == string("Ks"))
		{
			count++; check = 1;

			ifs1 >> Ks[0] >> Ks[1] >> Ks[2];

		}
		else if (header == string("Ke"))
		{
			count++; check = 1;

			ifs1 >> Ke[0] >> Ke[1] >> Ke[2];
		}
		if (count % 7 == 0 && check == 1)
		{
			materials.push_back(Material(n, Ns, Ni, Ka[0], Ka[1], Ka[2], Kd[0], Kd[1], Kd[2], Ks[0], Ks[1], Ks[2], Ke[0], Ke[1], Ke[2]));
		}
	}

	int mt = 0;
	ifstream ifs("jet.obj");
	if (!ifs) return 0;
	while (ifs)
	{
		string header;
		ifs >> header;
		if (header == string("mtllib"))
		{
			string mtllib;
			ifs >> mtllib;
		}
		else if (header == string("v"))
		{
			GLfloat v[3];
			ifs >> v[0] >> v[1] >> v[2];
			VX.push_back(Vertex(v[0], v[1], v[2]));
		}

		else if (header == string("vn"))
		{
			GLfloat vn[3];
			ifs >> vn[0] >> vn[1] >> vn[2];
			VN.push_back(Vertex(vn[0], vn[1], vn[2]));
		}
		else if (header == string("usemtl"))
		{
			ifs >> mt;
		}
		else if (header == string("f"))
		{
			int f[7];
			char a;
			ifs >> f[0] >> a >> f[1] >> a >> f[2] >> f[3] >> a >> f[1] >> a >> f[5] >> f[4] >> a >> f[1] >> a >> f[6];
			FC.push_back(Face(f[2], f[5], f[6], f[0], f[3], f[4], mt));

		}
	}

	int num;
	num = glGenLists(1);
	glNewList(num, GL_COMPILE);
	int last = -1;


	for (int i = 0; i < FC.size(); i++)
	{
		{
			setMaterial(FC[i].mat);
		}

		glBegin(GL_TRIANGLES);

		glNormal3f(VN[FC[i].facen[0] - 1].x, VN[FC[i].facen[0] - 1].y, VN[FC[i].facen[0] - 1].z);
		glVertex3f(VX[FC[i].faces[0] - 1].x, VX[FC[i].faces[0] - 1].y, VX[FC[i].faces[0] - 1].z);
		glNormal3f(VN[FC[i].facen[1] - 1].x, VN[FC[i].facen[1] - 1].y, VN[FC[i].facen[1] - 1].z);
		glVertex3f(VX[FC[i].faces[1] - 1].x, VX[FC[i].faces[1] - 1].y, VX[FC[i].faces[1] - 1].z);
		glNormal3f(VN[FC[i].facen[2] - 1].x, VN[FC[i].facen[2] - 1].y, VN[FC[i].facen[2] - 1].z);
		glVertex3f(VX[FC[i].faces[2] - 1].x, VX[FC[i].faces[2] - 1].y, VX[FC[i].faces[2] - 1].z);

		glEnd();
	}

	glEndList();

	return num;

}

void paye(float R1, float R2, float H1, float H2) {
	int N = 360;
	float Dtheta = 2 * 3.1415926 / N;
	float r1 = R1, r2 = R2, h1 = H1, h2 = H2;
	float angle = 0.0;
	glPointSize(10.0);
	glBegin(GL_LINE_STRIP);
	glLineWidth(1000);

	for (int i = 0; i <= N; i++)
	{
		glColor3f(0, 0.5, 0.5);
		float angle = i * Dtheta;
		glVertex3f(cos(angle)*r2, h2, sin(angle)*r2);
		glVertex3f(cos(angle)*r1, h1, sin(angle)*r1);
	}

	glEnd();
}

void lastic() {
	int N = 360;
	float Dtheta = 2 * 3.1415926 / N;
	float r = 1, h1 = 0, h2 = -0.5;
	float angle = 0.0;
	glPointSize(10.0);
	glBegin(GL_LINE_STRIP);
	glLineWidth(10000);
	for (r; r > 0; r -= 0.01)
	{
		for (int i = 0; i <= N; i++)
		{
			glColor3f(0, 0, 0);
			float angle = i * Dtheta;
			glVertex3f(cos(angle)*r, sin(angle)*r, h2);
			glVertex3f(cos(angle)*r, sin(angle)*r, h1);
		}
	}
	glEnd();
}

void tree1() {
	paye(0.3, 0.3, 2, 0);

	glColor3f(0, 0.5, 0);
	glTranslatef(0.0f, 3.5f, 0.0f);
	glutSolidSphere(2.0f, 20, 20);

	glColor3f(0, 0.6, 0);
	glTranslatef(0.0f, 1.5f, 0.0f);
	glutSolidSphere(2.0f, 20, 20);

	glColor3f(0, 0.4, 0);
	glTranslatef(0.0f, -0.75f, 0.75f);
	glutSolidSphere(2.0f, 20, 20);

	glColor3f(0, 0.2, 0);
	glTranslatef(0.0f, 0.0f, -1.5f);
	glutSolidSphere(2.0f, 20, 20);

	glColor3f(0, 0.8, 0);
	glTranslatef(0.75f, 0.0f, 0.0f);
	glutSolidSphere(2.0f, 20, 20);

	glColor3f(0, 0.6, 0);
	glTranslatef(-1.5f, 0.0f, 0.0f);
	glutSolidSphere(2.0f, 20, 20);

}

void makhroot() {
	int N = 360;
	float Dtheta = 2 * 3.1415926 / N;
	float r = 2;
	float angle = 0.0;
	glPointSize(10.0);

	glBegin(GL_LINE_STRIP);
	glLineWidth(10);

	for (int i = 0; i <= N; i++)
	{

		float angle = i * Dtheta;
		glVertex3f(cos(angle)*r, 0, sin(angle)*r);
		glVertex3f(0, 2, 0);
	}

	glEnd();
}
void tree2() {
	glPushMatrix();
	paye(0.3, 0.3, 2, 0);
	glTranslatef(0, 2, 0);
	glColor3f(0, 0.4, 0);
	makhroot();
	glTranslatef(0, 1, 0);
	makhroot();
	glTranslatef(0, 1, 0);
	makhroot();
	glTranslatef(0, 1, 0);
	makhroot();
	glTranslatef(0, 1, 0);
	makhroot();
	glPopMatrix();
}
void draw()
{
	int N = 360;
	float Dtheta = 2 * 3.1415926 / N;
	float angle = 0.0;
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(0, 1, 0);
	for (int i = -90; i <= 90; i++)
	{
		float angle = i * Dtheta;
		glVertex2f(cos(angle) / 3, angle / 3);
		glVertex2f(-cos(angle) / 3, angle / 3);
	}
	for (int i = -90; i <= 90; i++)
	{
		float angle = i * Dtheta;
		glVertex2f(cos(angle) / 20, angle / 3);
	}

	for (int i = -200; i <= -170; i++)
	{
		float angle = i * Dtheta;
		glVertex2f((cos(angle)) + 0.98, (angle / 3) + 0.46);
	}
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	angle = 60 * Dtheta;
	glVertex2f(cos(angle) / 3, angle / 3);
	angle = 35 * Dtheta;
	glVertex2f(cos(angle) / 25, angle / 3);
	angle = 60 * Dtheta;
	glVertex2f(-cos(angle) / 3, angle / 3);
	angle = 35 * Dtheta;
	glVertex2f(cos(angle) / 25, angle / 3);
	angle = 35 * Dtheta;
	glVertex2f(cos(angle) / 3, angle / 3);
	angle = 0 * Dtheta;
	glVertex2f(cos(angle) / 25, angle / 3);
	angle = 35 * Dtheta;
	glVertex2f(-cos(angle) / 3, angle / 3);
	angle = 0 * Dtheta;
	glVertex2f(cos(angle) / 25, angle / 3);
	angle = 5 * Dtheta;
	glVertex2f(cos(angle) / 3, angle / 3);
	angle = -35 * Dtheta;
	glVertex2f(cos(angle) / 25, angle / 3);
	angle = 5 * Dtheta;
	glVertex2f(-cos(angle) / 3, angle / 3);
	angle = -35 * Dtheta;
	glVertex2f(cos(angle) / 25, angle / 3);
	angle = -35 * Dtheta;
	glVertex2f(cos(angle) / 3, angle / 3);
	angle = -70 * Dtheta;
	glVertex2f(cos(angle) / 25, angle / 3);
	angle = -35 * Dtheta;
	glVertex2f(-cos(angle) / 3, angle / 3);
	angle = -70 * Dtheta;
	glVertex2f(cos(angle) / 25, angle / 3);
	glEnd();
}


void Light_Manager()
{
	glLightfv(GL_LIGHT0, GL_SPECULAR, whiteSpecularLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);
	glLightfv(GL_LIGHT0, GL_POSITION, light0Position);

	glLightfv(GL_LIGHT1, GL_SPECULAR, whiteSpecularLight);
	glLightfv(GL_LIGHT1, GL_AMBIENT, blackAmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, whiteDiffuseLight);
	glLightfv(GL_LIGHT1, GL_POSITION, light1Position);

	glLightfv(GL_LIGHT2, GL_SPECULAR, whiteSpecularLight);
	glLightfv(GL_LIGHT2, GL_AMBIENT, blackAmbientLight);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, whiteDiffuseLight);
	glLightfv(GL_LIGHT2, GL_POSITION, light2Position);

	glLightfv(GL_LIGHT3, GL_SPECULAR, whiteSpecularLight);
	glLightfv(GL_LIGHT3, GL_AMBIENT, blackAmbientLight);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, whiteDiffuseLight);
	glLightfv(GL_LIGHT3, GL_POSITION, light3Position);

	glLightfv(GL_LIGHT4, GL_SPECULAR, whiteSpecularLight);
	glLightfv(GL_LIGHT4, GL_AMBIENT, blackAmbientLight);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, whiteDiffuseLight);
	glLightfv(GL_LIGHT4, GL_POSITION, light4Position);

	glLightfv(GL_LIGHT5, GL_SPECULAR, whiteSpecularLight);
	glLightfv(GL_LIGHT5, GL_AMBIENT, blackAmbientLight);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, whiteDiffuseLight);
	glLightfv(GL_LIGHT5, GL_POSITION, light5Position);

	if (lsource == 0)
	{
		glDisable(GL_LIGHT0); glDisable(GL_LIGHT1); glDisable(GL_LIGHT2); glDisable(GL_LIGHT3); glDisable(GL_LIGHT4); glDisable(GL_LIGHT5);
	}
	if (lsource == 1)
	{
		glEnable(GL_LIGHT0); glDisable(GL_LIGHT1); glDisable(GL_LIGHT2); glDisable(GL_LIGHT3); glDisable(GL_LIGHT4); glDisable(GL_LIGHT5);
	}
	if (lsource == 2)
	{
		glEnable(GL_LIGHT0); glEnable(GL_LIGHT1); glDisable(GL_LIGHT2); glDisable(GL_LIGHT3); glDisable(GL_LIGHT4); glDisable(GL_LIGHT5);
	}
	if (lsource == 3)
	{
		glEnable(GL_LIGHT0); glEnable(GL_LIGHT1); glEnable(GL_LIGHT2); glDisable(GL_LIGHT3); glDisable(GL_LIGHT4); glDisable(GL_LIGHT5);
	}
	if (lsource == 4)
	{
		glEnable(GL_LIGHT0); glEnable(GL_LIGHT1); glEnable(GL_LIGHT2); glEnable(GL_LIGHT3); glDisable(GL_LIGHT4); glDisable(GL_LIGHT5);
	}
	if (lsource == 5)
	{
		glEnable(GL_LIGHT0); glEnable(GL_LIGHT1); glEnable(GL_LIGHT2); glEnable(GL_LIGHT3); glEnable(GL_LIGHT4); glDisable(GL_LIGHT5);
	}
	if (lsource == 6)
	{
		glEnable(GL_LIGHT0); glEnable(GL_LIGHT1); glEnable(GL_LIGHT2); glEnable(GL_LIGHT3); glEnable(GL_LIGHT4); glEnable(GL_LIGHT5);
	}
}

int jetp;

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
											 //Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now
		GL_RGB,                       //Format OpenGL uses for image
		image->width, image->height,  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
						  //as unsigned numbers
		image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	Image* image = loadBMP("bricks.bmp");
	_textureBrick = loadTexture(image);
	image = loadBMP("door.bmp");
	_textureDoor = loadTexture(image);
	image = loadBMP("grass.bmp");
	_textureGrass = loadTexture(image);
	image = loadBMP("roof.bmp");
	_textureRoof = loadTexture(image);
	image = loadBMP("window.bmp");
	_textureWindow = loadTexture(image);
	image = loadBMP("sky.bmp");
	_textureSky = loadTexture(image);
	delete image;
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//jet
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LIGHTING);

	//base
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	jetp = Read();

}

void light() {

	GLfloat pos[] = { 0.0,0.0,1.5,1.0 };

	glPushMatrix();
	glTranslatef(8.0, 8.0, -5.0);
	//glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glTranslatef(0, 0, 1.5);
	if (!spin)
	{
		glDisable(GL_LIGHTING);
	}
	else
	{
		glEnable(GL_LIGHTING);
	}
	glPopMatrix();

}

void display(void) {

	light();
	glClearColor(0.3137, 0.5254, 1.0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(x, ey, z,
		x + lx, cy, z + lz,
		0.0f, 1.0f, 0.0f);


	glColor3f(0, 1, 0);
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();
	glPopMatrix();


	for (int i = 0; i < 25; i++)
	{
		glPushMatrix();
		glTranslatef(-77 + (i * 6), 0, -75);
		tree1();
		glPopMatrix();
	}
	for (int i = 0; i < 25; i++)//last
	{
		glPushMatrix();
		glTranslatef(-77 + (i * 7), 0, -85);
		tree1();
		glPopMatrix();
	}
	for (int i = 0; i < 28; i++)
	{
		glPushMatrix();
		glTranslatef(-75, 0, -72 + (i * 4.6));
		tree2();
		glPopMatrix();
	}
	for (int i = 0; i < 33; i++)//last
	{
		glPushMatrix();
		glTranslatef(-90, 0, -72 + (i * 4));
		tree2();
		glPopMatrix();
	}
	for (int i = 0; i < 25; i++)
	{
		glPushMatrix();
		glTranslatef(-77 + (i * 6), 0, 58);
		tree1();
		glPopMatrix();
	}
	for (int i = 0; i < 25; i++)//last
	{
		glPushMatrix();
		glTranslatef(-77 + (i * 7), 0, 70);
		tree1();
		glPopMatrix();
	}
	for (int i = 0; i < 28; i++)
	{
		glPushMatrix();
		glTranslatef(70, 0, -72 + (i * 4.6));
		tree2();
		glPopMatrix();
	}
	for (int i = 0; i < 33; i++)//last
	{
		glPushMatrix();
		glTranslatef(90, 0, -72 + (i * 4));
		tree2();
		glPopMatrix();
	}
	////3D start
	Light_Manager();

	glPushMatrix();
	glTranslatef(8, 0, -23);
	glScalef(scale, scale, scale);
	glRotatef(rotY, 0.0, 1.0, 0.0);
	if (ry == 1)
	{
		rotY += 1.0;
	}
	glColor3f(0.1294, 0.2313, 0.2784);
	glCallList(jetp);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(25, 40, 40);
	glScalef(scale, scale, scale);
	glRotatef(rotX, 1.0, 0.0, 0.0);
	glRotatef(rotY, 0.0, 1.0, 0.0);
	glRotatef(rotZ, 0.0, 0.0, 1.0);
	if (rx == 1)
	{
		rotX += 1.0;
	}
	if (ry == 1)
	{
		rotY += 1.0;
	}
	if (rz == 1)
	{
		rotZ += 1.0;
	}
	glColor3f(0.2156, 0.2784, 0.3098);
	glCallList(jetp);
	glPopMatrix();
	////3D end

	glutSwapBuffers();
}

void HomeScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);

	// Sky
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureSky);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -10);
	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 1.0, 0.1);  glVertex3f(-10, 10, 0);
	glTexCoord3f(1.0, 1.0, 0.1);  glVertex3f(10, 10, 0);
	glTexCoord3f(1.0, 0.0, 0.1);  glVertex3f(10, -10, 0);
	glTexCoord3f(0.0, 0.0, 0.1);  glVertex3f(-10, -10, 0);
	glEnd();
	glPopMatrix();

	// Grass
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureGrass);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 70.0, 1);  glVertex3f(-50, -1.5, 50);
	glTexCoord3f(0.0, 0.0, -1);  glVertex3f(-50, -1.5, -50);
	glTexCoord3f(70.0, 0.0, -1);  glVertex3f(50, -1.5, -50);
	glTexCoord3f(70.0, 70.0, 1);  glVertex3f(50, -1.5, 50);
	glEnd();
	glPopMatrix();

	// Front side
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureBrick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);  // Wall
	glTexCoord3f(0.0, 2.0, 0.1);  glVertex3f(-2, 0, 1);
	glTexCoord3f(4.0, 2.0, 0.1);  glVertex3f(2, 0, 1);
	glTexCoord3f(4.0, 0.0, 0.1);  glVertex3f(2, -1.5, 1);
	glTexCoord3f(0.0, 0.0, 0.1);  glVertex3f(-2, -1.5, 1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _textureRoof);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Roof
	glTexCoord3f(0.0, 2.0, 0); glVertex3f(-2.2, 0.5, 0);
	glTexCoord3f(4.0, 2.0, 0); glVertex3f(2.2, 0.5, 0);
	glTexCoord3f(4.0, 0.0, 1.25); glVertex3f(2.2, -0.1, 1.25);
	glTexCoord3f(0.0, 0.0, 1.25); glVertex3f(-2.2, -0.1, 1.25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _textureDoor);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Door
	glTexCoord3f(0.0, 1.0, 1.0001); glVertex3f(-0.3, -0.4, 1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); glVertex3f(0.3, -0.4, 1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); glVertex3f(0.3, -1.5, 1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); glVertex3f(-0.3, -1.5, 1.0001);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _textureWindow);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Window Left
	glTexCoord3f(0.0, 1.0, 1.0001); glVertex3f(-1.5, -0.3, 1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); glVertex3f(-0.75, -0.3, 1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); glVertex3f(-0.75, -0.8, 1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); glVertex3f(-1.5, -0.8, 1.0001);
	glEnd();

	glBegin(GL_QUADS);  // Window Right
	glTexCoord3f(0.0, 1.0, 1.0001); glVertex3f(1.5, -0.3, 1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); glVertex3f(0.75, -0.3, 1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); glVertex3f(0.75, -0.8, 1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); glVertex3f(1.5, -0.8, 1.0001);
	glEnd();
	glPopMatrix();

	// Back side
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureBrick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);  // Wall
	glTexCoord3f(0.0, 2.0, -1);  glVertex3f(-2, 0, -1);
	glTexCoord3f(4.0, 2.0, -1);  glVertex3f(2, 0, -1);
	glTexCoord3f(4.0, 0.0, -1);  glVertex3f(2, -1.5, -1);
	glTexCoord3f(0.0, 0.0, -1);  glVertex3f(-2, -1.5, -1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _textureRoof);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Roof
	glTexCoord3f(0.0, 2.0, 0); glVertex3f(-2.2, 0.5, 0);
	glTexCoord3f(4.0, 2.0, 0); glVertex3f(2.2, 0.5, 0);
	glTexCoord3f(4.0, 0.0, -1.25); glVertex3f(2.2, -0.1, -1.25);
	glTexCoord3f(0.0, 0.0, -1.25); glVertex3f(-2.2, -0.1, -1.25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _textureWindow);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);  // Window Left
	glTexCoord3f(0.0, 1.0, -1.0001); glVertex3f(-1.5, -0.3, -1.0001);
	glTexCoord3f(1.0, 1.0, -1.0001); glVertex3f(-0.75, -0.3, -1.0001);
	glTexCoord3f(1.0, 0.0, -1.0001); glVertex3f(-0.75, -0.8, -1.0001);
	glTexCoord3f(0.0, 0.0, -1.0001); glVertex3f(-1.5, -0.8, -1.0001);
	glEnd();

	glBegin(GL_QUADS);  // Window Right
	glTexCoord3f(0.0, 1.0, 1.0001); glVertex3f(1.5, -0.3, -1.0001);
	glTexCoord3f(1.0, 1.0, 1.0001); glVertex3f(0.75, -0.3, -1.0001);
	glTexCoord3f(1.0, 0.0, 1.0001); glVertex3f(0.75, -0.8, -1.0001);
	glTexCoord3f(0.0, 0.0, 1.0001); glVertex3f(1.5, -0.8, -1.0001);
	glEnd();
	glPopMatrix();

	// Right side
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureBrick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);  // Wall
	glTexCoord3f(0.0, 2.0, 1); glVertex3f(2, 0, 1);
	glTexCoord3f(2.0, 2.0, -1); glVertex3f(2, 0, -1);
	glTexCoord3f(2.0, 0.0, -1); glVertex3f(2, -1.5, -1);
	glTexCoord3f(0.0, 0.0, 1); glVertex3f(2, -1.5, 1);
	glEnd();

	glBegin(GL_TRIANGLES);  // Wall Upper
	glTexCoord3f(0.0, 1.0, 0); glVertex3f(2, 0.5, 0);
	glTexCoord3f(1.0, 0.0, 1); glVertex3f(2, 0, 1);
	glTexCoord3f(-1.0, 0.0, -1); glVertex3f(2, 0, -1);
	glEnd();
	glPopMatrix();

	// Left side
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _textureBrick);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTranslatef(0, 0, -6);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);  // Wall
	glTexCoord3f(0.0, 2.0, 1);    glVertex3f(-2, 0, 1);
	glTexCoord3f(2.0, 2.0, -1);    glVertex3f(-2, 0, -1);
	glTexCoord3f(2.0, 0.0, -1);    glVertex3f(-2, -1.5, -1);
	glTexCoord3f(0.0, 0.0, 1);    glVertex3f(-2, -1.5, 1);
	glEnd();

	glBegin(GL_TRIANGLES);  // Wall Upper
	glTexCoord3f(0.0, 1.0, 0);    glVertex3f(-2, 0.5, 0);
	glTexCoord3f(1.0, 0.0, 1);    glVertex3f(-2, 0, 1);
	glTexCoord3f(-1.0, 0.0, -1);    glVertex3f(-2, 0, -1);
	glEnd();
	glPopMatrix();


	if (_angle < -89)
	{
		glColor3f(0, 1, 0);
		glRasterPos3f(-1.8, 1.5, -8);
		for (int i = 0; sas[i]; i++)
		{
			glutBitmapCharacter((void*)font, sas[i]);
		}
	}
	else if (_angle > 89)
	{
		glColor3f(0, 1, 0);
		glRasterPos3f(-1, 1, -5);
		for (int i = 0; sas[i]; i++)
		{
			glutBitmapCharacter((void*)font, sas[i]);
		}
	}
	glutSwapBuffers();
}

void resize(int w, int h)
{
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(50.0f, ratio, 0.1f, 150.0f);
	glMatrixMode(GL_MODELVIEW);

}

void resizeHome(int w, int h)
{
	const float ar = (float)w / (float)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
// KeyBoard and JoyStick Controller Start
void key1(int key, int xx, int yy) {

	float f = 0.1;
	switch (key) {
	case GLUT_KEY_LEFT:
		if (Mode == 1)
		{
			angle -= 0.01;
			lx = sin(5 * angle);
			lz = -cos(5 * angle);
		}
		else if (Mode == 2)
		{
			_angle += 1;
			if (_angle > 360) _angle = 0.0;
		}
		break;
	case GLUT_KEY_RIGHT:
		if (Mode == 1)
		{
			angle += 0.01;
			lx = sin(5 * angle);
			lz = -cos(5 * angle);
		}
		else if (Mode == 2)
		{
			_angle -= 1;
			if (_angle > 360) _angle = 0.0;
		}
		break;
	case GLUT_KEY_UP:
		x += 5 * lx*f;
		z += 5 * lz*f;
		break;
	case GLUT_KEY_DOWN:
		x -= 5 * lx*f;
		z -= 5 * lz*f;
		break;

	}
	glutPostRedisplay();
}

void key2(unsigned char key, int x, int y);

void key3(unsigned int buttonmask, int x, int y, int z)
{
	switch (buttonmask) {
	case 0x01:
		if (spin) spin = 0;
		else spin = 1;
		break;
	case 0x02:
		if (cy <= 3.0)
		{
			cy += 0.1;
		}
		else
		{
			cout << "+Inf Limited!" << endl;
		}
		break;
	case 0x04:
		exit(0);
		break;
	case 0x08:
		if (cy >= 1.1)
		{
			cy -= 0.1;
		}
		else
		{
			cout << "-Inf Limited!" << endl;
		}
		break;
	}
}

void key4(unsigned int buttonmask, int x, int y, int z) {

	float f = 0.1;
	switch (buttonmask) {
	case VK_GAMEPAD_DPAD_LEFT:
		angle -= 0.01;
		lx = sin(5 * angle);
		lz = -cos(5 * angle);
		break;
	case VK_GAMEPAD_DPAD_RIGHT:
		angle += 0.01;
		lx = sin(5 * angle);
		lz = -cos(5 * angle);
		break;
	case VK_GAMEPAD_DPAD_UP:
		x += 5 * lx*f;
		z += 5 * lz*f;
		break;
	case VK_GAMEPAD_DPAD_DOWN:
		x -= 5 * lx*f;
		z -= 5 * lz*f;
		break;

	}
	glutPostRedisplay();
}


void joyStickHandeler()
{
	int present = glfwJoystickPresent(GLFW_JOYSTICK_1);
	float f = 0.1;

	if (1 == present)
	{
		int axesCount;
		const float *axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);
		int count;
		const unsigned char* button = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &count);
		//cout << "Left Stick X Axis: " << axes[0] << endl; // L-1  R1
		//cout << "Left Stick Y Axis: " << axes[1] << endl; // Up-1  Down1
		//cout << "Button Axis 1: "  << button[0] << endl;  //1 sabz
		//cout << "Button Axis 2: " << button[1] << endl; //2 qermez
		//cout << "Button Axis 3: " << button[2] << endl; // 3 abi
		//cout << "Button Axis 4: " << button[3] << endl; // 4 sorati
		//cout << "Button Axis L2: " << button[4] << endl; // L2
		//cout << "Button Axis R2: " << button[5] << endl; // R2
		//cout << "Button Axis L1: " << button[6] << endl; // L1
		//cout << "Button Axis R1: " << button[7] << endl; // R1
		//cout << "Button Axis 9: " << button[8] << endl; // 9 Start
		if (round(axes[0]) == 1)
		{
			angle -= 0.01;
			lx = sin(5 * angle);
			lz = -cos(5 * angle);
		}
		else if (round(axes[0]) == -1)
		{
			angle += 0.01;
			lx = sin(5 * angle);
			lz = -cos(5 * angle);
		}
		else if (round(axes[1]) == -1)
		{
			x += 5 * lx*f;
			z += 5 * lz*f;
		}
		else if (round(axes[1]) == 1)
		{
			x -= 5 * lx*f;
			z -= 5 * lz*f;
		}
		glutPostRedisplay();
	}
}
// KeyBoard and JoyStick Controller End


void timer(int)
{
	// Adjust rotation angles as needed here
	// Then tell glut to redisplay
	glutPostRedisplay();
	// And reset tht timer
	glutTimerFunc(1000.0 / updateRate, timer, 0);
}

bool startclock = true;       // True if clock is running
int hour = 0, Min = 0, sec = 0;     // time variables
string timestring = "00:00:00";
#define FPS 1

void myTimer(int v)     // timer function to update time
{
	ostringstream timestream;      // used to format time string
	if (startclock) sec++;         // increment second
	if (sec == 60)
	{
		Min++;
		sec = 0;
	} // increment minute
	if (Min == 60)
	{
		hour = hour++ % 24;
		Min = 0;
	} //increment hour
	timestream << setfill('0') << setw(2) << hour << ":" << setw(2)
		<< Min << ":" << setw(2) << sec;
	timestring = timestream.str();  //convert stream to string
	glutPostRedisplay();
	glutTimerFunc(1000 / v, myTimer, v);  //repost timer 
}

int main(int argc, char **argv) {
	PlaySound(TEXT("project.wav"), NULL, SND_ASYNC);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	//glutInitWindowSize(4096, 2160);
	glutInitWindowSize(3840, 2160);
	win = glutCreateWindow("A-M-P Project");
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	string name = "\n\n\n&BY THE NAME OF GOD\n\n\n\n!WellCome To Our Project.\n\n\n\n^This Page Will Be Cleared In 2.5 seconds.";
	system("color A0");
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] != '!' && name[i] != '@' && name[i] != '%' && name[i] != '$' && name[i] != '#' && name[i] != '&' && name[i] != '^')
			cout << name[i];
		else if (name[i] == '&')
			cout << setw(83 + 7);
		else if (name[i] == '!')
			cout << setw(20 + 7);
		else if (name[i] == '^')
			cout << setw(30 + 7);
		Sleep(107);
	}
	Sleep(2007);
	system("CLS");
	system("color b0");
	string ins[9] = { "Change Stage","Light(On/Off)","Top Camera","Bottom Camera","Exit","Increase Light","Decrease Light","Jet Transfer","Car Transfer" };
	string key[9] = { "g\t\t/\tR1","D\t\t/\tL1" ,"W\t\t/\tBottom 1" ,"S\t\t/\tBottom 3" ,"E\t\t/\tBottom 9" ,"J\t\t/\tBottom 2", "K\t\t/\tBottom 4","Y\t\t/\tR2","N\t\t/\tL2" };
L1:	cout << endl << endl << endl << setw(93 + 7) << "PROGRAM INSTRUCTIONS :" << endl << endl << endl << endl << endl << endl;
	cout << setw(24 + 7) << "Action" << setw(37 + 7) << "KeyBoard\t/\tJoyStick" << endl << endl;
	cout << setw(30 + 7) << ins[0] << setw(20 + 7) << key[0] << endl;
	cout << setw(31 + 7) << ins[1] << setw(19 + 7) << key[1] << endl;
	cout << setw(28 + 7) << ins[2] << setw(28 + 7) << key[2] << endl;
	cout << setw(31 + 7) << ins[3] << setw(25 + 7) << key[3] << endl;
	cout << setw(22 + 7) << ins[4] << setw(34 + 7) << key[4] << endl;
	cout << setw(32 + 7) << ins[5] << setw(24 + 7) << key[5] << endl;
	cout << setw(32 + 7) << ins[6] << setw(24 + 7) << key[6] << endl;
	cout << setw(30 + 7) << ins[7] << setw(20 + 7) << key[7] << endl;
	cout << setw(30 + 7) << ins[8] << setw(20 + 7) << key[8] << endl;
	cout << endl << setw(20 + 7) << "Select Mode:\n" << endl << setw(30 + 7) << "1 -> Centeral Site\n" << endl << setw(40 + 7) << "2 -> Home View\n" << endl << setw(50 + 7) << "3 -> Exit Project\n" << endl;
	cin >> Mode;
	switch (Mode)
	{
	case 1:
		init();
		glutDisplayFunc(display);
		glutReshapeFunc(resize);
		break;
	case 2:
		glEnable(GL_DEPTH_TEST);
		glutReshapeFunc(resizeHome);
		glutDisplayFunc(HomeScene);
		Initialize();
		break;
	case 3:
		goto l;
	default:
		goto L1;
		break;
	}
	glutSpecialFunc(key1);
	glutKeyboardFunc(key2);
	//glutJoystickFunc(key3, 25);
	//glutJoystickFunc(key4, 25);
	glutTimerFunc(1000, myTimer, FPS);
	glutMainLoop();
l:;
	return 0;
}

void key2(unsigned char key, int x, int y)
{

	switch (key) {
	case 'g':
		glutDestroyWindow(win);
		switch (Mode)
			{
			case 2:
				Mode = 1;
				glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
				glutInitWindowPosition(0, 0);
				//glutInitWindowSize(4096, 2160);
				glutInitWindowSize(1600, 900);
				win = glutCreateWindow("A-M-P Project");
				init();
				glutDisplayFunc(display);
				glutReshapeFunc(resize);
				glutSpecialFunc(key1);
				glutKeyboardFunc(key2);
				glutMainLoop();
				break;
			case 1:
				Mode = 2;
				//glutInit(&argc, argv);
				glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
				glutInitWindowPosition(0, 0);
				//glutInitWindowSize(4096, 2160);
				glutInitWindowSize(1600, 900);
				win = glutCreateWindow("A-M-P Project");
				glEnable(GL_DEPTH_TEST);
				glutReshapeFunc(resizeHome);
				glutDisplayFunc(HomeScene);
				Initialize();
				glutSpecialFunc(key1);
				glutKeyboardFunc(key2);
				glutMainLoop();
				break;
			}
		break;
	case 'd'://2
		if (spin == 0) {
			spin = 1;
		}
		else spin = 0;
		break;
	case 'w'://1
		if (cy <= 3.0)
		{
			//if (spin == 0) spin = 1;
			cy += 0.1;
		}
		else
		{
			cout << "+Inf Limited!" << endl;
			//	if (spin == 0) spin = 1;
		}
		break;
	case 's'://3
		if (cy >= 1.1)
		{
			//	if (cy == 1.1 && spin == 1) spin = 0;
			cy -= 0.1;
		}
		else
		{
			cout << "-Inf Limited!" << endl;
			//if (spin == 0) spin = 1;
		}
		break;
	case 'e': //R2
	{
		system("CLS");
		glutDestroyWindow(1);
		system("color 1");
		string end = "\n\n\n!You Have Closed The Project Right Now.\n\n\n@Watching Duration  -->  " + timestring + "\n\n\n#Thanks For Watching Our Project. :)\n\n\n$This Project Developed By :\n\n\n%Mehdi Brojeni\n\n\n^Amir Parsa Rahimian\n\n\n*Seyed Abolfazl Sherafat\n\n\n\n\n~Please Press 'Enter' To Exit.\n";
		for (int i = 0; i < end.size(); i++)
		{
			if (end[i] != '!' && end[i] != '@' && end[i] != '#' && end[i] != '$' && end[i] != '%' && end[i] != '^' && end[i] != '&' && end[i] != '*' && end[i] != '~')
				cout << end[i];
			else if (end[i] == '!')
				cout << setw(7 + 7);
			else if (end[i] == '@')
				cout << setw(17 + 7);
			else if (end[i] == '#')
				cout << setw(27 + 7);
			else if (end[i] == '$')
				cout << setw(37 + 7);
			else if (end[i] == '%')
				cout << setw(57 + 7);
			else if (end[i] == '^')
				cout << setw(67 + 7);
			else if (end[i] == '&')
				cout << setw(77 + 7);
			else if (end[i] == '*')
				cout << setw(87 + 7);
			else if (end[i] == '~')
				cout << setw(97 + 7);
			Sleep(107);
		}
		getchar();
		exit(0);
		break;
	}
	case 'j':
		if (lsource < 6)
		{
			lsource++;
			//	spin = 1;
		}
		else if (lsource == 6)
		{
			//spin = 0;
		}
		break;
	case 'k':
		if (lsource > 0)
		{
			lsource--;
			//	spin = 1;
		}
		else if (lsource == 0)
		{
			//	spin = 0;
		}
		break;
	case 'y':
		if (xct == 0)
		{
			rx = 1; xct++;
		}
		else
		{
			rx = 0; xct--;
		}
		if (yct == 0)
		{
			ry = 1; yct++;
		}
		else
		{
			ry = 0; yct--;
		}
		if (zct == 0)
		{
			rz = 1; zct++;
		}
		else
		{
			rz = 0; zct--;
		}
		break;
	}
	//reload project: R1+L1
	//Enter: 4
	glutPostRedisplay();
}