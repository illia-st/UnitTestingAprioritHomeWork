#include <gtest/gtest.h>
#include <Methods.h>

// I decided not to test negative numbers here because it will work as positive
// also I would like to make parameters uint32_t

TEST(GetProductsAmountTest, EasyTest){
    const int expected = 1;
    std::vector<int> prices {1};
    int amountOfMoney {1};
    const auto actual {GetProductsAmount(prices, amountOfMoney)};
    ASSERT_EQ(expected, actual);
}
TEST(GetProductsAmountTest, EmptyVectorTest){
    const int expected = 0;
    std::vector<int> prices;
    int amountOfMoney {100};
    const auto actual {GetProductsAmount(prices, amountOfMoney)};
    ASSERT_EQ(expected, actual);
}
TEST(GetProductsAmountTest, ZeroesVectorTest){
    std::vector<int> prices(5);
    const int expected = prices.size();
    int amountOfMoney {0};
    const auto actual {GetProductsAmount(prices, amountOfMoney)};
    ASSERT_EQ(expected, actual);
}
TEST(GetProductsAmountTest, RealExampleLessMoney){
    const int expected = 4;
    std::vector<int> prices {10,25,60,45,10};
    int amountOfMoney {96};
    const auto actual {GetProductsAmount(prices, amountOfMoney)};
    ASSERT_EQ(expected, actual);
}
TEST(GetProductsAmountTest, RealExampleMoreMoney){
    std::vector<int> prices {10,25,60,45,10};
    const auto expected = prices.size();
    int amountOfMoney {200};
    const auto actual {GetProductsAmount(prices, amountOfMoney)};
    ASSERT_EQ(expected, actual);
}
TEST(GetProductsAmountTest, ZeroMoney){
    const int expected = 0;
    std::vector<int> prices {10,25,60,45,10};
    int amountOfMoney {0};
    const auto actual {GetProductsAmount(prices, amountOfMoney)};
    ASSERT_EQ(expected, actual);
}


//// to avoid possible infinitive loop change int i to std::size_t i
//// also be careful with this test because of big vector
////TEST(GetProductsAmountTest, CheckOutOfBoundary){
////
////    // infinitive loop possible
////    std::vector<int> prices (INT32_MAX + 1);
////    const auto expected = prices.size();
////    prices.back() = 1;
////    int amountOfMoney {100};
////    const auto actual {GetProductsAmount(prices, amountOfMoney)};
////    ASSERT_EQ(expected, actual);
////}
//
//// type overflow. Result - wrong answer
// Perhaps it would be better to for i < prices.size() - 1 && INT32_MAX - sum < prices[i + 1]
// before the next iteration than increase sum every time
TEST(GetProductsAmountTest, CheckSumBoundary){
    std::vector<int> prices {INT32_MAX, 1};
    const int amountOfMoney {INT32_MAX};
    const auto expected = 1;
    const auto actual {GetProductsAmount(prices, amountOfMoney)};
    ASSERT_EQ(expected, actual);
}

TEST(IsLeapYearTest, Year1997){
    ASSERT_EQ(false, IsLeapYear(1997));
}
TEST(IsLeapYearTest, Year1900){
    ASSERT_EQ(false, IsLeapYear(1900));
}
TEST(IsLeapYearTest, Year1996){
    ASSERT_EQ(true, IsLeapYear(1996));
}
TEST(IsLeapYearTest, Year2000){
    ASSERT_EQ(true, IsLeapYear(2000));
}
TEST(IsLeapYearTest, Year2500){
    ASSERT_EQ(false, IsLeapYear(2500));
}

/*
 * AD dating begins with the year 1. Dionysius Exiguus, the sixth century Balkan
 * monk who created the modern system of dating from the traditional date of the
 * birth of Christ, was operating in a mathematical culture which did not have a
 * concept of zero. Nothingness was not regarded as something which could be regarded
 * as a number. Numbers were only assigned to things which could be counted or measured,
 * which meant that there had to be some non-zero number involved. The first year during
 * which Christ was alive is 1 AD, even though he wasn’t born until nearly the end.
 * Think of it as rounding up if you must, but the AD system is fundamentally defined
 * as not having a year zero.
 */
TEST(IsLeapYearTest, Year0){
    EXPECT_THROW(IsLeapYear(0), std::runtime_error);
}
TEST(IsLeapYearTest, Year1){
    ASSERT_EQ(false, IsLeapYear(1));
}
TEST(IsLeapYearTest, Year2){
    ASSERT_EQ(false, IsLeapYear(2));
}
TEST(IsLeapYearTest, Year4){
    ASSERT_EQ(true, IsLeapYear(4));
}
TEST(IsLeapYearTest, Year3000){
    ASSERT_EQ(false, IsLeapYear(3000));
}
TEST(IsLeapYearTest, YearUINT32_MAX){
    ASSERT_EQ(false, IsLeapYear(UINT32_MAX));
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}