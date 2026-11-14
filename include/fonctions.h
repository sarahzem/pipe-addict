#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include "structure.h"
#include "constantes.h"

// Les prototypes annoncent les fonctions ; leur code est dans les .c

// role : cree une nouvelle partie (grille aleatoire masquee, nouveaux entree/sortie,
//        sauvegarde de la situation de depart)
// parametre : jeu (pointeur pour modifier le vrai jeu)
// retour : rien
void nouvelle_partie(Jeu *jeu);

// role : recommence la meme partie (grille_copie, memes entree/sortie)
// parametre : jeu (pointeur)
// retour : rien
void refaire_partie(Jeu *jeu);

// role : dit quel bouton est sous la souris
// parametres : x, y = position du clic
// retour : BOUTON_NOUVEAU, BOUTON_REFAIRE, BOUTON_TERMINER ou BOUTON_AUCUN
Bouton bouton_sous_souris(int x, int y);

// role : reagit au clic sur une case (reveler, ou echanger avec la case swap)
// parametres : jeu (pointeur), ligne et colonne de la case cliquee
// retour : rien
void clic_case(Jeu *jeu, int ligne, int colonne);

// role : traite un clic : bouton ou case de la grille
// parametres : jeu (pointeur), x, y = position du clic
// retour : rien
void gerer_clic(Jeu *jeu, int x, int y);

// role : termine instantanement l'ecoulement du fluide (fonction du coequipier fluide)
void terminer_fluide(Jeu *jeu);

#endif // FONCTIONS_H_INCLUDED
