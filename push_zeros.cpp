#include <iostream>
#include <string>

template<int N>
void print_array(int (&elements)[N])
{
    for(int i = 0; i < N; ++i)
    {
        std::cout << elements[i];
    }

    std::cout << std::endl;
}

template<int N>
void push_zeros(int (&elements)[N])
{
    int j = 0;
    for(int i = 0; i < N; ++i)
    {
        if(elements[i] != 0)
            elements[j++] = elements[i];
    }

    for(; j < N; ++j)
        elements[j] = 0;
}

int main()
{
    int elements[] = { 2, 0, 3, 5, 0, 4, 2, 0, 2, 8, 7, 0, 1 };
    print_array(elements);
    push_zeros(elements);
    print_array(elements);
}
