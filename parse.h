#pragma once
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Parser
{

public:
    string result;
    Parser(
        std::string s)
    {
        try
        {
            result = parse_input(s);
        }
        catch (const std::invalid_argument &result)
        {
            throw result;
        };
    }

private:
    string parse_input(std::string s);
};