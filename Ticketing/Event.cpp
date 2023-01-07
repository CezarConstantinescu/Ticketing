#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Event.h"

Event::Event()
	:venueSeats(0), venueRows(0), eventName(""), zone(Zone::LAWN)
{
	venueSeats = 0;
	venueRows = 0;
	eventName = "";
	zone = Zone::LAWN;
}

Event::Event(int venueSeats,
	int venueRows,
	std::string eventName,
	Zone zone)
	:venueSeats(0), venueRows(0), eventName(""), zone(Zone::LAWN)
{
	this->venueSeats = venueSeats;
	this->venueRows = venueRows;
	this->eventName = eventName;
	this->zone = zone;
}

Event::~Event()
{
}

Event::Event(const Event& c)
{
	this->venueSeats = c.venueSeats;
	this->venueRows = c.venueRows;
	this->eventName = c.eventName;
	this->zone = c.zone;
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
    }
}