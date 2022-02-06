/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2017 13:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2700 KB                              
*  problem: https://codeforces.com/contest/899/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,s1,s2,dif;
vector<long>v1,v2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)
    {
        if(i%2==1)
        {
            v1.push_back(i);
            s1+=i;
        }
        else
        {
            v2.push_back(i);
            s2+=i;
        }
    }
    if(s1==s2)
    {
        cout<<0<<endl;
        cout<<v1.size()<<" ";
        for(auto x:v1)cout<<x<<" ";
        cout<<endl;
        return 0;
    }
    if(abs(s1-s2)==1)
    {
        cout<<1<<endl;
        cout<<v1.size()<<" ";
        for(auto x:v1)cout<<x<<" ";
        cout<<endl;
        return 0;
    }
    if(((n*(n+1))/2)%2==0)cout<<0<<endl;
    else cout<<1<<endl;
    if(s1>s2)
    {
        dif=(s1-s2)/2;
        if(dif%2==1)
        {
            v2.push_back(dif);
            cout<<v2.size()<<" ";
            for(auto x:v2)cout<<x<<" ";
            cout<<endl;
            return 0;
         }
        else
        {
            v2.push_back(dif+1);
            v2.push_back(1);
            cout<<v2.size()-1<<" ";
            for(auto x:v2)
            {
                if(x==2)continue;
                cout<<x<<" ";
            }
            cout<<endl;
            return 0;
        }
     }
    else
    {
        dif=(s2-s1)/2;
        if(dif%2==0)
        {
            v1.push_back(dif);
            cout<<v1.size()<<" ";
            for(auto x:v1)cout<<x<<" ";
            cout<<endl;
            return 0;
         }
        else
        {
            v1.push_back(dif+1);
            cout<<v1.size()-1<<" ";
            for(auto x:v1)
            {
                if(x==1)continue;
                cout<<x<<" ";
            }
            cout<<endl;
            return 0;
        }
    }
    return 0;
}