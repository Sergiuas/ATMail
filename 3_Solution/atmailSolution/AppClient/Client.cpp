#include "Client.h"

Client* Client::instance = nullptr;

Client::Client()
{
	ip_address_to = "127.0.0.1";
	port_to = 60000;
}

Client& Client::getInstance()
{
	if (!instance)
	{
		instance = new Client();
	}
	if (!instance->IsConnected())
	{
		// replace with credentials.
		instance->ConnectToServer();
	}
	return *instance;
}

void Client::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

bool Client::ClientIsConnected()
{
	return instance->IsConnected();
}

void Client::ConnectToServer()
{
	//instance->setIpPortTo();
	instance->Connect(instance->ip_address_to, instance->port_to);
}

void Client::PingServer()
{
	app::message<app::MessageType> msg;
	msg.header.id = app::MessageType::ServerPing;

	// Caution with this...
	std::chrono::system_clock::time_point timeNow = std::chrono::system_clock::now();

	msg << timeNow;
	Send(msg);
}

void Client::MessageAll()
{
	app::message<app::MessageType> msg;
	msg.header.id = app::MessageType::MessageAll;
	Send(msg);
}
