#include "../includes/object/house.h"


// dessine la base de la maison
static void draw_base() {
    // dessine de la face bas
    glBegin(GL_QUADS);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3f(-1, 0, 1);
        glVertex3f(1, 0, 1);
        glVertex3f(1, 0, -1);
        glVertex3f(-1, 0, -1);

        // dessine face avant
        glColor3f(0.8, 0.8, 0.8);
        glVertex3f(-1, 0, 1);
        glVertex3f(1, 0, 1);
        glVertex3f(1, 2, 1);
        glVertex3f(-1, 2, 1);

        // dessine face arriere
        glColor3f(0.8, 0.8, 0.8);
        glVertex3f(-1, 0, -1);
        glVertex3f(1, 0, -1);
        glVertex3f(1, 2, -1);
        glVertex3f(-1, 2, -1);

        // dessine face droite rouge
        glColor3f(1, 0, 0);
        glVertex3f(1, 0, -1);
        glVertex3f(1, 0, 1);
        glVertex3f(1, 2, 1);
        glVertex3f(1, 2, -1);

        // dessine face gauche verte
        glColor3f(0, 1, 0);
        glVertex3f(-1, 0, -1);
        glVertex3f(-1, 0, 1);
        glVertex3f(-1, 2, 1);
        glVertex3f(-1, 2, -1);
    glEnd();
}

// dessine le toit de la maison
static void draw_roof() {
    // triangle face avant vert/bleu
    glBegin(GL_TRIANGLES);
        glColor3f(0, 0.5, 0.5);
        glVertex3f(1, 2, 1);
        glVertex3f(-1, 2, 1);
        glVertex3f(0, 4, 1);
    glEnd();
    
    // triangle face arriere
    glBegin(GL_TRIANGLES);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(1, 2, -1);
        glVertex3f(-1, 2, -1);
        glVertex3f(0, 4, -1);
    glEnd();

     // dessine face gauche
    glBegin(GL_QUADS);
        glColor3f(0, 0.25, 1);
        glVertex3f(0, 4, -1);
        glVertex3f(0, 4, 1);
        glVertex3f(-1, 2, 1);
        glVertex3f(-1, 2, -1);
    glEnd();

    // dessine face droite
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.25, 1);
        glVertex3f(0, 4, -1);
        glVertex3f(0, 4, 1);
        glVertex3f(1, 2, 1);
        glVertex3f(1, 2, -1);
    glEnd();
}



void draw_house() {
  draw_base();
  draw_roof();
}