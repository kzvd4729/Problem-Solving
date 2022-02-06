/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/30/2017 21:47                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/834/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,a,b,z,x,lo,hi,mid;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        z=a*b;
        int f=0;
        lo=1;
        hi=1000000;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            if(mid*mid*mid==z)
            {
                f=1;
                cout<<"YES"<<endl;
                break;
            }
            else if(mid*mid*mid<z)lo=mid+1;
            else hi=mid-1;
        }
        if(f==0)cout<<"NO"<<endl;
    }
    return 0;
}