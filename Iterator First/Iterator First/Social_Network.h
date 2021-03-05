#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"windows.h"

class Profile {
private:
    std::string name;
    std::string email;
    std::map<std::string, std::vector<std::string>> contacts;

public:
    Profile(std::string email, std::string name, std::vector<char*> contacts) {
        this->email = email;
        this->name = name;

        // Parse contact list from a set of "friend:email@gmail.com" pairs.
        for (char* contact : contacts) {
            char c = ':';
            char* ch = &c;
            char* parts = strtok_s(contact, NULL, &ch);
            std::string contactType = "friend", contactEmail;
            if (parts[1]) {
                //contactEmail = parts[0];
            }
            else {
                // contactType = parts[0];
                 //contactEmail = parts[1];
            }
            auto it = std::find(contacts.begin(), contacts.end(), contactType);

            this->contacts[contactType];

            this->contacts[contactType].push_back(contactEmail);
        }
    }

public:
    std::string getEmail() {
        return email;
    }

    std::string getName() {
        return name;
    }

public:
    std::vector<std::string> getContacts(std::string contactType) {
        auto it = std::find(contacts.begin(), contacts.end(), contactType);


        this->contacts[contactType];

        return contacts[contactType];
    }
};

__interface ProfileIterator {
    bool hasNext();
    Profile* getNext();
    void reset();
};


class FacebookIterator;
__interface SocialNetwork {
    ProfileIterator* createFriendsIterator(std::string profileEmail);

    ProfileIterator* createCoworkersIterator(std::string profileEmail);
};
class Facebook :public SocialNetwork {
private:
    std::vector<Profile*> profiles;

public:
    Facebook(std::vector<Profile*> cache) {
        if (!cache.empty()) {
            this->profiles = cache;
        }
    }


    Profile* requestProfileFromFacebook(std::string profileEmail) {
        simulateNetworkLatency();
        std::cout << "Facebook: Loading profile '" + profileEmail + "' over the network..." << std::endl;
        return findProfile(profileEmail);
    }


    std::vector<std::string> requestProfileFriendsFromFacebook(std::string profileEmail, std::string contactType) {

        simulateNetworkLatency();
        std::cout << "Facebook: Loading '" + contactType + "' list of '" + profileEmail + "' over the network..." << std::endl;

        // ...and return test data.
        Profile* profile = findProfile(profileEmail);
        if (profile != nullptr) {
            return profile->getContacts(contactType);
        }
        return  std::vector<std::string>{};
    }

private:
    Profile* findProfile(std::string profileEmail) {
        for (Profile* profile : profiles) {
            if (profile->getEmail() == profileEmail) {
                return profile;
            }
        }
        return nullptr;
    }

private:
    void simulateNetworkLatency() {
        try {
            Sleep(2500);
        }
        catch (std::exception ex) {
            std::cout << ex.what() << std::endl;
        }
    }
public:
    ProfileIterator* createFriendsIterator(std::string profileEmail) {
        return new FacebookIterator(this, "friends", profileEmail);
    }


    ProfileIterator* createCoworkersIterator(std::string profileEmail) {
        return new FacebookIterator(this, "coworkers", profileEmail);
    }



};
class LinkedIn;
class FacebookIterator :public ProfileIterator {
private:
    Facebook* facebook;
    std::string type;
    std::string email;
    int currentPosition = 0;
    std::vector<std::string> emails;
    std::vector<Profile*> profiles;

public:
    FacebookIterator(Facebook* facebook, std::string type, std::string email) {
        this->facebook = facebook;
        this->type = type;
        this->email = email;
    }

private:
    void lazyLoad() {
        if (emails.size() == 0) {
            std::vector<std::string> profiles = facebook->requestProfileFriendsFromFacebook(this->email, this->type);
            for (std::string profile : profiles) {
                this->emails.push_back(profile);
                this->profiles.push_back(nullptr);
            }
        }
    }


public:
    bool hasNext() {
        lazyLoad();
        return currentPosition < emails.size();
    }
public:
    Profile* getNext() override {
        if (!hasNext()) {
            return nullptr;
        }

        std::string friendEmail = emails[currentPosition];
        Profile* friendProfile = profiles[currentPosition];
        if (friendProfile == nullptr) {
            friendProfile = facebook->requestProfileFromFacebook(friendEmail);
            profiles[currentPosition] = friendProfile;
        }
        currentPosition++;
        return friendProfile;
    }

    void reset() {
        currentPosition = 0;
    }
};
class LiLinkedInIterator;
class LinkedIn :public SocialNetwork {
private:
    std::vector<Profile*> contacts;

public:
    LinkedIn(std::vector<Profile*> cache) {
        if (!cache.empty()) {
            this->contacts = cache;
        }
    }

public:
    Profile* requestContactInfoFromLinkedInAPI(std::string profileEmail) {

        simulateNetworkLatency();
        std::cout << "LinkedIn: Loading profile '" + profileEmail + "' over the network..." << std::endl;

        return findContact(profileEmail);
    }

    std::vector<std::string> requestRelatedContactsFromLinkedInAPI(std::string profileEmail, std::string contactType) {
        simulateNetworkLatency();
        std::cout << "LinkedIn: Loading '" + contactType + "' list of '" + profileEmail + "' over the network..." << std::endl;

        // ...and return test data.
        Profile* profile = findContact(profileEmail);
        if (profile != nullptr) {
            return profile->getContacts(contactType);
        }
        return std::vector<std::string>{};
    }

private:
    Profile* findContact(std::string profileEmail) {
        for (Profile* profile : contacts) {
            if (profile->getEmail() == (profileEmail)) {
                return profile;
            }
        }
        return nullptr;
    }

    void simulateNetworkLatency() {
        try {
            Sleep(2500);
        }
        catch (std::exception ex) {
            std::cout << ex.what() << std::endl;
        }
    }


public:
    ProfileIterator* createFriendsIterator(std::string profileEmail) {
        return new class LinkedInIterator(this, "friends", profileEmail);
    }

    ProfileIterator* createCoworkersIterator(std::string profileEmail) {
        return new class LinkedInIterator(this, "coworkers", profileEmail);
    }
};

class LinkedInIterator : public ProfileIterator {
private:
    std::string type;
    std::string email;
    int currentPosition = 0;
    std::vector<std::string> emails;
    std::vector<Profile*> contacts;
    LinkedIn* linkedIn;
public:
    LinkedInIterator(LinkedIn* linkedIn,std::string type, std::string email) {
        this->type = type;
        this->email = email;
        if (linkedIn) {
            this->linkedIn = linkedIn;
        }
    }

private:
    void lazyLoad() {
        if (emails.size() == 0) {
            std::vector<std::string> profiles =  linkedIn->requestRelatedContactsFromLinkedInAPI(this->email, this->type);
            for (std::string profile : profiles) {
                this->emails.push_back(profile);
                this->contacts.push_back(nullptr);
            }
        }
    }


public:
    bool hasNext() {
        lazyLoad();
        return currentPosition < emails.size();
    }


public:
    Profile* getNext() {
        if (!hasNext()) {
            return nullptr;
        }

        std::string friendEmail = emails[currentPosition];
        Profile* friendContact = contacts[currentPosition];
        if (friendContact == nullptr) {
            friendContact = linkedIn->requestContactInfoFromLinkedInAPI(friendEmail);
            contacts[currentPosition] = friendContact;
        }
        currentPosition++;
        return friendContact;
    }


    void reset() {
        currentPosition = 0;
    }
};










