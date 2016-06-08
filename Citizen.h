#include <string>
#include <vector>
#include <iterator>

using namespace std;

class Country;

//! Typ wyliczeniowy z zatrudnieniem
enum e_employment
{
	standard, //!< standardowe zatrudnienie
	criminal, //!< przestępca, nie płaci podatków
	politician //!< polityk, nie płaci podatków
};

//! Struktura zawierająca poglądy obywateli i państwa
struct s_ideas 
{
	float economy; //!< im wyższy, tym większy wpływ państwa na gospodarkę
	float freedom; //!< im wyższy, tym większy wpływ państwa na ograniczanie swobód
	float taxes; //!< wpływają na przestępczość, rzeczywista wysokość to taxes/2
	float tradition; //!< przywiązanie do tradycji
	//int police;
};

//! Klasa obywatela, czyli mieszkańca państwa
class Citizen
{
private:
	friend void show_employment(int, vector<Citizen*> &);
	friend void atmosphere(int, vector<Citizen*> &);
	friend Citizen vote(int, vector<Citizen*>&, Citizen);
	static vector <string> names; //!< wektor imion
	static vector <string> surnames; //!< wektor nazwisk
	static int counter; //!< licznik obywateli
	string name; //!< imię
	string surname; //!< nazwisko
	static void init(); //!< funkcja inicjująca

public:
	float age; //!< wiek
	float happiness; //!< zadowolenie
	e_employment employment; //!< zatrudnienie
	s_ideas ideas; //!< poglądy
	float earnings; //!< zarobki
	float commitment; //!< zaangażowanie, decyduje o obecności na wyborach
	float charisma; //!< atrybut polityków, pomaga zdobywać poparcie
	float truthfulness; //!< prawdomówność, decyduje o tym, czy polityk spełnia obietnice
	int id; //!< id obywatela
	int r_id() {return id;}
	Citizen(); //!< konstruktor
	void id_up() {id++;}
	void description(); //!< funkcja wyświetlająca opis obywatela
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
	void change_happiness(Country &); //<! służy do zmiany zadowolenia
	void pay_taxes(Country &); //<! płacenie podatków do budżetu
	bool death(Citizen&); //<! algorytm umierania
	void change_earnings(Country&); //<! zmiana zarobków w zależności od gospodarki
	void go_criminal(Country&); //<! zmiana zatrudnienia na criminal (wysokie podatki lub niezadowolenie)
	void change_age() { age++; } //<! postarzenie, zwiększa szansę na śmierć
};