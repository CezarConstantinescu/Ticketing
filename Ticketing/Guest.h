#ifndef GUEST_H
#define GUEST_H
#include <iostream>
using namespace std;

class Guest
{
private:
	char* guestName;
	int groupSize;
	int* seatNumbers;
public:
	Guest();
	Guest(char* guestName,
		int groupSize,
		int* seatNumbers);
	~Guest();
	Guest(const Guest& c);
};

#endif
