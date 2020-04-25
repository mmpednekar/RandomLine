#include <GL/freeglut.h>
#include <stdio.h>
class Node { 
public: 
	GLfloat x, y, z; 
	GLfloat clor1, clor2, clor3;
	Node* next; 
}; 

Node* head = NULL; 
Node *curr = NULL;
Node * temp = NULL;
//global variable declaration
bool bFullscreen=false; //variable to toggle for fullscreen

GLfloat angleTri=0.0f; //angle of rotation of Pyramid
GLfloat angleSquare=0.0f; //angle of rotation of Cube

int main(int argc,char** argv)
{
	//function prototypes
	void display(void);
	void resize(int,int);
	void keyboard(unsigned char,int,int);
	void mouse(int,int,int,int);
    void spin(void);
	void initialize(void);
	void uninitialize(void);

	//code
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(800,600); //to declare initial window size
	glutInitWindowPosition(100,100); //to declare initial window position
	glutCreateWindow("3D Rotation : Pyramid And Cube"); //open the window with "3D Rotation : Pyramid And Cube" in the title bar

	initialize();

	glutDisplayFunc(display);
	glutFullScreen();
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutIdleFunc(spin);
	glutCloseFunc(uninitialize);

	glutMainLoop();

//	return(0); 
}

void display(void)
{
	//code
	//to clear all pixels
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// ###### PYRAMID ######
	Node * newNode = new Node();
	newNode->x = (rand()%100)/40.0;
	newNode->y = (rand()%100)/40.0;
	newNode->z = (rand()%100)/40.0;

	newNode->clor1 = (rand()%255)/255.0;
	newNode->clor2 = (rand()%255)/255.0;
	newNode->clor3 = (rand()%255)/255.0;

	newNode -> next = NULL;	
	curr->next = newNode;
	curr = curr->next;


	glLoadIdentity();
	glTranslatef(-1.0f,-1.0f,-7.0f);
	glRotatef(angleTri,1.0f,1.0f,1.0f);

	for(curr = head; curr->next != NULL; curr = curr->next)
	{
		if(curr->next)
		{
			temp = curr->next;
		}
		else
		{
			break;
		}
	
		glBegin(GL_LINE_LOOP);
		//NOTE : EACH FACE OF A PYRAMID (EXCEPT THE BASE/BOTTOM) IS A TRIANGLE

	    //****FRONT FACE****
		glColor3f(temp->clor1,temp->clor2,temp->clor3); //red : Colour of apex triangle
		glVertex3f(temp->x, temp->y, temp->z); //apex of triangle
		glVertex3f(curr->x,curr->y,curr->z); //apex of triangle
		glEnd();
	}
	// ###### CUBE ######

	glutSwapBuffers();
}

void initialize(void)
{
	//code
	glShadeModel(GL_SMOOTH);
	// set background clearing color to black
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	// set-up depth buffer
	glClearDepth(1.0f);
	// enable depth testing
	glEnable(GL_DEPTH_TEST);
	// depth test to do
	glDepthFunc(GL_LEQUAL);
	// set really nice percpective calculations ?
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
    glLineWidth(3.0f);
	//Initialize Head
	head = new Node();
	head->x = 0.0f;
	head->y = 0.0f;
	head->z = 0.0f;
	curr = head;
}

void keyboard(unsigned char key,int x,int y)
{
	//code
	switch(key)
	{
	case 27: // Escape
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if(bFullscreen==false)
		{
			glutFullScreen();
			bFullscreen=true;
		}
		else
		{
			glutLeaveFullScreen();
			bFullscreen=false;
		}
		break;
	default:
		break;
	}
}

void mouse(int button,int state,int x,int y)
{
	//code
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		break;
	default:
		break;
	}
}

void resize(int width,int height)
{
    //code
	if(height==0)
		height=1;
	glViewport(0,0,(GLsizei)width,(GLsizei)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void spin(void)
{
	// code
	angleTri=angleTri+1.0f;
	if(angleTri>=360.0f)
		angleTri=angleTri-360.0f;

	angleSquare=angleSquare+1.0f;
	if(angleSquare>=360.0f)
		angleSquare=angleSquare-360.0f;

	glutPostRedisplay();
}

void uninitialize(void)
{
	//code
}
