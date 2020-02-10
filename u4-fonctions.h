#ifndef _u4_fonctions_h
#define _u4_fonctions_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// d�claration des constantes pour la simulation

const double DUREE_CYCLE = 0.001;			// dur�e d'un cycle d'affichage
											// pour r�gler la vitesse d'affichage, il faut jouer sur le temps physique associ� � ce temps CPU (cf. TraiterCycleCB dans u3-callbacks.cpp)

const double Pi = M_PI;						// constante parfois utile (issue de cmath)
const double g = 9.81;            // constante physique ici indispensable (acc�l�ration de la pesanteur)
const double Gr = 6.67*1e-11;						// constante physique gravitationnelle
const double HauteurZone = 10;				// hauteur physique de la zone de dessin (en m�tres)


//Definiton des variables réduites (SANS DIMENSIONS)
const double VBas=103.6;  //vitesse sur l'orbite basse
const double VGeo=41.6;  //vitesse sur l'orbite géostationnaire
const double v1=135;   //vitesse nécessaire pour quitter l'orbite basse vers celle de transfert
const double v2=21.6;  //vitesse nécessaire pour arriver sur l'orbite géostationnaire depuis celle de transfert
const double Imp1=31;   //vitesse à donner pour atteindre orbite de transfert
const double Imp2=20;   //vitesse à donner pour atteindre orbite géostationnaire


//Définiton des rapports graphiques (PIXELS)
const double rTerre = 0.2;				// rayon (en m, DrawingScaleFactor = 100 pixels/m�tres => le rayon de Terre prend 20 pixels dans l'interface)
const double rSatellite = 0.05;

const double mTerre = 8;					// masse (en kg) : avec une densit� suppos�e ici commune aux deux boules (d'o� rayon x 2 => masse x 8)
const double mSatellite = 1;



// d�claration de la structure globale de donn�es gData (connue partout)
struct Data
{
  double x;		// abscisse (physique, en m) du centre de la boule
  double y;		// ordonn�e

  double vx;    // vitesse selon y (en m.s-1)
  double vy;		// vitesse selon y (en m.s-1)

	double t;			// temps physique (en s) de la simulation (de t=0 - valeur initiale - � une �ventuelle valeur maximale, non fix�e dans cette version minimaliste)

	bool Pause;			// pour faire une pause en cliquant sur un bouton (et reprendre la simu en cliquant � nouveau dessus)
	bool PropO2;
  bool PropO1;

};
extern struct Data gData;

// d�claration des m�thodes

void InitialiserData() ;
void Euler(double t0, double t1);


void DeplacerSatellite(double dt);


#endif
