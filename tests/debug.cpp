#include <bits/stdc++.h>
#include <iostream>
#include "ClassFloat.h"

#define TEST_PRINT_MACRO 0
#define TEST_FORMAT_MACRO 0
#define TEST_CMP_MACRO 0
#define TEST_MULTIPLY_MACRO 0
#define TEST_ADDINT_MACRO 0
#define TEST_ADDFL_MACRO 1
#define TEST_SUBSTRACT_MACRO 0
#define TEST_DIVIDE_MACRO 0
#define TEST_SIMPLE_DIVIDE_MACRO 0

#if TEST_CMP_MACRO == 1
#define TEST_CMP
int main() {
    Float a("123.456");
    Float b("987.654");
    Float c("123.456");
    Float d("-987.654");
    Float e("-123.456");
    Float f("-987.654");
    Float g("0");
    Float h("-23425789475982749837483.52389789237498");
    Float i("234257894759827498.3748352389789037498");
    std::cout << (a < b) << std::endl; // 1
    std::cout << (a < c) << std::endl;
    std::cout << (a < d) << std::endl;
    std::cout << (a < e) << std::endl;
    std::cout << (a < f) << std::endl;
    std::cout << (a < g) << std::endl;
    std::cout << (h < i) << std::endl;
    
}
#endif

#if TEST_SIMPLE_DIVIDE_MACRO == 1
#define TEST_TEST_SIMPLE_DIVIDE

#endif

#if TEST_DIVIDE_MACRO == 1
#define TEST_DIVIDE
int main() {
    #if 0
    #endif
    Float a("1");
    Float b("3");
    Float res = a / b;
    std::cout << res.toString() << "--------" << std::endl;
    // 测试用例1：两个正数相除
    Float a1("123.456");
    Float b1("987.654");
    Float res1 = a1 / b1;
    std::cout << res1.toString() << "--------" << std::endl;
    // EXPECT_NEAR(res1.toFloat(), 0.125, 0.001);

    // 测试用例2：一个正数和一个负数相除
    Float a2("123.456");
    Float b2("-987.654");
    Float res2 = a2 / b2;
    std::cout << res2.toString() << "--------" << std::endl;
    // EXPECT_NEAR(res2.toFloat(), -0.125, 0.001);

    // 测试用例3：两个负数相除
    Float a3("-123.456");
    Float b3("-987.654");
    Float res3 = a3 / b3;
    std::cout << res3.toString() << "--------" << std::endl;
    // EXPECT_NEAR(res3.toFloat(), 0.125, 0.001);

    // 测试用例4：除0
    Float a4("123.456");
    Float b4("0");
    Float res4 = a4 / b4;
    std::cout << res4.toString();
    std::cout << "--------" << std::endl;
    // EXPECT_NEAR(res4.toFloat(), 0, 0.001);

    // 测试用例5：除1
    Float a5("123.456");
    Float b5("1");
    Float res5 = a5 / b5;
    std::cout << res5.toString();
    std::cout << "--------" << std::endl;
    // EXPECT_NEAR(res5.toFloat(), 123.456, 0.001);

    // 测试用例6：尾数对齐
    Float a6("123.456");
    Float b6("123456.789");
    Float res6 = a6 / b6;
    std::cout << res6.toString();
    std::cout << "--------" << std::endl;  

    // 测试用例7：两个很大的相等负数相除
    Float a7("-123456789012.34567890");
    Float b7("-123456789012.34567890");
    Float res7 = a7 / b7;
    std::cout << res7.toString();
    std::cout << "--------" << std::endl;
    // EXPECT_NEAR(res7.toFloat(), 1, 0.001);
    a7 = "1000";
    b7 = "10";
    std::cout << (a7 / b7).toString() << "-------" << std::endl;
    Float a9;
    Float b9;
    a9 = "12345678901234567890";
    b9 = "987654321";
    std::cout << (a9 / b9).toString() << "-------" << std::endl;

    Float a8;
    Float b8;
    a8 = "-12345678901234567890";
    b8 = "987654321";
    std::cout << (a8 / b8).toString() << "--------" << std::endl;

    Float A1;
    A1 = "66,666,666,666,666,666,666,666,666,666,666.66666666666666";
    std::cout << A1.toString();
    Float B1;
    B1 = "-2";
    std::cout << (A1 / B1).toString() << "--------" << std::endl;
    #if 0
    #endif
}
#endif

#if TEST_SUBSTRACT_MACRO == 1
#define TEST_SUBSTRACT
int main() {
    #if 0
    // 测试用例6：尾数对齐
    Float a6("123.456");
    Float b6("123456.789");
    Float res6 = a6 - b6;
    res6.print();
    // EXPECT_NEAR(res6.toFloat(), -123333.333, 0.001);

    // 测试用例7：两个很大的相等负数相减
    Float a7("-123456789012.34567890");
    Float b7("-123456789012.34567890");
    Float res7 = a7 - b7;
    res7.print();
    // EXPECT_NEAR(res7.toFloat(), 0, 0.001);
    #endif
    Float a8("-41,829,471,284,124,414.49104801248981284");
    Float b8("-64,580,569,452,374,277.12783183148912947");
    std::cout << (a8 - b8).toString();

    a8 = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    b8 = "2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274";
    std::cout << a8.toString() << b8.toString();
    std::cout << (a8 - b8).toString();

    a8 = "-999999999999999999999999999999999999999";
    b8 = "1000000000000000000000000000000000000000";
    std::cout << (a8 + b8).toString();
}
#endif

#if TEST_ADDFL_MACRO == 1
#define TEST_ADDFL

int main() {
    // 测试用例1：两个正数相加
    Float a1("123.456");
    Float b1("987.654");
    Float res1 = a1 + b1;
    res1.print();

    // 测试用例2：一个正数和一个负数相加
    Float a2("123.456");
    Float b2("-987.654");
    Float res2 = a2 + b2;
    res2.print();

    // 测试用例3：两个负数相加
    Float a3("-123.456");
    Float b3("-987.654");
    Float res3 = a3 + b3;
    res3.print();

    // 测试用例4：加0
    Float a4("123.456");
    Float b4("0");
    Float res4 = a4 + b4;
    res4.print();

    // 测试用例5：加1
    Float a5("5789275087320570283750275807230572");
    Float b5("5723875027590327057203750237590275023759");
    Float res5 = a5 + b5;
    res5.print();

}
#endif

#if TEST_ADDINT_MACRO == 1
#define TEST_ADD
int main() {
    // 测试用例1：两个正数相加
    Float a1("1,111,111,111,111,111,111,111,111,111,111,111,111");
    Float b1("222,222,222,222,222,222,222,222,222,222,222,222");
    Float res1 = a1 + b1;
    res1.print();
    std::cout << "--------" << std::endl;
    // 1,333,333,333,333,333,333,333,333,333,333,333,333

    // 测试用例2：一个正数和一个负数相加
    Float a2("-12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890");
    Float b2("98,765,432,198,765,432,198,765,432,198,765,432,198,765,432,198,765");
    Float res2 = a2 + b2;
    res2.print();
    std::cout << "--------" << std::endl;
    // 86,419,753,297,530,864,308,641,975,409,753,086,519,864,197,630,875

    // 测试用例3：两个负数相加
    Float a3("-123456789");
    Float b3("-987654321");
    Float res3 = a3 + b3;
    res3.print();
    std::cout << "--------" << std::endl;
    // EXPECT_EQ(res3.toString(), "-1111111110");

    // 测试用例4：加0
    Float a4("123456789");
    Float b4("0");
    Float res4 = a4 + b4;
    res4.print();
    std::cout << "--------" << std::endl;
    // EXPECT_EQ(res4.toString(), "123456789");

    // 测试用例5：加1
    Float a5("123456789");
    Float b5("1");
    Float res5 = a5 + b5;
    res5.print();
    std::cout << "--------" << std::endl;
    // EXPECT_EQ(res5.toString(), "123456790");

    Float a6("3.14159265358979384626");
    Float b6("6.66666666666666666666666");
    Float res6 = a6 + b6;
    res6.print();
    std::cout << "--------" << std::endl;
    // 9.80825932025646051292666

    Float res = Float("0") + Float("0");
    res.print();
    std::cout << "--------" << std::endl;
    // 0
    res = Float("0") - Float("0");
    res.print();
    // 0
}
#endif

#if TEST_PRINT_MACRO == 1
#define TEST_PRINT
int main() {
    std::cout << Float("1,234.43565345").toString();
    std::cout << Float("0").toString();
    std::cout << Float("2355342342343.3532543").toString();
    std::cout << Float("23432534634").toString();
    std::cout << Float(("123.123")).toString();
    std::cout << Float("0.3332").toString();
    std::cout << Float("9223372036854775807").toString();
}
#undef TEST_FORMAT_MACRO
#undef TEST_MULTIPLY_MACRO
#endif

#if TEST_FORMAT_MACRO == 1
#define TEST_FORMAT
int main() {
    Float f1("0.000");
    f1.format();
    f1.print();
    Float f2("0000.000");
    f2.format();
    f2.print();
    Float f3("000234.000");
    f3.format();
    f3.print();
    Float f4("000234.120000");
    f4.format();
    f4.print();
}
#undef TEST_PRINT_MACRO
#undef TETEST_MULTIPLY_MACRO
#endif

#if TEST_MULTIPLY_MACRO == 1
#define TEST_MULTIPLY
int main() {
    Float f1("0.000");
    Float f2("134235245246245623523");
    Float f3 = f1 * f2;
    f3.print();
    std::cout << "---------" << std::endl;

    Float f4("333333.333333333");
    Float f5("3");
    Float f6 = f4 * f5;
    f6.print();
    std::cout << "---------" << std::endl;

    Float f7("1222220000");
    Float f8("20");
    Float f9 = f7 * f8;
    f9.print();
    std::cout << "---------" << std::endl;

    Float f10("1");
    Float f11("234444455333333333333.45435345");
    Float f12 = f10 * f11;
    f12.print();
    std::cout << "---------" << std::endl;

    // 测试用例1：两个正数相乘
    Float a1("12345.6789");
    Float b1("98765.4321");
    Float res1 = a1 * b1;
    res1.print();
    std::cout << "---------" << std::endl;

    // 测试用例2：一个正数和一个负数相乘
    Float a2("123456.789");
    Float b2("-987654321");
    Float res2 = a2 * b2;
    res2.print();
    std::cout << "---------" << std::endl;

    // 测试用例3：两个负数相乘
    Float a3("-123456789");
    Float b3("-987654321");
    Float res3 = a3 * b3;
    res3.print();
    std::cout << "---------" << std::endl;

    // 测试用例4：乘以0
    Float a4("12345.6789");
    Float b4("0");
    Float res4 = a4 * b4;
    res4.print();
    std::cout << "---------" << std::endl;

    // 测试用例5：乘以1
    Float a5("123456789");
    Float b5("1");
    Float res5 = a5 * b5;
    res5.print();
}
#undef TEST_PRINT_MACRO
#undef TEST_FORMAT_MACRO
#endif