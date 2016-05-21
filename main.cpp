#include "Functions.h"
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int numberOfCitizens = 1000;
	//cin >> numberOfCitizens;
	Citizen citizens[numberOfCitizens];
	//for (int i=0; i<numberOfCitizens; i++)
	//	citizens[i].description();

	vote(numberOfCitizens, citizens);
}