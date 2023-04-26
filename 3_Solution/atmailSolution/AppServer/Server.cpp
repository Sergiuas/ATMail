#include <iostream>
#include <app_net.h>


class CustomServer : public app::server_interface<app::MessageType>
{
public:
	CustomServer(uint16_t nPort) : app::server_interface<app::MessageType>(nPort)
	{

	}

protected:
	virtual bool OnClientConnect(std::shared_ptr<app::connection<app::MessageType>> client)
	{
		app::message<app::MessageType> msg;
		msg.header.id = app::MessageType::ServerAccept;
		client->Send(msg);
		return true;
	}

	// Called when a client appears to have disconnected
	virtual void OnClientDisconnect(std::shared_ptr<app::connection<app::MessageType>> client)
	{
		std::cout << "Removing client [" << client->GetID() << "]\n";
	}

	// Called when a message arrives
	virtual void OnMessage(std::shared_ptr<app::connection<app::MessageType>> client, app::message<app::MessageType>& msg)
	{
		switch (msg.header.id)
		{
		case app::MessageType::ServerPing:
		{
			std::cout << "[" << client->GetID() << "]: Server Ping\n";

			// Simply bounce message back to client
			client->Send(msg);
		}
		break;

		case app::MessageType::MessageAll:
		{
			std::cout << "[" << client->GetID() << "]: Message All\n";

			// Construct a new message and send it to all clients
			app::message<app::MessageType> msg;
			msg.header.id = app::MessageType::ServerMessage;
			msg << client->GetID();
			MessageAllClients(msg, client);

		}
		break;


		case app::MessageType::MailTest: // DOAR DE TEST
		{
			std::cout << "[" << client->GetID() << "]: CIOCANESCUU\n";

			// Construct a new message and send it to all clients
			app::message<app::MessageType> msg;
			msg.header.id = app::MessageType::MailTest;
			msg << client->GetID();
			MessageClientOnID(msg, client->GetID()+1);
		}
		break;
		}
	}
};

int main()
{
	CustomServer server(60000);
	server.Start();

	while (1)
	{
		server.Update(-1, true);
	}


	return 0;
}