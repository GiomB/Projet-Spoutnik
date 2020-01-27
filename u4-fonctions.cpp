#include "u1-interface.h"
#include "u4-fonctions.h"

using namespace std;

// rappel du type de la structure globale gData (d�clar�e dans u4-fonctions.h)
struct Data gData;

// initialisation de gData
void InitialiserData()
{
    //initialisation BouleInf

  	gData.BouleInf.x = 0;	// BouleInf au centre du rep�re (lui-meme au centre de ZoneDessin)
    gData.BouleInf.y = 0;

    gData.BouleInf.vy = 0;
    gData.BouleInf.ay = g;	// boule immobile si "= 0" (=> on peut faire commencer la chute en imposant "= g" via une m�thode (appel�e "CallBackStart" par exemple) � d�finir dans u3

    gData.BouleInf.m = mBouleInf;

    //initialisation BouleSup

    gData.BouleSup.x = 0;
    gData.BouleSup.y = gData.BouleInf.y - rBouleInf - rBouleSup;	// BouleSup pos�e sur BouleInf � t = 0 (donc son ordonn�e est n�gative car l'axe y est orient� vers le bas dans FLTK)

    gData.BouleSup.vy = 0;
    gData.BouleSup.ay = g;

    gData.BouleSup.m = mBouleSup;

	// initialisation des autres attributs de gData

    gData.t = 0;

	gData.Pause = false;
	gData.PropO1= false;
};

void DeplacerBouleSup(double dt)
{
    gData.BouleSup.vy 	= gData.BouleSup.vy + gData.BouleSup.ay*dt;
    gData.BouleSup.y 	= gData.BouleSup.y + gData.BouleSup.vy*dt;
}

void DeplacerBouleInf(double dt)
{

    gData.BouleInf.vy 	= gData.BouleInf.vy + gData.BouleInf.ay*dt;
    gData.BouleInf.y 	= gData.BouleInf.y + gData.BouleInf.vy*dt;
}

void RebondBouleInfSurSol()
{
    if(gData.BouleInf.y >= 0.5*HauteurZone - rBouleInf)
    {
    	gData.BouleInf.y 	= 0.5*HauteurZone - rBouleInf;
    	gData.BouleInf.vy 	= -InfSolCOR*gData.BouleInf.vy;
    }
}

void RebondBouleSupSurInf()
{
    if(gData.BouleSup.y + rBouleSup >= gData.BouleInf.y - rBouleInf)
    {
		double vInf	= gData.BouleInf.vy;
		double vSup	= gData.BouleSup.vy;

        gData.BouleInf.vy = (gData.BouleInf.m*vInf+gData.BouleSup.m*vSup+gData.BouleSup.m*SupInfCOR*(vSup-vInf))/(gData.BouleInf.m+gData.BouleSup.m);
 		gData.BouleSup.vy = (gData.BouleInf.m*vInf+gData.BouleSup.m*vSup+gData.BouleInf.m*SupInfCOR*(vInf-vSup))/(gData.BouleInf.m+gData.BouleSup.m);
    }
}

// calcule les nouvelles positions et vitesses à t1 à partir de t0

void Euler(double *pos, double *vit, double t0, double t1){        
        double dt=t1-t0;
       
        double dpos[2];
        double dvit[2];
       
        // équations du mouvement : definition des dpos (dx/dt, dy/dt) et des dvit (dvx/dt, dvy/dt) à partir des pos et des vit

        dpos[0] = vit[0];        // dx/dt = vx
        dpos[1] = vit[1];
                       
        dvit[0] = 0;             // dvx/dt = force (signe - car dirigée du satellite vers le Terre) / masse sonde
        dvit[1] = 0;
       
        // interaction avec la Terre
	
        double X_Terre = pos[0] - gData.Terre.X;                // abscisse du satellite par rapport au Terre
        double Y_Terre = pos[1] - gData.Terre.Y;
        double Dist_Terre = sqrt(X_Terre*X_Terre+Y_Terre*Y_Terre);
       
        // dv/dt = force (signe - car dirigée du satellite vers le Terre) / masse sonde
        dvit[0] += -(Gred*gData.Terre.Masse/pow(Dist_Terre,3))*X_Terre;       
        dvit[1] += -(Gred*gData.Terre.Masse/pow(Dist_Terre,3))*Y_Terre;
       
        // méthode d'Euler stricto sensu : mise à jour des pos et vit
	//à compléter : il ne reste en fait que l'intégration, très simple, à faire
