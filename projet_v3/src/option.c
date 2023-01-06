#include "option.h"

void init_option(Option* opt){
    /*
    on initialise les champ ou cas ou une option peut manquer ou alors l'utilisateur ne donne rien 
    le programme pourat s'éxécuter tout de même 
    */
    opt->dynamique = 0;
    opt->nb_point = 1000;
    opt->forme = 'm'; 
}


void lance_algo(Option opt, ConvexHull convex, TabPoint tab_p){
    switch (opt.forme){

    case 'm': convexe_souris(convex, tab_p); break;
    
    case 'r': convexe_cercle(convex, tab_p, opt.dynamique, opt.nb_point); break;
    
    case 'c': convexe_carre(convex, tab_p, opt.dynamique, opt.nb_point); break;
    
    default :convexe_souris(convex, tab_p); break;
    }
}


void choix_option(int nb_arg, char* option[], Option* opt){
        for(int i = 1; i < nb_arg; i++){
            if(option[i][0] == '-'){
                if(option[i][1] == 'r'){
                    opt->forme = 'r';
                    if(option[i+1] != NULL){ opt->nb_point = atoi(option[i+1]); }
                }

                if(option[i][1] == 'c'){
                    opt->forme = 'c';
                    if(option[i+1] != NULL){ opt->nb_point = atoi(option[i+1]); }
                }
                if(option[i][1] == 'd'){
                    opt->dynamique = 1;
                }
            }
        }
}
