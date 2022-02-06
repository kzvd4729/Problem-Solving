/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2017 23:02                        
*  solution_verdict: Time limit exceeded on pretest 8        language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 14400 KB                             
*  problem: https://codeforces.com/contest/796/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,m,h,k,hole[1000006],p,q,s1[300006],s2[300006],pos,i;
int main()
{
    cin>>n>>m>>k;
    memset(hole,0,sizeof(hole));
    for(i=1; i<=m; i++)
    {
        cin>>h;
        hole[h]=1;
    }
    pos=1;
    int f=0;
    for(i=1; i<=k; i++)
    {
        cin>>p>>q;
        s1[i]=p;
        s2[i]=q;
        if(f==0)
        {
            if(s1[i]==pos)pos=s2[i];
            else if(s2[i]==pos)pos=s1[i];
            if(hole[pos]==1)f=1;
        }
     }
    cout<<pos<<endl;
    return 0;
}