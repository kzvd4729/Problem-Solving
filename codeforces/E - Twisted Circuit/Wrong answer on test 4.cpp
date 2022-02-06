/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/31/2017 22:54                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/784/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==0&&b==0&&c==0&&d==0)cout<<0<<endl;
    else if(a==0&&b==0&&c==0&&d==1)cout<<1<<endl;
    else if(a==0&&b==0&&c==1&&d==0)cout<<1<<endl;
    else if(a==0&&b==0&&c==1&&d==1)cout<<0<<endl;
    else if(a==0&&b==1&&c==0&&d==0)cout<<1<<endl;
    else if(a==0&&b==1&&c==0&&d==1)cout<<0<<endl;
    else if(a==0&&b==1&&c==1&&d==0)cout<<0<<endl;
    else if(a==0&&b==1&&c==1&&d==1)cout<<1<<endl;
    else if(a==1&&b==0&&c==0&&d==0)cout<<1<<endl;
    else if(a==1&&b==0&&c==0&&d==1)cout<<0<<endl;
    else if(a==1&&b==0&&c==1&&d==0)cout<<0<<endl;
    else if(a==1&&b==0&&c==1&&d==1)cout<<1<<endl;
    else if(a==1&&b==1&&c==0&&d==0)cout<<0<<endl;
    else if(a==1&&b==1&&c==0&&d==1)cout<<1<<endl;
    else if(a==1&&b==1&&c==1&&d==0)cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}