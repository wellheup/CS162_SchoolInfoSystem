/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Implements the Person class 
*********************************************************************/
#include <string>
#include <iostream>
#include <chrono> //used for alternate random generator
#include <random> 
#include <sstream>
#include <iomanip>
#include "person.hpp"


Person::Person() {
	this->setName("Unnamed");
	this->setAge(-1);
	this->setIDType(0);
}
/*********************************************************************
** Description: creates a person based on name and age parameters
*********************************************************************/
Person::Person(std::string name, int age){
	this->setName(name);
	this->setAge(age);
	this->setIDType(0);
}
Person:: ~Person(){}

void Person::setName(std::string name){
	this->name = name;
}

void Person::setAge(int age){
	this->age = age;
}

std::string Person::getName()
{
	return this->name;
}

int Person::getAge()
{
	return this->age;
}

int Person::getIDType()
{
	return this->idType;
}

void Person::setIDType(int idType){
	this->idType = idType;
}

/*********************************************************************
** Description: returns a string of the current stats of this object
*********************************************************************/
std::string Person::returnStats(){
	std::string stats = "Person: " + this->getName() + ", Age: " + std::to_string(this->getAge())
		+ ", Rating: ";
	return stats;
}

/*********************************************************************
** Description: generates a random amount of work done by this object
** and prints that work to the console
*********************************************************************/
void Person::do_work(){
	std::cout << this->getName() << " did " << rdmDoubleInRangeAsStr(minWorkHours, maxWorkHours)
		<< " of work as a regular human being." << std::endl;
}

/*********************************************************************
** Description: generates a random double within range parameters
*********************************************************************/
std::string Person::rdmDoubleInRangeAsStr(double low, double high){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> distribution(low, high);
	double roll = distribution(generator);

	return formatDouble(roll);
}

/*********************************************************************
** Description: formats a double parameter and returns it as a string
** with only 1 decimal of precision
*********************************************************************/
std::string Person::formatDouble(double formatThis){
	//https://stackoverflow.com/questions/29200635/convert-float-to-string-with-precision-number-of-decimal-digits-specified
	std::stringstream stream;
	stream << std::fixed << std::setprecision(1) << std::setfill('0') << formatThis;
	return stream.str();
}


