// tpGestionDeBiblio.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include "Date.h"
#include "Livre.h"
#include "Bibliotheque.h"

    using namespace std;
    using namespace Biblio;

  
    int main() {
            
        
        Bibliotheque b("Bibliotheque universitaire", 3);

            return 0;
      

    
        Date d1(15, 5, 2024);
        Date d2(20, 6, 2023);
        Date d3(10, 3, 2022);

        // 3. Creation des livres
        Livre* L1 = new Livre("Les Miserables", "Victor Hugo", d1);
        Livre* L2 = new Livre("Le Petit Prince", "Saint-Exupery", d2);
        Livre* L3 = new Livre("L'Etranger", "Albert Camus", d3);

     
        b.ajouterLivre(L1);
        b.ajouterLivre(L2);
        b.ajouterLivre(L3);

       
        L1->ajouterNote(15);
        L1->ajouterNote(18);
        L1->ajouterNote(12);

        L2->ajouterNote(14);
        L2->ajouterNote(16);

        L3->ajouterNote(17);
        L3->ajouterNote(19);

        
    

    
        cout << "\n===== RECHERCHE PAR TITRE =====" << endl;

        Livre* resultat = b.rechercherTitre("Le Petit Prince");

        if (resultat != nullptr) {
            cout << "Livre trouve :" << endl;
            resultat->afficher();
        }
        else {
            cout << "Livre introuvable !" << endl;
        }

      
        resultat = b.rechercherTitre("Livre inconnu");

        if (resultat == nullptr)
            cout << "\nLivre inconnu introuvable !" << endl;

    
        cout << "\n===== RECHERCHE PAR ID =====" << endl;

        resultat = b.rechercherId(1);

        if (resultat != nullptr)
            resultat->afficher();
        else
            cout << "Identifiant introuvable !" << endl;

    
        cout << "\nNombre de livres existants : "
            << Livre::getNombreLivres() << endl;

        cout << "\nFin du programme." << endl;

        return 0;
    }



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
