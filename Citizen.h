#include <string>
#include <vector>
#include <iterator>

using namespace std;

class Country;

enum e_employment
{
	standard,
	criminal,
	politician
};

struct s_ideas
{
	float economy; //im wyższy, tym większy wpływ państwa na gospodarkę
	float freedom; //im wyższy, tym większy wpływ państwa na ograniczanie swobód
	float taxes;
	//int police;
};

class Citizen
{
private:
	static vector <string> names;
	static vector <string> surnames;
	static int counter;
	string name;
	string surname;
	int age;
	int happiness;
	e_employment employment;
	s_ideas ideas;
	float earnings;
	int commitment;
	float charisma;
	int truthfulness;

	static void init();

public:
	int id;
	int r_id() {return id;}
	Citizen();
	void id_up() {id++;}
	void description();
	float r_economy() { return ideas.economy; }
	float r_freedom() { return ideas.freedom; }
	float r_taxes() { return ideas.taxes;}
	int r_age() { return age; }
	int r_commitment() { return commitment; }
	int r_happiness() { return happiness; }
	int r_charisma() { return charisma; }
	int r_truthfulness() { return truthfulness; }
	string r_name() { return name; }
	string r_surname() { return surname; }
	e_employment r_employment() { return employment; }
	void change_happiness(Country &);
	void pay_taxes(Country &);
	//void death(vector<Citizen*> &vectorOfCitizens);
};