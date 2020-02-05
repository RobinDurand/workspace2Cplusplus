/** \brief Ce fichier doit contenir la déclaration de la classe vecteur
    Attention, elle ne doit contenir aucune implémentation de méthode / fonction
*/

#ifndef _VECTEUR_H
#define _VECTEUR_H
#include <iostream>

// Déclaration de la classe vecteur
class Vecteur {
private :
	// attributs
	float*const vTab;
	const unsigned int dim;

public :
	// prototypes des constructeurs et autres méthodes publiques
	//Constructeur
	Vecteur(const unsigned int dimension = 3, float valeurInit = 0.0 );
	Vecteur(const Vecteur & v); //TODO

	//méthodes public
	const float get(unsigned int & position)const;
	void set(unsigned int & position, float newValeur);
	const unsigned int dimension()const;

	//constructeur de copie
	void copierVecteur(const Vecteur & v);

private :
	// méthodes privées d'implémentation (si besoin)

};

// Prototypes des fonctions

// affiche un vecteur dans le flux de sortie out
void afficherVecteur(const Vecteur * v, std::ostream & out = std::cout);

//lit un vecteur dans le flux d'entree in
Vecteur * lireVecteur(std::istream & in = std::cin);

//additionner deux vecteurs
Vecteur add(const Vecteur * v1, const Vecteur * v2);




#endif
