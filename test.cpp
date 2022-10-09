#include <string>
#include <iostream>
#include "parse.h"
void test_1()
{
    string res, output = "minute 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 \nhour 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 \nday of month 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 \nmonth 1 2 3 4 5 6 7 8 9 10 11 12 \nday of week 1 2 3 4 5 6 7 \ncommand user";

    // sample output
    // minute 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59
    // hour 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
    // day of month 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
    // month 1 2 3 4 5 6 7 8 9 10 11 12
    // day of week 1 2 3 4 5 6 7
    // command user

    try
    {
        Parser parser("* * * * * user");
        res = parser.result;
    }
    catch (const std::exception &e)
    {
        cout << e.what();
    }

    if (res != output)
    {
        cout << "Test_1 is not passed;\n";
        return;
    }
    cout << "Test_1 is passed;\n";
}
void test_2()
{
    string res, output = "minute 0 15 30 45 \nhour 0 \nday of month 1 15\nmonth 1 2 3 4 5 6 7 8 9 10 11 12 \nday of week 1 2 3 4 5 \ncommand /usr/bin/find";

    // sample output
    // minute 0 15 30 45
    // hour 0
    // day of month 1 15
    // month 1 2 3 4 5 6 7 8 9 10 11 12
    // day of week 1 2 3 4 5
    // command /usr/bin/find

    try
    {
        Parser parser("*/15 0 1,15 * 1-5 /usr/bin/find");
        res = parser.result;
    }
    catch (const std::exception &e)
    {
        cout << e.what();
    }

    if (res != output)
    {
        cout << "Test_2 is not passed;\n";
        return;
    }
    cout << "Test_2 is passed;\n";
}
void test_3()
{
    string res, output = "minute 1 2 3 \nhour 7 8 \nday of month 21 22 23 24 25 \nmonth 11 12 \nday of week 1 2 3 4 5 6 7 \ncommand usr/gofind";

    // sample output
    // minute 1 2 3
    // hour 7 8
    // day of month 21 22 23 24 25
    // month 11 12
    // day of week 1 2 3 4 5 6 7
    // command usr/gofind

    try
    {
        Parser parser("1-3 7-8 21-25 11-12 1-7 usr/gofind");
        res = parser.result;
    }
    catch (const std::exception &e)
    {
        cout << e.what();
    }

    if (res != output)
    {
        cout << "Test_3 is not passed;\n";
        return;
    }
    cout << "Test_3 is passed;\n";
}
void test_4()
{
    string res, output = "minute 1 2 3 4 5 6\nhour 3 5\nday of month 20 25\nmonth 1 12\nday of week 3 7\ncommand usr/gofind";

    // sample output
    // minute 1 2 3 4 5 6
    // hour 3 5
    // day of month 20 25
    // month 1 12
    // day of week 3 7
    // command usr/gofind

    try
    {
        Parser parser("1,2,3,4,5,6 3,5 20,25 1,12 3,7 usr/gofind");
        res = parser.result;
    }
    catch (const std::exception &e)
    {
        cout << e.what();
    }

    if (res != output)
    {
        cout << "Test_4 is not passed;\n";
        return;
    }
    cout << "Test_4 is passed;\n";
}

void test_5()
{
    string res, output = "minute 1 2 3 4 5 6\nhour 3 5\nday of month 20 25\nError! You need to provide correct input in this line. For example: '*/15', '1,12', '1-24' or '*'.\nday of week 3 7\ncommand usr/gofind";

    // sample output
    // minute 1 2 3 4 5 6
    // hour 3 5
    // day of month 20 25
    //
    // Error! You need to provide correct input in this line. For example: '*/15', '1,12', '1-24' '*'.
    //
    // day of week 3 7
    // command usr/gofind

    try
    {
        Parser parser("1,2,3,4,5,6 3,5 20,25 1*12 3,7 usr/gofind");
        res = parser.result;
    }
    catch (const std::exception &e)
    {
        cout << e.what();
    }
    if (res != output)
    {
        cout << "Test_5 is not passed;\n";
        return;
    }
    cout << "Test_5 is passed;\n";
}

void test_6()
{
    string res, output = "Invalid input \n";

    // sample output

    // Invalid input
    try
    {
        Parser parser("1,2 Cron");
        res = parser.result;
    }
    catch (const std::exception &e)
    {
        cout << e.what();
    }
    if (res != output)
    {
        cout << "Test_6 is not passed;\n";
        return;
    }
    cout << "Test_6 is passed;\n";
}

void test_7()
{
    string res, output = "Invalid input \n";

    // sample output

    // Invalid input

    try
    {
        Parser parser("1,2 */2 * * 1-4 /usr/bin/find /usr/bin/parse");
        res = parser.result;
    }
    catch (const std::exception &e)
    {
        cout << e.what();
    }
    if (res != output)
    {
        cout << "Test_7 is not passed;\n";
        return;
    }
    cout << "Test_7 is passed;\n";
}

void test_8()
{
    string res, output = "Invalid input \n";

    // sample output

    // Invalid input

    try
    {
        Parser parser("");
        res = parser.result;
    }
    catch (const std::exception &e)
    {
        cout << e.what();
    }
    if (res != output)
    {
        cout << "Test_8 is not passed;\n";
        return;
    }
    cout << "Test_8 is passed;\n";
}

int main()
{
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
}