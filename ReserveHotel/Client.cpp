#include "Client.h"
#include <string>
#include <iostream>
#include <format>
#include <vector>

Client::Client(const int id, const std::string& _firstName, const std::string& _lastName, const int& _age, const std::string& _arrivalDate, const std::string& _departureDate)
{
	idClient = id;
	firstName = _firstName;
	lastName = _lastName;
	age = _age;
	arrivalDate = ConvertToDate(_arrivalDate);
	departureDate = ConvertToDate(_departureDate);
}

Client::Client(const Client& _copy)
{
	idClient = _copy.idClient;
	firstName = _copy.firstName;
	lastName = _copy.lastName;
	age = _copy.age;
	arrivalDate = _copy.arrivalDate;
	departureDate = _copy.departureDate;
}

std::string Client::ConvertToDate(std::string _date)
{
	int _index = 0;
	std::vector < std::string> _splited;
	for (int i = 0; i < _date.length(); i++) {
		if (_date[i] == ' ') {
			_splited.push_back(_date.substr(_index, i));
			_index = i+1;
		}
	}
	_splited.push_back(_date.substr(_index, _date.length()));

	std::vector<int> _days = std::vector<int>();
	std::vector<int> _hours = std::vector<int>();
	for (int i = 0; i < 2; i++)
	{
		std::string _str = _splited.at(i);
		int _index = 0;
		for (int y = 0; y < _str.length(); y++) {
			if (_str[y] == '/' && i == 0)
			{
				_days.push_back(std::stoi(_str.substr(_index, y)));
				_index = y + 1;
			}
			else if (_str[y] == ':' && i == 1)
			{
				_hours.push_back(std::stoi(_str.substr(_index, y)));
				_index = y + 1;
			}
			if (i == 0 && y == _str.length() -1)
				_days.push_back(std::stoi(_str.substr(_index, _str.length())));
			else if(i == 1 && y == _str.length() -1)
				_hours.push_back(std::stoi(_str.substr(_index, _str.length())));
		}
	}
	int day = _days.at(0);
	int month = _days.at(1);
	int years = _days.at(2);
	int hour = _hours.at(0);
	int min = _hours.at(1);
	int sec = _hours.at(2);
	return std::format("{:02}/{:02}/{:02} {:02}:{:02}:{:02}", day, month, years, hour, min, sec);
}

std::string Client::GetFirstName() const
{
	return firstName;
}

std::string Client::GetLastName() const
{
	return lastName;
}

int Client::GetId() const
{
	return idClient;
}

int Client::GetAge() const
{
	return age;
}

std::string Client::GetArrivalDate() const
{
	return arrivalDate;
}

std::string Client::GetDepartureDate() const
{
	return departureDate;
}

void Client::ShowInfos()
{
	std::cout << "================" << std::endl;
	std::cout << "Client: " << idClient << std::endl;
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Arrival Date: " << arrivalDate << std::endl;
	std::cout << "Departure Date: " << departureDate << std::endl;
	std::cout << "================" << std::endl;
}
 