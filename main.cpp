#include <iostream>
#include <string>

using namespace std;

struct coffeeNode
{
    string name;
    string drink;
    coffeeNode* next;
};

class linkedlist
{
private:
    coffeeNode* head;

public:
    linkedlist()
    {
        head = nullptr;
    }
    void push_back(string n, string d)
    {
        coffeeNode* newCustomer = new coffeeNode();
        coffeeNode->name = n;
        coffeeNode->drink = d;
        coffeeNode->next = nullptr;
        if (head!)
        {
            head = newCustomer;
        }
        else
        {
            coffeeNode* temp = head;
        }

        if ()
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
