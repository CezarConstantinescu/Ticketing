#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Ticket.h"

Ticket::Ticket()
	:id(0), ticketPrice(0), guestName(nullptr), eventName(""), numberOfSeats(0), seatNumbers(nullptr)
{
	ticketPrice = 0;
	guestName = new char[strlen("Anonim") + 1];
	strcpy(guestName, "Anonim");

	eventName = "";

	numberOfSeats = 0;

	seatNumbers = new int;
	*seatNumbers = 0;

	ticketsSold++;
}
Ticket::Ticket(int id,
	int ticketPrice,
	const char* guestName,
	string eventName,
	int numberOfSeats,
	int* seatNumbers)
	:id(id), ticketPrice(0), guestName(nullptr), eventName(""), numberOfSeats(0), seatNumbers(nullptr)
{
	this->ticketPrice = ticketPrice;

	this->guestName = new char[strlen(guestName) + 1];
	strcpy(this->guestName, guestName);

	this->eventName = eventName;

	this->numberOfSeats = numberOfSeats;

	this->seatNumbers = new int[numberOfSeats];
	for (int i = 0; i < numberOfSeats; i++)
	{
		this->seatNumbers[i] = seatNumbers[i];
	}

	ticketsSold++;
}
Ticket::Ticket(Event e, Guest g)
	:id(id), ticketPrice(0), guestName(nullptr), eventName(""), numberOfSeats(0), seatNumbers(nullptr)
{
	ticketsSold++;
	this->id = e.getId() + ticketsSold;

	this->ticketPrice = e.getEntryFee();

	this->guestName = new char[strlen(g.getguestName()) + 1];
	strcpy(this->guestName, g.getguestName());

	this->eventName = e.getEventName();

	this->numberOfSeats = g.getgroupSize();

	this->seatNumbers = new int[this->numberOfSeats];
	for (int i = 0; i < this->numberOfSeats; i++)
	{
		this->seatNumbers[i] = g.getseatNumbers()[i];
	}
}
Ticket::~Ticket()
{
	if (this->guestName != nullptr)
	{
		delete[] this->guestName;
	}

	if (this->seatNumbers != nullptr)
	{
		delete[] this->seatNumbers;
	}

	ticketsSold--;
}

Ticket::Ticket(const Ticket& c)
	:id(c.id)
{
	this->ticketPrice = c.ticketPrice;

	this->guestName = new char[strlen(c.guestName) + 1];
	strcpy(this->guestName, c.guestName);

	this->eventName = c.eventName;

	this->numberOfSeats = c.numberOfSeats;

	this->seatNumbers = new int[c.numberOfSeats];
	for (int i = 0; i < c.numberOfSeats; i++)
	{
		this->seatNumbers[i] = c.seatNumbers[i];
	}

	ticketsSold++;
}

Ticket& Ticket::operator=(const Ticket& c)
{
	if (this != &c)
	{
		this->ticketPrice = c.ticketPrice;

		if (this->guestName != nullptr)
		{
			delete[] this->guestName;
		}

		this->guestName = new char[strlen(c.guestName) + 1];
		strcpy(this->guestName, c.guestName);

		this->eventName = c.eventName;

		this->numberOfSeats = c.numberOfSeats;

		if (this->seatNumbers != nullptr)
		{
			delete[] this->seatNumbers;
		}

		this->seatNumbers = new int[c.numberOfSeats];
		for (int i = 0; i < c.numberOfSeats; i++)
		{
			this->seatNumbers[i] = c.seatNumbers[i];
		}
	}

	return *this;
}

Ticket& Ticket::operator++()
{
	this->ticketPrice++;

	return *this;
}

Ticket Ticket::operator++(int)
{
	Ticket Copie(*this);

	Ticket::operator++();

	return Copie;
}

Ticket& Ticket::operator--()
{
	this->ticketPrice--;

	return *this;
}

Ticket Ticket::operator--(int)
{
	Ticket Copie(*this);

	Ticket::operator--();

	return Copie;
}

int Ticket::getticketsSold() { return ticketsSold; }

int Ticket::getid() { return this->id; }
char* Ticket::getguestName() { return this->guestName; }
int Ticket::getticketPrice() { return this->ticketPrice; }
string Ticket::geteventName(){ return this->eventName; }
int Ticket::getnumberOfSeats() { return this->numberOfSeats; }
int* Ticket::getseatNumbers() { return this->seatNumbers; }

void Ticket::seteventName(string eventName)
{
	if (eventName != "")
	{
		this->eventName = eventName;
	}
	else
	{
		cout << "\nInput invalid" << endl << endl;
	}
}

void Ticket::setticketPrice(int ticketPrice)
{
	if (ticketPrice > 0)
	{
		this->ticketPrice = ticketPrice;
	}
	else
	{
		cout << "\nInput invalid" << endl << endl;
	}
}

void Ticket::setguestName(const char* guestName)
{
	if (guestName != nullptr)
	{
		if (this->guestName != nullptr)
		{
			delete[] this->guestName;
		}
		this->guestName = new char[strlen(guestName) + 1];
		strcpy(this->guestName, guestName);
	}
	else
	{
		cout << "\nInput invalid" << endl << endl;
	}
}

void Ticket::setseatNumbers(int numberOfSeats, int* seatNumbers)
{
	if (numberOfSeats > 0 && seatNumbers != nullptr)
	{
		this->numberOfSeats = numberOfSeats;

		if (this->seatNumbers != nullptr)
		{
			delete[] this->seatNumbers;
		}

		this->seatNumbers = new int[numberOfSeats];
		for (int i = 0; i < numberOfSeats; i++)
		{
			this->seatNumbers[i] = seatNumbers[i];
		}
	}
	else
	{
		cout << "\nInput invalid" << endl << endl;
	}
}

ostream& operator<<(ostream& out, const Ticket& c)
{
	out <<"ID: "<<  c.id << endl
		<< "Price: "<< c.ticketPrice << "$" << endl
		<< "Guest name: " << c.guestName << endl
		<< "Event : " << c.eventName << endl
		<< "Number of seats: " << c.numberOfSeats << endl
		<< "Seats: ";
	if (c.numberOfSeats == 0) out << "none";
	for (int i = 0; i < c.numberOfSeats; i++)
	{
		out << c.seatNumbers[i] << " ";
	}
	out << endl << endl;
	return out;
}

istream& operator>>(istream& in, Ticket& c)
{

	cout << "Pret bilet = ";
	in >> c.ticketPrice;

	cout << "Nume = ";

	char aux[1000];
	in >> aux;

	delete[] c.guestName;

	c.guestName = new char[strlen(aux) + 1];
	strcpy(c.guestName, aux);

	cout << "Nume eveniment = ";
	in >> c.eventName;

	cout << "Nr de scaune = ";
	in >> c.numberOfSeats;

	cout << "Locurile: " << endl;

	delete[] c.seatNumbers;

	c.seatNumbers = new int[c.numberOfSeats];

	for (int i = 0; i < c.numberOfSeats; i++)
	{
		cout << "\tPersoana " << i + 1 << " va sta pe locul: ";
		in >> c.seatNumbers[i];
	}

	return in;
}