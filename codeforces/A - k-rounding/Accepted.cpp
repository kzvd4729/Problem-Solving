/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/17/2017 19:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/861/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,two,five,zero,ans,nn;
vector<long>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    nn=n;
    while (n%2 == 0)
    {
        v.push_back(2);
        n = n/2;
    }
    for(long i = 3; i <= sqrt(n); i=i+2)
    {
        while (n%i==0)
        {
            v.push_back(i);
            n = n/i;
        }
    }
    if (n > 2)v.push_back(n);
    for(long i=0; i<v.size(); i++)
    {
        if(v[i]==2)two++;
        if(v[i]==5)five++;
    }
    zero=min(two,five);
    five-=zero;
    two-=zero;
    k-=zero;
    if(k<=0)
    {
        cout<<nn<<endl;
    }
    else
    {
        ans=1;
        while(k--)
        {
            if(five)
            {
                ans*=2;
                five--;
            }
            else if(two)
            {
                ans*=5;
                two--;
            }
            else ans*=10;
        }
        cout<<ans*nn<<endl;
    }
    return 0;
}