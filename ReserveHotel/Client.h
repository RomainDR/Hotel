#pragma once
#include <string>
class Client
{
private:
	int idClient = -1;
	std::string firstName = "";
	std::string lastName = "";
	int age = 0;
	std::string arrivalDate = "";
	std::string departureDate = "";

public:
	Client() = default;
	Client(const int id, const std::string& _firstName, const std::string& _lastName, const int& _age, const std::string& _arrivalDate, const std::string& _departureDate);
	Client(const Client& _copy);

#pragma region methods
private:
	std::string ConvertToDate(std::string _date);

public:
	std::string GetFirstName() const;
	std::string GetArrivalDate() const;
	std::string GetDepartureDate() const;
	std::string GetLastName() const;
	int GetId() const;
	int GetAge() const;
	void ShowInfos();
#pragma endregion methods
};

