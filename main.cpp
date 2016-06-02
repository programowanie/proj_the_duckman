#include "Functions.h"
#include <ctime>
#include <stdlib.h>
#include <cstdio>

using namespace std;

int main()
{
	srand(time(NULL));
	Country ourCountry;
	int numberOfCitizens = 100;
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
		ourCountry.description(president);
		atmosphere(numberOfCitizens, vectorOfCitizens);
		if (!(ourCountry.r_year()%4)) president = vote(numberOfCitizens, vectorOfCitizens, president);
		ourCountry.next_year();
		getchar();
		for (vector<Citizen*>::iterator it = vectorOfCitizens.begin(); it!=vectorOfCitizens.end(); it++)
		{
			(*it)->change_happiness(ourCountry);
			(*it)->pay_taxes(ourCountry);
		}
		ourCountry.change_country_ideas(president);
	}
}