#pragma once
#include<iostream>
#include<vector>
#include<string>

__interface IPay
{
	void pay();
};

class PayPayPal : public IPay
{
public:
    virtual void pay();
};

class PayCard : public IPay
{
public:
    virtual void pay();
};

class ShopingCard
{
public:
    ShopingCard(IPay* pay) : pay(pay) {};
	void addProduct(std::pair<std::string,size_t> pair);
	void Pay();
	const size_t countSum() const;
private:
	IPay* pay;
	std::vector<std::pair<std::string, size_t>> shopingCard;
};

inline void ShopingCard::addProduct(std::pair<std::string, size_t> pair)
{
    shopingCard.push_back(pair);
}

inline void ShopingCard::Pay()
{
    pay->pay();
}

inline const size_t ShopingCard::countSum() const
{
    size_t sum = 0;
    for (auto& i : shopingCard)
    {
        sum += i.second;
    }
    return sum;
}

inline void PayPayPal::pay()
{
    std::string emailId;
    std::string password;
    std::cout << "Enter emailId : ";
    getline(std::cin, emailId);
    std::cout << "Enter password : ";
    getline(std::cin, password);
    std::cout << "Buy was payed" << std::endl;
}

inline void PayCard::pay()
{
    std::string name;
    size_t numberCard;
    std::string cvv;
    std::string dateAchionCard;

    std::cout << "Enter name : ";
    getline(std::cin, name);
    std::cout << "Enter numberCard : ";
    std::cin >> numberCard;
    std::cout << "Enter cvv : ";
    getline(std::cin, cvv);
    std::cout << "Enter date achion card : ";
    getline(std::cin, dateAchionCard);
    std::cout << "Buy was payed" << std::endl;
}