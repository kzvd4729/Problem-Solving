/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2017 21:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/560/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        cin>>n;
    while(n--)
    {
        cin>>x;
        if(x==1)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<1<<endl;
        return 0;
}
 