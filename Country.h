#include "Citizen.h"

using namespace std;

class Country
{
private:
	//string name;
	s_ideas ideas;
	int year; //!< rok
public:
	float budget; //!< budżet, zależy od podatków i gospodarki
	Country(); //!< konstruktor
	void description(Citizen, bool); //!< opis państwa
	float r_budget() { return budget;}
	int r_year() { return year;}
	float r_taxes() { return ideas.taxes;}
	float r_economy() { return ideas.economy; }
	float r_freedom() { return ideas.freedom; }
	float r_tradition() { return ideas.tradition;}
	void next_year() { year++; }
	void change_country_ideas(Citizen); //!< zmiana poglądów państwa pod wpływem prezydenta
	void pay_welfare(); //!< wypłata zasiłków z budżetu
};