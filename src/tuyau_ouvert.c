//Un 0 indique que le côté du tuyau est fermé, un 1 qu'il est ouvert
//on crée un tableau contenant des Nb_tuyaux de chaque forme
int tuyau_ouvert(int piece, int direction){
    Tuyau tuyaux[Nb_tuyaux]{
    {0,1,0,1},//tuyau dont le haut et le bas sont fermés, à l'horizontal
    {1,0,1,0},//tuyau dont la gauche et la droite sont fermées, à la verticale
    {1,1,0,0}, //tuyau dont le bas et la gauche sont fermés : coude haut-droite
    {0,1,1,0}, //tuyau don droite et le bas sont fermés : coude droite-bas
    {0,0,1,1}, //tuyau dont le bas et la gauche sont fermés : coude bas-gauche
    {1,0,0,1} //tuyau dont la haut et la gauche sont fermés : coude haut-droite
    };
    if(piece<0||pièce>Nb_tuyau){//on vérifie que le numéro de la piece est conforme
        return 0;
    }

    //on regarde si par rapport à la structure le côté concerné est ouvert ou fermé
    switch(direction){ //On utilise switch pour "lister" les directions d'un tuyau
    case haut: //pour la surface haute du tuyau
    return tuyaux[piece].haut; //On va chercher si elle vaut 0(fermée) ou 1(ouverta)
    //et ainsi de suite pour chaque surface
    case bas:
    return tuyaux[piece].bas;
    case gauche:
    return tuyaux[piece].gauche;
    case droite:
    return tuyaux[piece].gauche;
    //pas besoin de brak vu que dans chaque cas on sort de la fonction de toutes façons
    }
}
