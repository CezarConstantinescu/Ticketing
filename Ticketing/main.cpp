#include "Ticket.h"
#include "Guest.h"
#include "Event.h"
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
	cout << "Total bilete vandute: " << Ticket::getticketsSold() << "\n";

	cin >> c;
	cout << c;
}