#pragma once
#include <app_net.h>
#include <iostream>



class Client : public app::client_interface<app::MessageType>
{
private:
	static Client* instance;
	std::string ip_address_to;
	int port_to;

	Client();
	Client(const Client& src) = delete;
	~Client() {};

	void setIpPortTo(); //TODO: ngrok maybe usage

public:
	std::string getIpAddressTo();
	int getPortTo();

	static Client& getInstance();
	static void destroyInstance();
	static bool ClientIsConnected();

	void ConnectToServer();
	void PingServer();
	void MessageAll();
	//void Register();
	//void LoginUser(const std::string& username, const std::string& password);

};