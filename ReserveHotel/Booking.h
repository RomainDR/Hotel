#pragma once
#include <vector>

class Client;

class Booking
{
private:
	std::vector<Client*> clients = std::vector<Client*>();

public:
	Booking() = default;
	Booking(const Booking& _copy);

	void AddClient(Client* _client);
};

