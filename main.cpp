// COMSC-210 | Final 1 | Daniil Malakhov
// IDE used: Codeblocks
#include <iostream>
#include <string>
#include <ctime>
#include <deque>
#include <vector>
#include <list>

using namespace std;

struct coffeeNode
{
    string name;
    string drink;
    coffeeNode* next;
};

struct muffin
{
    string name;
    string type;
};

struct bracelet
{
    string name;
    string color;
};

struct cake
{
    string name;
    string type;
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
        if(!head)
            return;

        coffeeNode* temp = head;

        if(head->next)
        {
            head = head->next;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
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
        cout << "    Name: " << temp->name << "  Drink: " << temp->drink << endl;
    }
};

void muffinLinePrint(deque<muffin>& muffinLine);
void braceletLinePrint(vector<bracelet>& braceletLine);
void cakeLinePrint(list<cake>& cakeLine);

int main()
{
    srand(time(0));

    const int ARRSIZE = 10;
    string names[ARRSIZE] = {"Charles", "Layla", "Daniel", "Maggie", "Colin", "Hillary", "Kiyan", "Pedro", "Anna", "Homer"};
    string drinks[ARRSIZE] = {"Coffee", "Tea", "Water", "Frapuchino", "Caffe Latte", "Hot Coco", "Milk", "Pumpkin Latte", "Fruit Shake", "Ice Cream Shake"};
    string muffins[ARRSIZE] = {"Blueberry", "Strawberry", "Bannana", "Chocolate Chip", "English", "Brownie", "Vanilla", "Regular", "American", "Safeway"};
    string colors[ARRSIZE] = {"Red", "White", "Blue", "Orange", "Purple", "Light Blue", "Violet", "Teal", "Rainbow", "Black"};
    string cakes[ARRSIZE] = {"Napolean", "Strawberry", "Chocolate Chip", "Vanilla", "Cheesekake", "Kiyv'skiy", "Fruit", "Ice cream", "Custom Design", "Blueberry"};


    vector<bracelet> braceletLine;
    for (int i = 0; i < 3; i++)
    {
        bracelet temp;
        temp.name = names[rand() % ARRSIZE];
        temp.color = colors[rand() % ARRSIZE];
        braceletLine.push_back(temp);
    }

    deque<muffin> muffinLine;
    for (int i = 0; i < 3; i++)
    {
        muffin temp;
        temp.name = names[rand() % ARRSIZE];
        temp.type = muffins[rand() % ARRSIZE];
        muffinLine.push_back(temp);
    }

    list<cake> cakeLine;
    for (int i = 0; i < 3; i++)
    {
        cake temp;
        temp.name = names[rand() % ARRSIZE];
        temp.type = cakes[rand() % ARRSIZE];
        cakeLine.push_back(temp);
    }

    coffeeBooth Line1;
    Line1.push_back(names[rand() % ARRSIZE], drinks[rand() %  ARRSIZE]);
    Line1.push_back(names[rand() % ARRSIZE], drinks[rand() %  ARRSIZE]);
    Line1.push_back(names[rand() % ARRSIZE], drinks[rand() %  ARRSIZE]);

    for (int i = 0; i < 10; i++)
    {
        int prob1 = rand() % 100 + 1;
        int prob2 = rand() % 100 + 1;
        int prob3 = rand() % 100 + 1;
        int prob4 = rand() % 100 + 1;

        Line1.serve_customer();

        if(!muffinLine.empty())
            muffinLine.pop_front();

        if(!braceletLine.empty())
            braceletLine.erase(braceletLine.begin());

        if(!cakeLine.empty())
            cakeLine.pop_front();

        if (prob1 <= 50)
        {
            // coffee line
            Line1.push_back(names[rand() % ARRSIZE], drinks[rand() %  ARRSIZE]);
        }
        if (prob2 <= 50)
        {
            // muffin line
            muffin temp;
            temp.name = names[rand() % ARRSIZE];
            temp.type = muffins[rand() % ARRSIZE];
            muffinLine.push_back(temp);
        }
        if (prob3 <= 50)
        {
            // bracelet line
            bracelet tempbracelet;
            tempbracelet.name = names[rand() % ARRSIZE];
            tempbracelet.color = colors[rand() % ARRSIZE];
            braceletLine.push_back(tempbracelet);
        }
        if (prob4 <= 50)
        {

            // cake line
            cake tempcake;
            tempcake.name = names[rand() % ARRSIZE];
            tempcake.type = cakes[rand() % ARRSIZE];
            cakeLine.push_back(tempcake);
        }

        Line1.print();

        muffinLinePrint(muffinLine);

        braceletLinePrint(braceletLine);

        cakeLinePrint(cakeLine);
        cout << endl;
    }
    return 0;
}

void muffinLinePrint(deque<muffin>& muffinLine)
{
    cout << "Current Muffin Booth Line: " << endl;\
    if(muffinLine.empty())
        cout << "    The line is empty!" << endl;
    for(auto it: muffinLine)
    {
        cout << "    Name: " << it.name << "  Muffin: " << it.type << endl;
    }
}


void braceletLinePrint(vector<bracelet>& braceletLine)
{
    cout << "Current Friendship Bracelet Booth Line: " << endl;
    if(braceletLine.empty())
        cout << "    The line is empty!" << endl;
    for(auto it: braceletLine)
    {
        cout << "    Name: " << it.name << "  Color: " << it.color << endl;
    }
}

void cakeLinePrint(list<cake>& cakeLine)
{
    cout << "Current Cake Booth Line: " << endl;
    if(cakeLine.empty())
        cout << "    The line is empty!" << endl;
    for(auto it: cakeLine)
    {
        cout << "    Name: " << it.name << "  Type: " << it.type << endl;
    }
}
