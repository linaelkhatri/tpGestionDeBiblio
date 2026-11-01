#pragma once
#include<iostream>
#include"Livre.h"
#include<string>
#include"Date.h"
using namespace std;
namespace Biblio {
	class Bibliotheque
	{
	private:
		string nom;
		Livre** livres;
		int nbBibliotheques;
		int capacite;
		int nbLivres;

	public:
		Bibliotheque(string nom, int capacite);
		Bibliotheque(const Bibliotheque& b);
		Bibliotheque operator=(const Bibliotheque&);
		~Bibliotheque();


		bool ajouterLivre(Livre* L);
		Bibliotheque operator+=(const Livre&);
		Livre* rechercherTitre(const string& titre) const;
		Livre* rechercherId(int id) const;

	};
}

