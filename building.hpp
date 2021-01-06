/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Specifies the university class
*********************************************************************/
#ifndef BUILDING_HPP
#define BUILDING_HPP
class Building{
private: 
	std::string name,
		address;
	double size;//in square feet

protected:
	
public:
	Building();
	Building(std::string name, std::string address, double size);
	~Building();
	void setName(std::string name);
	void setAddress(std::string address);
	void setSize(double size);
	std::string getName();
	std::string getAddress();
	double getSize();
	std::string returnStats();
	std::string formatDouble(double formatThis);
};
#endif