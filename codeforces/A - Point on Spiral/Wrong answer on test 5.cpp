/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2017 19:54                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/279/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    while(cin>>x>>y)
    {
        if(x==0&&y==0)cout<<0<<endl;
        else if(x==1&&y==0)cout<<0<<endl;
        else if(x==1&&y==1)cout<<1<<endl;
        else if(x==0&&y==1)cout<<2<<endl;
        else if(x==-1&&y==1)cout<<2<<endl;
        else if(x==-1&&y==0)cout<<3<<endl;
        else if(x==-1&&y==-1)cout<<3<<endl;
        else if(x==0&&y==-1)cout<<4<<endl;
        else if(x==1&&y==-1)cout<<4<<endl;
        else if(x==2&&y==-1)cout<<4<<endl;
        else cout<<5<<endl;
         }
    return 0;
}