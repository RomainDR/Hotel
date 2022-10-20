#include "Hotel.h"
#include "Utils.h"
#include "Booking.h"
#include "Menu.h"

Hotel::Hotel(const std::string _name)
{
	name = _name;
	Init();
}

Hotel::Hotel(const Hotel& _copy)
{
	name = _copy.name;
}

Hotel::~Hotel()
{
	delete booking;
}

void Hotel::Init()
{
	booking = new Booking();
	AddMenu(new Menu("Reservation", "Reservation Menu"));
}

void Hotel::Display()
{
	std::string title = "Hotel (" + name + ")";
	std::string underline = "";
	std::cout << "     " << title << std::endl;
	for (int i = 0; i < title.length(); i++)
		underline.append("-");
	std::cout << "     " << underline << std::endl;
	int _size = menus.size();
	for (int i = 0; i < _size; i++)
	{
		std::cout << i + 1 << ": " << menus.at(i)->GetTitle() << std::endl;
		std::cout << "     ->" << menus.at(i)->GetDescription() << std::endl;
	}
	int choice = Utils::UserChoice<int>("User selection: ");
	Menu* _menu = GetMenuByIndex(choice - 1);
	system("cls");
	_menu->Display();
}

Booking* Hotel::GetBooking() const
{
	return booking;
}

void Hotel::AddClient(Client* _client)
{
	booking->AddClient(_client);
}

void Hotel::AddMenu(Menu* _menu)
{
	menus.push_back(_menu);
}

Menu* Hotel::GetMenuByIndex(const int& _index)
{
	return menus.at(_index);
}
