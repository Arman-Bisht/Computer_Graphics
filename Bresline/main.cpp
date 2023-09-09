#include <GL/glut.h>
#include <cstdlib>
#include <stdio.h>
int round(float a) {
    if(a-int(a) >= 0.5)
        return int(a)+1;
    else
        return int(a);
}
void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-200.0,199.0,-200.0,199.0);
}
void plotPoint(GLint x,GLint y)
{
 glColor3f(1.0,0.0,1.0);
 glBegin(GL_POINTS);
  glVertex2i(x,y);
 glEnd();
 glFlush();
}
void Bresen(float x1, float y1, float x2, float y2) {
    float dx = x2-x1;
    float dy = y2-y1;
    int inc1, inc2;
    float x = x1;
    float y = y1;
    int i = 0, e;
    float xinc, yinc, len;
    if(dx < 0)
        dx = -dx;
    if(dy < 0)
        dy = -dy;
    xinc = 1;
    if(x2 < x1)
        xinc = -1;
    yinc = 1;
    if(y2 < y1)
        yinc = -1;
    x = x1;
    y = y1;
    if(dx > dy) {
        plotPoint(x, y);
        e = 2*dy-dx;
        inc1 = 2 * (dy - dx);
    	inc2 = 2 * dy;
        for(i=0; i<dx; i++) {
            if(e>=0) {
                y+=yinc;
                e+=inc1;
            } else
                e+=inc2;
            x+=xinc;
            plotPoint(x, y);
        }
    } else {
        plotPoint(x, y);
    	e = 2 * dx - dy;
    	inc1 = 2 * (dx - dy);
    	inc2 = 2 * dx;
    	for (i = 0; i < dy; i++) {
            if (e >= 0)
        	{
            	x += xinc;
            	e += inc1;
        	}
        	else
            	e += inc2;
        	y += yinc;
            plotPoint(x, y);
        }
    }
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.0,1.0,1.0);
//  glPointSize(10.0);
 glBegin(GL_LINES);
  glVertex2i(-200,0);
  glVertex2i(199,0);
  glVertex2i(0,-200);
  glVertex2i(0,199);
 glEnd();
 glColor3f(1.0,1.0,0.0);
 Bresen(-70,-10,-50,90);//m>1 steep,+ve
 Bresen(-10,-70,90,-50);//m<1 gen +ve
 Bresen(-10,70,90,50);//m>-1 gen -ve
 Bresen(70,-10,50,90);//m<-1 steep -ve
 glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bresenham's Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
