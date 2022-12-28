#include "convexe.h"
#include <MLV/MLV_all.h> 

#ifndef __GRAPH__
#define __GRAPH__

#define TAILLE_X 500
#define TAILLE_Y 500

/**
 * @brief fonction qui prend un clique de la souris et l'ajoute au tableaux de point
 * 
 * @param tab_p 
 */
void clique_souris(TabPoint* tab_p );


/**
 * @brief fonction qui affiche l'enveloppe convexe
 * 
 * @param tab_p 
 */
void affiche_convexe(ConvexHull* convex);


/**
 * @brief fonction qui affiche les points du tableaux
 * 
 * @param tab_p 
 */
void affiche_point(TabPoint* tab_p);

/**
 * @brief fonction qui appelle toutes les fonction d'affichage
 * 
 * @param convex 
 * @param tab_p 
 */
void affiche_all(ConvexHull* convex, TabPoint* tab_p);

/**
 * @brief fonction qui après un clique de souris le transforme
 * 
 * @param x 
 * @param y 
 */
void pixel_case(int *x, int *y);

#endif
