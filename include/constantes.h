#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

//definition de toutes les constantes que l'on va utiliser durant le code ICI pas autre part !
#define TAILLE_GRILLE 6       // taille de la grille ici 6 par 6
#define NB_TUYAUX 6     //def ici le nb de tuyaux
#define DELAIS 5000        // (en ms) 5 secondes pour le debut ecoulement du fluide et apres la bombe

// Pour les vitesses on en a 2: celle de base et celle apres une decharge
// les 2 valeurs des define suivant seront a valider avec les tests pour voir si ca va trop vite / pas assez!
#define DELAI_CASE_NORMAL 2000   // (en ms) 2 secondes pour traverser une case
#define DELAI_CASE_RAPIDE 1000    // (en ms) apres une decharge

// defnition du nb de malus par rapport a la difficulte
// le nb de malus sont a ajuster eux aussi !
#define DIFF_FACILE 2
#define DIFF_MOYEN 4
#define DIFF_DUR 6


//enum sert a donner des noms lisibles a des nombres
//les valeurs d un enum se comportent comme des constantes, donc on les ecrit en MAJUSCULES
//on peut l'utiliser directement avec des mots que l'on comprend : 0 on ne sait pas mais HAUT c'est haut.
typedef enum {
    HAUT,       // ici haut vaut 0
    BAS,        // bas vaut 1
    GAUCHE,     // gauche vaut 2
    DROITE,      // droite vaut 3
    AUCUNE
}Direction;

typedef enum{
    VERTICAL,    //la case peut etre verticale
    HORIZONTAL,  //horizontale
    COUDE_HD,    //un coude du haut vers la droite
    COUDE_DB,    //un coude de la droite vers le bas
    COUDE_BG,    //un coude du bas vers la gauche
    COUDE_GH,    //un coude de la gauche vers le haut
    MALUS_B,     // le malus de la bombe
    MALUS_D     // le malus de la decharge
}Contenu;

static const Direction SORTIE[8][4] = {
   //si le fluide entre par: HAUT    BAS     GAUCHE   DROITE
    /* VERTICAL   */      { BAS,    HAUT,   AUCUNE,  AUCUNE },
    /* HORIZONTAL */      { AUCUNE, AUCUNE, DROITE, GAUCHE },
    /* COUDE_HD   */      { DROITE, AUCUNE, AUCUNE, HAUT },
    /* COUDE_DB   */      { AUCUNE, DROITE, AUCUNE, BAS },
    /* COUDE_BG   */      { AUCUNE, GAUCHE, BAS, AUCUNE },
    /* COUDE_GH   */      { GAUCHE, AUCUNE, HAUT, AUCUNE },
    /* MALUS_B    */      { BAS, HAUT, DROITE, GAUCHE },
    /* MALUS_D    */      { BAS, HAUT, DROITE, GAUCHE }
};

typedef enum {
    CACHEE,
    REVELEE,
    REMPLIE
} Etat;

typedef enum{
    EN_COURS,
    GAGNEE,
    PERDUE
}Partie;

typedef enum{
    B_Nouveau,
    B_Refaire,
    B_Terminer,
    B_Aucun
}Bouton;



#endif // CONSTANTES_H_INCLUDED

