//Jamil Khan
//CECS 282 - 05
//Prog 4 - Overloading Operators
//Nov 1, 2018

#include "upDate.h"
#include <string>
#include <iostream>

using namespace std;

int upDate::count = 0;

void Julian2Greg(int JD, int & month, int  & day, int & year) {
	int I, J, K, L, N;
	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;
	year = I;
	month = J;
	day = K;
}

int Greg2Julian(int month, int day, int year) {
	int I, J, K, JD;
	I = year;
	J = month;
	K = day;
	JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
	return JD;
}

upDate::upDate() {
	dptr = new int[3];
	dptr[0] = 5;
	dptr[1] = 11;
	dptr[2] = 1959;
	count++;
}

upDate::upDate(int M, int D, int Y) {
	dptr = new int[3];
	int JD = Greg2Julian(M, D, Y);
	int m1, d1, y1;
	Julian2Greg(JD, m1, d1, y1);
	if (m1 == M && d1 == D && y1 == Y) {
		dptr[0] = M; dptr[1] = D; dptr[2] = Y;
	}
	else {
		dptr[0] = 5; dptr[1] = 11; dptr[2] = 1959;
	}
	count++;
}

upDate::upDate(int J) {
	dptr = new int[3];
	int m1, d1, y1;
	Julian2Greg(J, m1, d1, y1);
	dptr[0] = m1; dptr[1] = d1; dptr[2] = y1;
	count++;
}

upDate::upDate(const upDate &D) {
	dptr = new int[3];
	dptr[0] = D.dptr[0]; dptr[1] = D.dptr[1]; dptr[2] = D.dptr[2];
	count++;
}

upDate::~upDate() {
	delete []dptr;
	count--;
}

void upDate::setDate(int M, int D, int Y) {
	int JD = Greg2Julian(M, D, Y);
	int m1, d1, y1;
	Julian2Greg(JD, m1, d1, y1);
	if (m1 == M && d1 == D && y1 == Y) {
		dptr[0] = M; dptr[1] = D; dptr[2] = Y;
	}
	else {
		dptr[0] = 5; dptr[1] = 11; dptr[2] = 1959;
	}
}

int upDate::getMonth() {
	return dptr[0];
}

int upDate::getDay() {
	return dptr[1];
}

int upDate::getYear() {
	return dptr[2];
}

string upDate::getMonthName() {
	string Month;
	switch (dptr[0]) {
	case 1:
		Month = "January ";
		break;
	case 2:
		Month = "February ";
		break;
	case 3:
		Month = "March ";
		break;
	case 4:
		Month = "April ";
		break;
	case 5:
		Month = "May ";
		break;
	case 6:
		Month = "June ";
		break;
	case 7:
		Month = "July ";
		break;
	case 8:
		Month = "August ";
		break;
	case 9:
		Month = "September ";
		break;
	case 10:
		Month = "October ";
		break;
	case 11:
		Month = "November ";
		break;
	case 12:
		Month = "December ";
		break;
	default:
		break;
	}

	return Month;
}

upDate upDate::operator=(const upDate &D) {
	if (&D != this) {
		dptr[0] = D.dptr[0]; dptr[1] = D.dptr[1]; dptr[2] = D.dptr[2];
	}
	return *this;
}

upDate upDate::operator+=(int n) {
	upDate temp(*this);
	int JD = Greg2Julian(temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	JD += n;
	Julian2Greg(JD, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

upDate upDate::operator-=(int n) {
	upDate temp(*this);
	int JD = Greg2Julian(temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	JD -= n;
	Julian2Greg(JD, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

upDate upDate::operator+(int n) {
	upDate temp(*this);
	int JD = Greg2Julian(temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	JD += n;
	Julian2Greg(JD, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

upDate upDate::operator-(int n) {
	upDate temp(*this);
	int JD = Greg2Julian(temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	JD -= n;
	Julian2Greg(JD, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

upDate operator+(int n, upDate D) {
	upDate temp(D);
	int JD = Greg2Julian(temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	JD += n;
	Julian2Greg(JD, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

upDate operator-(int n, upDate D) {
	upDate temp(D);
	int JD = Greg2Julian(temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	JD -= n;
	Julian2Greg(JD, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

upDate upDate::operator++(int n) {
	upDate temp(*this);
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	JD++;
	Julian2Greg(JD, dptr[0], dptr[1], temp.dptr[2]);
	return temp;
}

upDate upDate::operator++() {
	upDate temp(*this);
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	JD++;
	Julian2Greg(JD, dptr[0], dptr[1], temp.dptr[2]);
	return *this;
}

upDate upDate::operator--(int n) {
	upDate temp(*this);
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	JD--;
	Julian2Greg(JD, dptr[0], dptr[1], temp.dptr[2]);
	return temp;
}

upDate upDate::operator--() {
	upDate temp(*this);
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	JD--;
	Julian2Greg(JD, dptr[0], dptr[1], dptr[2]);
	return *this;
}

int upDate::operator+(const upDate & D) {
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	int JD1 = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
	return JD + JD1;
}

int upDate::operator-(const upDate & D) {
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	int JD1 = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
	return JD - JD1;
}

int upDate::julian() {
	return Greg2Julian(dptr[0], dptr[1], dptr[2]);
}

int upDate::GetDateCount() {
	return count;
}

ostream& operator<<(ostream& os, const upDate & D)
{
	os << D.dptr[0] << '/' << D.dptr[1] << '/' << D.dptr[2];
	return os;
}

bool upDate::operator==(const upDate & D) {
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	int JD1 = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
	if (JD == JD1) {
		return true;
	}
	return false;
}

bool upDate::operator>(const upDate & D) {
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	int JD1 = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
	if (JD > JD1) {
		return true;
	}
	return false;
}

bool upDate::operator<(const upDate & D) {
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	int JD1 = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
	if (JD < JD1) {
		return true;
	}
	return false;
}