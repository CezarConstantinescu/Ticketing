#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include "Event.h"
#include "Guest.h"
using namespace std;

class Ticket {

	static int ticketsSold;

private:
	int id;
	int ticketPrice;
	char* guestName;
	std::string eventName;
	int numberOfSeats;
	int* seatNumbers;

public:
	Ticket();
	Ticket(int id,
		int ticketPrice,
		const char* guestName,
		string eventName,
		int numberOfSeats,
		int* seatNumbers);
	Event e;
	Guest g;
	Ticket(Event e , Guest g);
	~Ticket();
	Ticket(const Ticket& c);
	Ticket& operator=(const Ticket& c);
	Ticket& operator++();
	Ticket operator++(int);
	Ticket& operator--();
	Ticket operator--(int);
	static int getticketsSold();
	int getid();
	char* getguestName();
	int getticketPrice();
	int* getseatNumbers();
	void seteventName(string eventName);
	void setticketPrice(int ticketPrice);
	void setguestName(const char* guestName);
	void setseatNumbers(int numberOfSeats, int* seatNumbers);
	friend ostream& operator<<(ostream& out, const Ticket& c);
	friend istream& operator>>(istream& in, Ticket& c);
};

#endif