#include "Ticket.h"
#include "Guest.h"
#include "Event.h"
int Ticket::ticketsSold = 0;

int main()
{
	// Testing Ticket class methods
	int a[]{ 12, 22, 1 };
	int b[]{ 9, 10, 12, 13 };

	Ticket c;
	cout << c << endl;

	Ticket c1(100, 4, "George", "spectacol", 3, a);
	cout << c1 << endl;

	Ticket c2(200, 4, "Alex", "concert", 4, b);
	cout << c2 << endl;
	cout << c2.getguestName() << endl;

	c2.setticketPrice(-5);

	c2.setguestName("Tudor");
	cout << c2.getguestName() << endl << endl;

	c2.setseatNumbers(3, a);
	for (int i = 0; i < 3; i++)
		cout << *(c2.getseatNumbers() + i) << " ";
	cout << endl << endl;

	cout << c2 << endl;
	c2 = c1;
	cout << c2 << endl;

	Ticket copie1(c1);
	cout << copie1 << endl;

	cout << c2.getid();

	cout << endl << endl;
	cout << "Total bilete vandute: " << Ticket::getticketsSold() << endl << endl;

	//cin >> c;
	cout << c;

	// Testing Event class methods
	Event e;
	cout << e.getZone() << endl;
	Event e1(100, 1000, "serbare", Event::Zone::VIP);
	cout << e1.getZone() << endl;
	Event copie2(e1);
	cout << copie2.getEntryFee() << endl;
	cout << copie2.getZone() <<endl <<endl;
	cout << e.getId() << endl << e1.getId() << endl << copie2.getId() << endl << endl;

	// Testing Guest class methods
	
	Guest g;
	Guest g1("Mihai", 4, b);
	Guest g2(g1);

	cout << g2.getgroupSize() << endl;
	cout << g2.getguestName() << endl;
	for (int i = 0; i < 4; i++)
		cout << *(g2.getseatNumbers() + i) << " ";
	cout << endl << endl;

	g2.setguestName("Mircea");
	cout << g2.getguestName() << endl;

	g2.setseatNumbers(3, a);
	for(int i = 0; i<3; i++)
		cout << *(g2.getseatNumbers() + i) << " ";
	cout << endl << endl;
	
	// Creating a Ticket based on an Event and a Guest

	Ticket t(e1,g1);
	cout << t;
}