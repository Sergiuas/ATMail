#define CHUNK_SIZE 1024
#include "Client.h"
#include <QString>
#include <QFile>
#include <QFileInfo>

Client* Client::instance = nullptr;

Client::Client()
{
	ip_address_to = "192.168.43.33";
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

void Client::Register(const std::string& username, const std::string& password, const std::string& firstname, const std::string& lastname)
{
	app::message<app::MessageType> msg;
	msg.header.id = app::MessageType::RegisterRequest;

	char l_username[1024]; strcpy(l_username, username.c_str());
	char l_password[1024]; strcpy(l_password, password.c_str());
	char l_firstname[1024]; strcpy(l_firstname, firstname.c_str());
	char l_lastname[1024]; strcpy(l_lastname, lastname.c_str());
	msg << l_username << l_password<<l_firstname<<l_lastname;
	Send(msg);
}

void Client::LoginUser(const std::string& username, const std::string& password)
{
	app::message<app::MessageType> msg;
	msg.header.id = app::MessageType::LoginRequest;

	char l_username[1024]; strcpy(l_username, username.c_str());
	char l_password[1024]; strcpy(l_password, password.c_str());
	msg << l_username << l_password;
	Send(msg);
}

void Client::SendMail(const std::string& src, const std::string& dest, const std::string& subject, const std::string& mailContent, const std::vector<std::string>& files)
{
	// Calculate the number of chunks needed to send the file content
	//const int chunkSize = 1024;
	//const int numChunks = (fileContent.size() + chunkSize - 1) / chunkSize;

	char l_src[1024]; strcpy(l_src, src.c_str());
	char l_dest[1024]; strcpy(l_dest, dest.c_str());
	char l_subject[1024]; strcpy(l_subject, subject.c_str());
	char l_content[4 * 1024]; strcpy(l_content, mailContent.c_str());
	int fileBool;
	int nr = files.size();

	if (files.empty())
		fileBool = 0;
	else
		fileBool = 1;

	// Create a message for the mail
	app::message<app::MessageType> msg;
	msg.header.id = app::MessageType::MailTest;

	msg.body.clear();
	msg << l_src << l_dest << l_subject << l_content << fileBool << nr;

	Incoming().clear();
	Send(msg);

	while (Incoming().empty() && fileBool==1)
	{
		//loop waiting for reply
	}
	if (!Incoming().empty())
	{
		auto msg = Incoming().pop_front().msg;

		int id;
			msg >> id;

		if (id != 0) //Daca ar fi sa trimit fisiere mai mari, trebuie sa incep sa trimit de la final la inceput 
		{ 
			switch (msg.header.id)
			{
			case app::MessageType::MailId: //the dest mail exists so send files
			{
				for (auto path : files)
				{
					std::size_t chunk_size = 1024;
					app::message<app::MessageType> msg;
					msg.header.id = app::MessageType::File;
					std::ifstream fin(path, std::ios::binary);

					//if (!fin) {
					//	std::cerr << "Error: Failed to open file: " << path << std::endl; // Throw
					//	return;
					//}

					 // Calculate the file size
					fin.seekg(0, std::ios::end);
					std::size_t fileSize = fin.tellg();
					fin.seekg(0, std::ios::beg);

					// Calculate the number of chunks to send
					std::size_t numChunks = fileSize / chunk_size;
					if (fileSize % chunk_size != 0) {
						numChunks++;
					}
					char buf[1024];
					for (std::size_t i = 0; i < numChunks; i++)
					{
						if ((int(fileSize)-int(chunk_size)) <= 0)
						{
							fin.seekg(0, std::ios::beg);
							fin.read(buf, fileSize);
						}
						else {
							fin.seekg((int(fileSize) - int(chunk_size)), std::ios::beg);
							fin.read(buf, chunk_size);
							fileSize = int(fileSize) - int(chunk_size);
						}

						std::size_t bytesRead = fin.gcount();
						msg << buf << bytesRead;

					}
					
					QString fileName = QString::fromStdString(path);
					fileName = QFileInfo(fileName).fileName();
					std::string aux = fileName.toStdString();
					char name[1024];
					strcpy(name, aux.c_str());

					msg << numChunks << id << name;

					Send(msg);
				}
			}
			break;
			}
		
		}
		

	}

}

void Client::checkUpdate(const std::string& email, const size_t lastMailId)
{
	char l_email[1024]; strcpy(l_email, email.c_str());

	app::message<app::MessageType> msg;
	msg.header.id = app::MessageType::Update;

	msg << lastMailId << l_email;

	Send(msg);
}

void Client::requestMail(size_t mailId, int r)
{
	app::message<app::MessageType> msg;
	msg.header.id = app::MessageType::MailRequest;

	msg << r << mailId;
	Send(msg);
}

void Client::requestFile(size_t mailId, std::string fileName)
{
	app::message<app::MessageType> msg;
	msg.header.id = app::MessageType::FileRequest;

	char l_filename[1024]; strcpy(l_filename, fileName.c_str());

	msg << mailId << l_filename;
	Send(msg);
}

void Client::deleteMail(size_t mailId)
{
	app::message<app::MessageType> msg;
	msg.header.id = app::MessageType::DeleteMail;

	msg << mailId;
	Send(msg);
}

void Client::addFolder(std::string folderName)
{
	app::message<app::MessageType> msg;
	msg.header.id = app::MessageType::Folder;
	char l_folderName[1024]; strcpy(l_folderName, folderName.c_str());

	msg << l_folderName;
	Send(msg);
}

void Client::addMailInFolder(int mailId, int folderId)
{
	app::message<app::MessageType> msg;
	msg.header.id = app::MessageType::MailInFolder;

	msg << mailId << folderId;

	Send(msg);
}

void Client::createFolders(const std::string& email)
{
	char l_email[1024]; strcpy(l_email, email.c_str());

	app::message<app::MessageType> msg;
	msg.header.id = app::MessageType::CreateFolders;

	msg << l_email;

	Send(msg);
}



