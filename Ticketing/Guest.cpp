#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Guest.h"

Guest::Guest()
	:guestName(nullptr), groupSize(0), seatNumbers(nullptr)
{
	guestName = new char[strlen("Anonim") + 1];
	strcpy(guestName, "Anonim");

	groupSize = 0;

	seatNumbers = new int;
	*seatNumbers = 0;
}

Guest::Guest(const char* guestName,
	int groupSize,
	int* seatNumbers)
	:guestName(nullptr), groupSize(0), seatNumbers(nullptr)
{
	this->guestName = new char[strlen(guestName) + 1];
	strcpy(this->guestName, guestName);

	this->groupSize = groupSize;

	this->seatNumbers = new int[groupSize];
	for (int i = 0; i < groupSize; i++)
	{
		this->seatNumbers[i] = seatNumbers[i];
	}
}

Guest::~Guest()
{
	if (this->guestName != nullptr)
	{
		delete[] this->guestName;
	}

	if (this->seatNumbers != nullptr)
	{
		delete[] this->seatNumbers;
	}
}

Guest::Guest(const Guest& c)
{
	this->guestName = new char[strlen(c.guestName) + 1];
	strcpy(this->guestName, c.guestName);

	this->groupSize = c.groupSize;

	this->seatNumbers = new int[c.groupSize];
	for (int i = 0; i < c.groupSize; i++)
	{
		this->seatNumbers[i] = c.seatNumbers[i];
	}
}

char* Guest::getguestName() { return this->guestName; }
int Guest::getgroupSize() { return this->groupSize; }
int* Guest::getseatNumbers() { return this->seatNumbers; }

void Guest::setguestName(const char* guestName)
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

void Guest::setseatNumbers(int groupSize, int* seatNumbers)
{
	if (groupSize > 0 && seatNumbers != nullptr)
	{
		this->groupSize = groupSize;

		if (this->seatNumbers != nullptr)
		{
			delete[] this->seatNumbers;
		}

		this->seatNumbers = new int[groupSize];
		for (int i = 0; i < groupSize; i++)
		{
			this->seatNumbers[i] = seatNumbers[i];
		}
	}
	else
	{
		cout << "\nInput invalid" << endl << endl;
	}
}