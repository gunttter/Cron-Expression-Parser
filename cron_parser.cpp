#include "parse.h"
#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

string parse(string input, int start, int end, int column)
{
    int slash = input.find('/');
    int comma = input.find(',');
    int hyphen = input.find('-');

    string time_field;
    string error_message = "Error! You need to provide correct input in this line. For example: '*/15', '1,12', '1-24' or '*'.";

    // Check correctness of input of each time fields
    if (slash == -1 && comma == -1 && hyphen == -1 && input[0] != '*')
    {
        int size = input.length();

        char char_array[size + 1];

        strcpy(char_array, input.c_str());

        for (int i = 0; i < strlen(char_array); i++)
        {
            if (!isdigit(char_array[i]))
            {
                return error_message;
            }
        }
    }

    switch (column)
    {
    case 0:
    {
        time_field = "minute ";
        break;
    }
    case 1:
    {
        time_field = "hour ";
        break;
    }
    case 2:
    {
        time_field = "day of month ";
        break;
    }
    case 3:
    {
        time_field = "month ";
        break;
    }
    case 4:
    {
        time_field = "day of week ";
        break;
    }
    }

    // any int
    if (input != "*" && slash == string::npos && comma == string::npos && hyphen == string::npos)
    {
        return time_field + input + " ";
    }

    // *
    if (input == "*" && slash == string::npos && comma == string::npos && hyphen == string::npos)
    {
        input = "";
        input += time_field;
        for (int i = start; i <= end; i++)
        {
            input += to_string(i);
            input += " ";
        }
        return input;
    }

    // */int
    if (slash != string::npos && input[0] == '*')
    {
        int tens = input[2] - '0';

        if (input.size() > 3)
        {
            int ones = input[3] - '0';
            input = "";
            input += time_field;
            tens *= 10;
            tens += ones;
            for (int i = start; i < end; i += tens)
            {
                input += to_string(i);
                input += " ";
            }
        }
        else
        {
            input = "";
            input += time_field;
            for (int i = start; i < end; i += tens)
            {
                input += to_string(i);
                input += " ";
            }
        }
        return input;
    }

    // int,int
    if (comma != string::npos)
    {
        int string_size = input.size();

        for (int i = 0; i < string_size; i++)
        {
            if (isdigit(input[i]))
            {
                time_field += input[i];
            }
            else
            {
                time_field += " ";
            }
        }

        // time_field += " ";

        return time_field;
    }

    // int-int
    if (hyphen != string::npos)
    {
        int start = 0, end = 0, string_size = input.size();

        switch (string_size)
        {
        case 3:
        {
            start = input[0] - '0';
            end = input[2] - '0';
            break;
        }
        case 4:
        {
            start = input[0] - '0';
            end = (input[2] - '0') * 10;
            end += (input[3] - '0');
            break;
        }
        case 5:
        {
            start = (input[0] - '0') * 10;
            start += (input[1] - '0');
            end = (input[3] - '0') * 10;
            end += +(input[4] - '0');
            break;
        }
        }

        for (int i = start; i <= end; i++)
        {
            time_field += to_string(i);
            time_field += " ";
        }
        return time_field;
    }
    return error_message;
}

string Parser::parse_input(std::string input)
{
    stringstream ss(input);
    const char delimiter = ' ';
    vector<string> vec;

    string data, minute, hours, day_of_month, month, day_of_week, command;
    while (getline(ss, data, delimiter))
    {
        vec.push_back(data);
    }

    int sz = (int)vec.size();

    if (sz != 6)
    {
        return "Invalid input \n";
    }

    int i = 0;

    while (i != 6)
    {
        switch (i)
        {
        case 0:
        {
            minute = parse(vec[i], 0, 59, i);
            i++;
            break;
        }
        case 1:
        {
            hours = parse(vec[i], 0, 23, i);
            i++;
            break;
        }
        case 2:
        {
            day_of_month = parse(vec[i], 1, 31, i);
            i++;
            break;
        }
        case 3:
        {
            month = parse(vec[i], 1, 12, i);
            i++;
            break;
        }
        case 4:
        {
            day_of_week = parse(vec[i], 1, 7, i);
            i++;
            break;
        }
        case 5:
        {
            command = "command " + vec[i];
            i++;
            break;
        }
        }
    }

    return minute + "\n" + hours + "\n" + day_of_month + "\n" + month + "\n" + day_of_week + "\n" + command;
}