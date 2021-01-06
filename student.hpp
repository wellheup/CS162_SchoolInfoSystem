
/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Specifies the Student class
*********************************************************************/
#ifndef STUDENT_HPP
#define STUDENT_HPP
class Student : public Person{
private: 
	
protected:
	double GPA;
public:
	Student();
	Student(std::string name, int age, double GPA);
	double getGPA();
	void setGPA(double GPA);
	void do_Work() override;
	std::string returnStats() override;
	double getRateGPA() override;
};
#endif