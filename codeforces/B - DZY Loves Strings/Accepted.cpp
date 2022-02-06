/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/30/2017 16:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/447/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    long long int l,k,a[30],b,sum,i;
    while(cin>>s)
    {
        cin>>k;
        b=0;
        sum=0;
        for(i=1;i<=26;i++)
        {
            cin>>a[i];
            if(a[i]>b)b=a[i];
        }
         l=s.size();
         for(i=0;i<l;i++)
        {
            sum=sum+(a[s[i]-96]*(i+1));
        }
         //cout<<sum<<endl;
         for(i=l+1;i<=k+l;i++)
        {
            sum=sum+(b*i);
        }
         cout<<sum<<endl;
       }
       return 0;
}