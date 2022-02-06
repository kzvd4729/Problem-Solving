/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2017 22:49                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/449/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,k,x,lo,hi,mid,nn,mm,z,z1,z2,mid1,mid2;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m>>k;
     if(k>n-1+m-1)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(k>((n/2)-1+(m/2)+1))
    {
        cout<<1<<endl;
        return 0;
    }
    lo=0;
    hi=k;
    while(true)
    {
        mid=(lo+hi)/2;
        nn=n/(mid+1);
        mm=m/(k-mid+1);
         z=nn*mm;
         mid1=mid+1;
        if(mid1+1==0)
        {
            nn=n;
        }
        else nn=n/(mid1+1);
        if(k-mid1+1==0)
        {
            mm=m;
        }
        else mm=m/(k-mid1+1);
         z1=nn*mm;
         mid2=mid-1;
        if(mid2+1==0)
        {
            nn=n;
        }
        else nn=n/(mid2+1);
        if(k-mid2+1==0)
        {
            mm=m;
        }
        else mm=m/(k-mid2+1);
         z2=nn*mm;
         if(z>=z1&&z>=z2)break;
        if(z1>z2)lo=mid+1;
        else hi=mid-1;
    }
    cout<<z<<endl;
     return 0;
}