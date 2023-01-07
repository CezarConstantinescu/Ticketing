#ifndef EVENT_H
#define EVENT_H
#include <iostream>
using namespace std;

class Event
{
private:
	int venueSeats;
	int venueRows;
	std::string eventName;
public:
	Event();
	Event(int venueSeats,
		int venueRows,
		std::string eventName);
	~Event();
	Event(const Event& c);
};

#endif