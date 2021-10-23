#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
//#include <bitset>
//#include <complex>
//#include <deque>
//#include <exception>s
//#include <fstream>
//#include <functional>
//#include <iomanip>
//#include <ios>
//#include <iosfwd>
//#include <istream>
//#include <iterator>
//#include <limits>
//#include <list>
//#include <locale>
//#include <map>
//#include <memory>
//#include <new>
//#include <numeric>
//#include <ostream>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <stdexcept>
//#include <streambuf>
#include <string>
//#include <typeinfo>
//#include <utility>
//#include <valarray>
//#include <vector>
#include <math.h>
using namespace std;

class flight
{
    int fare;
    char source[30], destination[30], flight_no[30];
public:
    flight()
    {
        strcpy(flight_no,"A136-64");
        strcpy(source,"Delhi");
        strcpy(destination,"Mumbai");
        fare = 25000;
    }
    void display()
    {
        cout<<"\nFlight No. : "<<this->flight_no;
        cout<<"\nSource : "<<this->source;
        cout<<"\nDestination : "<<this->destination;
        cout<<"\nFare : "<<this->fare;
    }
    ~flight()
    {
        cout<<"destructor is called";
    }
};

template <class T>
class Array
{
    int size;
    T arr[10];
public:
    void input()
    {
        cout<<"Enter Size of Array : ";
        cin>>size;
        for(int i = 0 ; i < size ; i++ )
        {
            printf("arr[%d] : ", i);
            cin>>arr[i];
        }
    }
    void display()
    {
        for (int i = 0; i < size - 1; i++)
            for (int j = size - 1; i < j; j--)
                if (arr[j] < arr[j - 1])
                    swap(arr[j], arr[j - 1]);
        cout <<"\nSorted array : \n";
            for (int i = 0; i < size; i++)
                cout << arr[i] <<"  ";
            cout <<"\n\n";
    }
};

template <class T>
class num
{
    T a;
 
public:
    num(T x)
    {
        a = x;
    }
 
    friend void square_a(num &x)
    {
        T sq = x.a*x.a;
        cout<<"Square of "<<x.a<<" is "<<sq<<"\n\n";
    }
};

int main()
{
    num<float> A(8.7);
    square_a(A);
    Array<float> A1;
    A1.input();
    A1.display();
    flight F1;
    F1.display();
    string str = "627 dopr";
    string str2(10,' '); // string with 10 spaces
    int x = stoi(str);
//    sort(arr.begin, arr.end) or arr,arr+size sort woth O(nlogn)
    float floatk = 32.342342;
    cout<<"\n"<<setprecision(6)<<setw(10)<<floatk;
    cout<<endl<<x<<endl<<str2;
    return 0;
}
