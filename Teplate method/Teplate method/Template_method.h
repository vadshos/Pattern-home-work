#pragma once
#include<iostream>
#include"windows.h"
class Network abstract {
protected:
    std::string userName;
    std::string password;
public:
    bool post(std::string message) {

        if (logIn(userName, password)) {
            bool result = sendData(message.c_str());
            logOut();
            return result;
        }
        return false;
    }

    virtual bool logIn(std::string userName, std::string password) = 0;
    virtual bool sendData(const char* data) = 0;
    virtual void logOut() = 0;
};

class Facebook : public Network {
public:
    Facebook(std::string userName, std::string password) {
        this->userName = userName;
        this->password = password;
    }

    bool logIn(std::string userName, std::string password) {
        std::cout << "\nChecking user's parameters" << std::endl;
        std::cout << "Name: " + this->userName << std::endl;
        std::cout << "Password: " << std::endl;
        for (int i = 0; i < this->password.length(); i++) {
            std::cout << "*";
        }
        simulateNetworkLatency();
        std::cout << "\n\nLogIn success on Facebook" << std::endl;
        return true;
    }

    bool sendData(const char* data) {
        bool messagePosted = true;
        if (messagePosted) {
            std::cout << "Message: '" + std::string(data) + "' was posted on Facebook" << std::endl;
            return true;
        }
        else {
            return false;
        }
    }

    void logOut() {
        std::cout << "User: '" + userName + "' was logged out from Facebook" << std::endl;
    }

private:
    void simulateNetworkLatency() {
        try {
            int i = 0;
            std::cout << std::endl;
            while (i < 10) {
                std::cout << ".";
                Sleep(500);
                i++;
            }
        }
        catch (std::exception ex) {
            std::cout << ex.what();
        }
    }
};

class Twitter : public Network {

public:
    Twitter(std::string userName, std::string password) {
        this->userName = userName;
        this->password = password;
    }

public:
    bool logIn(std::string userName, std::string password) {
        std::cout << "\nChecking user's parameters" << std::endl;
        std::cout << "Name: " << this->userName.c_str() << std::endl;
        std::cout << "Password: ";
        for (int i = 0; i < this->password.length(); i++) {
            std::cout << "*";
        }
        simulateNetworkLatency();
        std::cout << "\n\nLogIn success on Twitter" << std::endl;
        return true;
    }

    bool sendData(const char* data) override{
        boolean messagePosted = true;
        if (messagePosted) {
            std::cout << "Message: '" + std::string(data) + "' was posted on Twitter" << std::endl;
            return true;
        }
        else {
            return false;
        }
    }

    void logOut() {
        std::cout << "User: '" + userName + "' was logged out from Twitter" << std::endl;
    }

private:
    void simulateNetworkLatency() {
        try {
            int i = 0;
            std::cout << std::endl;
            while (i < 10) {
                std::cout << ".";
                Sleep(500);
                i++;
            }
        }
        catch (std::exception ex) {
            ex.what();
        }
    }
};