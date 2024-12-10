#include <iostream>
#include <string>
#include <ctime>
#include <deque>

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
        if(!head)
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
        if(head->next->next)
        {
            coffeeNode* temp = head->next;
            temp->next = head->next->next;
            head = temp;
        }
        else if (head->next)
        {
            coffeeNode* temp = head->next;
            head = temp;
        }
        else
        {
            head = nullptr;
        }
    }
    void print()
    {
        cout << "Current coffee line: " << endl;
        coffeeNode* temp = head;
        if (!temp)
        {
            cout << "    There is nobody in Line!" << endl;
            return;
        }
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
    string muffins[ARRSIZE] = {"Blueberry", "Strawberry", "Bannana", "Chocolate Chip", "English", "Brownie", "Vanilla", "Regular", "American", "Safeway"};

    deque<string> muffinLine;

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
            muffinLine.push_back(muffins[rand() % ARRSIZE]);
        }
        Line1.serve_customer();
        if(!muffinLine.empty())
            muffinLine.pop_front();
        Line1.print();

    }
    return 0;
}
