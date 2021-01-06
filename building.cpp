/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Implements the university class
*********************************************************************/
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "building.hpp"

Building::Building(){
	this->setName("unnamed");
	this->setAddress("no address");
	this->setSize(0);
}

/*********************************************************************
** Description: creates a building based on name, address and size 
** parameters
*********************************************************************/
Building::Building(std::string name, std::string address, double size){
	this->setName(name);
	this->setAddress(address);
	this->setSize(size);
}
Building::~Building(){}

void Building::setName(std::string name){
	this->name = name;
}

void Building::setAddress(std::string address){
	this->address = address;
}

void Building::setSize(double size){
	this->size = size;
}

std::string Building::getName()
{
	return this->name;
}

std::string Building::getAddress()
{
	return this->address;
}

double Building::getSize()
{
	return this->size;
}

/*********************************************************************
** Description: returns a string of the current stats of this object
*********************************************************************/
std::string Building::returnStats()
{
	std::string stats = this->getName() + ", " + this->getAddress() + ": "
		+ formatDouble(this->getSize()) + " square feet";

	return stats;
}

/*********************************************************************
** Description: formats a double parameter and returns it as a string
** with only 2 decimal of precision
*********************************************************************/
std::string Building::formatDouble(double formatThis) {
	//https://stackoverflow.com/questions/29200635/convert-float-to-string-with-precision-number-of-decimal-digits-specified
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << std::setfill('0') << formatThis;
	return stream.str();
}
