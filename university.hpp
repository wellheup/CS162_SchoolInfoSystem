/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Specifies the university class which can read and 
** write directories of either people or buildings to .txt files
** as well as add or remove them
*********************************************************************/
#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP
#include <vector>
#include <string>
class Person; 
class Building;
class Instructor;
class Student;

class University{
private: 
	
	std::vector<Building*> buildings;
	std::vector<Person*> people;
	std::string universityName;
protected:
	
public:
	University();

	University(bool run);

	~University();

	std::string getName();

	void setName(std::string name);

	void mainMenu();

	void printPeopleDirectory();

	void printBuildingDirectory();

	void getWorkReport();

	void addToDirectory();

	void addPersonToDirectory();

	void addBuildingToDirectory();

	void removeFromDirectory();

	void removePersonFromDirectory();

	void removeBuildingFromDirectory();

	void loadDirectory();

	void saveDirectory();
};
#endif