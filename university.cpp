/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Implements the university class which can read and 
** write directories of either people or buildings to .txt files
** as well as add or remove them
*********************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "university.hpp"
#include "person.hpp"
#include "building.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "menuShell.hpp"

University::University() {
	this->setName("Oregon State University");
}
/*********************************************************************
** Description: Running the constructor with 
** a true parameter will automatically run the directory
*********************************************************************/
University::University(bool run){
	this->setName("Oregon State University");
	if (run == true) {
		mainMenu();
	}
}
University::~University() {
	for (unsigned int i = 0; i < buildings.size(); i++) {
		delete buildings[i];
	}
	for (unsigned int i = 0; i < people.size(); i++) {
		delete people[i];
	}
}

//getters and setters
std::string University::getName(){
	return this->universityName;
}
void University::setName(std::string name){
	this->universityName = name;
}

/*********************************************************************
** Description: provides a menu for navigating the University directory
** program
*********************************************************************/
void University::mainMenu() {
	std::string welcome = "\nWelcome to the "+ this->getName() +" directory, what would you like to do?",
		printPeopleStr = "1. Print the personnel directory",
		printBuildingsStr = "2. Print the building directory",
		workReportStr = "3. Print a person's work report",
		addEntriesStr = "4. Add/Remove buildings/people to/from the directory",
		askSaveLoadStr = "5. Save/Load directory to/from file (EXTRA CREDIT)",
		exitDirectoryStr = "6. Exit the directory";
	bool exitDirectory = false;
	while (exitDirectory == false) {
		int choice = choiceMenu5(welcome, printPeopleStr, printBuildingsStr, workReportStr, addEntriesStr, askSaveLoadStr, exitDirectoryStr);
		if (choice == 1) {
			printPeopleDirectory();
		}
		else if (choice == 2) {
			printBuildingDirectory();
		}
		else if (choice == 3) {
			getWorkReport();
		}
		else if (choice == 4) {
			std::string askAddRemoveStr = "Would you like to add or remove?",
				addStr = "1. Add",
				removeStr = "2. Remove",
				exitAddRemove = "3. Exit";
			int addRemove = choiceMenu2(askAddRemoveStr, addStr, removeStr, exitAddRemove);
			if (addRemove == 1) {
				addToDirectory();
			}
			else if (addRemove == 2) {
				removeFromDirectory();
			}
		}
		else if (choice == 5) {
			std::string askSaveLoadStr2 = "Would you like to save or load?",
				saveStr = "1. Save",
				loadStr = "2. Load",
				exitSaveLoadStr = "3. Exit";
			int saveLoad = choiceMenu2(askSaveLoadStr2, saveStr, loadStr, exitSaveLoadStr);
			if (saveLoad == 1) {
				saveDirectory();
			}
			else if (saveLoad == 2) {
				loadDirectory();
			}
		}
		else {
			exitDirectory = true;
		}
	}
}

/*********************************************************************
** Description: prints out all of the attributes of the people in the
** currently loaded directory
*********************************************************************/
void University::printPeopleDirectory() {
	for (unsigned int i = 0; i < people.size(); i++) {
		std::cout << people[i]->returnStats() << "\n" << std::endl;
	}
}

/*********************************************************************
** Description: prints out all of the attributes of all buildings in
** the currently loaded directory
*********************************************************************/
void University::printBuildingDirectory() {
	for (unsigned int i = 0; i < buildings.size(); i++) {
		std::cout << buildings[i]->returnStats() << std::endl;
	}
}

/*********************************************************************
** Description: provides the user with a list of the people in the
** currently loaded directory and allows them to call the do_Work()
** method for a person
*********************************************************************/
void University::getWorkReport() {
	if (people.size() > 0) {
		std::cout << "Here are your options: " << std::endl;
		for (unsigned int i = 0; i < people.size(); i++) {
			std::cout << i << ". " << people[i]->getName() << std::endl;
		}
		int choice = chooseIntInRange("Who would you like to do work?", 0, people.size());
		people[choice]->do_Work();
	}
	else {
		std::cout << "There are no people in the directory to do work." << std::endl;
	}
}

/*********************************************************************
** Description: uses menus to select whether to add people or buildings
** to the directory
*********************************************************************/
void University::addToDirectory() {
	std::string addWhatStr = "What would you like to add to the directory?",
		addPersonStr = "1. Add a person",
		addBuildingStr = "2. Add a building",
		exitAddStr = "3. Nevermind";

	int choice = choiceMenu2(addWhatStr, addPersonStr, addBuildingStr, exitAddStr);
	if (choice == 1) {
		addPersonToDirectory();
	}
	else if (choice == 2) {
		addBuildingToDirectory();
	}
}

/*********************************************************************
** Description: uses menus to walk the user through adding a new 
** person (student or instructor) to the current directory
*********************************************************************/
void University::addPersonToDirectory() {
	int choice = choiceMenu1("What kind of person is this?", "1. Instructor", "2. Student");
	if (choice == 1) {
		std::string name = enterStringWithinRange("What is their name? ", 1, 50);
		int age = chooseIntInRange("What is their age? ", 19, 100);
		double rating = chooseDoubleInRange("What is their rating? ", 0.0, 5.0);
		people.push_back(new Instructor(name, age, rating));
	}
	else if (choice == 2) {
		std::string name = enterStringWithinRange("What is their name? ", 1, 50);
		int age = chooseIntInRange("What is their age? ", 19, 100);
		double GPA = chooseDoubleInRange("What is their GPA? ", 0.0, 5.0);
		people.push_back(new Student(name, age, GPA));
	}
	else {}
}

/*********************************************************************
** Description: uses menus to walk the user through adding a new 
** building to the current directory
*********************************************************************/
void University::addBuildingToDirectory(){
	std::string buildingName = enterStringWithinRange("What is the building called?", 1, 50);
	std::string buildingAddress = enterStringWithinRange("What is the building's address?", 1, 50);
	double	buildingSize = chooseDoubleInRange("What is the building's size in square feet?", 100, 2000000);
	buildings.push_back(new Building(buildingName, buildingAddress, buildingSize));
}

/*********************************************************************
** Description: uses menus to select whether to remove people or
** buildings from the directory
*********************************************************************/
void University::removeFromDirectory() {
	std::string removeWhatStr = "What would you like to remove from the directory?",
		addPersonStr = "1. Remove a person",
		addBuildingStr = "2. Remove a building",
		exitAddStr = "3. Nevermind";

	int choice = choiceMenu2(removeWhatStr, addPersonStr, addBuildingStr, exitAddStr);
	if (choice == 1) {
		removePersonFromDirectory();
	}
	else if (choice == 2) {
		removeBuildingFromDirectory();
	}
}

/*********************************************************************
** Description: uses menus to walk the user through removing a person
** (student or instructor) from the currently loaded directory
*********************************************************************/
void University::removePersonFromDirectory(){
	if (people.size() > 0) {
		std::cout << "Here are your options: " << std::endl;
		for (unsigned int i = 0; i < people.size(); i++) {
			std::cout << i << ". " << people[i]->getName() << std::endl;
		}
		int choice = chooseIntInRange("Who would you like to remove from the directory?", 0, people.size());
		people.erase(people.begin() + choice); //http://www.cplusplus.com/reference/vector/vector/erase/
	}
	else {
		std::cout << "There are no people in the directory to remove." << std::endl;
	}
}

/*********************************************************************
** Description: uses menus to walk the user through removing a building
** from the currently loaded directory
*********************************************************************/
void University::removeBuildingFromDirectory(){
	if (buildings.size() > 0) {
		std::cout << "Here are your options: " << std::endl;
		for (unsigned int i = 0; i < buildings.size(); i++) {
			std::cout << i << ". " << buildings[i]->getName() << std::endl;
		}
		int choice = chooseIntInRange("What building would you like to remove from the directory?", 0, buildings.size());
		buildings.erase(buildings.begin() + choice);
	}
	else {
		std::cout << "There are no buildings in the directory to remove." << std::endl;
	}
}

/*********************************************************************
** Description: allows user to load a directory of buildings or 
** people from a .txt file 
*********************************************************************/
void University::loadDirectory(){
	std::string askTypeInfoStr = "Which type of information would you like to load to the directory?",
		chooseBuildings = "1. Buildings",
		choosePeople = "2. People",
		askFileName = "Please enter a text file to load.",
		inFileName,
		currentLine;
	
	int choice = choiceMenu2(askTypeInfoStr, chooseBuildings, choosePeople, "3. Nevermind");
	std::ifstream inFile;
	inFileName = enterTxtFileWithinRange(askFileName, 1, 30);
	inFile.open(inFileName, std::ios::in);
	if (choice == 1) {
		std::string tempName, tempAddr;
		double tempSize;
		while (inFile.good()) {
			getline(inFile, currentLine);
			tempName = currentLine;
      std::cout<< tempName <<std::endl;
			getline(inFile, currentLine);
			tempAddr = currentLine;
      std::cout<<tempAddr<<std::endl;
			getline(inFile, currentLine);
			tempSize = std::stod(currentLine);
      std::cout<<tempSize<<std::endl;
			buildings.push_back(new Building(tempName, tempAddr, tempSize));
		}
		std::cout << buildings.size() << " buildings added." << std::endl;
	}
	else if (choice == 2) {
		std::string tempName;
		double tempRateGPA;
		int tempID, tempAge;
		while (inFile.good()) {
			getline(inFile, currentLine);
			tempID = stoi(currentLine);
			if (tempID == 1) {//Instructor
				getline(inFile, currentLine);
				tempName = currentLine;
				getline(inFile, currentLine);
				tempAge = stoi(currentLine);
				getline(inFile, currentLine);
				tempRateGPA = std::stod(currentLine);
				people.push_back(new Instructor(tempName, tempAge, tempRateGPA));
			}
			else if (tempID == 2) {//Student
				getline(inFile, currentLine);
				tempName = currentLine;
				getline(inFile, currentLine);
				tempAge = stoi(currentLine);
				getline(inFile, currentLine);
				tempRateGPA = std::stod(currentLine);
				people.push_back(new Student(tempName, tempAge, tempRateGPA));
			}
		}
		std::cout << people.size() << " people added." << std::endl;
	}
	inFile.close();
}

/*********************************************************************
** Description: allows user to save a people or buildings directory to
** a .txt file
*********************************************************************/
void University::saveDirectory(){
	std::string askTypeInfoStr = "Which type of information would you like to save from the directory?",
		chooseBuildings = "1. Buildings",
		choosePeople = "2. People",
		askFileName = "Please enter a text file to save as.",
		outFileName;

	int choice = choiceMenu2(askTypeInfoStr, chooseBuildings, choosePeople, "3. Nevermind");
	std::ofstream outFile;
	outFileName = enterTxtFileWithinRange(askFileName, 1, 30);
	outFile.open(outFileName, std::ios::out);
	if (choice == 1) {
		for (unsigned int i = 0; i < buildings.size(); i++) {
			if (i > 0) {
				outFile << std::endl;
			}
			outFile << buildings[i]->getName() << std::endl;
			outFile << buildings[i]->getAddress() << std::endl;
			outFile << buildings[i]->getSize();
		}
	}
	else if (choice == 2) {
		for (unsigned int i = 0; i < people.size(); i++) {
			if (i > 0) {
				outFile << std::endl;
			}
			outFile << people[i]->getIDType() << std::endl;
			outFile << people[i]->getName() << std::endl;
			outFile << people[i]->getAge() << std::endl;
			outFile << std::fixed << std::setprecision(1) << std::setfill('0')
				<< people[i]->getRateGPA();
		}
	}
	outFile.close();
}


