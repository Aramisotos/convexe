#include "algo.h"
#include "tab_point.h"

#ifndef __OPTION__
#define __OPTION__

typedef struct {
    int nb_point; /* le nombre de poitn que l'utilisateur veut */
    char type_option; /* savoir si l'on veut un affichage dynamique ou final */
    char forme; /* soit c pour carre ou r pour rond */
} Option;


/**
 * @brief fonction qui va déterminer les options de choix de l'utilisateur
 * 
 * @param argc 
 * @param argv 
 */
void choix_option(int argc, char* argv[]);


/**
 * @brief fonction qui va lancer l'algo demander par l'utilisateur
 * 
 * @param opt 
 * @param convex 
 * @param tab_p 
 */
void lance_algo(Option opt, ConvexHull convex, TabPoint tab_p);


/**
 * @brief fonction qui va initialiser la strcuture option 
 * 
 * @param opt 
 */
void init_option(Option* opt);

#endif
