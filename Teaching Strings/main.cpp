#include <iostream>
#include <string> // header file to be included
using namespace std;

int main()
{
    string str1,str2;
    cout<<"str1 - ";
    cin>>str1;
    cout<<"str1 - "<<str1;
    cin.ignore();
    cout<<"\nstr2 - ";
    getline(cin, str2);
    cout<<"str2 - "<<str2;
    cout<<endl;
    return 0;
}
