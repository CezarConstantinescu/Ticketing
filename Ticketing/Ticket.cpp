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
Ticket::Ticket(const int id,
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

const int Ticket::getid() { return this->id; }
char* Ticket::getguestName() { return this->guestName; }
int Ticket::getticketPrice() { return this->ticketPrice; }
int* Ticket::getseatNumbers() { return this->seatNumbers; }

void Ticket::setticketPrice(int ticketPrice)
{
	if (ticketPrice > 0)
	{
		this->ticketPrice = ticketPrice;
	}
	else
	{
		cout << "Input invalid";
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
		cout << "Input invalid";
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
}

ostream& operator<<(ostream& out, const Ticket& c)
{
	out << c.id << endl
		<< c.ticketPrice << endl
		<< c.guestName << endl
		<< c.eventName << endl
		<< c.numberOfSeats << endl;

	for (int i = 0; i < c.numberOfSeats; i++)
	{
		out << c.seatNumbers[i] << " ";
	}

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