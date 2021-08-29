// AMOGH NIGAM 2K20/CO/64 Avg Calc
#include <iostream>
using namespace std;
int main()
{ 
    int a;
    cout<<"Enter the number of numbers whose avg is to be calculated : ";
    cin>>a;
    float sum = 0;
    for(int i=0; i<a ; i++)
    {
        int num=0;
        cout<<"Enter the number : ";
        cin>>num;
        sum+=num;
    }
    cout<<"\nAvg of above nos. are : "<<sum/a<<endl;
    return 0;
}
