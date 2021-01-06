/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Specifies the instructor class
*********************************************************************/
#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP
class Instructor : public Person{
private: 
	
protected: 
	double rating;
public:
	Instructor();
	Instructor(std::string name, int age, double rating);
	double getRating();
	void setRating(double rating);
	void do_Work()override;
	std::string returnStats() override;
	double getRateGPA() override;
};
#endif