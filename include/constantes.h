#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

// Toutes les constantes du projet sont definies ICI et nulle part ailleurs.
#define TAILLE_GRILLE 6        // grille de 6 par 6
#define NB_TUYAUX 6            // les 6 premieres valeurs de Contenu sont des tuyaux

// Delais (tous en millisecondes)
#define DELAI_DEBUT 5000       // attente avant le debut de l'ecoulement
#define DELAI_BOMBE 5000       // pause apres une bombe
#define DELAI_CASE_NORMAL 2000 // traversee d'une case (a ajuster en testant)
#define DELAI_CASE_RAPIDE 1000 // traversee d'une case apres une decharge

// Nombre de malus par niveau de difficulte (a ajuster)
#define DIFF_FACILE 2
#define DIFF_MOYEN 4
#define DIFF_DUR 6

// Positions en pixels (PROVISOIRES : a ajuster quand la bibliotheque graphique sera choisie)
#define GRILLE_X 200
#define GRILLE_Y 50
#define TAILLE_CASE 80

#define BTN_NOUVEAU_X 20
#define BTN_NOUVEAU_Y 150
#define BTN_REFAIRE_X 20
#define BTN_REFAIRE_Y 220
#define BTN_TERMINER_X 300
#define BTN_TERMINER_Y 550
#define BTN_LARGEUR 120
#define BTN_HAUTEUR 40

typedef enum {
    HAUT,
    BAS,
    GAUCHE,
    DROITE
} Direction;

// Les 6 tuyaux DOIVENT rester en premier (contenu < NB_TUYAUX => c'est un tuyau)
typedef enum {
    VERTICAL,
    HORIZONTAL,
    COUDE_HD,    // haut-droite
    COUDE_DB,    // droite-bas
    COUDE_BG,    // bas-gauche
    COUDE_GH,    // gauche-haut
    MALUS_B,     // bombe
    MALUS_D      // decharge
} Contenu;

typedef enum {
    CACHEE,
    REVELEE,
    REMPLIE
} Etat;

typedef enum {
    EN_COURS,
    GAGNEE,
    PERDUE
} Partie;

typedef enum {
    BOUTON_NOUVEAU,
    BOUTON_REFAIRE,
    BOUTON_TERMINER,
    BOUTON_AUCUN
} Bouton;

#endif // CONSTANTES_H_INCLUDED
