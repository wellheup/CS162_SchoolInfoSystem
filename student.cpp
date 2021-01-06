/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Implements the Student class
*********************************************************************/
#include <string>
#include <iostream>
#include "person.hpp"
#include "student.hpp"

Student::Student() {
	this->setGPA(0.0);
	this->setIDType(2);
}

Student::Student(std::string name, int age, double GPA){
	this->setName(name);
	this->setAge(age);
	this->setGPA(GPA);
	this->setIDType(2);
}

void Student::setGPA(double GPA){
	this->GPA = GPA;
}

double Student::getGPA(){
	return this->GPA;
}

void Student::do_Work() {
	std::cout << this->getName() << " did " << rdmDoubleInRangeAsStr(minWorkHours, maxWorkHours)
		<< " hours of homework." << std::endl;
}

std::string Student::returnStats(){
	std::string stats = "Student: " + this->getName() + ", Age: " + std::to_string(this->getAge())
		+ ", GPA: " + formatDouble(this->getGPA());

	return stats;
}

double Student::getRateGPA(){
	return this->getGPA();
}

