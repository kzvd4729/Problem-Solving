/****************************************************************************************
*  @author: kzvd4729#                                        created: Apr/17/2017 20:42                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/754/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int n,f,z,i,l;
    bool t;
    cin>>n;
    f=0;
    z=0;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]==0)z++;
        if(a[i]!=0)f=1;
    }
    if(f==0)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        cout<<n-z<<endl;
        for(i=1; i<=n; i++)
        {
            if(a[i]!=0)
            {
                cout<<i<<" "<<i<<endl;
            }
            else
            {
                l=i;
                while(a[i]==0)
                {
                    if(i==n)
                    {
                        t=true;
                        break;
                    }
                    i++;
                }
                if(!t)cout<<l<<" "<<i<<endl;
            }
        }
    }
     return 0;
}