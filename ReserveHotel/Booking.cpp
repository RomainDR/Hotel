#include "Booking.h"

Booking::Booking(const Booking& _copy)
{
	clients = _copy.clients;
}

void Booking::AddClient(Client* _client)
{
	clients.push_back(_client);
}
