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
	float tradition;
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
	static void init();

public:
	float age;
	float happiness;
	e_employment employment;
	s_ideas ideas;
	float earnings;
	float commitment;
	float charisma;
	float truthfulness;
	int id;
	int r_id() {return id;}
	Citizen();
	void id_up() {id++;}
	void description();
	float r_economy() { return ideas.economy; }
	float r_freedom() { return ideas.freedom; }
	float r_taxes() { return ideas.taxes;}
	float r_tradition() {return ideas.tradition; }
	float r_age() { return age; }
	float r_commitment() { return commitment; }
	float r_happiness() { return happiness; }
	float r_charisma() { return charisma; }
	float r_truthfulness() { return truthfulness; }
	string r_name() { return name; }
	string r_surname() { return surname; }
	e_employment r_employment() { return employment; }
	void change_happiness(Country &);
	void pay_taxes(Country &);
	bool death(Citizen&);
	void change_earnings(Country&);
	void go_criminal(Country&);
	void change_age() { age++; }
};