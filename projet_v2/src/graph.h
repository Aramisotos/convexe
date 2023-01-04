#include "tab_point.h"
#include "algo.h"
#include <MLV/MLV_all.h> 

#ifndef __GRAPH__
#define __GRAPH__



/**
 * @brief fonction qui affiche l'enveloppe convexe
 * 
 * @param tab_p 
 */
void affiche_convexe(ConvexHull convex);


/**
 * @brief fonction qui affiche les points du tableaux
 * 
 * @param tab_p 
 */
void affiche_point(TabPoint tab_p);

/**
 * @brief fonction qui affiche la fentre avec MLV
 * 
 * @param convex 
 * @param tab_p 
 */
void affiche_fenetre();

#endif
