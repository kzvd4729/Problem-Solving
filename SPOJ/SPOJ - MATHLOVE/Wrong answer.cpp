/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-07 22:02:54                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-MATHLOVE
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,lo,hi,mid,x,f;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;
            lo=0;
            hi=100000000000;
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
    }
    return 0;
}