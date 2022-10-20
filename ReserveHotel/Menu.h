#pragma once
#include <vector>
#include <string>
class Menu
{
private:
	std::string title = "";
	std::string description = "";
	std::vector<Menu*> submenus = std::vector<Menu*>();

public:
	Menu() = default;
	Menu(const std::string& _title, const std::string& _description);

	void AddSubMenu(Menu* _menu);
	std::string GetTitle() const;
	std::string GetDescription() const;
	void Display();
};

