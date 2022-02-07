/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-28 15:22:37                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11614
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int bs(long long int n)
{
    long long int hi,lo,mid,x;
    lo=0;
    hi=10000000000;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        x=(mid*(mid+1))/2;
        if(x==n)break;
        else if(x>n)hi=mid-1;
        else lo=mid+1;

    }
    return mid;

}
int main()
{
    long long int n,lo,hi,mid,x,t;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;
            cout<<bs(n)<<endl;
        }

    }

    return 0;
}