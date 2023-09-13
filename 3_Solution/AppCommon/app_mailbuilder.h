#pragma once
#include "app_common.h"
#include "app_mail.h"


static std::vector<uint8_t> readFile(std::string filePath)
{

    std::vector<uint8_t> fileContent;
    // Open the file in binary mode
    std::ifstream file(filePath, std::ios::binary);

    if (file) {
        // Determine the size of the file
        file.seekg(0, std::ios::end);
        std::streampos fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        // Resize the vector to accommodate the file's contents
        fileContent.resize(fileSize);

        // Read the file's contents into the vector
        file.read((char*)&fileContent[0], fileSize);
    }
    else {
        //TODO: Handle error opening file
    }

    return fileContent;
}

namespace app {
    class MailBuilder {
    private:
        std::string sourceClient;
        std::string destinatarClient;
        std::string subject;
        std::string text;
        std::string fileName;
        std::vector<uint8_t> fileContent;

    public:
        MailBuilder& setSourceClient(std::string sourceClient);
        MailBuilder& setDestinatarClient(std::string destinatarClient);
        MailBuilder& setSubject(std::string subject);
        MailBuilder& setText(std::string text);
        MailBuilder& setFileName(std::string fileName);
        MailBuilder& setFileContent(std::string filePath);

        Mail build() const;
    };

    MailBuilder& MailBuilder::setSourceClient(std::string sourceClient) {
        this->sourceClient = sourceClient;
        return *this;
    }

    MailBuilder& MailBuilder::setDestinatarClient(std::string destinatarClient) {
        this->destinatarClient = destinatarClient;
        return *this;
    }

    MailBuilder& MailBuilder::setSubject(std::string subject) {
        this->subject = subject;
        return *this;
    }

    MailBuilder& MailBuilder::setText(std::string text) {
        this->text = text;
        return *this;
    }

    MailBuilder& MailBuilder::setFileName(std::string fileName) {
        this->fileName = fileName;
        return *this;
    }

    MailBuilder& MailBuilder::setFileContent(std::string filePath) {
        this->fileContent = readFile(filePath);
        return *this;
    }

    Mail MailBuilder::build() const {
        return Mail(sourceClient, destinatarClient, subject, text, fileName, fileContent);
    }
}