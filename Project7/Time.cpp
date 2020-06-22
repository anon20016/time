#include "Time.h"
#include <stdexcept>
#include "Time.h"

int Time::Sec()
{
	return getHours() * 3600 + getMin() * 60 + getSec();
}

void Time::Sec(const int s)
{
	setHours((s / 3600) % 24);
	setMin((s % 3600) / 60);
	setSec(s % 60);
}


Time::Time()
{
	setHours(0);
	setMin(0);
	setSec(0);
}

Time::Time(int h, int m, int s)
{
	setHours(h);
	setMin(m);
	setSec(s);
}

Time::Time(int s)
{
	Sec(s);
}

Time::Time(const Time& t)
{
	setHours(t.hours);
	setMin(t.min);
	setSec(t.sec);
}

int Time::getSec()
{
	return sec;
}

int Time::getMin()
{
	return min;
}

int Time::getHours()
{
	return hours;
}

void Time::setSec(int s)
{
	if (s >= 0 && s <= 59) {
		sec = s;
	}
	else {
		throw std::invalid_argument("Sec out of range");
	}
}

void Time::setMin(int m)
{
	if (m >= 0 && m <= 59) {
		min = m;
	}
	else {
		throw std::invalid_argument("Min out of range");
	}
}

void Time::setHours(int h)
{
	if (h >= 0 && h <= 23) {
		hours = h;
	}
	else {
		throw std::invalid_argument("Hours out of range");
	}
}

const Time Time::operator+(const Time& rv)
{
	return Time(Sec() + rv.sec + rv.min * 60 + rv.hours * 3600);
}

const Time Time::operator-(const Time& rv)
{
	return Time(Sec() - rv.sec - rv.min * 60 - rv.hours * 3600);
}

void Time::addSec(int s)
{
	Sec(Sec() + s);
}

void Time::decSec(int s)
{
	if (Sec() - s >= 0) {
		Sec(Sec() - s);
	}
	else {
		throw std::invalid_argument("Sec out of range");
	}
}

std::string Time::ToString()
{
	return std::to_string(getHours()) + ":" + std::to_string(getMin()) + ":" + std::to_string(getSec());
}


