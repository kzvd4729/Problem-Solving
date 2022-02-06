/****************************************************************************************
*  @author: kzvd4729#                                        created: May/03/2017 18:23                        
*  solution_verdict: Wrong answer on test 29                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/750/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,dis=0,i,x;
    string s;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>s;
        if(dis==0)
        {
            if(s!="South")
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if(dis==20000)
        {
            if(s!="North")
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if(s=="South")dis+=x;
        if(s=="North")dis-=x;
        dis%=40000;
        if(dis>20000)dis=40000-20000;
    }
    if(dis==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}