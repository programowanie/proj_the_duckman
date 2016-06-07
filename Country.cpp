#include "Country.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cmath>

Country::Country()
{
	year = 0;
	budget = rand()%10000+10000;
	ideas.economy = rand()%20 + 40;
	ideas.freedom = rand()%20 + 40;
	ideas.taxes = rand()%20 + 40;
	ideas.tradition = rand()%20 + 40;
}

void Country::description(Citizen president, bool inGame)
{
	cout << endl << endl;
	cout << "ROK " << (this)->year << endl;
	cout << "BUDZET PANSTWA TO " << (this)->budget << endl;
	cout << "IDEOLOGIA PANSTWA: " << endl;
	cout << "\tGospodarka: " << (this)->ideas.economy << endl;
	cout << "\tSwobody: " << (this)->ideas.freedom << endl;
	cout << "\tPodatki: " << (this)->ideas.taxes << endl;
	cout << "\tTradycja: " << (this)->ideas.tradition << endl;
	cout << endl;
	if (inGame)
	{
		cout << "OBECNIE URZEDUJACYM PREZYDENTEM JEST: " << endl;
		president.description();
	}
}

void Country::change_country_ideas(Citizen president)
{
	if ((this)->ideas.economy > president.r_economy())
		(this)->ideas.economy -= (sqrt(fabs((this)->ideas.economy - president.r_economy())))*president.r_truthfulness()/100;
	if ((this)->ideas.economy < president.r_economy())
		(this)->ideas.economy += (sqrt(fabs((this)->ideas.economy - president.r_economy())))*president.r_truthfulness()/100;

	if ((this)->ideas.freedom > president.r_freedom())
		(this)->ideas.freedom -= (sqrt(fabs((this)->ideas.freedom - president.r_freedom())))*president.r_truthfulness()/100;
	if ((this)->ideas.freedom < president.r_freedom())
		(this)->ideas.freedom += (sqrt(fabs((this)->ideas.freedom - president.r_freedom())))*president.r_truthfulness()/100;

	if ((this)->ideas.taxes > president.r_taxes())
		(this)->ideas.taxes -= (sqrt(fabs((this)->ideas.taxes - president.r_taxes())))*president.r_truthfulness()/100;
	if ((this)->ideas.taxes < president.r_taxes())
		(this)->ideas.taxes += (sqrt(fabs((this)->ideas.taxes - president.r_taxes())))*president.r_truthfulness()/100;

	if ((this)->ideas.tradition > president.r_tradition())
		(this)->ideas.tradition -= (sqrt(fabs((this)->ideas.tradition - president.r_tradition())))*president.r_truthfulness()/100;
	if ((this)->ideas.tradition < president.r_tradition())
		(this)->ideas.tradition += (sqrt(fabs((this)->ideas.tradition - president.r_tradition())))*president.r_truthfulness()/100;


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
	if ((this)->ideas.tradition>100)
		(this)->ideas.tradition = 100;
	if ((this)->ideas.tradition<0)
		(this)->ideas.tradition = 0;
}

void Country::pay_welfare()
{
	budget -= (budget*(this)->r_economy()*2/100);
}