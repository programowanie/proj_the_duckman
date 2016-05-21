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
	int economy;
	int freedom;
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
	int charisma;
	int truthfulness;

	static void init();

public:
	Citizen();
	void description();
	int r_economy() { return ideas.economy; }
	int r_freedom() { return ideas.freedom; }
	string r_name() { return name; }
	string r_surname() { return surname; }
	e_employment r_employment() { return employment; }
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