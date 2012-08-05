#include <iostream>
#include <string>

void enumerate_perms_helper(std::string prefix, std::string elems)
{
    if(elems.empty())
    {
        std::cout << prefix << std::endl;
    } 
    else 
    {
        for(int i = 0; i < elems.size(); ++i)
        {
            std::string newprefix = prefix + elems[i];
            std::string newelems = elems;
            newelems.erase(i, 1);
            enumerate_perms_helper(newprefix, newelems);
        }
    }
}

void enumerate_perms(std::string elems)
{
    enumerate_perms_helper("", elems);
}

int main(int argc, char** argv)
{
    enumerate_perms(argv[1]);
}
