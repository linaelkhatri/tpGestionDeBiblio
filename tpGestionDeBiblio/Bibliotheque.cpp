#include "Bibliotheque.h"
#include<iostream>
#include"Livre.h"
#include"Date.h"
using namespace std;
namespace Biblio {

	Bibliotheque::Bibliotheque(string nom, int capacite)
	{
		this->nom = nom;
		this->capacite = capacite;
		this->nbLivres = 0;
		if (capacite < 1)
			capacite = 1;

		livres = new Livre * [capacite];

		for (int i = 0; i < capacite; i++)
			livres[i] = nullptr;

	}

	Bibliotheque::Bibliotheque(const Bibliotheque& b)
	{
	}

	Bibliotheque Bibliotheque::operator=(const Bibliotheque&)
	{
	}

	Bibliotheque::~Bibliotheque()
	{
		for (int i = 0; i < nbLivres; i++)
			delete livres[i];

		delete[] livres;
	}

	bool Bibliotheque::ajouterLivre(Livre* L)
	{
		if (L == nullptr)
			return false;

		if (nbLivres >= capacite) {
			std::cout << "Capacite maximale atteinte !" << std::endl;
			return false;
		}

		livres[nbLivres] = L;
		nbLivres++;

		return true;
	}

	Bibliotheque Bibliotheque::operator+=(const Livre&)
	{
	}

	Livre* Bibliotheque::rechercherTitre(const string& titre) const
	{
		for (int i = 0; i < nbLivres; i++) {
			if (livres[i]->getTitre() == titre)
				return livres[i];
			return nullptr;
		}

		Livre* Bibliotheque::rechercherId(int id) const {
			for (int i = 0; i < nbLivres; i++) {
				if (livres[i]->getId() == id)
					return livres[i];
			}

			return nullptr;
		}
	}

