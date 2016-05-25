#include <string>
#include <vector>
#include <iterator>

using namespace std;
enum e_employment
{
	standard,
	criminal,
	politician
};

struct s_ideas
{
	float economy;
	float freedom;
	//int police;
};

class Country
{
private:
	//string name;
	long int budget;
	s_ideas ideas;
	int taxes;
	int year;
public:
	Country();
	void description();
	long int r_budget() { return budget;}
	int r_year() { return year;}
	int r_taxes() { return taxes;}
	float r_economy() { return ideas.economy; }
	float r_freedom() { return ideas.freedom; }
	void next_year() { year++; }
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
	long int earnings;
	int commitment;
	float charisma;
	int truthfulness;

	static void init();

public:
	Citizen();
	void description();
	float r_economy() { return ideas.economy; }
	float r_freedom() { return ideas.freedom; }
	int r_age() { return age; }
	int r_commitment() { return commitment; }
	int r_happiness() { return happiness; }
	int r_charisma() { return charisma; }
	string r_name() { return name; }
	string r_surname() { return surname; }
	e_employment r_employment() { return employment; }
	void change_happiness();
	//void death(vector<Citizen*> &vectorOfCitizens);
};

/*vector <Citizen *> vectorOfPoliticians;
int numberOfPoliticians = vectorOfPoliticians.size();
	int *results = new int[numberOfPoliticians];
	for (int i = 0; i<numberOfPoliticians; i++)
		results[i] = 0;
	//vector<Citizen **>::iterator it = vectorOfPoliticians.begin();
	for (int i=0; i<CITIZENS; i++)
	{
		int endorsement[numberOfPoliticians];
		for (int i = 0; i<numberOfPoliticians; i++)
			endorsement[i] = 0;
		for (int j=0; j<numberOfPoliticians; j++)
		{
			endorsement[j] += abs(citizens[i].r_economy()) - abs((vectorOfPoliticians[j])->r_economy());
			endorsement[j] += abs(citizens[i].r_freedom()) - abs((vectorOfPoliticians[j])->r_freedom());
		}

		int choice = 0;
		for (int i=0; i<numberOfPoliticians; i++)
		{
			if (endorsement[i]<endorsement[choice])
				choice = i;
		}

		for (int i=0; i<numberOfPoliticians; i++)
		endorsement[i] = 0;

		results[choice]++;
	
	}


	int winner = 0;
	for (int i = 0; i < numberOfPoliticians; i++)
	{
		if (results[i] > results[winner])
			winner = i;
	}
	cout << endl << endl << "WYBORY WYGRAL KANDYDAT NR " << winner+1 << ", " << (vectorOfPoliticians[winner])->r_name() << " " << (vectorOfPoliticians[winner])->r_surname() << "!";
*/