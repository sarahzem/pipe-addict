//fonction qui renvoie un entier au hasard entre min et max inclus avec rand

int alea(int min, int max){

    int nombre = (rand()%(max - min + 1))+ min;

    return nombre;
    }
