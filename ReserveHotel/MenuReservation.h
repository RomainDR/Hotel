#pragma once
#include "Menu.h"
class MenuReservation : public Menu
{
private:
	std::vector<Menu*> submenu = std::vector<Menu*>();

public:
	MenuReservation(const std::string& _name, const std::string& _description);

	void Display();
};

