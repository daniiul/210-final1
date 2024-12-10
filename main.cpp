#include <iostream>
#include <string>


using namespace std;

struct coffeeNode
{
    string name;
    string drink;
    coffeeNode* next;
};

class coffeBooth
{
private:
    coffeeNode* head;

public:
    coffeeBooth()
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
            while (temp->next)
                temp = temp->next;

            temp->next = newCustomer;
        }
    }
    void serve_customer()
    {
        coffeeNode* temp = head->next;
        temp->next = head->next->next;
        head = temp;
    }

};

int main()
{
    const int ARRSIZE = 10;
    string names[ARRSIZE] = ["Charles", "Layla", "Daniel", "Maggie", "Colin", "Hillary", "Kiyan", "Pedro", "Anna", "Homer"];
    string drinks[ARRSIZE] = ["Coffee", "Tea", "Water", "Frapuchino", "Caffe Latte", "Hot Coco", "Milk", "Pumpkin Latte", "Fruit Shake", "Ice Cream Shake"];

    coffeBooth Line1;

    Line1.push_back(names[rand % ARRSIZE], drinks[rand % ARRSIZE]);
    Line1.push_back(names[rand % ARRSIZE], drinks[rand % ARRSIZE]);
    Line1.push_back(names[rand % ARRSIZE], drinks[rand % ARRSIZE]);

    for (int i = 0, i )
    return 0;
}
