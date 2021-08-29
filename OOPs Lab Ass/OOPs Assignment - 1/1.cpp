// AMOGH NIGAM 2K20/CO/64 Usage of Enum
#include <iostream>
#include <string.h>
using namespace std;

enum Months
{
   January = 1,February = 2,March = 3,April = 4,May = 5,June = 6,July = 7,August = 8,September = 9,
    October = 10,November = 11,December = 12
};
int main()
{
    Months month;
    int n = 0;
    char str[10];
    bool choice;
    cout << "For Month Number \t\t\t\t\t  : 1 \nFor Month Name (January,February,...) : 0\nEnter Your Choice\t\t\t\t\t  : ";
    cin >> choice;
    if (choice)
    {
        cout<<"Enter Month Number : ";
        cin>>n;
    }
    else
    {
        cout<<"Enter Month Name : ";
        cin>>str;
        if (strcmp(str,"January")==0)
        {
            month = January;
        }
        else if (strcmp(str,"February")==0)
        {
            month = February;
        }
        else if (strcmp(str,"March")==0)
        {
            month = March;
        }
        else if (strcmp(str,"April")==0)
        {
            month = April;
        }
        else if (strcmp(str,"May")==0)
        {
            month = May;
        }
        else if (strcmp(str,"June")==0)
        {
            month = June;
        }
        else if (strcmp(str,"July")==0)
        {
            month = July;
        }
        else if (strcmp(str,"August")==0)
        {
            month = August;
        }
        else if (strcmp(str,"September")==0)
        {
            month = September;
        }
        else if (strcmp(str,"October")==0)
        {
            month = October;
        }
        else if (strcmp(str,"November")==0)
        {
            month = November;
        }
        else if (strcmp(str,"December")==0)
        {
            month = December;
        }
        else
        {
            cout << "Error typing month name\n";
            return 0;
        }
            n = month;
    }
    if(n == 1 || n == 12 || n == 11)
    {
        cout<<"Winter Season\n";
    }
    else if(n == 2 || n == 3)
    {
        cout<<"Spring Season\n";
    }
    else if(n >= 4 && n <= 7)
    {
        cout<<"Summer Season\n";
    }
    else if(n >= 8 && n <= 9)
    {
        cout<<"Monsoon Season\n";
    }
    else if(n == 10)
    {
        cout<<"Autumn Season\n";
    }
    else
    {
        cout <<"Error typing month number\n";
        return 0;
    }
    return 0;
}
