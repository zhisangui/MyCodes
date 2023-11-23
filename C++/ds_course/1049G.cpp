#include <iostream>
#include <queue>
#include <string>
using namespace std;

class AnimalShelf
{
    queue<int> dog;
    queue<int> cat;
public:
    AnimalShelf(){}
    void enqueue(int number, string type)
    {
        if(type == "dog")
            dog.push(number);
        else
            cat.push(number);
    }
    void dequeueAny(int* number, string* type)
    {
        if(dog.empty() && cat.empty())
        {
            string type = "none";
            Print(-1, type);
            return;
        }
        if(dog.empty() && !cat.empty())
        {
            number[0] = cat.front();
            type[0] = "cat";
            Print(number[0], type[0]);
            cat.pop();
        }
        else if(!dog.empty() && cat.empty())
        {
            number[0] = dog.front();
            type[0] = "dog";
            Print(number[0], type[0]);
            dog.pop();
        }
        else
        {
            if(dog.front() > cat.front())
            {
                number[0] = cat.front();
                type[0] = "cat";
                Print(number[0], type[0]);
                cat.pop();
            }
            else
            {
                number[0] = dog.front();
                type[0] = "dog";
                Print(number[0], type[0]);
                dog.pop();
            }
        }
    }
    void Print(int number, string type)
    {
        cout << '[' << number << ' ' << type << ']' << ' ';
    }
    int dequeueDog()
    {
        string type = "none";
        int number = -1;
        if(!dog.empty())
        {
            type = "dog";
            number = dog.front();
            dog.pop();
        }
        Print(number, type);
        return 1;
    }
    int dequeueCat()
    {
        string type = "none";
        int number = -1;
        if(!cat.empty())
        {
            type = "cat";
            number = cat.front();
            cat.pop();
        }
        Print(number, type);
        return 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        AnimalShelf animal;
        int len;
        cin >> len;
        while(len--)
        {
            string op, type;
            int num;
            cin >> op;
            if(op == "enqueue")
            {
                cin >> num >> type;
                animal.enqueue(num, type);
            }
            else if(op == "dequeueCat")
                animal.dequeueCat();
            else if(op == "dequeueDog")
                animal.dequeueDog();
            else
            {
                int number;
                string type;
                animal.dequeueAny(&number, &type); // 此处用指针为什么不行？
            }
        }
        cout << endl;
    }
    return 0;
}