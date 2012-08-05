#include <iostream>
#include <string>

bool simpleregex(std::string target, std::string regex)
{
    if(target.empty() && regex.empty())
        return true;

    if(regex.empty())
        return false;

    if(regex.size() == 1 || regex[1] != '*')
    {
        if(target.empty())
            return false;

        if(regex[0] == '.' || regex[0] == target[0])
            return simpleregex(target.substr(1), regex.substr(1));
    }
    else // x* pattern
    {
        // try match zero (and consume the x*)
        if(simpleregex(target, regex.substr(2)))
            return true;

        // just match the first character, don't consume x*
        if(!target.empty() && (regex[0] == '.' || regex[0] == target[0]))
            return simpleregex(target.substr(1), regex);
    }

    return false;
}

int main(int argc, char** argv)
{
    std::cout << simpleregex(argv[1], argv[2]);
}
