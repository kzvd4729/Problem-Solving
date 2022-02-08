/****************************************************************************************
*  @author: kzvd4729                                         created: 22-10-2017 22:14:43                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.16 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/COOK87/problems/CK87QUER
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,y;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>y;
        long yy=sqrt(y),ans=0;
        yy-=100;
        if(yy<=0)yy=1;
        else ans=700LL*(yy-1);
        for(long i=yy;  ;i++)
        {
            long xx=i*i;
            if(xx>=y)break;
            ans+=min(700LL,y-xx);
        }
        cout<<ans<<endl;
    }
    return 0;
}