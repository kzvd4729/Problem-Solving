/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-06 14:21:48                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-MST1
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int rec(int n,int ans)
{
    if(n==1)return ans;
    else if(n%2==0)rec(n/2,ans+1);
    else if(n%3==0)rec(n/2,ans+1);
    else rec(n-1,ans+1);
}
int main()
{
    int t,n;
    cin>>t;
    int tc=0;
    while(t--)
    {
        cin>>n;
        cout<<"Case "<<++tc<<": "<<rec(n,0)<<endl;
    }
    return 0;
}