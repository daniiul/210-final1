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
    coffeeNode*

public:
    linkedlist()
    {
        coffeeNode* head = nullptr;
    }
    void push(string n, string d)
    {
        coffeeNode* temp = new coffeeNode();
        coffeeNode->name = n;
        coffeeNode->drink = d;
        if ()
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
