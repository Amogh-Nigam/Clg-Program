// AMOGH NIGAM 2K20/CO/64 Passing Parameters in Function
#include<iostream>
using namespace std;

float cuboid_vol(float l = 15.0, float b = 10.5, float h = 5.5)
{
    return (l*b*h);
}

int main(){
    cout<<"BY DEFAULT DIAMENTION OF CUBOID ARE L = 15.0 cm, B = 10.5 cm, H = 5.5 cm"<<endl;
    cout<<"Its volume (in cm³) is : "<<cuboid_vol()<<endl;
    cout<<"Volume (in cm³) IF L = 12.5 cm : "<<cuboid_vol(12.5)<<endl;
    cout<<"Volume (in cm³) IF L = 12.5 cm and B = 8.5 cm : "<<cuboid_vol(12.5,8.5)<<endl;
    cout<<"Volume (in cm³) IF L = 12.5 cm and B = 8.5 cm and H = 4.5 cm: "<<cuboid_vol(12.5,8.5,4.5)<<endl;

    return 0;
}
