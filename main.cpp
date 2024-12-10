#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct coffeeNode
{
    string name;
    string drink;
    coffeeNode* next;
};

class coffeeBooth
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
        newCustomer->name = n;
        newCustomer->drink = d;
        newCustomer->next = nullptr;
        if(head == nullptr)
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
    void print()
    {
        cout << "Current coffee line: " << endl;
        coffeeNode* temp = head;
        while (temp->next)
        {
            cout << "    Name: " << temp->name << "  Drink: " << temp->drink << endl;
            temp = temp->next;
        }
    }

};

int main()
{
    srand(time(0));

    const int ARRSIZE = 10;
    string names[ARRSIZE] = {"Charles", "Layla", "Daniel", "Maggie", "Colin", "Hillary", "Kiyan", "Pedro", "Anna", "Homer"};
    string drinks[ARRSIZE] = {"Coffee", "Tea", "Water", "Frapuchino", "Caffe Latte", "Hot Coco", "Milk", "Pumpkin Latte", "Fruit Shake", "Ice Cream Shake"};

    coffeeBooth Line1;

    Line1.push_back(names[rand() % ARRSIZE], drinks[rand() %  ARRSIZE]);
    Line1.push_back(names[rand() % ARRSIZE], drinks[rand() %  ARRSIZE]);
    Line1.push_back(names[rand() % ARRSIZE], drinks[rand() %  ARRSIZE]);
    Line1.print();

    for (int i = 0; i < 10; i++)
    {
        int prob = rand() % 100 + 1;
        if (prob <= 50)
        {
            Line1.push_back(names[rand() % ARRSIZE], drinks[rand() %  ARRSIZE]);
        }
        Line1.serve_customer();
        Line1.print();

    }
    return 0;
}
