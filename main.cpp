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
	for (int i=0; i<numberOfCitizens; i++)
		vectorOfCitizens.push_back(&(citizens[i]));
	//for (int i=0; i<numberOfCitizens; i++)
	//	citizens[i].description();
	while (1)
	{
		ourCountry.description();
		atmosphere(numberOfCitizens, vectorOfCitizens);
		if (!(ourCountry.r_year()%4)) vote(numberOfCitizens, vectorOfCitizens);
		ourCountry.next_year();
		getchar();
	}
}