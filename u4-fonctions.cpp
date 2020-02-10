#include "u1-interface.h"
#include "u4-fonctions.h"

using namespace std;

// rappel du type de la structure globale gData (d�clar�e dans u4-fonctions.h)
struct Data gData;

// initialisation de gData
void InitialiserData()
{
	// Terre au centre du rep�re (lui-meme au centre de ZoneDessin) : déjà placé

    //initialisation Satellite

    gData.x = 0.25;
    gData.y = 0 - rTerre;	// Satellite pos�e sur Terre � t = 0 (donc son ordonn�e est n�gative car l'axe y est orient� vers le bas dans FLTK)

    gData.vy = 0;
    gData.vx = 0;

	// initialisation des autres attributs de gData

    gData.t = 0;

	gData.Pause = false;
	gData.PropO1= false;
};

void DeplacerSatellite(double dt) //(à enlever pourfaire marcher interface)
{
  gData.Satellite.vy 	= gData.Satellite.vy + gData.Satellite.ay*dt;
  gData.y 	= gData.y + gData.Satellite.vy*dt;
}



void Euler(double *pos, double *vit, double t0, double t1)        // calcule les nouvelles positions et vitesses à t1 à partir de t0
{
        double dt=t1-t0;

        double dpos[2]; //nouvelles vitesses
        double dvit[2]; //nouvelles accelerations

        // équations du mouvement : definition des dpos (dx/dt, dy/dt) et des dvit (dvx/dt, dvy/dt) à partir des pos et des vit

        dpos[0] = vit[0];        // dx/dt = vx
        dpos[1] = vit[1];

        dvit[0] = 0;                // dvx/dt = force (signe - car dirigée du Satellite vers le Terre) / masse sonde
        dvit[1] = 0;

        // interaction avec la Terre
        double X_Sat = pos[0] - 0;                // abscisse du Satellite par rapport au Terre
        double Y_Sat = pos[1] - 0;
        double Dist_Terre = sqrt(X_Sat*X_Sat+Y_Sat*Y_Sat);

        // dv/dt = force (signe - car dirigée du Satellite vers le Terre) / masse sonde
        dvit[0] += -(Gr*mTerre/pow(Dist_Terre,3))*X_Sat;
        dvit[1] += -(Gr*mTerre/pow(Dist_Terre,3))*Y_Sat;

}
