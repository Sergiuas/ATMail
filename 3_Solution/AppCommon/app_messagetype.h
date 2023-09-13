#pragma once
#include "app_common.h"


namespace app
{
	enum class MessageType : uint32_t
	{
		ServerAccept,
		ServerDeny,
		ServerPing,
		MessageAll,
		ServerMessage,
		RegisterRequest,
		LoginRequest,
		LoginRememeberedRequest,
		RememberMeRequest,
		MailTest,
		File,
		MailId,
		FileSent,
		Sent,
		Update,
		MailRequest,
		FileRequest,
		DeleteMail,
		Folder,
		MailInFolder,
		CreateFolders
	};
}