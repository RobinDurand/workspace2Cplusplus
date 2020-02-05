/** \brief Ce fichier doit contenir l'ensemble des implémentations
 relatives à la classe vecteur et aux fonctionnalités la concernant */

#include <cassert>
#include <iostream>
#include "vecteur.h"

// constructeur:: precondition: dim>0
Vecteur::Vecteur(const unsigned int dimension, float valeurInit) :
		vTab(new float[dimension]), dim(dimension) {
	assert(dim > 0);
	for (unsigned int i = 0; i < dim; i++) {
		vTab[i] = valeurInit;
	}
	std::cout<<"Construction du Vecteur a "<<dim<<" dimension et initialise a "<<valeurInit<<std::endl;
}

void Vecteur::copierVecteur(const Vecteur & v){
	//Initialisation des attributs "non pointeurs"
	dim = (v.dimension());

	//Allocation de la memoire et initialisation du pointeur
	vTab = (new float[dim]);

	//Copie le contenu du Vecteur v dans la zone alloué
	for(unsigned int i = 0; i < dim; i++){
		vTab[i]= set(i,v.get(i));
	}
}
// return value at &position
// precondition : &position < dim
const float Vecteur::get(unsigned int & position) const {
	assert(position < dim);
	return vTab[position];
}

// change la valeur
// precondition : &position < dim
void Vecteur::set(unsigned int & position, float newValeur) {
	assert(position < dim);
	vTab[position] = newValeur;
}
// return value of Dimension
const unsigned int Vecteur::dimension() const {
	return dim;
}



// affiche un vecteur dans le flux de sortie out
void afficherVecteur(const Vecteur * v, std::ostream & out){
	for(unsigned int i = 0; i < v->dimension(); i++){
		out<<v->get(i)<<" "<<std::endl;
	}
}



//lit un vecteur dans le flux d'entree in
Vecteur * lireVecteur(std::istream & in){
	unsigned int dim;
	float value;
	std::cout<<"Entrez la dimension du vecteur : "<<std::endl;
	std::cin>>dim;
	Vecteur * v = new Vecteur(dim);
	for(unsigned int i = 0; i < dim; i++){

		std::cout<<"c"<<i<<" : "<<std::endl;
		std::cin>>value;
		v->set(i,value);
	}
	return v;
}

//additionner deux vecteurs
//Précondition : v1->dimension()== v2->dimension()
Vecteur add(const Vecteur * v1, const Vecteur * v2){
	assert(v1->dimension()== v2->dimension());
	Vecteur v(v1->dimension());
	for(unsigned int i = 0; i < v1->dimension(); i++){
		v.set(i, v1->get(i) + v2->get(i) );
	}
	return v;
}
