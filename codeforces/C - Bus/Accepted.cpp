/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/25/2017 17:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/864/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,f,k,ans,po,tn;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>a>>b>>f>>k;
     if(k==1)
    {
        if(f>b||(a-f)>b)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(a>b)cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    if(k==2)
    {
        if(f>b||((a-f)*2)>b)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(a+a<=b)cout<<0<<endl;
        else if(a+a-f<=b)cout<<1<<endl;
        else cout<<2<<endl;
        return 0;
     }
    if(2*f>b||2*(a-f)>b)
    {
        cout<<-1<<endl;
        return 0;
    }
    po=0;
    tn=b;
    for(long i=1;i<k;i++)
    {
        if(po==0)
        {
            po=1;
            if(a+a-f<=tn)tn=tn-a;
            else
            {
                ans++;
                tn=b-(a-f);
            }
        }
        else
        {
            po=0;
            if(a+f<=tn)tn=tn-a;
            else
            {
                ans++;
                tn=b-f;
            }
        }
    }
    if(tn<a)ans++;
    cout<<ans<<endl;
    return 0;
}