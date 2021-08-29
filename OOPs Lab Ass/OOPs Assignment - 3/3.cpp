// AMOGH NIGAM 2K20/CO/64 Power to n
#include<iostream>
using namespace std;

long double power(double m, int n = 2)
{
    long double pow = 1;
    for(int i = 1; i <= n; i++)
        pow = pow * m;
    return pow;
}
int main()
{
    double m;
    int n;
    cout<<"Enter the value m^n"<<"\nNumber m = ";
    cin>>m;
    cout<<"Power n = ";
    cin>>n;
    cout<<"Answer "<<m<<"^"<<n<<" = "<<power(m,n)<<endl;
    cout<<"When n is omitted "<<m<<"^2 = "<<power(m)<<endl;
    return 0;
}
