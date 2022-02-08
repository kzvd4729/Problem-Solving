/****************************************************************************************
*  @author: kzvd4729                                         created: 06-10-2017 15:59:47                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/OCT17/problems/PERFCONT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,p,cw,hp,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        cw=0;
        hp=0;
        while(n--)
        {
            cin>>x;
            if(x>=p/2)cw++;
            if(x<=p/10)hp++;
        }
        if(cw==1&&hp==2)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}