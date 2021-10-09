// AMOGH NIGAM 2K20/CO/64 Function Overloading
#include<iostream>
using namespace std;

float area(float b, float h)
{
    return (0.5*b*h);
}
float area(double r)
{
    return (3.14159*r*r);
}
float area(int side)
{
    return (side*side);
}

int main()
{
    cout<<"Area of Triangle is : "<<area(3.5,4.2)<<endl;
    cout<<"Area of  Circle  is : "<<area(3.08)<<endl;
    cout<<"Area of  Square  is : "<<area(3)<<endl;
    return 0;
}

