#pragma once
#include <app_common.h>

struct Mail {
    std::string src;
    std::string dest;
    std::string subject;
    std::string ora;
    size_t mailId;
    bool seen;
    int files;
    int section;
};

class MailBox
{

    public:
        MailBox() :lastMailId(0) {
            sections.push_back({ 1, "Trash" });
            sections.push_back({ 2, "Starred" });
        };
        void addMail(const std::string& src, const std::string& dest, const std::string& subject, size_t mailId, const std::string& ora, bool seen, int files=0, int section = 0) {
            Mail newMail = { src, dest, subject, ora, mailId, seen, files, section};
            mails.push_back(newMail);
            if (mails.size() == 1)
                lastMailId = mailId;
        }

        void addFrontMail(const std::string& src, const std::string& dest, const std::string& subject, size_t mailId, const std::string& ora, bool seen, int files = 0, int section = 0)
        {
            Mail newMail = { src, dest, subject, ora, mailId, seen, files, section };
            mails.push_front(newMail);
           // lastMailId = mailId;
        }
        const std::deque<Mail>& getAllMails() const {
            return mails;
        }

        const std::deque<Mail> getInbox(std::string email) {
            std::deque<Mail> inbox;
            for (auto i : mails)
            {
                if (i.dest == email && i.section != 1) // sa nu fie in trashbox
                {
                    inbox.push_back(i);
                }
            }
            return inbox;
        }

        const std::deque<Mail> getSendbox(std::string email) {
            std::deque<Mail> sendbox;
            for (auto i : mails)
            {
                if (i.src == email) //la stergere nu se pune in trash, se sterge de tot
                {
                    sendbox.push_back(i);
                }
            }
            return sendbox;
        }

        const std::deque<Mail> getSectionMails(int id_sectiune, std::string email) {
            std::deque<Mail> trashbox;
            for (auto i : mails)
            {
                if (i.dest == email && i.section == id_sectiune)
                {
                    trashbox.push_back(i);
                }
            }
            return trashbox;
        }



        Mail& operator[](int index) { //not const we want to modify it
            return mails[index];
        }
        size_t getLastId() const
        {
            return lastMailId;
        }

        void setLastId(size_t x)
        {
            lastMailId = x;
        }

        void setSeen(int id)
        {
            for (int i = 0; i < mails.size(); i++)
            {
                if (mails[i].mailId == id)
                    mails[i].seen = true;
            }
        }

        void setSection(int id_mail, int id_section)
        {
            for (int i = 0; i < mails.size(); i++)
            {
                if (mails[i].mailId== id_mail)
                    mails[i].section = id_section;
            }
        }

        Mail& getMail(int id)
        {
            for (int i = 0; i < mails.size(); i++)
            {
                if (id == mails[i].mailId)
                    return mails[i];
            }
        }

        void addSection(int id, std::string sectionName)
        {
            std::pair<int, std::string> p(id, sectionName);
            sections.push_back(p);
        }

        int getSectionIdByName(std::string sectionName) const
        {
            for (auto p : sections)
            {
                if (p.second == sectionName)
                    return p.first;
            }
        }

    private:
        std::deque<Mail> mails;
        size_t lastMailId;
        std::vector<std::pair<int, std::string>> sections;
    
};

