#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include "structure.h"
#include "constantes.h"
//on est pas oblige d'inclure constantes.h car il est inclut dans structure.h mais ca gene pas

// On creer des prototypes (pas des fonctions), les focntions sont definies dans des .c !
// Ca annonce que des fonctions existe mais elle ne sont pas exprimees ici!
// prototype > ;
// fonctions > {}


//role: creer une nouvelle partie soit :
//      initialise une nouvelle grille 6x6 avec cases cachees, temps reinitialise, entree et sortie soit differents de la partie pr�c�dente
//parametres : la structure Jeu en pointeur pour la modifiee reellement pas sur une copie!
//retour: rien
void nouvelle_partie(Jeu *jeu);


//role : refais la meme partie que precedement soit:
//      meme grille (utilise grille_copie)avec cases cachees, meme entree et sortie, temps reinitialise
//parametres : la structure Jeu en pointeur pour la modifiee reellement pas sur une copie!
//retour: rien
void refaire_partie(Jeu *jeu);


//role: savoir quel boutons parmis les 4 (avec l'enum Nouveau, Refaire, Terminer, Aucun dans constantes.h)
//      il y a sous la souris (avec les coordonee ou la souris a cliquee)
//parametre: les coordonnees de la souris x et y
//retour: l'enum Bouton donc soit Nouveau, Refaire, Terminer, Aucun
Bouton bouton_sous_souris(int x, int y);


//role: Reagir au clic : reveler la case ou l echanger avec la case swap
//parametre: la structure Jeu en pointeur (meme explications), ligne (cliquee) de la grille et colonne (cliquee) de la grille
//retour: rien
void clic_case(Jeu *jeu, int ligne, int colonne);


//role: Si ya un bouton sous la souris on effectue son action sinon on ne fait rien
//      dans la fonction on appelle la fonction bouton_sous_souris
//parametre: la structure Jeu en pointeur (meme explications), la positions du clic de la souris (qui va aller dans la fonction bouton_sosu_souris)
//retour: rien
void gerer_clic(Jeu *jeu, int x, int y);

// Renvoie le cote par lequel le fluide ressort, ou AUCUNE (cul-de-sac)
Direction cote_sortie(Contenu contenu, Direction entree);

int fluide(/* a remplir par Anissa ou Sarah*/);
int affichage(/* a remplir par Anissa ou Sarah*/);

#endif // FONCTIONS_H_INCLUDED
