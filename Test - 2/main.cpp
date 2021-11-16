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
#include <cmath>
#include <cassert>
#include <array>
#include <math>

#define ll long long
#define MOD 1000000007
#define pb push_back
#define ss second
#define ff first
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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll findlcm(vector<int> arr, int n)
{
    ll ans = arr[0];
 
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));
 
    return ans;
}

int main()
{
    fastio();
    vector<int> a, b;
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {   int num;
        cin>>num;
        a.push_back(num);
    }
    for (int i = 0; i < m; i++)
    {
        int num;
        cin>>num;
        b.push_back(num);
    }
    ll L = findlcm(a, n);
    ll count = 0, k = L, flag = 0;
    while ( k <= 100)
    {
        for (int i = 0; i < m; i++)
        {
            if ( b[i] % k != 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            count++;
        }
        k += L;
        flag = 0;
    }
    cout<<count<<endl;
    return 0;
}

