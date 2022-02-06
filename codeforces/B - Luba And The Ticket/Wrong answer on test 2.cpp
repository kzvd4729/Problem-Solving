/****************************************************************************************
*  @author: kzvd4729#                                        created: Aug/22/2017 20:31                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/845/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 5
using namespace std;
long x,s1,s2,mn1,mx1,mn2,mx2;
string s;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    s1=0,s2=0,mn1=99,mn2=99,mx1=0,mx2=0;
    for(long i=0; i<3; i++)
    {
        x=s[i]-'0';
        s1+=x;
        mn1=min(mn1,x);
        mx1=max(mx1,x);
    }
    ///cout<<mn1<<mx1<<endl;
    for(long i=3; i<6; i++)
    {
        x=s[i]-'0';
        s2+=x;
        mn2=min(mn2,x);
        mx2=max(mx2,x);
    }
    ///cout<<mn2<<mx2<<endl;
    if(s1==s2)
    {
        cout<<0<<endl;
        return 0;
    }
    if(s1-mx1<=s2||s2-mn2+9>=s1||s2-mx2<=s1||s1-mn1+9>=s2)
    {
        cout<<1<<endl;
        return 0;
    }
    if(mn1>s2||mn2>s1)
    {
        cout<<3<<endl;
        return 0;
    }
    cout<<2<<endl;
    /*if(mn1<=s2||mx2+18>=s1)
    {
        cout<<2<<endl;
        return 0;
    }
    cout<<3<<endl;*/
    return 0;
}