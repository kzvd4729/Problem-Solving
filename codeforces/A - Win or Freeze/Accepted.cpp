/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/26/2018 11:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/150/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
vector<long>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    while(true)
    {
        long lim=sqrt(n),f=0;
        for(long i=2;i<=lim;i++)
        {
            if(n%i==0)
            {
                v.push_back(i);
                n/=i;
                f=1;
                break;
            }
        }
        if(f==0)break;
    }
     if(v.size()==0)
    {
        cout<<1<<endl;
        cout<<0<<endl;
    }
    else if(v.size()==1)
    {
        cout<<2<<endl;
    }
    else
    {
        cout<<1<<endl;
        cout<<v[0]*v[1]<<endl;
    }
    return 0;
}