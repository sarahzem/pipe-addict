#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#include "constantes.h" // on va utiliser des fonctions/ des cste definies dans constante.h donc on l'inclu !

typedef struct {
    Contenu contenu;      // on nomme Contenu contenu pour l'utiliser
    Etat etat;            // pareil on nomme Etat etat pour l'utiliser
    // pour savoir si la case est bloquée on se base dans le main de si elle est remplie ou non
} Case;

typedef struct{
    //on creer des tableaux de type Case c'est a dire que dans CHAQUE cellules du tableau on a la structure Case (soit son contenu et son etat)
    Case grille[TAILLE_GRILLE][TAILLE_GRILLE]; //créer un tableau 6 lignes x 6 colonnes car TAILLE_GRILLE = 6 dans constante.h
    Case grille_copie[TAILLE_GRILLE][TAILLE_GRILLE];//creer tableau meme dimensions que grille pour le copier apres dans "nouvelle partie" (pour le rejouer car on doit avoir les memes départ)
    // on creer une variable de type Case, elle va avoir les attributs de Case (Contenu et Etat)
    Case swapp;                 // on creer un type Case (meme principe qu'au dessus mais ce n'est pas un tableau)
    int entree;                 // initialise la ligne de l'entrée de 0 à 5 (aléatoire)
    int sortie;                 // initialise la ligne de la sortie de 0 à 5 (aléatoire)
    Partie partie;              // on nomme Partie partie pour l'utiliser
}Jeu;



#endif // STRUCTURE_H_INCLUDED
