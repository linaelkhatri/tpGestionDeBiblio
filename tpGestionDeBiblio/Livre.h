#pragma once
#include<string>
#include "Date.h"
#include<iostream>
using namespace std;
class Livre
{
private:
	const int id;
	string titre;
	string auteur;
	Date parution;
	double* notes;
	int nbNotes;
	bool disponible;
	static int compteurId;
	static int nombreLivres;
	int nbInstances;
public:
   
    Livre(const string& titre, const string& auteur, const Date& parution);
    Livre(int, string, string, Date, int*);
    Livre(const Livre&);
    Livre operator=(const Livre&);
    ~Livre();
    bool ajouterNote(double note);
    double calculerMoyenne() const;
    void afficher() const;
    int getId() const;
    string getTitre() const;
    static int getNombreLivres();
	


};




   

    






