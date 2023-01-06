/**
 * @file option.h
 * @author Marc POTTIER Yanis TWARDAWA
 * @brief header qui regroupe toute les fonction permettant de gerer les differente option
 * @version 0.1
 * @date 2023-01-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "algo.h"

#ifndef __OPTION__
#define __OPTION__

typedef struct {
    int nb_point; /* le nombre de poitn que l'utilisateur veut */
    int dynamique; /* savoir si l'on veut un affichage dynamique ou final */
    char forme; /* soit c pour carre ou r pour rond ou m pour la souris*/
} Option;


/**
 * @brief fonction qui va déterminer les options de choix de l'utilisateur
 * 
 * @param argc 
 * @param argv 
 */
void choix_option(int nb_arg, char* option[], Option* opt);


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
