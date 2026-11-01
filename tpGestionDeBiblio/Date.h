#pragma once
class Date
{ 
private:
	int jour;
	int mois;
	int annee;
public:
	Date(int j = 1, int m = 1, int a = 2000);
	static bool estBissextile(int a);
	static bool estValide(int j, int m, int a);
	void afficher()const;
	bool operator== (const Date & d)const;
	bool operator<(const Date& d)const;


};

