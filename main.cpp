#include "Functions.h"
#include <ctime>
#include <stdlib.h>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	srand(time(NULL));
	Country ourCountry;
	Country startCountry = ourCountry;
	int numberOfCitizens = atoi(argv[1]);
	int cadence = atoi(argv[2]);
	int duration = atoi(argv[3]);
	int s_duration = duration;
	int presidents = 0;
	int elections = 0;
	Citizen citizens[numberOfCitizens];
	vector<Citizen *> vectorOfCitizens;
	Citizen president;
	for (int i=0; i<numberOfCitizens; i++)
		vectorOfCitizens.push_back(&(citizens[i]));

	while (duration)
	{
		ourCountry.next_year();
		int death_ratio=0;
		if (!(ourCountry.r_year()%cadence))
		{
			elections++;
			Citizen oldPresident = president;
			president = vote(numberOfCitizens, vectorOfCitizens, president);
			if (oldPresident.r_id() != president.r_id())
				presidents++;
		}
		ourCountry.description(president,1);
		atmosphere(numberOfCitizens, vectorOfCitizens);
		show_employment(numberOfCitizens, vectorOfCitizens);
		for (vector<Citizen*>::iterator it = vectorOfCitizens.begin(); it!=vectorOfCitizens.end(); it++)
		{
			(*it)->change_happiness(ourCountry);
			(*it)->go_criminal(ourCountry);
			(*it)->pay_taxes(ourCountry);
			death_ratio+=(*it)->death(president);
			(*it)->change_earnings(ourCountry);
		}
		ourCountry.pay_welfare();
		ourCountry.change_country_ideas(president);
		president.change_age();
		cout << endl << endl << "W tym roku zmarlo/narodzilo sie " << death_ratio << " ludzi." << endl << "=========================";
		getchar();
		duration--;
	}

	cout << "-------------KONIEC SYMULACJI-------------" << endl;
	cout << "------------------------------------------" << endl;
	cout << "---------------PODSUMOWANIE---------------" << endl << endl;
	cout << "Dane wejsciowe: " << endl;
	cout << "\tIlosc obywateli: " << numberOfCitizens << endl;
	cout << "\tCzas trwania kandencji: " << cadence << endl;
	cout << "\tIlosc lat: " << s_duration << endl << endl;
	cout << "Stan poczatkowy: " << endl;
	startCountry.description(president,0);

	cout << endl << endl << "Stan koncowy: " << endl;
	ourCountry.description(president,0);

	cout << endl << endl << "W tym czasie wybory odbyly sie " << elections << " razy." << endl;
	cout << "Urzad prezydenta sprawowalo " << presidents << " osob.";

	getchar();


}