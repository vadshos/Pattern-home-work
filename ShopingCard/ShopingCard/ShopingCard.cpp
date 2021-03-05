#include <iostream>
#include "ShopingCard.h"

int main()
{
	IPay* pay = new PayPayPal();
	ShopingCard sh(pay);
	sh.addProduct({ "Bread",14 });
	sh.addProduct({ "Milk",35 });
	std::cout << sh.countSum()<<std::endl;
	sh.Pay();

}


