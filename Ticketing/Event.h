#ifndef EVENT_H
#define EVENT_H
#include <iostream>
using namespace std;

class Event
{
private:
	int id;
	int venueSeats;
	int venueRows;
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
		int venueRows,
		std::string eventName,
		Zone zone);
	~Event();
	Event(const Event& c);
	std::string getZone();
	int getId();
	int generateId();
};

#endif