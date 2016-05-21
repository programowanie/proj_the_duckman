#include "Citizen.h"
#include <iostream>



int vote(int numberOfCitizens, Citizen citizens[])
{
vector <Citizen *> vectorOfPoliticians;
for (int i = 0; i < numberOfCitizens; i++)
{
	if (citizens[i].r_employment() == politician)
		vectorOfPoliticians.push_back(&(citizens[i]));
}
int numberOfPoliticians = vectorOfPoliticians.size();
int *results = new int[numberOfPoliticians];
for (int i = 0; i<numberOfPoliticians; i++)
	results[i] = 0;
	//vector<Citizen **>::iterator it = vectorOfPoliticians.begin();
for (int x=0; x<numberOfCitizens; x++)
{
	int *endorsement = new int[numberOfPoliticians];
	for (int i = 0; i<numberOfPoliticians; i++)
		endorsement[i] = 0;
	for (int j=0; j<numberOfPoliticians; j++)
	{
		endorsement[j] += abs(abs(citizens[x].r_economy()) - abs((vectorOfPoliticians[j])->r_economy()));
		endorsement[j] += abs(abs(citizens[x].r_freedom()) - abs((vectorOfPoliticians[j])->r_freedom()));
	}
	int choice = 0;
	for (int i=0; i<numberOfPoliticians; i++)
	{
		if (endorsement[i]<endorsement[choice])
		{
			cout << endorsement[i] << " < " << endorsement[choice] << ";";
			choice = i;
		}
		//cout << "wybor:" << choice << ";";
	}
	for (int i=0; i<numberOfPoliticians; i++)
		endorsement[i] = 0;
	results[choice]++;
}

cout << "Wyniki wyborow: " << endl;
for (int i = 0; i < numberOfPoliticians; i++)
{
	cout << results[i] << "\t";
	cout << (vectorOfPoliticians[i])->r_name() << " " << (vectorOfPoliticians[i])->r_surname() << endl;
}

	int winner = 0;
	for (int i = 0; i < numberOfPoliticians; i++)
	{
		if (results[i] > results[winner])
			winner = i;
	}
	cout << endl << endl << "WYBORY WYGRAL KANDYDAT NR " << winner+1 << ", " << (vectorOfPoliticians[winner])->r_name() << " " << (vectorOfPoliticians[winner])->r_surname() << "!";
	return winner;
}