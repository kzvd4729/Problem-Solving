/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-07 22:08:04                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 670                                        memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-MATHLOVE
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,lo,hi,mid,x,f;
    cin>>t;
    while(t--)
    {
        cin>>n;
        lo=0;
        hi=10000000;
        f=0;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            x=(mid*(mid+1))/2;
            if(x==n)
            {
                f=1;
                break;
            }
            else if(x>n)hi=mid-1;
            else lo=mid+1;
        }
        if(f==1)cout<<mid<<endl;
        else cout<<"NAI"<<endl;

    }
    return 0;
}