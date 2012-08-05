#include <iostream>
#include <string>

struct node
{
    int data;
    node* next;
};

void print_ll(node* head)
{
    while(head)
    {
        std::cout << head->data;
        head = head->next;
    }

    std::cout << std::endl;
}

node* reverse_ll(node* head)
{
    node* current, *trailing;
    current = head;
    trailing = nullptr;

    while(current)
    {
        node* temp = current;
        current = current->next;
        temp->next = trailing;
        trailing = temp;
    }

    return trailing;
}

int main()
{
    node values[10];
    for(int i = 0; i < 10; ++i)
    {
        values[i].data = i;
        values[i].next = (i == 9 ? nullptr : &values[i+1]);
    }

    print_ll(values);
    node* newhead = reverse_ll(values);
    print_ll(newhead);
}
