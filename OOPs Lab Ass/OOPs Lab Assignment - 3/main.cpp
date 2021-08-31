// AMOGH NIGAM 2K20/CO/64 In-Line Function
#include<iostream>
using namespace std;

inline int cube(int a)
{
    return a * a * a;
}
int main()
{
    cout<<"Cube of Nos. from 1 - 10 are :\n";
    for(int i = 1 ; i <= 10 ; i++)
        cout<<"Cube of "<<i<<" is : "<<cube(i)<<endl;
    return 0;
}
