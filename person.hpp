/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Specifies the Person class
*********************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP
class Person{
private: 
	
protected:
	
public:
	std::string name = "";
	int age, idType, minWorkHours=1, maxWorkHours=80;
	Person();
	Person(std::string name, int age);
	virtual ~Person() = 0;
	virtual void do_Work()=0;
	void setName(std::string name);
	void setAge(int age);
	std::string getName();
	int getAge();
	int getIDType();
	void setIDType(int idType);
	virtual std::string returnStats();
	virtual void do_work();
	std::string rdmDoubleInRangeAsStr(double low, double high);
	std::string formatDouble(double formatThis);
	virtual double getRateGPA() = 0;
};
#endif