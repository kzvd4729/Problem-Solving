/****************************************************************************************
*  @author: kzvd4729                                         created: May/11/2017 19:49                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/743/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,i,j,k,x,y,z,a;
    cin>>n;
    int f=0;
    x=0,y=0,z=0;
    for(i=1;i<=100000;i++)
    {
        for(j=1;j<=100;j++)
        {
            x=i;
            y=j;
            if(2*x*y-n*y-n*x==0)break;
            z=(n*x*y)/(2*x*y-n*y-n*x);
            if(((n*(x*y+y*z+z*x))==2*x*y*z)&&z>0)
            {
                f=1;
                break;
            }
        }
        if(f==1)break;
    }
    if(f==0)cout<<-1<<endl;
    cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
}