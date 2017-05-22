#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

//** The base class
class Animal 
{
public :
	bool counted;
	static int animals[10];

	// Displays message with default green text then sets it back to normal
	void OutputMessage(string input, WORD mod = 0x0A)
	{
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hout, mod);
		cout << input << endl;
		SetConsoleTextAttribute(hout, 0x07);
	}
	// Animal constructor with argument if animal is counted - defaulted to true
	Animal(bool isCounted = true)
	{
		cout << "Animal was created!" << endl;
		counted = isCounted;
		if(counted) animals[0]++;
	}
	// Base deconstructor
	~Animal()
	{ 
		OutputMessage("The animal '" + name + "' is gone...\n",0x08);
		if(counted) animals[0]--;
	}
	// Set the animals name
	void SetName(string _name) { name = _name; }
	// Get the animals name
	string GetName() const
	{
		return name;
	}
	// Allow the animal to speak
	virtual string Speak()
	{ 
		return GetName() + " : Makes animal sound.";
	}
	// Display all counted animals that exist
	void GetAnimals() const
	{ 
		cout << "There are " << animals[0] << " animals total." << endl;
		GetDogs();
		GetCats();
		GetBunnies();
		GetBirds();
		GetReptiles();
		GetFishes();
		GetInsects();
		GetMonkies();
		GetRodents();
		cout << endl;
	}
	void GetDogs() const
	{
		cout << "There are " << animals[1] << " dogs." << endl;
	}
	void GetCats() const
	{
		cout << "There are " << animals[2] << " cats." << endl;
	}
	void GetBunnies() const
	{
		cout << "There are " << animals[3] << " bunnies." << endl;
	}
	void GetBirds() const
	{
		cout << "There are " << animals[4] << " birds." << endl;
	}
	void GetReptiles() const
	{
		cout << "There are " << animals[5] << " reptiles." << endl;
	}
	void GetFishes() const
	{
		cout << "There are " << animals[6] << " fishes." << endl;
	}
	void GetInsects() const
	{
		cout << "There are " << animals[7] << " insects." << endl;
	}
	void GetMonkies() const
	{
		cout << "There are " << animals[8] << " monkies." << endl;
	}
	void GetRodents() const
	{
		cout << "There are " << animals[9] << " rodents." << endl;
	}

private :
	string name;
};


//== Sub Animal
class Dog : public Animal
{
public:
	Dog(string _name)
	{	
		SetName(_name);
		cout << "Dog '" << GetName() << "' was created!" << endl;
		animals[1]++;
	}
	~Dog()
	{ 
		Animal::OutputMessage("Dog '" + GetName() + "' is leaving.",0x0E);
		animals[1]--;
	}
	virtual string Speak() 
	{

		return GetName() + " Says : 'Woof'!\n";
	}
};
//- Sub Dog
class Pomeranian : public Dog
{
public:
	Pomeranian(string name) : Dog(name) {};
	~Pomeranian() {}
	string Speak()
	{
		return GetName() + " Says : 'Arf'!\n";
	}
};
class Chihuahua : public Dog
{
public:
	Chihuahua(string name) : Dog(name) {};
	~Chihuahua() {}
	string Speak()
	{
		return GetName() + " Says : 'Grrr'!\n";
	}
};


//== Sub Animal
class Cat : public Animal
{
public:
	Cat(string _name)
	{ 
		SetName(_name);
		cout << "Cat '" << GetName() << "' was created!" << endl;
		animals[2]++;
	}
	~Cat() 
	{
		Animal::OutputMessage("Cat '" + GetName() + "' is leaving.", 0x0E);
		animals[2]--;
	}

	virtual string Speak()
	{ 
		return GetName() + " Says : 'Meow'!\n";
	}
	
};
//- Sub Cat
class Calico : public Cat
{
public:
	Calico(string name) : Cat(name) {};
	~Calico() {}
	string Speak()
	{
		return GetName() + " Says : 'Purrrr'!\n";
	}
};
class Persian : public Cat
{
public:
	Persian(string name) : Cat(name) {};
	~Persian() {}
	string Speak()
	{
		return GetName() + " Says : 'Mew'!\n";
	}
};


//== Sub Animal
class Bunny : public Animal
{
public:
	Bunny(string _name)
	{ 
		SetName(_name);
		cout << "Bunny '" << GetName() << "' was created!" << endl;
		animals[3]++;
	}
	~Bunny()
	{
		Animal::OutputMessage("Bunny '" + GetName() + "' is leaving.", 0x0E);
		animals[3]--;
	}

	virtual string Speak()
	{ 
		return GetName() + " Says : 'Sneef sneef'!\n";
	}
	
};
//- Sub Bunny
class JackRabbit : public Bunny
{
public :
	JackRabbit(string name) : Bunny(name) {}
	~JackRabbit() {}
	string Speak()
	{
		return GetName() + " Says : 'Thump thump'!\n";
	}
};
class RexRabbit : public Bunny
{
public:
	RexRabbit(string name) : Bunny(name) {}
	~RexRabbit() {}
	string Speak()
	{
		return GetName() + " Says : 'Grunt'!\n";
	}
};


//== Sub Animal
class Bird : public Animal
{
public:
	Bird(string _name)
	{ 
		SetName(_name);
		cout << "Bird '" << GetName() << "' was created!" << endl;
		animals[4]++;
	}
	~Bird() 
	{ 
		Animal::OutputMessage("Bird '" + GetName() + "' is leaving.", 0x0E);
		animals[4]--;
	}

	virtual string Speak()
	{ 
		return GetName() + " Says : 'Tweet'!\n";
	}

};
//- Sub Bird
class Parrot : public Bird
{
public:
	Parrot(string name) : Bird(name) {}
	~Parrot() {}
	string Speak()
	{
		return GetName() + " Says : 'Crackers'!\n";
	}
};
class Parakeet : public Bird
{
public:
	Parakeet(string name) : Bird(name) {}
	~Parakeet() {}
	string Speak()
	{
		return GetName() + " Says : 'Squak'!\n";
	}
};


//== Sub Animal
class Reptile : public Animal
{
public:
	Reptile(string _name)
	{ 
		SetName(_name);
		cout << "Reptile '" << GetName() << "' was created!" << endl;
		animals[5]++;
	}
	~Reptile() 
	{
		Animal::OutputMessage("Reptile '" + GetName() + "' is leaving.", 0x0E);
		animals[5]--;
	}

	virtual string Speak()
	{ 
		return GetName() + " Says : 'Ribbit'!\n";
	}

};
//- Sub Reptile
class Snake : public Reptile
{
public:
	Snake(string name) : Reptile(name) {}
	~Snake() {}
	string Speak()
	{
		return GetName() + " Says : 'Ssssssss'!\n";
	}
};
class Frog : public Reptile
{
public:
	Frog(string name) : Reptile(name) {}
	~Frog() {}
	string Speak()
	{
		return GetName() + " Says : 'Ribbit'!\n";
	}
};


//== Sub Animal
class Fish : public Animal
{
public:
	Fish(string _name)
	{ 
		SetName(_name);
		cout << "Fish '" << GetName() << "' was created!" << endl;
		animals[6]++;
	}
	~Fish()
	{ 
		Animal::OutputMessage("Fish '" + GetName() + "' is leaving.", 0x0E);
		animals[6]--;
	}

	virtual string Speak()
	{ 
		return GetName() + " Says : 'Glub'!\n";
	}
};
//- Sub Fish
class Bass : public Fish
{
public:
	Bass(string name) : Fish(name) {}
	~Bass() {}
	string Speak()
	{
		return GetName() + " Says : 'Splash'!\n";
	}
};
class Flounder : public Fish
{
public:
	Flounder(string name) : Fish(name) {}
	~Flounder() {}
	string Speak()
	{
		return GetName() + " Says : 'Blub'!\n";
	}
};


//== Sub Animal
class Insect : public Animal
{
public:
	Insect(string _name)
	{ 
		SetName(_name);
		cout << "Insect '" << GetName() << "' was created!" << endl;
		animals[7]++;
	}
	~Insect()
	{ 
		Animal::OutputMessage("Insect '" + GetName() + "' is leaving.", 0x0E);
		animals[7]--;
	}

	virtual string Speak()
	{ 
		return GetName() + " Says : 'Chirp chirp'!\n";
	}
};
//- Sub Insect
class Cicada : public Insect
{
public:
	Cicada(string name) : Insect(name) {}
	~Cicada() {}
	string Speak()
	{
		return GetName() + " Says : 'REEEEEEEE'!\n";
	}
};
class Bee : public Insect
{
public:
	Bee(string name) : Insect(name) {}
	~Bee() {}
	string Speak()
	{
		return GetName() + " Says : 'Bzzzzz'!\n";
	}
};


//== Sub Animal
class Monkey : public Animal
{
public:
	Monkey(string _name)
	{ 
		SetName(_name);
		cout << "Monkey '" << GetName() << "' was created!" << endl;
		animals[8]++;
	}
	~Monkey() 
	{ 
		Animal::OutputMessage("Monkey '" + GetName() + "' is leaving.", 0x0E);
		animals[8]--;
	}

	virtual string Speak()
	{ 
		return GetName() + " Says : 'Ooh ooh aah aah'!\n";
	}
	
};
//- Sub Monkey
class Chimp : public Monkey
{
public:
	Chimp(string name) : Monkey(name) {}
	~Chimp() {}
	string Speak()
	{
		return GetName() + " Says : 'Shrill'!\n";
	}
};
class Gorilla : public Monkey
{
public:
	Gorilla(string name) : Monkey(name) {}
	~Gorilla() {}
	string Speak()
	{
		return GetName() + " Says : 'Rah rah'!\n";
	}
};


//== Sub Animal
class Rodent : public Animal
{
public:
	Rodent(string _name)
	{ 
		SetName(_name);
		cout << "Rodent '" << GetName() << "' was created!" << endl;
		animals[9]++;
	}
	~Rodent()
	{ 
		Animal::OutputMessage("Rodent '" + GetName() + "' is leaving.", 0x0E);
		animals[9]--;
	}

	virtual string Speak()
	{ 
		return GetName() + " Says : 'Squeek'!\n";
	}
	
};
//- Sub Rodent
class Mouse : public Rodent
{
public:
	Mouse(string name) : Rodent(name) {}
	~Mouse() {}
	string Speak()
	{
		return GetName() + " Says : 'Squeek'!\n";
	}
};
class Ferret : public Rodent
{
public:
	Ferret(string name) : Rodent(name) {}
	~Ferret() {}
	string Speak()
	{
		return GetName() + " Says : 'Dook'!\n";
	}
};

#endif // !ANIMAL_H