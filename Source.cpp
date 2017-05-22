#include <iostream>
#include <Windows.h>
#include "Animal.h"
using namespace std;

// A function that allows me to type less each time I want an animal to talk
void Talk(Animal* a)
{
	a->OutputMessage(a->Speak());
}
void Talk(Animal a)
{
	a.OutputMessage(a.Speak());
}

// Main
int main() 
{
	// Create a default animal object pointer that wount be counted in animals.
	Animal* a_Ob = new Animal(false);
	
	// Create a cute calico pointer
	Calico* cat1 = new Calico("Cici");
	Talk(cat1);
	
	// Create a cute persian pointer
	Persian* cat2 = new Persian("Molly");
	Talk(cat2);
	
	// Create a default cat pointer
	Cat* cat3 = new Cat("Beau");
	Talk(cat3);
	
	// Create a Parakeet pointer
	Parakeet* bird1 = new Parakeet("Petree");
	Talk(bird1);
	
	// Create a Parrot pointer
	Parrot* bird2 = new Parrot("Crackers");
	Talk(bird2);

	// Display animals
	a_Ob->GetAnimals();

	delete cat1;
	delete cat2;
	delete cat3;
	delete bird1;
	delete bird2;

	// Display animals again
	a_Ob->GetAnimals();

	// Press Any Key
	cin.get();
	return 0;
}