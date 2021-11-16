#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <stdlib.h>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <random>
#include <numeric>
#include <iomanip>
#include <chrono>
#include <cassert>
#include <array>
#include <math.h>
#include <ctype.h>

#define ll long long
#define MOD 1000000007
#define pb push_back
#define ss second
#define ff first
#define endl "\n"
#define vi vector<int>
#define gi greater<int>
#define all(a) a.begin(), a.end()
#define MAXN 100001
#define BLOCK 555
#define pii pair<int, int>
#define pmq priority_queue<int, vi, gi>

using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main()
{
    fastio();
//  When an exception is thrown, all objects created inside the enclosing try block are destructed before the control is transferred to catch block.
    try
    {
        float a,b;
        cout<<"Enter two numbers : "<<endl;
        cin>>a;
        if (cin.fail())
        {
            throw 'n';
        }
        cin>>b;
        if (cin.fail())
        {
            throw 'd';
        }
        if (b == 0)
        {
            throw b;
        }
        float div = a/b;
        cout<<"a/b = "<<div<<endl;
    }
    catch (int x)
    {
        cout<<"Divide by Zero"<<endl<<"Denominator is : "<<x<<endl;
    }
    catch (char c)
    {
        if (c == 'n')
            cout<<"Entered Numerator is not a digit"<<endl;
        else
            cout<<"Entered Denominator is not a digit"<<endl;
    }
    try
    {
        vector<int> arr;
        cout<<"Enter Size of Array";
        int n;
        cin>>n;
        if (cin.fail())
        {
            throw 'n';
        }
        for (int i = 0; i < n; i ++)
        {
            int a;
            cin>>a;
            if (cin.fail())
            {
                throw 'a';
            }
            arr.push_back(a);
        }
        for (int i = 0; i <= arr.size(); i++)
        {
            if (i >= arr.size())
            {
                throw 1;
            }
            cout<<arr[i]<<" ";
        }
        
    }
    catch (int x)
    {
        cout<<"Index out of bound"<<endl;
    }
    catch (char c)
    {
        cout<<"Input Entered is not a digit"<<endl;
    }
    return 0;
}

