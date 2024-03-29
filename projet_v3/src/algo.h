 /**
 * @file algo.h
 * @author Marc POTTIER Yanis TWARDAWA
 * @brief header qui regroupe toute les fonction qui permette de faire tourner les different algo
 * @version 0.1
 * @date 2023-01-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
 #include "graph.h"

#ifndef __ALGO__
#define __ALGO__

/**
 * @brief fonction qui va lancer l'algo pour creer un enveloppe convexe à la main
 * 
 * @param convex 
 * @param tab_p 
 */
void convexe_souris(ConvexHull convex, TabPoint tab_p);

/**
 * @brief fonction qui va lancer l'algo pour réaliser une enveloppe convexe carre avec des points aléatoires
 * 
 * @param convex 
 * @param tab_p 
 */
void convexe_carre(ConvexHull convex, TabPoint tab_p, int dynamique, int nb_point);


/**
 * @brief fonction qui v alancer l'alog pour réaliser une enveloppe convexe en cercle avec des points aléatoire
 * 
 * @param convex 
 * @param tab_p 
 */
void convexe_cercle(ConvexHull convex, TabPoint tab_p, int dynamique, int nb_point);

#endif
