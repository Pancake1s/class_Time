#include "timeh.h"

Time::Time() {
	minute = hour = 0;
}

Time::Time(int hour, int minute) {
	this->minute = minute;
	this->hour = hour + minute / 60;
	this->minute %= 60;
}

void Time::AddMin(int minute){
	this->minute += minute;
	this->hour += this->minute / 60;
	this->minute %= 60;
}

void Time::AddHour(int hour)
{
	this->hour += hour;
}

Time& Time::operator+(const Time& other) const
{
	Time temp(*this);
	temp.minute += other.minute;
	temp.hour += (other.hour + temp.minute / 60);
	temp.minute %= 60;
	return temp;
}

Time& Time::operator-(const Time& other) const
{
	Time temp(*this);
	temp.minute -= other.minute;
	if (temp.minute < 0){
		temp.hour -= (other.hour + 1);
		temp.minute = 60 - temp.minute;
	}
	else {
		temp.hour -= other.hour;
	}

	if (temp.hour < 0){
		temp.hour = temp.minute = 0;
	}
	return temp;
}

Time& Time::operator=(const Time& other) {
	this->minute = other.minute;
	this->hour = other.hour;
	return *this;
}

Time& Time::operator*(double mult) const
{
	Time temp;
	long total = (hour * 60 + minute) * mult;
	temp.hour = total / 60;
	temp.minute = total % 60;
	return temp;
}

ostream& operator<<(ostream& os, Time& t)
{
	os << t.hour << " hour  " << t.minute << " minute";
	return os;
}

void Time::Show(){
	cout << hour << " hour  " << minute << " minute\n";
}

Time::~Time() {};
