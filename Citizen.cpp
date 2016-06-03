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
	if ((counter%100)<80)
		employment = standard;
	if ((counter%100)>=80 && (counter%100)<90)
		employment = criminal;
	if ((counter%100)>=90)
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
	if (fabs(((this)->r_economy())-ourCountry.r_economy())>30)
		happiness -= sqrt(sqrt(fabs(((this)->r_economy())-ourCountry.r_economy())));
	if (fabs(((this)->r_economy())-ourCountry.r_economy())<15)
		happiness += fabs((this)->r_economy()-ourCountry.r_economy());
	happiness += sqrt(sqrt(sqrt((float)(this)->r_economy())));
	
	if((ourCountry.budget>0)&&rand()%6>4)
		happiness+=1;
	else happiness-=1;

	if (happiness>100)
		happiness=100;
	if (happiness<0)
		happiness=0;
}

void Citizen::pay_taxes(Country &ourCountry)
{
	if(employment == standard)
	{
		ourCountry.budget += (earnings)*(ourCountry.r_taxes()/2);
	}
}

bool Citizen::death(Citizen &president)
{
	int x = (this)->r_age();
	int death_randomizer = (float)(rand()%100001)/1000.0;
	bool is_dead=0;
	int new_age=0;
	if(((x/50)*(x/50)*(x/50)*sqrt(x*0.75))>death_randomizer)
		is_dead=1;
	//politycy poza prezydentem beda mieli wieksza szanse na smierc - stres, zamachy, te sprawy :)
	//glownie chodzi o wieksza wymiennosc wsrod politykow
	if (employment == politician && ((this)->r_id()!=president.r_id()))
		{
			if ((this)->r_age()>rand()%100)
			{
				is_dead=1;
				new_age=rand()%30+20;
			}
		}

	if(is_dead)
	{
		age = new_age;
		happiness = rand()%71 + 30;
		commitment = rand()%81 + 20;
		ideas.economy = rand()%101;
		ideas.freedom = rand()%101;			
		ideas.taxes = rand()%101;
		charisma = rand()%10 + 1;
		truthfulness = rand()%101;
		earnings = rand()%10 + 10;
		return 1;
	}
	return 0;
}

void Citizen::change_earnings(Country& ourCountry)
{
	earnings*=(ourCountry.r_economy()/1000)+0.95;
}

void Citizen::go_criminal(Country& ourCountry)
{
	if ((happiness<(30.0*ourCountry.r_freedom()/100))&&employment==standard)
		if(id%11>rand()%20)
			employment = criminal;
	if ((happiness>(30.0*ourCountry.r_freedom()/100))&&employment==criminal)
		if(id%11>rand()%20)
			employment = standard;
}