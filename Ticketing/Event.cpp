#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include "Event.h"

Event::Event()
	:venueSeats(0), entryFee(0), eventName(""), zone(Zone::LAWN)
{
	venueSeats = 0;
	entryFee = 0;
	eventName = "";
	zone = Zone::LAWN;
	id = generateId();
}

Event::Event(int venueSeats,
	int entryFee,
	std::string eventName,
	Zone zone)
	:venueSeats(0), entryFee(0), eventName(""), zone(Zone::LAWN)
{
	this->venueSeats = venueSeats;
	this->entryFee = entryFee;
	this->eventName = eventName;
	this->zone = zone;
	this->id = generateId();
}

Event::~Event()
{
}

Event::Event(const Event& c)
{
	this->venueSeats = c.venueSeats;
	this->entryFee = c.entryFee;
	this->eventName = c.eventName;
	this->zone = c.zone;
	this->id = c.id;
}

std::string Event::getZone() {
      switch (this->zone) {
        case Zone::VIP:
          return "VIP";
        case Zone::LAWN:
          return "LAWN";
        case Zone::TRIBUNE:
          return "TRIBUNE";
		case Zone::BOXES:
		  return "BOXES";
		default: return "LAWN";
      }
}

int Event::getId() { return this->id; }
int Event::getEntryFee() { return this->entryFee; }
string Event::getEventName() { return this->eventName; }
int Event::generateId()
{
	srand(chrono::duration_cast<chrono::nanoseconds>(
		chrono::system_clock::now().time_since_epoch())
		.count());
	int random_number = rand() % 1000000 + 1;
	auto now = time(nullptr);
	return (now) + (random_number);
}
