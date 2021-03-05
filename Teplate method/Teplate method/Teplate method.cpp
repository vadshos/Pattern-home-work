#include <iostream>
#include<string>
#include"Template_method.h"

int main()
{
    std::cout << "Input user name: ";
    std::string userName;
    getline(std::cin, userName);
    std::cout << "Input password: ";
    std::string password;
    getline(std::cin, password);

    // Вводим сообщение.
    std::cout << "Input message: ";
    std::string message;
    getline(std::cin, message);

    std::cout << "\nChoose social network for posting message.\n" <<
        "1 - Facebook\n" <<
        "2 - Twitter";
    int choice;
    std::cin >> choice;
    // Создаем сетевые объекты и публикуем пост.
    Network* network  = nullptr;
    if (choice == 1) {
        network = new Facebook(userName, password);
    }
    else if (choice == 2) {
        network = new Twitter(userName, password);
    }
    network->post(message);
};
