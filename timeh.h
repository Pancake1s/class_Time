#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int minute;
	int hour;
public:
	Time();
	Time(int hour, int minute);
	void AddMin(int minute);
	void AddHour(int hour);
	Time& operator+(const Time& other) const;
	Time& operator-(const Time& other) const;
	Time& operator=(const Time& other);
	Time& operator*(double mult) const;
	friend Time& operator*(double mult, Time& other) {
		return other * mult;
	};
	friend ostream& operator<<(ostream& os, Time& t);
	void Show();
	~Time();
};