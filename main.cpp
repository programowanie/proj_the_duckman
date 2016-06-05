#include "Functions.h"
#include <ctime>
#include <stdlib.h>
#include <cstdio>

using namespace std;

int main()
{
	srand(time(NULL));
	Country ourCountry;
	int numberOfCitizens = 1000;
	//cin >> numberOfCitizens;
	Citizen citizens[numberOfCitizens];
	vector<Citizen *> vectorOfCitizens;
	Citizen president;
	for (int i=0; i<numberOfCitizens; i++)
		vectorOfCitizens.push_back(&(citizens[i]));
	//for (int i=0; i<numberOfCitizens; i++)
	//	citizens[i].description();
	while (1)
	{
		int death_ratio=0;
		if (!(ourCountry.r_year()%7)) president = vote(numberOfCitizens, vectorOfCitizens, president);
		ourCountry.description(president);
		atmosphere(numberOfCitizens, vectorOfCitizens);
		show_employment(numberOfCitizens, vectorOfCitizens);
		ourCountry.next_year();
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
	}
}