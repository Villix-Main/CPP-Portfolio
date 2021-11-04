#include <iostream>


class PersonBase
{
public:
	PersonBase() { }
	virtual ~PersonBase() { }    
};


class Person : public PersonBase
{
public:
	Person() { }
};

class SpecialPerson : public PersonBase
{
public:
	SpecialPerson() { }
};

void RunCastFile()
{
	// Type Punning 
	/*Person person{ 20, 15 };
	
	int* mPosition = (int*)&person;
	
	int age = *(int*)((char*)&person + 4);;

	std::cout << mPosition[0] << std::endl;
	std::cout << age << std::endl;*/

	// Type Casting
	double value = 10.15;
	double cValue = static_cast<int>(value) + 5.50;

	
	Person* person = new Person();
	PersonBase* base = person;
	SpecialPerson* sPerson = new SpecialPerson();   

	//SpecialPerson* sp = dynamic_cast<SpecialPerson*>(sPerson);
	SpecialPerson* sp = dynamic_cast<SpecialPerson*>(base); // This will be NULL as base is not a instance of SpecialPerson class
	PersonBase* basePerson = dynamic_cast<PersonBase*>(person); // This will be a value/TRUE as person is a instance of PerosnBase class

	if (!sp)
	{
		std::cout << "'base' is not a instance of 'specialPerson'";
	}


	std::cin.get(); 
}