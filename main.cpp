#include <iostream>
#include <vector>
#include <sstream>
#include "parse.h"

using namespace std;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        cout << "You need to provide input as an command line agrument.\n";
        return -1;
    }

    string res;

    try
    {
        Parser parser(argv[1]);
        res = parser.result;
    }
    catch (const std::exception &e)
    {
        cout << e.what();
    }

    cout << res;

    return 0;
}
