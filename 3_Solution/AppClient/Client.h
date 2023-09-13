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

	void setIpPortTo(); //TODO: ngrok maybe 


public:

	
	std::string getIpAddressTo();
	int getPortTo();


	static Client& getInstance();
	static void destroyInstance();
	static bool ClientIsConnected();

	void ConnectToServer();
	void PingServer();
	void MessageAll();
	void Register(const std::string& username, const std::string& password, const std::string& firstname, const std::string& lastname);
	void LoginUser(const std::string& username, const std::string& password);
	void SendMail(const std::string& src, const std::string& dest, const std::string& subject, const std::string& mailContent, const std::vector<std::string>& files);
	void checkUpdate(const std::string& email, const size_t lastMailId);
	void requestMail(size_t mailId, int r);
	void requestFile(size_t mailId, std::string fileName);
	void deleteMail(size_t mailId);
	void addFolder(std::string folderName);
	void addMailInFolder(int mailId, int folderId);
	void createFolders(const std::string& email);
};