

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
				std::cout << "[" << client->GetID() << "]: Email sent\n";

				int fileBool;
				int id;
				char content[4 * 1024];
				char subject[1024];
				char dest[1024];
				char src[1024];
				int files;
				msg >> files >> fileBool >> content >> subject >> dest >> src;

				msg.body.clear();

				std::string l_content = convertToSqlVarcharFormat(content);
				std::string l_subject = convertToSqlVarcharFormat(subject);
				std::string l_dest = convertToSqlVarcharFormat(dest);
				std::string l_src = convertToSqlVarcharFormat(src);
				std::string l_files = "'" + std::to_string(files) + "'";
				std::string str;
				str = "'";

				//l_src = "'sese@mta.ro'"; //pana fac si credentials handleru

				std::string query = "SELECT UserId FROM atmail.dbo.Users WHERE Email = " + l_src;
				std::string srcUserId = GetQueryExecResult(query);

				query = "SELECT UserId FROM atmail.dbo.Users WHERE Email = " + l_dest;
				std::string destUserId = GetQueryExecResult(query);

				if (destUserId != "") {
					query = "INSERT INTO [atmail].[dbo].[Mails] (SrcUserId, DestUserId, Subject, Text, Files) OUTPUT inserted.MailId VALUES(" + str + srcUserId + str + ", " + str + destUserId + str + ", " + l_subject + ", " + l_content + ", " + l_files + ")";
					std::string mailId = GetQueryExecResult(query);

					id = std::stoi(mailId);
				}
				else
				{
					id = 0;
					// give up the dest mail doesn't exit;
				}

					app::message<app::MessageType> msj;
					msj.header.id = app::MessageType::MailId;
					msj << id;
					client->Send(msj);
				
				
				//functie de adaugare a mailului in baza de date
				//functie de notificare a destinatarului real-time 
				
			}
			break;

			case app::MessageType::File:
			{
				std::cout << "[" << client->GetID() << "]: File sent\n";
				int mailId;
				char fileName[1024];
				
				std::size_t numChunks;
				msg >> fileName >> mailId >> numChunks;
				std::string str;
				str = "'";
				std::string l_fileName = convertToSqlVarcharFormat(fileName);

				std::string path = R"(E:\storage\)" + std::string(fileName);

				//std::ofstream finaux(path, std::ios::binary);
				//finaux << "";
				//finaux.close();

				std::ofstream fout(path, std::ios::binary | std::ios::app);// | std::ios::out);

				size_t fileSize = 0;
				for (std::size_t i = 0; i < numChunks; i++)
				{
					char buf[1024];
					
					std::size_t bytesRead;

					msg >> bytesRead;
					msg>> buf;
					std::cout << buf;
					fout.write(buf, bytesRead);

					

				}
				fout.close();
				std::cout << std::endl;
				std::string query = "INSERT INTO [atmail].[dbo].[MailFiles] ( MailId, FileName, FileContent) VALUES(" + str + std::to_string(mailId) + str + ", " + l_fileName + ", " + str + path +str + ")";
				ExecQuery(query);

				
			}
			break;

			case app::MessageType::DeleteMail:
			{
				std::cout << "[" << client->GetID() << "]: Delete mail request\n";
				size_t mailId;
				msg >> mailId;

				std::string query = "DELETE FROM atmail.dbo.MailFiles WHERE MailId = '" + std::to_string(mailId) + "'; DELETE FROM atmail.dbo.Mails WHERE MailId = '" + std::to_string(mailId) + "';";
				ExecQuery(query);

			}
			break;

			case app::MessageType::MailRequest:
			{
				std::cout << "[" << client->GetID() << "]: Mail request\n";
				size_t mailId;
				msg >> mailId;
				msg.header.id = app::MessageType::Sent;

				char content[4 * 1024];
				char subject[1024];
				char dest[1024];
				char src[1024];
				int files;
				int read;
				msg >> read;
				msg.body.clear();

				std::string query="SELECT u.Email from atmail.dbo.Mails as m INNER JOIN atmail.dbo.Users as u ON m.SrcUserId=u.UserId Where MailId = '" + std::to_string(mailId) + "'";
				std::string result = GetQueryExecResult(query);
				strcpy(src, result.c_str());

				 query = "SELECT Subject from atmail.dbo.Mails Where MailId = '" + std::to_string(mailId) + "'";
				result = GetQueryExecResult(query);
				strcpy(subject, result.c_str());

				query = "SELECT Text from atmail.dbo.Mails Where MailId = '" + std::to_string(mailId) + "'";
				 result = GetQueryExecResult(query);
				strcpy(content, result.c_str());

				query = "SELECT Files from atmail.dbo.Mails Where MailId = '" + std::to_string(mailId) + "'";
				result = GetQueryExecResult(query);
				files = std::stoi(result);

				query = "SELECT u.Email from atmail.dbo.Mails as m INNER JOIN atmail.dbo.Users as u ON m.DestUserId=u.UserId Where MailId = '" + std::to_string(mailId) + "'";
				result = GetQueryExecResult(query);
				strcpy(dest, result.c_str());

				if (read == 1) {
					query = "UPDATE atmail.dbo.Mails SET Seen = 1 WHERE MailId = ' " + std::to_string(mailId) + "';";
					ExecQuery(query);
				}

				msg << content << subject << src << dest;

				for (int i = 0; i < files; i++)
				{
					char fileName[1024];

					query = "SELECT FileName FROM (SELECT FileName, row_number() over (order by MailId) as pos from atmail.dbo.MailFiles WHERE MailId = '" + std::to_string(mailId) + "') as files where pos = '" + std::to_string(i + 1) + "'";
					result = GetQueryExecResult(query);
					strcpy(fileName, result.c_str());

					msg << fileName;

				}
				msg << files;
				client->Send(msg);


			}
			break;

			case app::MessageType::FileRequest:
			{
				char fileName[1024];
				size_t mailId;

				msg >> fileName >> mailId;

				msg.header.id = app::MessageType::FileSent;
				msg.body.clear();

				std::string filePath;
				std::size_t chunk_size = 1024;

				std::string query = "SELECT FileContent from atmail.dbo.MailFiles WHERE MailId = '" + std::to_string(mailId) + "' and FileName = " + convertToSqlVarcharFormat(fileName);
				filePath = GetQueryExecResult(query);

				std::ifstream fin(filePath, std::ios::binary);

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
					if ((int(fileSize) - int(chunk_size)) <= 0)
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

		
				msg << numChunks;

				client->Send(msg);

			}
			break;

			case app::MessageType::Update:
			{
				std::cout << "[" << client->GetID() << "]: Check mails update request\n";

				char email[1024];
				size_t lastMailId;

				msg >> email >> lastMailId;

				msg.body.clear();

				std::string l_email = convertToSqlVarcharFormat(email);
				std::string l_lastMailId = "'" + std::to_string(lastMailId) + "'";

				std::string query = "SELECT UserId FROM atmail.dbo.Users WHERE Email = " + l_email;
				std::string userId = "'" + GetQueryExecResult(query) + "'";

				query = "SELECT COUNT(*) FROM atmail.dbo.Mails WHERE SrcUserId = " + userId + " OR DestUserId = " + userId;
				std::string result = GetQueryExecResult(query);

				size_t totalMails = std::stoi(result);


				if (lastMailId == 0)
				{
					for (size_t i = 1; i <= totalMails; i++)
					{
						char subject[1024], src[1024], dest[1024];
						size_t mailId;
						int s;
						char ora[1024];
						int files;
						int section;

						query = "SELECT Subject FROM (SELECT MailId, SrcUserId, DestUserId, Subject, Seen, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(i) + "'";
						result = GetQueryExecResult(query);
						strcpy(subject, GetQueryExecResult(query).c_str());
						query = "SELECT SrcUserId FROM (SELECT MailId, SrcUserId, DestUserId, Subject, Seen, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(i) + "'";
						result = GetQueryExecResult(query);
						query = "SELECT Email FROM atmail.dbo.Users WHERE UserId = '" + result + "'";
						strcpy(src, GetQueryExecResult(query).c_str());
						query = "SELECT DestUserId FROM (SELECT MailId, SrcUserId, DestUserId, Subject, Seen, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(i) + "'";
						result = GetQueryExecResult(query);
						query = "SELECT Email FROM atmail.dbo.Users WHERE UserId = '" + result + "'";
						strcpy(dest, GetQueryExecResult(query).c_str());
						query = "SELECT MailId FROM (SELECT MailId, SrcUserId, DestUserId, Subject, Seen, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(i) + "'";
						result = GetQueryExecResult(query);
						mailId = std::stoi(result);
						query = "SELECT Ora FROM (SELECT MailId, SrcUserId, DestUserId, Subject, Seen, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(i) + "'";
						result = GetQueryExecResult(query).c_str();
						strncpy(ora, result.c_str(), result.size() - 8);
						query = "SELECT Seen FROM (SELECT MailId, SrcUserId, DestUserId, Subject, Seen, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(i) + "'";
						result = GetQueryExecResult(query);
						s = std::stoi(result);
						query = "SELECT Files FROM (SELECT MailId, SrcUserId, DestUserId, Subject, Seen, Ora, Files, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(i) + "'";
						result = GetQueryExecResult(query);
						files = std::stoi(result);
						query = "SELECT SectionId from atmail.dbo.SecRels WHERE MailId ='" + std::to_string(mailId) + "'";
						result = GetQueryExecResult(query);
						if (result == "")
						{
							section = 0;
						}
						else
						{
							section = std::stoi(result);
						}

						msg <<section<< files << s << ora << subject << dest << src << mailId;
					}
					msg << totalMails;

					client->Send(msg);

					break;
				}

				query = "SELECT position FROM(SELECT mailId, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE MailId = " + l_lastMailId + ";";
				result = GetQueryExecResult(query);

				size_t mailPos = std::stoi(result);
				
				if (totalMails != mailPos) {

					for (size_t i = 1; i <= totalMails - mailPos; i++)
					{
						char subject[1024], src[1024], dest[1024];
						size_t mailId;
						int s;
						int files;
						char ora[1024];
						int section;

						query = "SELECT Subject FROM(SELECT MailId, SrcUserId, DestUserId, Subject, Seen, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(mailPos + i) + "'";
						strcpy(subject, GetQueryExecResult(query).c_str());
						query = "SELECT SrcUserId FROM(SELECT MailId, SrcUserId, DestUserId, Subject,Seen, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(mailPos + i) + "'";
						result = GetQueryExecResult(query);
						query = "SELECT Email FROM atmail.dbo.Users WHERE UserId = '" + result + "'";
						strcpy(src, GetQueryExecResult(query).c_str());
						query = "SELECT DestUserId FROM(SELECT MailId, SrcUserId, DestUserId, Subject,Seen, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(mailPos + i) + "'";
						result = GetQueryExecResult(query);
						query = "SELECT Email FROM atmail.dbo.Users WHERE UserId = '" + result + "'";
						strcpy(dest, GetQueryExecResult(query).c_str());
						query = "SELECT MailId FROM(SELECT MailId, SrcUserId, DestUserId, Subject,Seen, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(mailPos + i) + "'";
						result = GetQueryExecResult(query);
						mailId = std::stoi(result);
						query = "SELECT Ora FROM(SELECT MailId, SrcUserId, DestUserId, Subject,Seen, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(mailPos + i) + "'";
						result = GetQueryExecResult(query).c_str();
						strncpy(ora, result.c_str(), result.size() - 8);
						query = "SELECT Seen FROM(SELECT MailId, SrcUserId, DestUserId, Subject,Seen, Ora, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(mailPos + i) + "'";
						result = GetQueryExecResult(query);
						s = std::stoi(result);
						query = "SELECT Files FROM (SELECT MailId, SrcUserId, DestUserId, Subject, Seen, Ora, Files, ROW_NUMBER() OVER(ORDER BY Ora ASC) AS position FROM atmail.dbo.Mails WHERE (SrcUserId = " + userId + " OR DestUserId = " + userId + ")) AS mail_positions WHERE position = '" + std::to_string(mailPos + i) + "'";
						result = GetQueryExecResult(query);
						files = std::stoi(result);
						query = "SELECT SectionId from atmail.dbo.SecRels WHERE MailId ='" + std::to_string(mailId) + "'";
						result = GetQueryExecResult(query);
						if (result == "")
						{
							section = 0;
						}
						else
						{
							section = std::stoi(result);
						}

						msg <<section<< files << s << ora << subject << dest << src << mailId;
					}

					msg << (totalMails - mailPos);

					client->Send(msg);
				}
				else
				{
					msg << (totalMails - mailPos);

					client->Send(msg);
				}
			}
			break;

			case app::MessageType::Folder:
			{
				std::cout << "[" << client->GetID() << "]: Add section request\n";
				char folderName[1024];
				int folderId;

				msg >> folderName;
				std::string query = "INSERT INTO [atmail].[dbo].[Secs] (SectionName) OUTPUT inserted.SectionId VALUES('" + std::string(folderName) + "')";
				std::string result = GetQueryExecResult(query);

				folderId = std::stoi(result);

				msg.body.clear();
				msg << folderId;

				client->Send(msg);

				
			}
			break;

			case app::MessageType::MailInFolder: //Trebuie sa bag si userul ce a primit mailul aici
			{
				std::cout << "[" << client->GetID() << "]: Added a mail in a folder\n";
				int mailId, folderId;

				msg >> folderId >> mailId;


				if (folderId != 0) {
					std::string query = "SELECT DestUserId from atmail.dbo.Mails Where MailId = '" + std::to_string(mailId) + "'";
					std::string result = GetQueryExecResult(query);
					query = "INSERT INTO [atmail].[dbo].[SecRels] VALUES('" + std::to_string(folderId) + "', '" + std::to_string(mailId) + "', '" + result + "')";
					ExecQuery(query);
				}
				else
				{
					std::string query = "DELETE from atmail.dbo.SecRels Where MailId = '" + std::to_string(mailId) + "'";
					ExecQuery(query);
				}

			}
			break;

			case app::MessageType::CreateFolders:
			{
				std::cout << "[" << client->GetID() << "]: Create folders\n";

				char email[1024];
				msg >> email;
				std::string l_email = convertToSqlVarcharFormat(email);

				std::string query = "SELECT UserId FROM atmail.dbo.Users WHERE Email = " + l_email ;
				std::string UserId = GetQueryExecResult(query);

				msg.body.clear();
				query = "SELECT COUNT(DISTINCT s.SectionId) AS Total FROM atmail.dbo.Secs s INNER JOIN atmail.dbo.SecRels r ON s.SectionId = r.SectionId WHERE r.UserId ='" + UserId + "'";
				std::string result = GetQueryExecResult(query);

				size_t totalMails = std::stoi(result);

				for (size_t i = 2; i < totalMails; i++)
				{
					int sectionId;
					char sectionName[1024];
					query = "SELECT Distinct s.SectionId FROM atmail.dbo.Secs s INNER JOIN atmail.dbo.SecRels r ON s.SectionId = r.SectionId WHERE r.UserId = '" + UserId + "' Order By SectionId OFFSET " + std::to_string(i) +  " ROWS FETCH NEXT 1 ROWS ONLY";
					result = GetQueryExecResult(query);
					sectionId = std::stoi(result);
					query = "SELECT SectionName from (SELECT Distinct s.SectionId, SectionName FROM atmail.dbo.Secs s INNER JOIN atmail.dbo.SecRels r ON s.SectionId = r.SectionId WHERE r.UserId = '" + UserId + "' Order By SectionId OFFSET " + std::to_string(i) + " ROWS FETCH NEXT 1 ROWS ONLY) as aux";
					result = GetQueryExecResult(query);
					strcpy(sectionName, result.c_str());

					msg << sectionName << sectionId;
				}
				int a = (int)totalMails;
				a = a - 2;
				msg << a;

				client->Send(msg);
				
			}
			break;

			case app::MessageType::LoginRequest:
			{
				std::cout << "[" << client->GetID() << "]: Login to Server request\n";
				char username[1024];
				char password[1024];

				msg >> password >> username;
				char responseback[1024];
				try
				{
					OnLoginUserToServer(username, password);
					strcpy(responseback, "SuccessLogin");
					
					users.insert({ client->GetID(), std::string(username) });
				}
				catch (app::UsernameInvalidLoginError)
				{
					strcpy(responseback, "UsernameInvalidError");
				}
				catch (app::PasswordInvalidLoginError)
				{
					strcpy(responseback, "PasswordInvalidError");
				}
				catch (...)
				{
				}
				msg << responseback;
				client->Send(msg); // send message back to client.
			}
			break;

			case app::MessageType::RegisterRequest:
			{
				std::cout << "[" << client->GetID() << "]: Register to Server request\n";
				char username[1024];
				char password[1024];
				char firstname[1024];
				char lastname[1024];

				msg >> lastname >> firstname >> password >> username;
				char responseback[1024];
				try
				{
					RegisterUserToServer(username, password, firstname, lastname);
					strcpy(responseback, "Success");
					users.insert({ client->GetID(), std::string(username) });
				}
				catch (app::EmailValidationError)
				{
					strcpy(responseback, "EmailInvalid");
				}
				catch (app::UserAlreadyRegisteredError)
				{
					strcpy(responseback, "AlreadyRegistered");
				}
				catch (app::DatabaseQueryError)
				{
					strcpy(responseback, "ServerToDatabaseQueryError");
				}
				catch (app::DatabaseConnectionError)
				{
					strcpy(responseback, "ServerToDatabaseConnectionError");
				}
				catch (...)
				{
				}
				msg << responseback;
				client->Send(msg); // send message back to client.
			}
			break;
			}

		}
	
		
	private:
		std::unordered_map<uint32_t, std::string> users;
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