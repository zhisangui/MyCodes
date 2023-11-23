#include <iostream>
using namespace std;

#define MAXSIZE 30

typedef struct {
    string name;  
    int room;     
    int cur;      
} Dormitory, DormitoryList[MAXSIZE];

void InitializeDormitories(DormitoryList& available, DormitoryList& occupied) 
{
    for (int i = 0; i < MAXSIZE - 1; ++i) 
    {
        available[i].cur = i + 1;
        available[i].room = 0;
    }
    available[MAXSIZE - 1].cur = 0;

    for (int i = 0; i < MAXSIZE - 1; ++i) 
    {
        occupied[i].cur = i + 1;
        occupied[i + 1].room = 100 + i + 1;
    }
    occupied[MAXSIZE - 1].cur = 0;
}

void InitializeOccupiedDormitories(DormitoryList& available, DormitoryList& occupied, int n) 
{
    for (int i = 1; i <= n; i++) 
    {
        cin >> available[i].name >> available[i].room;
        int room = available[i].room;
        int j = occupied[0].cur;
        int j1 = 0;
        for (int i = 1; i <= 20; i++) 
        {
            if (occupied[j].room == room) 
            {
                occupied[j1].cur = occupied[j].cur;
                break;
            }
            j1 = j;
            j = occupied[j].cur;
        }
    }
}

void AssignDormitory(DormitoryList& available, DormitoryList& occupied, string name, int n) 
{
    int j2 = occupied[0].cur;
    available[n].name = name;
    available[n].room = occupied[j2].room;
    occupied[0].cur = occupied[j2].cur;
    int j = available[0].cur;
    int j1 = 0;
    for (int i = 1; i < n; i++) 
    {
        if (available[n].room < available[j].room) 
        {
            available[j1].cur = n;
            available[n].cur = j;
            break;
        }
        j1 = j;
        j = available[j].cur;
    }
}

void ReturnDormitory(DormitoryList& available, DormitoryList& occupied, int room, int n, int i1) 
{
    int j = available[0].cur;
    int j1 = 0;
    for (int i = 1; i <= n; i++) {
        if (room == available[j].room) 
        {
            available[j1].cur = available[j].cur;
            break;
        }
        j1 = j;
        j = available[j].cur;
    }
    int n1 = 20 + i1;
    occupied[n1].room = room;
}

void DisplayAvailableDormitories(DormitoryList& available, int n) 
{
    int j = available[0].cur;
    for (int i = 1; i <= n; i++) 
    {
        cout << available[j].name << "(" << available[j].room << ")";
        j = available[j].cur;
        if (i != n) { cout << "-"; }
    }
    cout << endl;
}

// 显示已用宿舍链表信息
void DisplayOccupiedDormitories(DormitoryList& occupied, int n) 
{
    int j = occupied[0].cur;
    for (int i = 1; i <= n - 2; i++) 
    {
        cout << occupied[j].room;
        j = occupied[j].cur;
        if (i != n - 2) { cout << "-"; }
    }
    cout << endl;
}

int main() 
{
    int n;
    cin >> n;
    DormitoryList AvailableDormitories, OccupiedDormitories;
    InitializeDormitories(AvailableDormitories, OccupiedDormitories);
    InitializeOccupiedDormitories(AvailableDormitories, OccupiedDormitories, n);
    string operation, studentName;
    int room;
    int t;
    cin >> t;
    int i1 = 0, i2 = 1;
    while (t--) 
    {
        cin >> operation;
        if (operation == "assign") 
        {
            n++;
            cin >> studentName;
            AssignDormitory(AvailableDormitories, OccupiedDormitories, studentName, n);
        }
        if (operation == "return") 
        {
            cin >> room;
            ++i1;
            ReturnDormitory(AvailableDormitories, OccupiedDormitories, room, n, i1);
            n--;
        }
        if (operation == "display_used") 
        {
            DisplayAvailableDormitories(AvailableDormitories, n);
        }
        if (operation == "display_free") 
        {
            int nn = 20 - n + i1;
            DisplayOccupiedDormitories(OccupiedDormitories, nn);
        }
    }
}
