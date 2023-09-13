#pragma once
#include "app_common.h"
//#include openssl

namespace app
{
	class credentials
	{
	public:
		credentials() {};
		credentials(std::string email, std::string firstname, std::string lastname, std::string password):
			email(email), firstname(firstname), lastname(lastname), password(password){}
		~credentials(){}

		// Setter and getter functions for email
		void setEmail(std::string email) { this->email = email; }
		std::string getEmail() const { return email; }

		// Setter and getter functions for firstname
		void setFirstname(std::string firstname) { this->firstname = firstname; }
		std::string getFirstname() const { return firstname; }

		// Setter and getter functions for lastname
		void setLastname(std::string lastname) { this->lastname = lastname; }
		std::string getLastname() const { return lastname; }

		// Setter and getter functions for password
		void setPassword(std::string password) { this->password = password; }
		std::string getPassword() const { return password; }


		//// Setter and getter functions for password hash
		//void setPasswordHash(std::string password) {
		//	unsigned char hash[EVP_MAX_MD_SIZE];
		//	const unsigned char* data = reinterpret_cast<const unsigned char*>(password.c_str());
		//	unsigned int len = password.length();
		//	EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
		//	EVP_DigestInit(mdctx, EVP_sha256());
		//	EVP_DigestUpdate(mdctx, data, len);
		//	EVP_DigestFinal(mdctx, hash, &len);
		//	EVP_MD_CTX_free(mdctx);
		//	passwordHash = std::string(reinterpret_cast<const char*>(hash), len);
		//}
		//std::string getPasswordHash() const { return passwordHash; }

	private:
		std::string email;
		std::string firstname;
		std::string lastname;
		std::string password;
	};


}