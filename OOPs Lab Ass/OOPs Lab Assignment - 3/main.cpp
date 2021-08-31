// AMOGH NIGAM 2K20/CO/64 In-Line Function
#include<iostream>
using namespace std;

inline int square(int a)
{
    return a * a;
}
int main()
{
    cout<<"Square of Nos. from 1 - 10 are :\n";
    for(int i = 1 ; i <= 10 ; i++)
        cout<<"Square of "<<i<<" is : "<<square(i)<<endl;
    return 0;
}
