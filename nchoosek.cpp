#include <iostream>
#include <string>

void nchoosek(std::string results, std::string n, int k)
{
    if(k == 0)
    {
        std::cout << results << std::endl;
        return;
    }

    if(k > n.size())
    {
        return;
    }
    

    for(int i = 0; i < n.size(); ++i)
    {
        nchoosek(results + n[i], n.substr(i+1), k-1);
    }
}

int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    std::string base;

    for(int i = 0; i < n; ++i)
    {
        base += char('a' + i);
    }

    nchoosek("", base, k);
}
