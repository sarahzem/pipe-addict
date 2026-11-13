#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include "structure.h"
#include "constantes.h"
//on est pas obligé d'inclure constantes.h car il est inclut dans structure.h mais ça gène pas

// On creer des prototypes (pas des fonctions), les focntions sont definies dans des .c !
// ça annonce que des fonctions existe mais elle ne sont pas exprimées ici!
// prototype > ;
// fonctions > {}


//role: creer une nouvelle partie soit :
//      initialise une nouvelle grille 6x6 avec cases cachées, temps réinitialisé, entrée et sortie soit différents de la partie précédente
//paramètres : la structure Jeu en pointeur pour la modifiée réellement pas sur une copie!
//retour: rien
void nouvelle_partie(Jeu *jeu);


//role : refais la meme partie que précédement soit:
//      meme grille (utilise grille_copie)avec cases cachées, meme entrée et sortie, temps réinitialisé
//paramètres : la structure Jeu en pointeur pour la modifiée réellement pas sur une copie!
//retour: rien
void refaire_partie(Jeu *jeu);


//role: savoir quel boutons parmis les 4 (avec l'enum Nouveau, Refaire, Terminer, Aucun dans constantes.h)
//      il y a sous la souris (avec les coordonée où la souris à cliquée)
//paramètre: les coordonnées de la souris x et y
//retour: l'enum Bouton donc soit Nouveau, Refaire, Terminer, Aucun
Bouton bouton_sous_souris(int x, int y);


//role: Réagir au clic : révéler la case ou l’échanger avec la case swap
//paramètre: la structure Jeu en pointeur (meme explications), ligne (cliquée) de la grille et colonne (cliquée) de la grille
//retour: rien
void clic_case(Jeu *jeu, int ligne, int colonne);


//role: Si ya un bouton sous la souris on effectue son action sinon on ne fait rien
//      dans la fonction on appelle la fonction bouton_sous_souris
//paramètre: la structure Jeu en pointeur (meme explications), la positions du clic de la souris (qui va aller dans la fonction bouton_sosu_souris)
//retour: rien
void gerer_clic(Jeu *jeu, int x, int y);


int fluide(/* a remplir par Anissa ou Sarah*/);
int affichage(/* a remplir par Anissa ou Sarah*/);

#endif // FONCTIONS_H_INCLUDED
