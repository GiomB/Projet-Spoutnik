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
    gData.x = RBas;
    gData.y = -RTerre;	// Satellite pos�e sur Terre � t = 0 (donc son ordonn�e est n�gative car l'axe y est orient� vers le bas dans FLTK)

    gData.vy = -VBas;
    gData.vx = 0;


	// initialisation des autres attributs de gData
    gData.t = 0;
    gData.Pause = false;
    gData.PropO1= false;
    gData.PropO2= false;
};



void Euler(double dt)        // calcule les nouvelles positions et vitesses à partir d'un pas dt
{

        double dpos[2]; //pour stocker vitesses actuelles
        double dvit[2]; //pour stocker accelerations actuelles

        // équations du mouvement : definition des dpos (dx/dt, dy/dt) et des dvit (dvx/dt, dvy/dt) à partir des pos et des vit

        dpos[0] = gData.vx; // vitesse en x
        dpos[1] = gData.vy; // vitesse en y


        // interaction avec la Terre
        double X_Sat = gData.x; //pos[0] - 0;                // abscisse du Satellite par rapport au Terre
        double Y_Sat = gData.y + RTerre; //pos[1] - 0;
        double Dist_Terre = sqrt(X_Sat*X_Sat+Y_Sat*Y_Sat);

        // dv/dt = force (signe - car dirigée du Satellite vers le Terre) / masse sonde
        dvit[0] += -(Gr/pow(Dist_Terre,2))*X_Sat;
        dvit[1] += -(Gr/pow(Dist_Terre,2))*Y_Sat;
        cout << dvit[0] << endl;
        //Calcul des nouvelles valeurs des positions et vitesses
        gData.x += dpos[0]*dt;
        gData.y += dpos[1]*dt;
        gData.vx += dvit[0]*dt;
        gData.vy += dvit[1]*dt;
}
