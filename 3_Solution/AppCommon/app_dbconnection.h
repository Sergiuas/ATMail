#pragma once

#include "app_net.h"
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

namespace app
{
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

	//TODO: MECANISME DE EXCEPTIE!
	class dbconnection
	{
	public:
		dbconnection() 
		{
			sqlEnvHandle = NULL;
			sqlConnHandle = NULL;
			sqlStmtHandle = NULL;
		}
		virtual ~dbconnection()
		{
			//close connection and free resources
			SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
			SQLDisconnect(sqlConnHandle);
			SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
			SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
		}
		bool connectDB()
		{
		
			if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle) != SQL_SUCCESS)
			{
				return false;
			}
			if (SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0) != SQL_SUCCESS)
			{
				return false;
			}
			if (SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle) != SQL_SUCCESS)
			{
				return false;
			}

			std::cout << "[DBCONNECTION] Attempting connection to SQL Server...\n";

			//connect to SQL Server  
			switch (SQLDriverConnect(sqlConnHandle,
				NULL,

				(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1434;DATABASE=model;UID=sergiu;PWD=12345678;Trusted=true;",
				SQL_NTS,
				retconstring,
				1024,
				NULL,
				SQL_DRIVER_NOPROMPT)) {
			case SQL_SUCCESS:
				std::cout << "[DBCONNECTION] Successfully connected to SQL Server";
				std::cout << "\n";
				break;
			case SQL_SUCCESS_WITH_INFO:
				std::cout << "[DBCONNECTION] Successfully connected to SQL Server";
				std::cout << "\n";
				break;
			case SQL_INVALID_HANDLE:
				std::cout << "[DBCONNECTION] Could not connect to SQL Server";
				std::cout << "\n";
				return false;
			case SQL_ERROR:
				std::cout << "[DBCONNECTION] Could not connect to SQL Server";
				std::cout << "\n";
				return false;
			default:
				break;
			}

			if (SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle) != SQL_SUCCESS)
			{
				return false;
			}

			return true;

		}


		bool isConnected()
		{
			return SQLGetConnectAttr(sqlConnHandle, SQL_ATTR_CONNECTION_DEAD, NULL, NULL, NULL);
		}

		void ExecuteQuery(const std::string& query)
		{
			SQLPrepareA(sqlStmtHandle, (SQLCHAR*)query.c_str(), SQL_NTS);
			SQLExecute(sqlStmtHandle);
			SQLDisconnect(sqlConnHandle);

		}


		std::string GetResultFromExecuteQuery(const std::string& query, int columnIndex = 1)
		{

			std::string resultString = "";


			SQLPrepareA(sqlStmtHandle, (SQLCHAR*)query.c_str(), SQL_NTS);
		
			SQLExecute(sqlStmtHandle);

			SQLCHAR queryResult[SQL_RESULT_LEN];
			SQLLEN ptrQueryResult;
			if (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
			{
				SQLGetData(sqlStmtHandle, columnIndex, SQL_CHAR, queryResult, SQL_RESULT_LEN, &ptrQueryResult);
				std::string str((const char*)queryResult);
				resultString += str;
			}
			
			
			SQLDisconnect(sqlConnHandle);

			return resultString;
		}

		std::string GetResultFromRowsetExecuteQuery(const std::string& query, int columnStart = 1, int columnEnd = 1)
		{
			//SQLCHAR queryResult[SQL_RESULT_LEN];

			std::string resultString = "";


			if (SQLPrepareA(sqlStmtHandle, (SQLCHAR*)query.c_str(), SQL_NTS) != SQL_SUCCESS)
			{
				std::cout << "[DBCONNECTION] Error querying SQL Server";
			}
			else
			{
				SQLExecute(sqlStmtHandle);
				std::cout << "[DBCONNECTION] Query executed successfully!\n";
				//declare output variable and pointer
				SQLCHAR queryResult[SQL_RESULT_LEN];
				SQLLEN ptrQueryResult;
				while (SQLFetchScroll(sqlStmtHandle, SQL_FETCH_NEXT, 0) == SQL_SUCCESS)
				{
					for (int i = columnStart; i <= columnEnd; i++)
					{
						SQLGetData(sqlStmtHandle, i, SQL_CHAR, queryResult, SQL_RESULT_LEN, &ptrQueryResult);
						std::string str((const char*)queryResult);
						resultString += str;
						resultString += ";";
					}
					resultString += "\n";
				}
			}
			// finish the query and disconnect. Expect connect attempt in Server.ExecQuery()
			SQLDisconnect(sqlConnHandle);

			return resultString;
		}

		

	private:
		SQLHANDLE sqlConnHandle; //connection
		SQLHANDLE sqlStmtHandle; //statement/query
		SQLHANDLE sqlEnvHandle;  //environment
		SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
	};
}