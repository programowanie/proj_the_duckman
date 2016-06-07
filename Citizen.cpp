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
	commitment = rand()%81 + 20;
	ideas.economy = rand()%101;
	ideas.freedom = rand()%101;
	ideas.taxes = rand()%101;
	ideas.tradition = rand()%101;
	if ((counter%100)<85)
		employment = standard;
	if ((counter%100)>=85 && (counter%100)<90)
		employment = criminal;
	if ((counter%100)>=90)
		employment = politician;
	if (employment!=criminal) happiness = rand()%71 + 30;
	else happiness = rand()%10;
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
	cout << "(" << ideas.taxes << ")" << endl << "\tTradycja: ";
	if (ideas.tradition<30) cout << "kosmopolita ";
	if (ideas.tradition>=30 && ideas.tradition<=70) cout << "neutralny ";
	if (ideas.tradition>70) cout << "narodowiec ";
	cout << "(" << ideas.tradition << ")"
		<< endl << endl;
	if (employment==politician)
		cout << "Charyzma: " << charisma << endl << "Prawdomownosc: " << truthfulness << endl << endl;
}

void Citizen::change_happiness(Country &ourCountry)
{
	if (fabs(((this)->r_economy())-ourCountry.r_economy())>40)
		happiness -= sqrt(sqrt(fabs(((this)->r_economy())-ourCountry.r_economy())));
	if (fabs(((this)->r_economy())-ourCountry.r_economy())<20)
		happiness += sqrt(fabs((this)->r_economy()-ourCountry.r_economy()));


	if (fabs(((this)->r_freedom())-ourCountry.r_freedom())>40)
		happiness -= sqrt(sqrt(fabs(((this)->r_freedom())-ourCountry.r_freedom())));
	if (fabs(((this)->r_freedom())-ourCountry.r_freedom())<20)
		happiness += sqrt(fabs((this)->r_freedom()-ourCountry.r_freedom()));


	if (fabs(((this)->r_taxes())-ourCountry.r_taxes())>40)
		happiness -= sqrt(sqrt(fabs(((this)->r_taxes())-ourCountry.r_taxes())));
	if (fabs(((this)->r_taxes())-ourCountry.r_taxes())<20)
		happiness += sqrt(fabs((this)->r_taxes()-ourCountry.r_taxes()));


	if (fabs(((this)->r_tradition())-ourCountry.r_tradition())>40)
		happiness -= sqrt(sqrt(fabs(((this)->r_tradition())-ourCountry.r_tradition())));
	if (fabs(((this)->r_tradition())-ourCountry.r_tradition())<20)
		happiness += sqrt(fabs((this)->r_tradition()-ourCountry.r_tradition()));

	
	if((ourCountry.budget>0)&&rand()%6>4)
		happiness++;
	else happiness--;


	if (happiness>100)
		happiness=100;
	if (happiness<0)
		happiness=0;
}

void Citizen::pay_taxes(Country &ourCountry)
{
	if((employment == standard)&&(age>=18))
	{
		ourCountry.budget += (earnings)*(ourCountry.r_taxes()/2);
	}
}

bool Citizen::death(Citizen &president)
{
	int x = (this)->r_age();
	int death_randomizer = (float)(rand()%100001)/1000.0;
	bool is_dead=0;
	int new_age=-1;
	if(((x/50)*(x/50)*(x/50)*sqrt(x*0.75))>death_randomizer)
		is_dead=1;
	//politycy poza prezydentem beda mieli wieksza szanse na smierc - stres, zamachy, te sprawy :)
	//glownie chodzi o wieksza wymiennosc wsrod politykow
	if (employment == politician && ((this)->r_id()!=president.r_id()))
		{
			if ((this)->r_age()>rand()%300)
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
		ideas.tradition = rand()%101;
		charisma = rand()%101;
		truthfulness = rand()%101;
		earnings = rand()%10 + 10;
		age++;
		return 1;
	}
	age++;
	return 0;
}

void Citizen::change_earnings(Country& ourCountry)
{
	earnings*=(ourCountry.r_economy()/1000)+0.95;
}

void Citizen::go_criminal(Country& ourCountry)
{
	if ((happiness<(10.0*ourCountry.r_freedom()/100))&&employment==standard)
	{
		//if(rand()%100<1)
			employment = criminal;
	}

	if ((happiness<(10.0*ourCountry.r_taxes()/100))&&employment==standard)
	{
		//if(rand()%100<1)
			employment = criminal;
	}

	if ((happiness>(10.0*ourCountry.r_freedom()/100))&&employment==criminal)
	{
		//if(rand()%4<1)
			employment = standard;
	}

	if ((happiness>(10.0*ourCountry.r_taxes()/100))&&employment==criminal)
	{
		//if(rand()%4<3)
			employment = standard;
	}
}