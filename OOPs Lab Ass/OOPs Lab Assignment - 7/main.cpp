// AMOGH NIGAM 2K20/CO/64 Classes and Array within Class
#include<iostream>
#define SIZE 10
using namespace std;

class A {
    int a = 5;
    
public:
    int pub  = 1;
    void display()
    {
        cout<<"\nA = "<<a;
        cout<<"\nPub variable in class A = "<<pub;
    }
};
class B : public A
{
public:
    int pub_b = 2;
    void display()
    {
        cout<<"\nPub variable in class B = "<<pub_b;
        cout<<"\nPub variable in class A called from member variable of class B = "<<pub;
    }
};
class C : private A
{
public:
    int pub_c = 3;
    void display()
    {
        cout<<"\nPub variable in class B = "<<pub_c;
        cout<<"\nPub variable in class A called from member variable of class C = "<<pub;
    }
};
class D : protected A
{
public:
    int pub_d = 4;
    void display()
    {
        cout<<"\nPub variable in class B = "<<pub_d;
        cout<<"\nPub variable in class A called from member variable of class D = "<<pub;
    }
};

int main()
{
    A A;
    B B;
    C C;
    D D;
    A.display();
    B.display();
    B.A::display();
    cout<<"\nPub variable in class B called from object of class B = "<<B.pub_b;
    cout<<"\nPub variable in class A called from object of class B = "<<B.pub;
    cout<<endl;

    return 0;
}

