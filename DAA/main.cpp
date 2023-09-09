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
void DDA(float x1, float y1, float x2, float y2) {
    float dx = x2-x1;
    float dy = y2-y1;
    float x = x1;
    float y = y1;
    int i = 0;

    float xinc, yinc, len;
    if(abs(dx) > abs(dy)) {
        len = abs(dx);
    } else {
        len = abs(dy);
    }
    printf("length = %f\n",len);
    xinc = dx/len;
    yinc = dy/len;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    while(i <= len) {
        plotPoint(x, y);
        printf("%f %f\n",x,y);
        x += xinc;
        y += yinc;
        i++;
    }
}
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,0.0,0.0);
//  glPointSize(10.0);
 glBegin(GL_LINES);
  glVertex2i(-200,0);
  glVertex2i(199,0);
  glVertex2i(0,-200);
  glVertex2i(0,199);
 glEnd();
 glColor3f(0.0,0.0,1.0);
 DDA(-10,-70,90,-50);
 DDA(-70,-10,-50,90);
 DDA(-10,70,90,50);
 DDA(70,-10,50,90);
 glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("DDA");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
