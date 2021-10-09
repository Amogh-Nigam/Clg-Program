// AMOGH NIGAM 2K20/CO/64 OOPs Test CT - 1
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class Passenger;
class fare
{
    int Fare;
    
public:
    void in_fare()
    {
        cout<<"\nEnter Fare : ";
        cin>>Fare;
    }
    friend void display(Passenger &p1, fare &f2);
};

class Passenger
{
    char name[30];
    
public:
    void input()
    {
        cin.ignore();
        cout<<"\nEnter Name : ";
        cin.getline(name, 30);
    }
    friend void display(Passenger &p1, fare &f2);
};
void display(Passenger &p1, fare &f2)
{
    cout << "\nThe name of the passenger is " << p1.name << " and the fare is " << f2.Fare << endl;
}
int main()
{
    Passenger p[3];
    fare f[3];
    for (int i = 0; i < 3; i++)
    {
        cout<<"\nEnter details of Passenger : "<<i+1;
        p[i].input();
        f[i].in_fare();
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<"\nDetails of Passenger : "<<i+1;
        display(p[i],f[i]);
    }
    return 0;
}
