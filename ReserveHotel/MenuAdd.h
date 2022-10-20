#pragma once
#include "Menu.h"
#include <string>

class MenuAdd : public Menu
{
private:
	std::string name = "";

public:
	MenuAdd(const std::string& _title, const std::string& _description);

	void SetName(const std::string& _name);
};

