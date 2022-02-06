/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2017 10:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/492/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,y,a,b,z;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>x>>y;
    while(n--)
    {
        cin>>z;
        long lo=1,hi=1000000000000000000,mid;
        while(hi-lo>2)
        {
            mid=(lo+hi)/2;
            a=mid/x;
            b=mid/y;
            if((a+b)<z)lo=mid+1;
            else hi=mid-1;
            ///cout<<lo<<" "<<hi<<endl;
         }
        long f=0;
        for(long i=max(1LL,lo-4); i<=hi+4; i++)
        {
            a=i/x;
            b=i/y;
            ///cout<<a+b<<endl;
            if(a+b==z)
            {
                if(i%x==0&&i%y==0)cout<<"Both"<<endl;
                else if(i%x==0)cout<<"Vova"<<endl;
                else cout<<"Vanya"<<endl;
                f=1;
                break;
            }
        }
        if(f==0)cout<<"Both"<<endl;
     }
    return 0;
}