#include "Citizen.h"
#include <iostream>
#include <cmath>

void atmosphere(int numberOfCitizens, vector<Citizen*> &vectorOfCitizens)
{
	float avg_economy=0;
	float avg_freedom=0;
	float avg_happiness=0;
	int underage = 0;
	for (int i = 0; i<numberOfCitizens; i++)
	{
		if ((vectorOfCitizens[i])->r_age()>=18)
		{
			avg_economy+=(vectorOfCitizens[i])->r_economy();
			avg_freedom+=(vectorOfCitizens[i])->r_freedom();
			avg_happiness+=(vectorOfCitizens[i])->r_happiness();
		}
		else underage++;
	}
	cout << "Nastroje w spoleczenstwie: " << endl;
	cout << "Gospodarka: " << avg_economy/(numberOfCitizens-underage) << endl;
	cout << "Swobody: " << avg_freedom/(numberOfCitizens-underage) << endl;
	cout << "Zadowolenie: " << avg_happiness/(numberOfCitizens-underage) << endl;
}

int vote(int numberOfCitizens, vector<Citizen*> &vectorOfCitizens)
{
int attendance = 0;
int underage = 0;
vector <Citizen *> vectorOfPoliticians;
for (int i = 0; i < numberOfCitizens; i++)
{
	if ((vectorOfCitizens[i])->r_employment() == politician)
		vectorOfPoliticians.push_back((vectorOfCitizens[i]));
}
int numberOfPoliticians = vectorOfPoliticians.size();
int *results = new int[numberOfPoliticians];
for (int i = 0; i<numberOfPoliticians; i++)
	results[i] = 0;
	//vector<Citizen **>::iterator it = vectorOfPoliticians.begin();
for (int x=0; x<numberOfCitizens; x++)
{
	float *endorsement = new float[numberOfPoliticians];
	for (int i = 0; i<numberOfPoliticians; i++)
		endorsement[i] = 0;
	for (int j=0; j<numberOfPoliticians; j++)
	{
		endorsement[j] += fabs(fabs((vectorOfCitizens[x])->r_economy()) - fabs((vectorOfPoliticians[j])->r_economy()));
		endorsement[j] += fabs(fabs((vectorOfCitizens[x])->r_freedom()) - fabs((vectorOfPoliticians[j])->r_freedom()));
		endorsement[j] /= sqrt(sqrt((vectorOfPoliticians[j])->r_charisma()));
	}
	int choice = 0;
	for (int i=0; i<numberOfPoliticians; i++)
	{
		if (endorsement[i]<endorsement[choice])
		{
			choice = i;
		}
		//cout << "wybor:" << choice << ";";
	}
	for (int i=0; i<numberOfPoliticians; i++)
		endorsement[i] = 0;
	if ((vectorOfCitizens[x])->r_age() >= 18)
		{
			if ((vectorOfCitizens[x])->r_commitment()>=rand()%100)
			{
				results[choice]++;
				attendance++;
			}
		}
	else underage++;
}

cout << "Frekwencja w pierwszej turze wyniosla " << attendance << "/" << numberOfCitizens-underage
<< " (" << ((float)attendance/((float)numberOfCitizens-(float)underage))*100.0 << "%)." << endl;
cout << "Wyniki pierwszej tury: " << endl;
for (int i = 0; i < numberOfPoliticians; i++)
{
	cout << results[i] << "\t";
	cout << (vectorOfPoliticians[i])->r_name() << " " << (vectorOfPoliticians[i])->r_surname() << endl;
}

	int winner = 0;
	int second = 0;
	for (int i = 0; i < numberOfPoliticians; i++)
	{
		if (results[i] > results[winner])
			winner = i;
	}

	if (winner==0) second = 1;
	for (int i = 0; i < numberOfPoliticians; i++)
	{
		if (i != winner)
		{
			if (results[i] > results[second])
				second = i;
		}
	}

cout << endl << endl << "Wybory wygral kandydat nr " << winner+1 << ", " << (vectorOfPoliticians[winner])->r_name() << " " << (vectorOfPoliticians[winner])->r_surname() << "." << endl;
(vectorOfPoliticians[winner])->description();
//cout << "W drugiej turze zmierzy sie z kandydatem nr " << second +1 << ", " << (vectorOfPoliticians[second])->r_name() << " " << (vectorOfPoliticians[second])->r_surname() << "." << endl;
//(vectorOfPoliticians[second])->description();
return winner;
}