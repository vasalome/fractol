#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

/*
27/06/04 - Didier STRAUS - La fougere de Barnsley
http://www.Software-DS.com

Fonctionne sous Linux
Compilation : (Fonctionne sur MacOSX si vous avez installe X11)
gcc -o Fougere Fougere.c -L/usr/X11R6/lib -lX11
*/

/* prototypes */
void contact_serveur();
void Creat_fenetre(void);
void gerer_evenement();
void fougere(int n);

/* variables globales */
GC gc;
Display *display;
int screen;
Window win,root;
int win_larg,win_haut;
unsigned long white_pixel, black_pixel;

/* ******************************************************************** */

void contact_serveur() {
 if ((display = XOpenDisplay("")) == NULL) {
  fprintf(stderr, "Can't open Display\n");
  exit(1);
 }
} /* contact_serveur */

/* ******************************************************************** */

void Creat_fenetre(void) {
 short border_width;

 screen=DefaultScreen(display);
 root=RootWindow(display,screen);

 white_pixel=WhitePixel(display,screen);
 black_pixel=BlackPixel(display,screen);

 border_width=3;
 win_larg=740; /* dimension de la fenetre */
 win_haut=330;

 win=XCreateSimpleWindow(display,root,0,0,win_larg,win_haut,border_width,black_pixel,white_pixel);
 gc=DefaultGC(display,screen);

 XStoreName(display,win,"Fougere Barnsley - DS");

 XMapWindow(display,win);
} /* Creat_fenetre */

/* ******************************************************************** */

void gerer_evenement() {
 char *str1="http://www.Software-DS.com";
 int i,a,b,c,d;

 XSelectInput(display,win,ExposureMask | KeyPressMask);

 for(;;) {
  XEvent ev;
  XNextEvent(display,&ev);

  switch(ev.type) {
   case Expose :
    /* on dessine la fougere de Barnsley */
    fougere(45000); /* La fougere sera compose de 45000 points */

    break;

    case KeyPress : /* on appuie sur une touche pour quitter */
     XClearWindow(display,win);
     XDrawString(display,win,gc,win_larg/5,win_haut*2/5,str1,strlen(str1));
     XFlush(display);
     sleep(3); /* petite pause avant de fermer */
     XDestroyWindow(display,win);
     XCloseDisplay(display);
     exit(0);
     break;

     default :
      fprintf(stderr,"J'ai recu un evt : %d\n",ev.type);
      break;
  } /* switch */
 } /* for */
} /* gerer_evenement */


/* ******************************************************************** */

void fougere(int n) {
 int k;
 int r;
 float p[2]={50,0};

 for(k=1;k<n;k++) {
  r=rand()%100;
    
  if (r<2) {
   p[0]=50;
   p[1]=0.27*p[1];
  }
  else if (r<17) {
   p[0]=-0.139*p[0]+0.263*p[1]+57;
   p[1]=0.246*p[0]+0.224*p[1]-8.28;
  }
  else if (r<30) {
   p[0]=0.17*p[0]-0.215*p[1]+40.8;
   p[1]=0.222*p[0]+0.176*p[1]+20.539;
  }
  else {
   p[0]=0.781*p[0]+0.034*p[1]+10.75;
   p[1]=-0.032*p[0]+0.739*p[1]+62.1;
  }

  XDrawPoint(display,win,gc, 3*(235-p[1]), 3*(p[0]-5)+10);
 }

} /* fougere */


/* ******************************************************************** */

int main() {
 contact_serveur();
 Creat_fenetre();
 gerer_evenement();

 return 0;
}