#include "Citizen.h"

using namespace std;

class Country
{
private:
	//string name;
	s_ideas ideas;
	int year;
public:
	float budget;
	Country();
	void description(Citizen);
	float r_budget() { return budget;}
	int r_year() { return year;}
	float r_taxes() { return ideas.taxes;}
	float r_economy() { return ideas.economy; }
	float r_freedom() { return ideas.freedom; }
	void next_year() { year++; }
	void change_country_ideas(Citizen);
};