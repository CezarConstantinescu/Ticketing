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
	Guest(const char* guestName,
		int groupSize,
		int* seatNumbers);
	~Guest();
	Guest(const Guest& c);
	char* getguestName();
	int getgroupSize();
	int* getseatNumbers();
	void setguestName(const char* guestName);
	void setseatNumbers(int groupSize, int* seatNumbers);
};

#endif
