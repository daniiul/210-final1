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
        cout << "work";
        coffeeNode* newCustomer = new coffeeNode();
        newCustomer->name = n;
        newCustomer->drink = d;
        newCustomer->next = nullptr;
        cout << "work";
        if (!head)
        {
            head = newCustomer;
            cout << "work";
        }
        else
        {
            coffeeNode* temp = head;
            while (temp->next)
                temp = temp->next;
            cout << "work";
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
    const int ARRSIZE = 10;
    string names[ARRSIZE] = {"Charles", "Layla", "Daniel", "Maggie", "Colin", "Hillary", "Kiyan", "Pedro", "Anna", "Homer"};
    string drinks[ARRSIZE] = {"Coffee", "Tea", "Water", "Frapuchino", "Caffe Latte", "Hot Coco", "Milk", "Pumpkin Latte", "Fruit Shake", "Ice Cream Shake"};

    coffeBooth Line1;



    Line1.push_back(names[rand() % ARRSIZE], drinks[rand() %  ARRSIZE]);
    Line1.push_back(names[rand() % ARRSIZE], drinks[rand() %  ARRSIZE]);
    Line1.push_back(names[rand() % ARRSIZE], drinks[rand() %  ARRSIZE]);
    Line1.print();
    cout << "work";

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
