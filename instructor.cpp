/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Implements the instructor class
*********************************************************************/
#include <string>
#include <iostream>
#include "person.hpp"
#include "instructor.hpp"

Instructor::Instructor() {
	this->setRating(0.0);
	this->setIDType(1);
}

Instructor::Instructor(std::string name, int age, double rating) {
	this->setName(name);
	this->setAge(age);
	this->setRating(rating);
	this->setIDType(1);
}

void Instructor::setRating(double rating){
	this->rating = rating;
}

double Instructor::getRating()
{
	return this->rating;
}

void Instructor::do_Work(){
	std::cout << this->getName() << " graded papers for " << rdmDoubleInRangeAsStr(minWorkHours, maxWorkHours)
		<< " hours." << std::endl;
}

std::string Instructor::returnStats()
{
	std::string stats = "Instructor: " + this->getName() + ", Age: " + std::to_string(this->getAge())
		+ ", Rating: " + formatDouble(this->getRating());
	return stats;
}

double Instructor::getRateGPA(){
	return this->getRating();
}



