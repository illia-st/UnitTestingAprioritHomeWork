#pragma once
#include <vector>
#include <algorithm>
#include <cstdint>
#include <stdexcept>
// here is a compile error
// remove const from vector or pass it by value
int GetProductsAmount(std::vector<int> prices, int amountOfMoney);
bool IsLeapYear(uint32_t year);