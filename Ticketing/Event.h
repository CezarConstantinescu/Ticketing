#ifndef EVENT_H
#define EVENT_H
#include <iostream>
using namespace std;

class Event
{
private:
	int id;
	int venueSeats;
	int entryFee;
	std::string eventName;
public:
enum class Zone {
      VIP,
      LAWN,
      TRIBUNE,
	  BOXES
    };
	Zone zone;
	Event();
	Event(int venueSeats,
		int entryFee,
		std::string eventName,
		Zone zone);
	~Event();
	Event(const Event& c);
	std::string getZone();
	int getId();
	int getEntryFee();
	int generateId();
	string getEventName();
};

#endif