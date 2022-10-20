#pragma once
#
#include <string>
#include <vector>
#include <iostream>

class Client;
class Menu;
class Booking;

class Hotel
{

private:
	std::string name = "";
	Booking* booking = nullptr;
	std::vector<Menu*> menus = std::vector<Menu*>();

public:
	Hotel() = default;
	Hotel(const std::string _name);
	Hotel(const Hotel& _copy);

	~Hotel();

#pragma region methods
public:
	void Init();
	void Display();
	Booking* GetBooking() const;
	void AddClient(Client* _client);
	void AddMenu(Menu* _menu);
	Menu* GetMenuByIndex(const int& _index);
#pragma endregion methods
};

