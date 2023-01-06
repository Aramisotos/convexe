#include <MLV/MLV_all.h> 
#include "tab_point.h"
#include "convexe.h"

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
void affiche_point(TabPoint tab_p, ConvexHull convex);

/**
 * @brief fonction qui affiche la fentre avec MLV
 * 
 * @param convex 
 * @param tab_p 
 */
void affiche_fenetre();

/**
 * @brief fonction qui vérifie sur un point est dans la liste convex pol 
 * 
 * @param p 
 * @param convex 
 * @return int 
 */
int est_dans_liste(Point p, ConvexHull convex);


#endif
