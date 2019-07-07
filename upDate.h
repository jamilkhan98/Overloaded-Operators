//Jamil Khan
//CECS 282 - 05
//Prog 4 - Overloading Operators
//Nov 1, 2018

#include <string>
using namespace std;

#ifndef UPDATE_H
#define UPDATE_H
class upDate {
private:
	int *dptr;
	static int count;

public:
	upDate();
	upDate(int M, int D, int Y);
	upDate(int J);
	upDate(const upDate &D);
	~upDate();
	void setDate(int M, int D, int Y);
	int getMonth();
	int getDay();
	int getYear();
	string getMonthName();

	upDate operator=(const upDate & D);
	upDate operator+=(int n);
	upDate operator-=(int n);
	upDate operator+(int n);
	upDate operator-(int n);
	upDate operator++(int n);
	upDate operator++();
	upDate operator--(int n);
	upDate operator--();


	friend upDate operator+(int n, upDate D);
	friend upDate operator-(int n, upDate D);

	int operator+(const upDate & D);
	int operator-(const upDate & D);
	int julian();
	static int GetDateCount();

	friend ostream& operator<<(ostream& os, const upDate& D);

	bool operator==(const upDate & D);
	bool operator>(const upDate & D);
	bool operator<(const upDate & D);
};
#endif