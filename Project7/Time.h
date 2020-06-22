#pragma once
#include <string>

class Time
{
private:
	int sec, min, hours;
		
	// Convert Time from Sec
	void Sec(const int s);
public:
	Time();
	Time(int s, int m, int h);
	Time(int s);
	Time(const Time& t);

	int getSec();
	int getMin();
	int getHours();

	void setSec(int s);
	void setMin(int m);
	void setHours(int h);

	const Time operator+(const Time& rv);
	const Time operator-(const Time& rv);

	// Convert Time to Sec
	int Sec();

	void addSec(int s);
	void decSec(int s);

	std::string ToString();
};

