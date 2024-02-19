#include <gtest/gtest.h>
#include <string>
#include <utility>
#include "ClassFloat.h"

#define TOSTRING 1
#define OPERATION_ADD 1
#define OPERATION_MULTIPLY 1

#if TOSTRING == 1
#define TOSTRING_TEST
TEST(toString_args, FloatToString) {
    std::string res = std::move(Float("1,234.43565345").toString());
    EXPECT_EQ(res, "1,234.43565345");

    res = std::move(Float("0").toString());
    EXPECT_EQ(res, "0");

    res = std::move(Float("1,111,112,355,342,342,343.3532543").toString());
    EXPECT_EQ(res, "1,111,112,355,342,342,343.3532543");

    res = std::move(Float("23432534634").toString());
    EXPECT_EQ(res, "23,432,534,634");

    res = std::move(Float("123.123").toString());
    EXPECT_EQ(res, "123.123");
}
#endif

#if OPERATION_ADD == 1
#define OPERATION_ADD_TEST
TEST(add_args, AddOperator) {
 // 测试用例1：两个正数相加
    Float a1("123456789");
    Float b1("987654321");
    Float res1 = a1 + b1;
    EXPECT_EQ(res1.toString(), "1,111,111,110");

    // 测试用例2：一个正数和一个负数相加
    Float a2("123456789");
    Float b2("-987654321");
    Float res2 = a2 + b2;
    EXPECT_EQ(res2.toString(), "-864,197,532");

    // 测试用例3：两个负数相加
    Float a3("-123456789");
    Float b3("-987654321");
    Float res3 = a3 + b3;
    EXPECT_EQ(res3.toString(), "-1,111,111,110");

    Float a4("-0.0000000000000000000000000001");
    Float b4("0.0000000000000000000000000001");
    Float res4 = a4 + b4;
    EXPECT_EQ(res4.toString(), "0");

    Float a5("-999999999999999999999999999999999999999");
    Float b5("1000000000000000000000000000000000000000");
    Float res5 = a5 + b5;
    EXPECT_EQ(res5.toString(), "1");

    Float a6("1,111,111,111,111,111,111,111,111,111,111,111,111");
    Float b6("222,222,222,222,222,222,222,222,222,222,222,222");
    Float res6 = a6 + b6;
    EXPECT_EQ(res6.toString(), "1,333,333,333,333,333,333,333,333,333,333,333,333");

    Float a7("3.14159265358979384626");
    Float b7("6.66666666666666666666666");
    Float res7 = a7 + b7;
    EXPECT_EQ(res7.toString(), "9.80825932025646051292666");

    Float a8("-12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890");
    Float b8("98,765,432,198,765,432,198,765,432,198,765,432,198,765,432,198,765");
    Float res8 = a8 + b8;
    EXPECT_EQ(res8.toString(), "86,419,753,297,530,864,308,641,975,409,753,086,519,864,197,630,875");

}
#endif

#if OPERATION_MULTIPLY == 1
#define OPERATION_MULTIPLY_TEST

TEST(multiply_args, MultiplyOperator) {
    // 测试用例1：两个正数相乘
    Float a1("123456789");
    Float b1("987654321");
    Float res1 = a1 * b1;
    EXPECT_EQ(res1.toString(), "121,932,631,112,635,269");

    // 测试用例2：一个正数和一个负数相乘
    Float a2("123456789");
    Float b2("-987654321");
    Float res2 = a2 * b2;
    EXPECT_EQ(res2.toString(), "-121,932,631,112,635,269");

    // 测试用例3：两个负数相乘
    Float a3("-123456789");
    Float b3("-987654321");
    Float res3 = a3 * b3;
    EXPECT_EQ(res3.toString(), "121,932,631,112,635,269");

    // 测试用例4：乘以0
    Float a4("123456789");
    Float b4("0");
    Float res4 = a4 * b4;
    EXPECT_EQ(res4.toString(), "0");

    // 测试用例5：乘以1
    Float a5("123456789");
    Float b5("1");
    Float res5 = a5 * b5;
    EXPECT_EQ(res5.toString(), "123,456,789");
}
#endif