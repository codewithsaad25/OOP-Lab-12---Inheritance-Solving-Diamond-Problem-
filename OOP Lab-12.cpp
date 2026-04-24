#include<iostream>
using namespace std;

class character
{
private:
	string name;
	int age;
public:
	character()
	{
		name = "unknown";
		age = 0;
	}
	character(string n, int a)
	{
		name = n;
		age = a;
	}
	void displayCharacterInfo()
	{
		cout << "The name of the character is: " << name;
		cout << "\nThe age of the character is: " << age;
	}
	string getname()
	{
		return name;
	}
	int getage()
	{
		return age;
	}
	void setname(string Name)
	{
		name = Name;
	}
	void setage(int Age)
	{
		age = Age;
	}
};

class Human : virtual public character
{
private:
	string nationality;
	string profession;
public:
	Human()
	{
		nationality = "unknown";
		profession = "unknown";
	}
	Human(string name, int age, string Nationality, string Profession) : character(name, age)
	{
		nationality = Nationality;
		profession = Profession;
	}
	void displayHumanTraits()
	{
		displayCharacterInfo();
		cout << "\nThe Nationality of the character is: " << nationality;
		cout << "\nThe Profession of the character is: " << profession;

	}
	string getnationality()
	{
		return nationality;
	}
	string getprofession()
	{
		return profession;
	}
	void setnationality(string n)
	{
		nationality = n;
	}
	void setprofession(string p)
	{
		profession = p;
	}
	void think()
	{
		cout << endl << getname() << " uses logic and human intelligence. ";
	}
};

class Alien : virtual public character
{
private:
	string planetOrigin;
	string specialPower;
public:
	Alien()
	{
		planetOrigin = "unknown";
		specialPower = "unknown";
	}
	Alien(string name, int age, string po, string sp) : character(name, age)
	{
		planetOrigin = po;
		specialPower = sp;
	}
	void displayAlienTraits()
	{
		displayCharacterInfo();
		cout << "\nThe Planet origin of " << getname() << " is: " << planetOrigin;
		cout << "\nThe Special Power of " << getname() << " is: " << specialPower;
	}
	string getplanetorigin()
	{
		return planetOrigin;
	}
	string getspecialpower()
	{
		return specialPower;
	}
	void setplanetOrigin(string po)
	{
		planetOrigin = po;
	}
	void setspecialPower(string Sp)
	{
		specialPower = Sp;
	}
	void usePower()
	{
		cout << endl << getname() << " activates " << getspecialpower();
	}
};

class HumanAlienCombo : public Human, public Alien
{
private:
	int omnitrixID;
	string omnitrixVersion;
public:
	HumanAlienCombo(string name, int age, string Nationality, string Profession, string specialPower, string planetOrigin, int oID, string oV) : character(name, age),
		Human(name, age, Nationality, Profession),
		Alien(name, age, planetOrigin, specialPower)
	{
		omnitrixID = oID;
		omnitrixVersion = oV;
	}
	void displayHybridProfile()
	{
		displayHumanTraits();
		//displayAlienTraits();
		cout << "\nThe Planet origin of " << getname() << " is: " << getplanetorigin();
		cout << "\nThe Special Power of " << getname() << " is: " << getspecialpower();
		cout << "\nThe Omnitrix ID is: " << omnitrixID;
		cout << "\nThe Omnitrix Version is :" << omnitrixVersion;
	}
	int getomnitrixId()
	{
		return omnitrixID;
	}
	string getomnitrixversion()
	{
		return omnitrixVersion;
	}
	void setomnitrixid(int id)
	{
		omnitrixID = id;
	}
	void setomnitrixversion(string omnitrixV)
	{
		omnitrixVersion = omnitrixV;
	}
	void activateOmnitrix()
	{
		cout << "\nOmnitrix is activated. ";
	}
	void displayAbilities()
	{
		think();
		usePower();
	}
};

int main()
{
	cout << "=== Human Information ===\n";
	Human H1("Ben Tennyson", 16, "America", "Brave");
	Human H2("Gwem Tennyson", 16, "America", "Intelligent");
	H1.displayHumanTraits();
	H1.think();
	cout << endl << endl;
	H2.displayHumanTraits();
	H2.think();
	cout << "\n\n\n";
	cout << "=== Alien Information ===\n";
	Alien A1("Heatblast", 200, "Pyros", "Fire Manipulation");
	Alien A2("XLR8", 150, "Kinet", "Super Speed");
	A1.displayAlienTraits();
	A1.usePower();
	cout << endl << endl;
	A2.displayAlienTraits();
	A2.usePower();
	cout << "\n\n\n";
	cout << "=== Ben10 Hybrid Profile (Fixed Diamond) ===\n";
	HumanAlienCombo C1("Ben Tennyson Hybrid", 16, "American", "Brave", "Fire Manipulation", "Pyros", 1001, "V2.5");
	C1.displayHybridProfile();
	C1.displayAbilities();
	C1.activateOmnitrix();
}