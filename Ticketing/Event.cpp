#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Event.h"

Event::Event()
	:venueSeats(0), venueRows(0), eventName("")
{
	venueSeats = 0;
	venueRows = 0;
	eventName = "";
}

Event::Event(int venueSeats,
	int venueRows,
	std::string eventName)
	:venueSeats(0), venueRows(0), eventName("")
{
	this->venueSeats = venueSeats;
	this->venueRows = venueRows;
	this->eventName = eventName;
}

Event::~Event()
{
}

Event::Event(const Event& c)
{
	this->venueSeats = c.venueSeats;
	this->venueRows = c.venueRows;
	this->eventName = c.eventName;
}