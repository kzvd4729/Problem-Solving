/****************************************************************************************
*  @author: kzvd4729                                         created: May/11/2017 20:15                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/743/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,i,j,k,x,y,z,lo,hi,mid;
    cin>>n;
    int f=0;
    x=0,y=0,z=0;
    if(n==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(i=1;i<=10000;i++)
    {
        lo=1;
        hi=1000000000;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            x=i;
            y=mid;
            if(2*x*y-n*y-n*x==0)break;
            z=(n*x*y)/(2*x*y-n*y-n*x);
            if(((n*(x*y+y*z+z*x))==2*x*y*z)&&z>0&&x!=y&&y!=z&&x!=z&&z<=1000000000)
            {
                f=1;
                break;
            }
            if((double)(2/n)>=(double)((double)(x*y+y*z+z*x)/(double)x*y*z))lo=mid+1;
            else hi=mid-1;
        }
        if(f==1)break;
    }
    if(f==0)cout<<-1<<endl;
    else cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
}