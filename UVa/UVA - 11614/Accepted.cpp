/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-28 21:05:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11614
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,lo,hi,mid,x,x1;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;

            lo=0;
            hi=1e9;
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                x=(mid*(mid+1))/2;
                x1=((mid+1)*(mid+2))/2;
                if(x<=n&&x1>n)
                {
                    cout<<mid<<endl;
                    break;
                }
                else if(x>n)hi=mid-1;
                else lo=mid+1;

            }

        }

    }

    return 0;
}