#include "BigInteger.h"
#include <gtest/gtest.h>

TEST(SUM, SMALL) {
    BigInteger a = 37;
    BigInteger b = 63;
    ASSERT_EQ(a + b, 100);
}

TEST(SUM, MIDDLE) {
    BigInteger a = 999999999;
    BigInteger b = 111111111;
    ASSERT_EQ(a + b, 1111111110);
}

TEST(SUM, LARGE) {
    BigInteger a = "999999999999999999999";
    BigInteger b = "111111111111111111111";
    ASSERT_EQ(a + b, "1111111111111111111110");
}

TEST(SUM, HUGE) {
    char* a_string = new char[MAX_SIZE - 2];
    char* b_string = new char[MAX_SIZE - 2];
    char* c_string = new char[MAX_SIZE - 1];
    for (int i = 0; i < MAX_SIZE - 2; ++i) {
        a_string[i] = '1';
        b_string[i] = '9';
        c_string[i] = '1';
    }
    c_string[MAX_SIZE - 2] = '0';
    BigInteger a = a_string;
    BigInteger b = b_string;
    BigInteger c = c_string;
    ASSERT_EQ(a + b, c);
}

TEST(DIFF, SMALL) {
    BigInteger a = 37;
    BigInteger b = 34;
    ASSERT_EQ(a - b, 3);
}

TEST(DIFF, MIDDLE) {
    BigInteger a = 111111;
    BigInteger b = 99900;
    ASSERT_EQ(a - b, 11211);
}

TEST(DIFF, Large) {
    BigInteger a = 1000000000;
    BigInteger b = 999999999;
    ASSERT_EQ(a - b, 1);
}

TEST(DIFF, Large_ZERO) {
    BigInteger a = 1000000000;
    BigInteger b = 1000000000;
    ASSERT_EQ(a - b, 0);
}

TEST(DIFF, HUGE) {
    char* a_string = new char[MAX_SIZE];
    char* b_string = new char[MAX_SIZE];
    char* c_string = new char[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; ++i) {
        a_string[i] = '7';
        b_string[i] = '3';
        c_string[i] = '4';
    }
    BigInteger a = a_string;
    BigInteger b = b_string;
    BigInteger c = c_string;
    ASSERT_EQ(a - b, c);
}

TEST(MULT, ZEROS) {
    BigInteger a = 0;
    BigInteger b = 0;
    ASSERT_EQ(a * b, 0);
}

TEST(MULT, SMALL) {
    BigInteger a = 5;
    BigInteger b = 20;
    ASSERT_EQ(a * b, 100);
}

TEST(MULT, MIDDLE_WITH_ONE) {
    BigInteger a = 1;
    BigInteger b = 345654;
    ASSERT_EQ(a * b, 345654);
}

TEST(MULT, MIDDLE_WITH_ZERO) {
    BigInteger a = 0;
    BigInteger b = 345654;
    ASSERT_EQ(a * b, 0);
}

TEST(MULT, MIDDLE) {
    BigInteger a = 345655;
    BigInteger b = 345654;
    ASSERT_EQ(a * b, "119477033370");
}

TEST(MULT, LARGE) {
    BigInteger a = "1234576533693322";
    BigInteger b = "34565434567876544567887";
    ASSERT_EQ(a * b, "42673674394412353790111217228667550614");
}

TEST(MULT, LARGE_WITH_ONE) {
    BigInteger a = "1";
    BigInteger b = "345654345678765445678873456787654323456786666666";
    ASSERT_EQ(a * b, "345654345678765445678873456787654323456786666666");
}

TEST(MULT, HUGE_WITH_ZERO) {
    char* a_string = new char[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; ++i) {
        a_string[i] = '7';
    }
    BigInteger a = a_string;
    BigInteger b = 0;
    ASSERT_EQ(a * b, 0);
}

TEST(MULT, HUGE_WITH_ONE) {
    char* a_string = new char[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; ++i) {
        a_string[i] = '7';
    }
    BigInteger a = a_string;
    BigInteger b = 1;
    ASSERT_EQ(a * b, a);
}

TEST(MULT, HUGE) {
    BigInteger a = 4;
    BigInteger b = 4;
    for (int i = 0; i < 20; ++i) {
        a = a * 2;
        if (i % 2 == 0) {
            b = b * 4;
        }
    }
    ASSERT_EQ(a, b);
}


TEST(DIVIDE, ZERO) {
    BigInteger a = 0;
    ASSERT_EQ(a / 2, 0);
}

TEST(DIVIDE, ZERO_EXC) {
    BigInteger a = 37;
    ASSERT_ANY_THROW(a / 0);
}

TEST(DIVIDE, ZERO_EXC_MORE) {
    BigInteger a = "234567865434567";
    ASSERT_ANY_THROW(a / (a - a));
}

TEST(DIVIDE, SMALL) {
    BigInteger a = 4;
    ASSERT_EQ(a / 2, 2);
}

TEST(DIVIDE, MIDDLE) {
    BigInteger a = "234565";
    ASSERT_EQ(a / (a / 3), 3);
}

TEST(DIVIDE, MIDDLE_MORE) {
    BigInteger a = "23456786";
    ASSERT_EQ(a / 23672, 990);
}

TEST(DIVIDE, MIDDLE_RESULT_IN_Z) {
    BigInteger a = "564173280";
    ASSERT_EQ(a / 569872, 990);
}

TEST(DIVIDE, LARGE_RESULT_IN_Z) {
    BigInteger a = "28958963877549442139597928245679";
    BigInteger b = "23456765432167899999";
    ASSERT_EQ(a / b, "1234567654321");
}

TEST(DIVIDE, LARGE_RESULT_NOT_IN_Z) {
    BigInteger a = "28958963877549442139597928299999";
    BigInteger b = "23456765432167899999";
    ASSERT_EQ(a / b, "1234567654321");
}

TEST(DIVIDE, HUGE_RESULT_IN_Z) {
    char* a_string = new char[MAX_SIZE - 1];
    char* b_string = new char[MAX_SIZE - 1];
    for (int i = 0; i < MAX_SIZE - 1; ++i) {
        a_string[i] = '6';
        b_string[i] = '3';
    }
    BigInteger a = a_string;
    BigInteger b = b_string;
    ASSERT_EQ(a / b, 2);
}

TEST(DIVIDE, HUGE_RESULT_NOT_IN_Z) {
    char* a_string = new char[MAX_SIZE - 1];
    char* b_string = new char[MAX_SIZE - 1];
    for (int i = 0; i < MAX_SIZE - 2; ++i) {
        a_string[i] = '6';
        b_string[i] = '3';
    }
    a_string[MAX_SIZE - 2] = '7';
    b_string[MAX_SIZE - 2] = '3';
    BigInteger a = a_string;
    BigInteger b = b_string;
    ASSERT_EQ(a / b, 2);
}

TEST(SQRT, SMALL_RESULT_NOT_IN_Z) {
    BigInteger a = 26;
    ASSERT_EQ(a.sqrt(), 5);
}

TEST(SQRT, SMALL_RESULT_IN_Z) {
    BigInteger a = 36;
    ASSERT_EQ(a.sqrt(), 6);
}

TEST(SQRT, MIDDLE_RESULT_IN_Z) {
    BigInteger a = 6431296;
    ASSERT_EQ(a.sqrt(), 2536);
}

TEST(SQRT, MIDDLE_RESULT_NOT_IN_Z) {
    BigInteger a = 725903;
    ASSERT_EQ(a.sqrt(), 851);
}

TEST(SQRT, LARGE_RESULT_IN_Z) {
    BigInteger a = "2110912598404";
    ASSERT_EQ(a.sqrt(), 1452898);
}

TEST(SQRT, LARGE_RESULT_NOT_IN_Z) {
    BigInteger a = "1055456299202";
    ASSERT_EQ(a.sqrt(), 1027354);
}

TEST(GCD, ZERO) {
    BigInteger a = 0;
    BigInteger b = 4;
    ASSERT_ANY_THROW(gcd(a, b));
}

TEST(GCD, SMALL) {
    BigInteger a = 2;
    BigInteger b = 4;
    ASSERT_EQ(gcd(a, b), 2);
}

TEST(GCD, SMALL_MORE) {
    BigInteger a = 37;
    BigInteger b = 36;
    ASSERT_EQ(gcd(a, b), 1);
}

TEST(GCD, MIDDLE) {
    BigInteger a = 345668;
    BigInteger b = 7654432;
    ASSERT_EQ(gcd(a, b), 4);
}

TEST(GCD, MIDDLE_MORE) {
    BigInteger a = 1537698;
    BigInteger b = 3075396;
    ASSERT_EQ(gcd(a, b), a);
}

TEST(GCD, LARGE) {
    BigInteger a = "15654237535456760563451";
    BigInteger b = "245055152816503352938973416878894074997029401";
    ASSERT_EQ(gcd(a, b), "15654237535456760563451");
}

TEST(GCD, HUGE) {
    int size = MAX_SIZE - 2;
    char* a_string = new char[size];
    char* b_string = new char[size];
    for (int i = 0; i < size; ++i) {
        a_string[i] = '9';
        b_string[i] = '3';
    }

    BigInteger a = a_string;
    BigInteger b = b_string;
    ASSERT_EQ(gcd(a, b), b);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
