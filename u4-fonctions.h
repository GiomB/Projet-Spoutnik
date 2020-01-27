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

const double g = 9.81;						// constante physique ici indispensable (acc�l�ration de la pesanteur)

const double HauteurZone = 10;				// hauteur physique de la zone de dessin (en m�tres)

const double rBouleInf = 0.2;				// rayon (en m, DrawingScaleFactor = 100 pixels/m�tres => le rayon de BouleInf prend 20 pixels dans l'interface)
const double rBouleSup = 0.1;

const double mBouleInf = 8;					// masse (en kg) : avec une densit� suppos�e ici commune aux deux boules (d'o� rayon x 2 => masse x 8)
const double mBouleSup = 1;

const double InfSolCOR = 1.0;				// COR de la BouleInf sur le sol
											// le COR (Coefficient Of Restitution) d'une boule (ici sur le sol) est le rapport de la vitesse juste apr�s le rebond sur celle juste avant
											// COR = 1 : rebond �lastique, COR = 0 : rebond nul

const double SupInfCOR = 1.0;				// COR de la BouleSup sur la BouleInf

const double t_max = 30;					// dur�e max de la simu en s

// d�claration des structures du projet

// structure pratique pour y stocker toutes les caract�ristiques de chaque boule
struct boule
{
    double x;		// abscisse (physique, en m) du centre de la boule
    double y;		// ordonn�e

    double vy;		// vitesse selon y (en m.s-1)
    double ay;		// acc�l�ration selon y (en m.s-2)

    double m;		// masse de la boule (en kg)
};

// d�claration de la structure globale de donn�es gData (connue partout)
struct Data
{
	struct boule BouleSup;
    struct boule BouleInf;

	double t;			// temps physique (en s) de la simulation (de t=0 - valeur initiale - � une �ventuelle valeur maximale, non fix�e dans cette version minimaliste)

	bool Pause;			// pour faire une pause en cliquant sur un bouton (et reprendre la simu en cliquant � nouveau dessus)
	bool PropO2;
  bool PropO1;
  bool Pause;
};
extern struct Data gData;

// d�claration des m�thodes

void InitialiserData() ;

void DeplacerBouleInf(double dt);
void DeplacerBouleSup(double dt);

void RebondBouleInfSurSol();
void RebondBouleSupSurInf();

#endif
