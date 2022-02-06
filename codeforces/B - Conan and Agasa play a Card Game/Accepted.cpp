/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/20/2018 21:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/914/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[100005],x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        arr[x]++;
    }
    for(int i=100000;i>=1;i--)
    {
        if(arr[i]%2==1)
        {
            cout<<"Conan"<<endl;
            return 0;
        }
    }
    cout<<"Agasa"<<endl;
     return 0;
}