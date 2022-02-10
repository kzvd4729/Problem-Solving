/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-06 15:16:21                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-MST1
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int fx(int n)
{
    if(n==1)return 0;
    if(mp[n]!=0)return mp[n];
    else if(n%3==0&&n%2==0)
    {
        return mp[n]=1+min(fx(n-1),min(fx(n/3),fx(n/2)));
    }
    else if(n%2==0)
    {
        return mp[n]=1+min(fx(n/2),fx(n-1));
    }
    else if(n%3==0)
    {
        return mp[n]=1+min(fx(n/3),fx(n-1));
    }
    else
    {
        return mp[n]=1+fx(n-1);
    }

}
int main()
{
    int t,n;
    cin>>t;
    int tc=0;
    while(t--)
    {
        cin>>n;
        cout<<"Case "<<++tc<<": "<<fx(n)<<endl;
    }
    return 0;
}