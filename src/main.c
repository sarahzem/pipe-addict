/* main.c : initialise Allegro et boucle sur les événements du jeu */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include"constantes.h"
#include"structure.h"
#include"fonctions.h"
#define LARGEUR_FENETRE 1000
#define HAUTEUR_FENETRE 700
int main(void)
{
    Jeu jeu;
    int fin = 0;
    int a_redessiner = 1;

    /* 1. Initialisation d'Allegro */
        /* Démarrer Allegro */
    if (!al_init() || !al_init_primitives_addon() || !al_init_image_addon() || !al_install_mouse())
    {
        fprintf(stderr, "Erreur d'initialisation d'Allegro\n");
        return 1;
    }

    /* Créer la fenêtre, la file d'événements et les timers */
    ALLEGRO_DISPLAY *ecran = al_create_display(LARGEUR_FENETRE, HAUTEUR_FENETRE);
    ALLEGRO_EVENT_QUEUE *file = al_create_event_queue();
    ALLEGRO_TIMER *t_affichage = al_create_timer(1.0 / 60.0);
    ALLEGRO_TIMER *t_depart = al_create_timer(DELAIS / 1000.0);
    ALLEGRO_TIMER *t_fluide = al_create_timer(DELAI_CASE_NORMAL / 1000.0);

    if (!ecran || !file || !t_affichage || !t_depart || !t_fluide)
    {
        fprintf(stderr, "Erreur de création de la fenêtre, de la file ou des timers\n");
        return 1;
    }

    /* Brancher les sources d'événements sur la file */
    al_register_event_source(file, al_get_display_event_source(ecran));
    al_register_event_source(file, al_get_mouse_event_source());
    al_register_event_source(file, al_get_timer_event_source(t_affichage));
    al_register_event_source(file, al_get_timer_event_source(t_depart));
    al_register_event_source(file, al_get_timer_event_source(t_fluide));

    /* Lancer la partie */
    srand((unsigned int)time(NULL));
    nouvelle_partie(&jeu);

    al_start_timer(t_affichage);
    al_start_timer(t_depart);

    /* 2. Boucle événementielle */
        while (!fin)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(file, &ev);

        switch (ev.type)
        {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            fin = 1;
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (ev.mouse.button == 1)
            {
                Bouton b = bouton_sous_souris(ev.mouse.x, ev.mouse.y);
                gerer_clic(&jeu, ev.mouse.x, ev.mouse.y);

                if (b == B_Nouveau || b == B_Refaire)
                {
                    al_stop_timer(t_fluide);
                    al_stop_timer(t_depart);
                    al_set_timer_count(t_depart, 0);
                    al_start_timer(t_depart);
                }
            }
            break;

        case ALLEGRO_EVENT_TIMER:
            if (ev.timer.source == t_affichage)
            {
                a_redessiner = 1;
            }
            else if (ev.timer.source == t_depart)
            {
                al_stop_timer(t_depart);
                al_start_timer(t_fluide);
            }
            else if (ev.timer.source == t_fluide)
            {
                fluide(&jeu);
                if (jeu.partie != EN_COURS)
                {
                    al_stop_timer(t_fluide);
                }
            }
            break;
        }

        if (a_redessiner && al_is_event_queue_empty(file))
        {
            affichage(&jeu);
            al_flip_display();
            a_redessiner = 0;
        }
    }

    /* 3. Nettoyage */
        al_destroy_timer(t_affichage);
    al_destroy_timer(t_depart);
    al_destroy_timer(t_fluide);
    al_destroy_event_queue(file);
    al_destroy_display(ecran);

    return 0;
}
