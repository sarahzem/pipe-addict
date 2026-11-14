#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#include "constantes.h"

typedef struct {
    Contenu contenu;
    Etat etat;
    // une case est bloquee quand etat == REMPLIE
} Case;

typedef struct {
    Case grille[TAILLE_GRILLE][TAILLE_GRILLE];
    Case grille_copie[TAILLE_GRILLE][TAILLE_GRILLE]; // sauvegarde pour refaire_partie
    Case swapp;
    Case swapp_copie;     // sauvegarde de la case swap de depart
    int entree;           // ligne de l'entree (0 a 5)
    int sortie;           // ligne de la sortie (0 a 5)
    Partie partie;        // EN_COURS, GAGNEE ou PERDUE
    int chrono;           // PLACEHOLDER : a definir avec le coequipier du fluide
    // TODO : champs du fluide (position, direction, vitesse, pause bombe)
} Jeu;

#endif // STRUCTURE_H_INCLUDED
