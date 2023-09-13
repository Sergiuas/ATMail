#pragma once
#include "app_common.h"

namespace app
{
    class Mail {
    private:
        std::string sourceClient;
        std::string destinatarClient;
        std::string subject;
        std::string text;
        std::string fileName;
        std::vector<unsigned char> fileContent;

    public:
        Mail(std::string sourceClient, std::string destinatarClient, std::string subject, std::string text, std::string fileName, std::vector<unsigned char> fileContent);

        std::string getSourceClient() const;
        std::string getDestinatarClient() const;
        std::string getSubject() const;
        std::string getText() const;
        std::string getFileName() const;
        std::vector<unsigned char> getFileContent() const;
    };
}