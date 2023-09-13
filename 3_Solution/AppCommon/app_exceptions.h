#pragma once

#include "app_common.h"
namespace app
{
	class IException
	{
	public:
		IException(std::string errmsg, int errcode)
		{
			this->err = errmsg;
			this->err_code = errcode;
		}
		virtual void LogError()
		{
			std::cout << "[SERVER]: Error Code " << err_code << ": " << err;
		}
	protected:
		std::string err;
		int err_code;
	};

	class EmailValidationError : public IException
	{
	public:
		EmailValidationError(std::string err, int errcode = 1) : IException(err, errcode)
		{

		}
	};

	class UserAlreadyRegisteredError : public IException
	{
	public:
		UserAlreadyRegisteredError(std::string err, int errcode = 2) : IException(err, errcode)
		{

		}
	};

	class DatabaseConnectionError : public IException
	{
	public:
		DatabaseConnectionError(std::string err, int errcode = 3) : IException(err, errcode)
		{

		}
	};

	class DatabaseQueryError : public IException
	{
	public:
		DatabaseQueryError(std::string err, int errcode = 4) : IException(err, errcode)
		{

		}
	};

	class UsernameInvalidLoginError : public IException
	{
	public:
		UsernameInvalidLoginError(std::string err, int errcode = 5) : IException(err, errcode)
		{

		}
	};
	class PasswordInvalidLoginError : public IException
	{
	public:
		PasswordInvalidLoginError(std::string err, int errcode = 6) : IException(err, errcode)
		{

		}
	};
	
	
}