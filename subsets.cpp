#include <iostream>
#include <string>

void enumerate_subsets_helper(std::string prefix, std::string elems)
{
    if(elems.size() == 0)
    {
        std::cout << prefix << std::endl;
    } else {
        std::string sub = elems.substr(1);
        enumerate_subsets_helper(prefix + elems[0], sub);
        enumerate_subsets_helper(prefix, sub);
    }
}

void enumerate_subsets(std::string elems)
{
    enumerate_subsets_helper("", elems);
}

int main(int argc, char** argv)
{
    return enumerate_subsets(argv[1]);
}
