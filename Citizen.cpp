#include "Country.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cmath>

vector <string> Citizen::names;
vector <string> Citizen::surnames;
int Citizen::counter = 0;

void Citizen::init()
{
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
	ifstream file2("surnames.dat");
	copy(istream_iterator<string>(file2),
		istream_iterator<string>(),
		back_inserter(surnames));
	file2.close();
}

Citizen::Citizen()
{
	static int amountOfNames = (init(), names.size());
	static int amountOfSurnames = (init(), surnames.size());
	id = counter;
	name = names[rand()%amountOfNames];
	surname = surnames[rand()%amountOfSurnames];
	age = rand()%80;
	happiness = rand()%71 + 30;
	commitment = rand()%81 + 20;
	ideas.economy = rand()%101;
	ideas.freedom = rand()%101;
	ideas.taxes = rand()%101;
	if ((counter%100)<85)
		employment = standard;
	if ((counter%100)>=85 && (counter%100)<95)
		employment = criminal;
	if ((counter%100)>=95)
		employment = politician;
	charisma = rand()%10 + 1;
	truthfulness = rand()%101;
	earnings = rand()%10 + 10;
	counter++;
}

void Citizen::description()
{
	cout << "ID: " << id << endl << "Imie: " << name << endl << "Nazwisko: " << surname << endl 
	<< "Wiek:" << age << endl << 
	"Zatrudnienie: ";
	if (employment==standard) cout << "Sektor prywatny";
	if (employment==criminal) cout << "Przestepca";
	if (employment==politician) cout << "Polityk";
	cout << endl << "Zadowolenie: "<< happiness << endl << 
	"Zaangazowanie: " << commitment << endl 
	<< "Poglady: " << endl << "\tGospodarka: ";
	if (ideas.economy<30) cout << "wolnorynkowy ";
	if (ideas.economy>=30 && ideas.economy<=70) cout << "neutralny ";
	if (ideas.economy>70) cout << "socjalista ";
	cout << "(" << ideas.economy << ")" << endl << "\tSwobody: ";
	if (ideas.freedom<30) cout << "wolnosciowiec ";
	if (ideas.freedom>=30 && ideas.freedom<=70) cout << "neutralny ";
	if (ideas.freedom>70) cout << "konserwatywny ";
	cout << "(" << ideas.freedom << ")" << endl << "\tPodatki: ";
	if (ideas.taxes<30) cout << "niskie ";
	if (ideas.taxes>=30 && ideas.taxes<=70) cout << "neutralny ";
	if (ideas.taxes>70) cout << "wysokie ";
	cout << "(" << ideas.taxes << ")"
		<< endl << endl;
	if (employment==politician)
		cout << "Charyzma: " << charisma << endl << "Prawdomownosc: " << truthfulness << endl << endl;
}

void Citizen::change_happiness(Country &ourCountry)
{
	if (fabs(((this)->r_economy())-ourCountry.r_economy())>20)
		(this)->happiness -= sqrt(sqrt(fabs(((this)->r_economy())-ourCountry.r_economy())));
	if (fabs(((this)->r_economy())-ourCountry.r_economy())<10)
		(this)->happiness += fabs((this)->r_economy()-ourCountry.r_economy());
	//if (ourCountry.)
	if ((this)->happiness>100)
		(this)->happiness=100;
	if ((this)->happiness<0)
		(this)->happiness=0;
}

void Citizen::pay_taxes(Country &ourCountry)
{
	if((this)->employment == standard)
	{
		cout << (this)->earnings;
		ourCountry.budget += ((this)->earnings)*(ourCountry.r_taxes()/2);
	}
}

/*int Citizen::vote()
{
	float *endorsement = new float[vectorOfPoliticians.size()];
	int i = 0;
	for (vector<Politician **>::iterator it = vectorOfPoliticians.begin(); it != vectorOfPoliticians.end(); it++, i++)
	{
		endorsement[i] += abs(r_economy() - abs((*it)->r_economy()));
		endorsement[i] += abs(r_freedom() - abs((*it)->r_freedom()));
	}

	int choice = 0;

	for (int i = 1; i < vectorOfPoliticians.size(); i++)
	{
		if (endorsement[i] > endorsement[choice])
			choice = i;
	}
	return i;
}*/