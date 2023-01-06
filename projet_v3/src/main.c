#include "test.h"
#include "option.h"

char nom_music[12][100] = {"musique_projet/carefree.mp3", "musique_projet/fluffing-a-duck.mp3", "musique_projet/life-of-riley.mp3", 
                    "musique_projet/monkeys-spinning-monkeys.mp3", "musique_projet/pixel-peeker-polka-faster.mp3", 
                    "musique_projet/scheming-weasel-faster.mp3", "musique_projet/sneaky-snitch.mp3","musique_projet/spazzmatica-polka.mp3",
                    "musique_projet/wagon-wheel.mp3", "musique_projet/wallpaper.mp3", "musique_projet/who-likes-to-party.mp3"};


int main(int argc, char* argv[]){
    ConvexHull convex;
    Polygon poly;
    TabPoint tab_p;
    Option opt;

    poly = NULL;
    
    init_tab_point(&tab_p);
    init_ConvexHull(&convex, &poly);
    init_option(&opt);
    MLV_init_audio();
    MLV_Music* music = MLV_load_music(nom_music[MLV_get_random_integer(0, 11)]);
    
    choix_option(argc, argv, &opt);
    
    affiche_fenetre();
    
    MLV_play_music(music, 1.0, -1 );

    lance_algo(opt, convex, tab_p);    

    MLV_stop_music();
    MLV_free_music( music );
    MLV_free_audio();
    MLV_free_window();

    return 0;
}
