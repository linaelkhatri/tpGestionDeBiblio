#include "Date.h"
#include<iostream>

Date::Date(int j, int m, int a)
{
	if (!estValide(j, m, a)) {
		std::cout << "Date invalide" << std::endl;
	}
	else {
		this->jour = j;
		this->mois = m;
		this->annee = a;
}
	
}

bool Date::estBissextile(int a)
{ 
	if (a % 400 == 0)
		return true;
	else if (a % 4 == 0 && a % 100 != 0)
		return true;
	else 
	   return false;
}

bool Date::estValide(int j, int m, int a)
{
	if (a < 1 || m < 1 || m>12 || j < 1)
		return false;
	int joursMois[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (estBissextile(a)) {
		joursMois[1] = 29;
	}
	if (m <= 0 && m > 12) {
		return false;

	}
	else {
		if (j<1 || j>joursMois[m - 1])
			return false;
	}


	
}

void Date::afficher() const
{
	std::cout << "jour: " << this->jour << std::endl;
	std::cout << "mois: " << this->mois << std::endl;
	std::cout << "annee: " << this->annee << std::endl;
}

bool Date::operator==(const Date& d) const
{
	if (this->jour == d.jour && this->annee == d.annee && this->mois == d.mois){
	return true;
} 
return false;
}

bool Date::operator<(const Date& d) const
{
	if (annee != d.annee)
		return annee < d.annee;
	if (mois != d.mois)
		return mois < d.mois;
	if (jour != d.jour)
		return jour < d.jour;
}
