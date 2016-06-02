#include "Country.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cmath>

Country::Country()
{
	year = 2000;
	budget = rand()%10000+10000;
	ideas.economy = rand()%20 + 40;
	ideas.freedom = rand()%20 + 40;
	ideas.taxes = rand()%20 + 40;
}

void Country::description(Citizen president)
{
	cout << endl << endl;
	cout << "JEST ROK " << (this)->year << endl;
	cout << "BUDZET PANSTWA TO " << (this)->budget << endl;
	cout << "IDEOLOGIA PANSTWA: " << endl;
	cout << "Gospodarka: " << (this)->ideas.economy << endl;
	cout << "Swobody: " << (this)->ideas.freedom << endl;
	cout << "Podatki: " << (this)->ideas.taxes << endl;
	cout << endl;
	if ((this)->year != 2000)
	{
		cout << "OBECNIE URZEDUJACYM PREZYDENTEM JEST: " << endl;
			president.description();
	}
}

void Country::change_country_ideas(Citizen president)
{
	if ((this)->ideas.economy > president.r_economy())
		(this)->ideas.economy -= sqrt(fabs((this)->ideas.economy - president.r_economy()));
	if ((this)->ideas.economy < president.r_economy())
		(this)->ideas.economy += sqrt(fabs((this)->ideas.economy - president.r_economy()));

	if ((this)->ideas.freedom > president.r_freedom())
		(this)->ideas.freedom -= sqrt(fabs((this)->ideas.freedom - president.r_freedom()));
	if ((this)->ideas.freedom < president.r_freedom())
		(this)->ideas.freedom += sqrt(fabs((this)->ideas.freedom - president.r_freedom()));

	if ((this)->ideas.taxes > president.r_taxes())
		(this)->ideas.taxes -= sqrt(fabs((this)->ideas.taxes - president.r_taxes()));
	if ((this)->ideas.taxes < president.r_taxes())
		(this)->ideas.taxes += sqrt(fabs((this)->ideas.taxes - president.r_taxes()));

	if ((this)->ideas.economy>100)
		(this)->ideas.economy = 100;
	if ((this)->ideas.economy<0)
		(this)->ideas.economy = 0;
	if ((this)->ideas.freedom>100)
		(this)->ideas.freedom = 100;
	if ((this)->ideas.freedom<0)
		(this)->ideas.freedom = 0;
	if ((this)->ideas.taxes>100)
		(this)->ideas.taxes = 100;
	if ((this)->ideas.taxes<0)
		(this)->ideas.taxes = 0;
}