// AMOGH NIGAM 2K20/CO/64 Classes and Array of Class Objects
#include<iostream>
#include<string.h>
#define SIZE 3
using namespace std;

class clg
{
    string name;
    int age;
    
public:
    void input()
    {
        cin.ignore();
        cout<<"\nEnter Name : ";
        cin.getline(name);
        cout<<"Enter Age : ";
        cin>>age;
    }
    void output()
    {
        cout<<"Name : "<<name;
        cout<<"\nAge : "<<age;
    }
};

int main()
{
    clg studs[SIZE], prof[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        cout<<"Enter details of Student : "<<i+1;
        studs[i].input();
    }
    for (int i = 0; i < SIZE; i++)
    {
        cout<<"Details of Student : "<<i+1;
        studs[i].output();
    }
    for (int i = 0; i < SIZE; i++)
    {
        cout<<"Enter details of Prof. : "<<i+1;
        prof[i].input();
    }
    for (int i = 0; i < SIZE; i++)
    {
        cout<<"Details of Prof. : "<<i+1;
        prof[i].output();
    }
    return 0;
}
