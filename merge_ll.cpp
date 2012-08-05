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
        std::cout << head->data << " ";
        head = head->next;
    }

    std::cout << std::endl;
}

node* merge_ll(node* l1, node* l2)
{
    node* newhead = nullptr;
    node* current = nullptr;

    while(l1 || l2)
    {
        node* next = nullptr;
        if(!l2 || (l1 && (l1->data < l2->data)))
        {
            next = l1;
            l1 = l1->next;
        }
        else 
        {
            next = l2;
            l2 = l2->next;
        }

        if(current)
        {
            current->next = next;
        } 
        if(!newhead)
        {
            newhead = next;
        }
        current = next;
    }
    current->next = nullptr;
    return newhead;
}

int main()
{
    node val1[10];
    node val2[10];

    for(int i = 0; i < 10; ++i)
    {
        val1[i].data = i*2;
        val1[i].next = (i == 9 ? nullptr : &val1[i+1]);
        val2[i].data = i*2 + 1;
        val2[i].next = (i == 9 ? nullptr : &val2[i+1]);
    }

    print_ll(val1);
    print_ll(val2);
    node* newhead = merge_ll(val1, val2);
    print_ll(newhead);
}
