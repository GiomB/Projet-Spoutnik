#ifndef _u1_interface_h
#define _u1_interface_h

#include "main.h"

#include <iostream>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.H>

// déclaration des constantes de l'interface graphique

// dimensions de Fenetre (la fenetre principale)

const int L_FENETRE = 1200;	// Largeur en pixels de Fenetre
const int H_FENETRE = 1050;	// Hauteur en pixels de Fenetre

// positions et dimensions (en pixels) de ZoneDessin dans Fenetre
// cf. orientation (X,Y) de Fenetre dans la doc FLTK : (0,0) tout en haut et � gauche de la Fenetre => X augmente vers la droite et Y augmente vers le bas
const int X_ZONE = 180;		// Position X (Xmin) de ZoneDessin dans Fenetre, en pixels
const int Y_ZONE = 20;      	// Position Y (Ymin) de ZoneDessin dans Fenetre, en pixels
const int L_ZONE = 1000;    	// Largeur en pixels de ZoneDessin qu'on choisit d'associer � une longueur d'1 m dans la r�alit�, d'o� DrawingScaleFactor (entre dessin et r�alit�) = 100 pixels/m�tre
const int H_ZONE = 850;    	// Hauteur en pixels de ZoneDessin (correspondant � 4 m dans la r�alit� d'apr�s le choix fait ci-dessus)

const double RTerre=1;
const double RBas = 1.063;
const double RGeo = 6.63;

// d�claration de la structure globale gInterface : connue partout (comme gData), pour g�rer la grande Fenetre et la petite ZoneDessin
struct Interface
{
    Fl_Double_Window*   Fenetre ;
    DrawingArea*        ZoneDessin ;

    Fl_Button*          BoutonExit;
    Fl_Button*          BoutonPropO1;
    Fl_Button*          BoutonPropO2;
    Fl_Button*		      BoutonPause;

    Fl_Box*             BackBox;
    Fl_JPEG_Image*      BackImage;
};
extern struct Interface gInterface ;

// d�claration des m�thodes (une seule ici)

void CreerInterface();

#endif
