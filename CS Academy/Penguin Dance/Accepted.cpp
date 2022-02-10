/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 12 ms                                           memory_used: 764 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,p,t;cin>>n>>p>>t;int lt=1,rt=n;
    for(int i=0;i<t;i++)
    {
        if(i%9==5)lt--,rt--;
        else if(i%9>=4)lt++,rt++;
    }
    if(p<lt||p>rt)cout<<-1<<endl;
    else cout<<p-lt+1<<endl;
    return 0;
}