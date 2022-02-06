/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2018 23:16                        
*  solution_verdict: Wrong answer on pretest 10              language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/937/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
unsigned long long int k,d,t,dv,of,lo,hi,cy,on,tper,kt,per,ex,ans;
long double tt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>k>>d>>t;
     t*=2;
     dv=(k-1)/d;
    dv++;
    on=k;
    of=dv*d-k;
     cy=on+of;
     per=on*2+of;
     kt=t/per;
     tt=kt*cy;
     ex=t-kt*per;
    ///cout<<ex<<endl;
     if(ex<=on*2)
    {
        tt+=double(ex/2.00);
        ex=0;
    }
    if(ex<=of)tt+=ex;
    cout<<setprecision(10)<<fixed<<tt<<endl;
    return 0;
}