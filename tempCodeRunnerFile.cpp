#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a ;
    cin >> a  ;
    short int x;
    int sum = 0;
    while (a--)
    {
        cin >> x ;
        sum += x ;
    }
    if (sum >= 100)
    {
        cout <<"YES"<<endl;
    }
    else 
    {
        cout <<"NO"<<endl;
    }
}
