// AMOGH NIGAM 2K20/CO/64 Classes and Array within Class
#include<iostream>
#define SIZE 10
using namespace std;

class Array_Sum_and_Product
{
    int a[SIZE];
    long SUM, PRODUCT;
    void calc(int a)
    {
        SUM += a;
        PRODUCT *= a;
    }
    
public:
    Array_Sum_and_Product()
    {
        SUM = 0;
        PRODUCT = 1;
    }
    void input()
    {
        for (int i = 0; i < SIZE; i++)
        {
            
            cout<<"Enter Element "<<setw(2)<<i + 1<<" : ";
            cin>>a[i];
            calc(a[i]);
        }
    }
    void sum_prod()
    {
        cout<<"\nSum of Entered Array is : "<<SUM;
        cout<<"\nProduct of Entered Array is : "<<PRODUCT;
        cout<<"\n\n";
    }
};

int main()
{
    Array_Sum_and_Product S;
    cout<<"Enter Array ( SIZE = "<<SIZE<<" ) to find their Sum and Product : \n\n";
    S.input();
    S.sum_prod();
    return 0;
}
