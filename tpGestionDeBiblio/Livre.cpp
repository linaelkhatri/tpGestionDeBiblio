#pragma once
#include "Livre.h"
#include<iostream>
#include"Date.h"
using namespace std;
int Livre::compteurId = 0;
int Livre::nombreLivres = 0;

Livre::Livre(int i, string t, string a, Date d, int* n):id(compteurId + 1)
{
    this->titre = t;
    this->auteur = a;
    this->parution = d;
    this->notes = new double[20];
    compteurId++;

}

Livre::Livre(const Livre& L):id(compteurId +1)
{
    this->titre= L.titre;
    this->auteur = L.auteur;
    this->parution = L.parution;
    if (nbNotes > 0) {
       this->notes = new double[nbNotes];

        for (int i = 0; i < nbNotes; i++)
            notes[i] = L.notes[i];
    }

    nombreLivres++;
}

 Livre Livre::operator=(const Livre & L) {
        if (this != &L) {
            titre = L.titre;
            auteur = L.auteur;
            parution = L.parution;

            double* nouveau = nullptr;

            if (L.nbNotes > 0) {
                nouveau = new double[L.nbNotes];

                for (int i = 0; i < L.nbNotes; i++)
                    nouveau[i] = L.notes[i];
            }

            delete[] notes;
            notes = nouveau;
            nbNotes = L.nbNotes;
        }

        return *this;
    }



Livre::~Livre()
{
    delete[] notes;
    nombreLivres--;
}

bool Livre::ajouterNote(double note)
{
    if (note < 0 || note > 20) {
        std::cout << "Note invalide !" << std::endl;
        return false;
    }

    double* nouveau = new double[nbNotes + 1];

    for (int i = 0; i < nbNotes; i++)
        nouveau[i] = notes[i];

    nouveau[nbNotes] = note;

    delete[] notes;
    notes = nouveau;
    nbNotes++;

    return true;
}

double Livre::calculerMoyenne() const
{
    if (nbNotes == 0)
        return 0;

    double somme = 0;

    for (int i = 0; i < nbNotes; i++)
        somme += notes[i];

    return somme / nbNotes;

}

void Livre::afficher() const {
    std::cout << "ID : " << this->id << std::endl;
    std::cout << "Titre : " << this->titre << std::endl;
    std::cout << "Auteur : " << this->auteur << std::endl;

    std::cout << "Date de parution : ";
    parution.afficher();
    std::cout << std::endl;

    std::cout << "Notes : ";

    for (int i = 0; i < nbNotes; i++)
        std::cout << notes[i] << " ";

    std::cout << std::endl;
    std::cout << "Moyenne : " << calculerMoyenne() << std::endl;
}

int Livre::getId() const {
    return id;
}

std::string Livre::getTitre() const {
    return titre;
}

int Livre::getNombreLivres() {
    return nombreLivres;
}

   

