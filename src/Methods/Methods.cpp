#include <Methods.h>

// I decided to pass vector by value in order to avoid vector modifying
int GetProductsAmount(std::vector<int> prices, int amountOfMoney)
{
    std::sort(prices.begin(), prices.end());

    int sum = 0;
    for (int i = 0; i < prices.size(); ++i)
    {
        sum += prices[i];
        if (sum > amountOfMoney)
        {
            return i;
        }
    }

    return prices.size();
}
bool IsLeapYear(uint32_t year){
    if(year == 0){
        throw std::runtime_error("0 is a wrong year");
    }

    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0) return true;
            return false;
        }
        return true;
    }
    return false;
}
