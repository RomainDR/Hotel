#include "Menu.h"
#include "Utils.h"
#include <iostream>

Menu::Menu(const std::string& _title, const std::string& _description)
{
	title = _title;
	description = _description;
}

void Menu::AddSubMenu(Menu* _menu)
{
}

std::string Menu::GetTitle() const
{
	return title;
}

std::string Menu::GetDescription() const
{
	return description;
}

void Menu::Display()
{
	std::string underline = "";
	std::cout << "     " << title << std::endl;
	for (int i = 0; i < title.length(); i++)
		underline.append("-");
	std::cout << "     " << underline << std::endl;
	int _size = submenus.size();
	for (int i = 0; i < _size; i++)
	{
		std::cout << i + 1 << ": " << submenus.at(i)->GetTitle() << std::endl;
		std::cout << "     ->" << submenus.at(i)->GetDescription() << std::endl;
	}
	int choice = Utils::UserChoice<int>("User selection: ");
}
