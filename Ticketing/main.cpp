#include "Ticket.h"
#include "Guest.h"
#include "Event.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
int Ticket::ticketsSold = 0;

int main(int argc, char* argv[])
{
	int areThereEntries = 0;
	int iterator = 0;
	int z[99], zz[99], zzz[99], zzzz[99];
	//// Testing Ticket class methods
	//int a[]{ 12, 22, 1 };
	//int b[]{ 9, 10, 12, 13 };

	//Ticket c;
	//cout << c << endl;

	//Ticket c1(100, 4, "George", "spectacol", 3, a);
	//cout << c1 << endl;

	//Ticket c2(200, 4, "Alex", "concert", 4, b);
	//cout << c2 << endl;
	//cout << c2.getguestName() << endl;

	//c2.setticketPrice(-5);

	//c2.setguestName("Tudor");
	//cout << c2.getguestName() << endl << endl;

	//c2.setseatNumbers(3, a);
	//for (int i = 0; i < 3; i++)
	//	cout << *(c2.getseatNumbers() + i) << " ";
	//cout << endl << endl;

	//cout << c2 << endl;
	//c2 = c1;
	//cout << c2 << endl;

	//Ticket copie1(c1);
	//cout << copie1 << endl;

	//cout << c2.getid();

	//cout << endl << endl;
	//cout << "Total bilete vandute: " << Ticket::getticketsSold() << endl << endl;

	//cin >> c;
	//cout << c;

	//// Testing Event class methods
	//Event e;
	//cout << e.getZone() << endl;
	//Event e1(100, 1000, "serbare", Event::Zone::VIP);
	//cout << e1.getZone() << endl;
	//Event copie2(e1);
	//cout << copie2.getEntryFee() << endl;
	//cout << copie2.getZone() <<endl <<endl;
	//cout << e.getId() << endl << e1.getId() << endl << copie2.getId() << endl << endl;

	//// Testing Guest class methods
	//
	//Guest g;
	//Guest g1("Mihai", 4, b);
	//Guest g2(g1);

	//cout << g2.getgroupSize() << endl;
	//cout << g2.getguestName() << endl;
	//for (int i = 0; i < 4; i++)
	//	cout << *(g2.getseatNumbers() + i) << " ";
	//cout << endl << endl;

	//g2.setguestName("Mircea");
	//cout << g2.getguestName() << endl;

	//g2.setseatNumbers(3, a);
	//for(int i = 0; i<3; i++)
	//	cout << *(g2.getseatNumbers() + i) << " ";
	//cout << endl << endl;
	//
	//// Creating a Ticket based on an Event and a Guest

	//Ticket t(e1,g1);
	//cout << t;

	if (argc > 1) {
		string file_name = argv[1];
		//string file_name = "input.txt";
		ifstream file(file_name);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				Ticket t1;

				t1.setticketPrice(stoi(line));
				getline(file, line);
				t1.setguestName(line.c_str());
				getline(file, line);
				t1.seteventName(line);
				getline(file, line);
				int numberOfSeats = stoi(line);
				getline(file, line);
				int* seatNumbers = new int[numberOfSeats];
				istringstream iss(line);
				for (int iter = 0; iter < numberOfSeats; iter++)
				{
					iss >> seatNumbers[iter];
				}
				t1.setseatNumbers(numberOfSeats, seatNumbers);
				delete[] seatNumbers;
				cout << "Entry added from file:\n" << t1 << endl << endl;

				ofstream out("data.bin", ios::binary);
				if (!out.is_open()) {
					cout << "Error opening file!" << endl;
				}

				z[iterator] = t1.getticketPrice();
				out.write(reinterpret_cast<char*>(&z[iterator]), sizeof(int));

				zz[iterator] = strlen(t1.getguestName()) + 1;
				out.write(t1.getguestName(), strlen(t1.getguestName()) + 1);

				zzzz[iterator] = t1.getnumberOfSeats();
				int int_arr[999];
				for (int itera = 0; itera < zzzz[iterator]; itera++)
				{
					int_arr[itera] = *(t1.getseatNumbers() + itera);
				}
				out.write(reinterpret_cast<char*>(int_arr), zzzz[iterator] * sizeof(int));
				out.close();

				zzz[iterator] = t1.geteventName().length();
				out.write(t1.geteventName().c_str(), t1.geteventName().length());

				areThereEntries = 1;
				iterator++;
			}
			file.close();
		}
		else {
			cout << "Error: Could not open the provided file!\n" << endl;
		}
	}
	else {
		cout << "No file name provided. Moving on.\n" << endl;
	}

	int noEscape = 1;
	int choice;
	
	do {
		cout << "1. Create a new ticket" << endl;
		cout << "2. Display all tickets" << endl;
		cout << "3. Close program" << endl;
		cout << endl <<  "Enter your choice: " << endl;
		cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3)
		{
			if (choice == 1)
			{
				Ticket x;
				cin >> x;
				ofstream out("data.bin", ios::binary);
				if (!out.is_open()) {
					cout << "Error opening file!" << endl;
				}

				z[iterator] = x.getticketPrice();
				out.write(reinterpret_cast<char*>(&z[iterator]), sizeof(int));

				zz[iterator] = strlen(x.getguestName())+1;
				out.write(x.getguestName(), strlen(x.getguestName())+1);

				zzzz[iterator] = x.getnumberOfSeats();
				int int_arr[999];
				for (int itera = 0; itera < zzzz[iterator]; itera++)
				{
					int_arr[itera] = *(x.getseatNumbers()+itera);
				}
				out.write(reinterpret_cast<char*>(int_arr), zzzz[iterator] * sizeof(int));
				out.close();

				zzz[iterator] = x.geteventName().length();
				out.write(x.geteventName().c_str(), x.geteventName().length());

				areThereEntries = 1;
				iterator++;

			}
			if (choice == 2)
			{
				if (areThereEntries == 0) {
					cout << "No entries added yet." << endl << endl;
				}
				else
				{
					

					ifstream infile("data.bin", std::ios::binary);
					if (!infile.is_open()) {
						cout << "Error opening file!" << endl;
					}
					for (int i = 0; i < iterator; i++)
					{
						int int1;
						infile.read(reinterpret_cast<char*>(&int1), sizeof(int));
						std::cout << "Ticket price: " << int1 << std::endl;

						char* name = new char[zz[i]];
						infile.read(name, zz[i]);
						std::cout << "Guest name: " << name << std::endl;
						delete[] name;

						std::cout << "Number of seats: " << zzzz[i] << std::endl;
						int* seats = new int[zzzz[i]];
						infile.read(reinterpret_cast<char*>(seats), zzzz[i] * sizeof(int));
						std::cout << "Seat numbers: ";
						for (int j = 0; j < zzzz[i]; j++) {
							std::cout << seats[j] << " ";
						}
						std::cout << std::endl;
						delete[] seats;

						std::string event;
						std::getline(infile, event);
						std::cout << "Event name: " << event << std::endl;
					}
					infile.close();
				}
			}
			if (choice == 3)
			{
				cout << "Shutting down..." << endl;
				noEscape = 0;
			}
		}
		else cout << "Invalid input >:(" << endl << endl;
		
	}while (noEscape);

	return 0;
}