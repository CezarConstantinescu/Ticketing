#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//TODO: I will split this into multiple files later
class Ticket {

	static int ticketsSold; 

private:
	const int id;
	int ticketPrice;
	char* guestName;
	string eventName;
	int numberOfSeats;
	int* seatNumbers;

public:
	Ticket()
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

	Ticket(const int id,
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
    	~Ticket()
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

	Ticket(const Ticket& c)
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

    static int getobiecteActive() { return ticketsSold; }

	const int getid() { return this->id; }
	char* getnumeStapan() { return this->guestName; }
	int getnumarMembre() { return this->ticketPrice; }
	int* getdataVaccin() { return this->seatNumbers; }

	void setnumarMembre(int ticketPrice)
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

	void setnumeStapan(const char* guestName)
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
			cout << "input invalid";
		}
	}

	void setdataVaccin(int numberOfSeats, int* seatNumbers)
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

};

int Ticket::ticketsSold = 0; 


int main()
{
    int a[]{ 12, 22, 1 };
	Ticket c;
    Ticket c1(100, 4, "george", "000", 3, a);
}