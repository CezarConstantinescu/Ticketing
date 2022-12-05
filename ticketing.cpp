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

	Ticket& operator=(const Ticket& c)
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

	Ticket& operator++()
	{
		this->ticketPrice++;

		return *this;
	}

	Ticket operator++(int)
	{
		Ticket Copie(*this);

		Ticket::operator++();

		return Copie;
	}

	Ticket& operator--()
	{
		this->ticketPrice--;

		return *this;
	}

	Ticket operator--(int)
	{
		Ticket Copie(*this);

		Ticket::operator--();

		return Copie;
	}

    static int getticketsSold() { return ticketsSold; }

	const int getid() { return this->id; }
	char* getguestName() { return this->guestName; }
	int getticketPrice() { return this->ticketPrice; }
	int* getseatNumbers() { return this->seatNumbers; }

	void setticketPrice(int ticketPrice)
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

	void setguestName(const char* guestName)
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

	void setseatNumbers(int numberOfSeats, int* seatNumbers)
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

    friend ostream& operator<<(ostream& out, const Ticket& c)
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

	friend istream& operator>>(istream& in, Ticket& c)
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

		cout << "Locurile = " << endl;

		delete[] c.seatNumbers;

		c.seatNumbers = new int[c.numberOfSeats];

		for (int i = 0; i < c.numberOfSeats; i++)
		{
			cout << "\tPersoana " << i + 1 << " va sta pe locul: ";
			in >> c.seatNumbers[i];
		}

		return in;
	}
};

int Ticket::ticketsSold = 0; 


int main()
{
    int a[]{ 12, 22, 1 };

	Ticket c;
	cout << c;
	Ticket c1(100, 4, "george", "000", 3, a);
	cout << c1;
	
	Ticket c2(200, 4, "alex", "002", 3, a);
	cout << c2;
	cout << c2.getguestName();
	c2.setticketPrice(-5);
	cout << endl << endl;
	c2.setguestName("Tudor");
	cout << c2.getguestName();

	cout << c2;
	c2 = c1;
	cout << c2;

	Ticket Copie(c1);
	cout << Copie;
	std::cout << c2.getid();

	cout << endl << endl;
	cout << "Obiecte active: " << Ticket::getticketsSold();

	cin >> c;
	cout << c;
}