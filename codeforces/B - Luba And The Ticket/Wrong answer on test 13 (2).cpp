/****************************************************************************************
*  @author: kzvd4729#                                        created: Aug/22/2017 19:05                        
*  solution_verdict: Wrong answer on test 13                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/845/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 5
using namespace std;
long a[N],b[N],id,s1,s2,mn1=99,mx1,mn2=99,mx2;
string s;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    id=0;
    for(long i=0; i<3; i++)
    {
        a[++id]=s[i]-'0';
        s1+=a[id];
        mn1=min(mn1,a[id]);
        mx1=max(mx1,a[id]);
    }
    id=0;
    for(long i=3; i<6; i++)
    {
        b[++id]=s[i]-'0';
        s2+=b[id];
        mn2=min(mn2,b[id]);
        mx2=max(mx2,b[id]);
    }
    ///cout<<s1<<" "<<s2<<endl;
    if(s1==s2)
    {
        cout<<0<<endl;
        return 0;
    }
    if(s2>s1)
    {
        swap(s1,s2);
        swap(mn1,mn2);
        swap(mx1,mx2);
    }
    if(s1-mx1<=s2||s2-mn2+9>=s1)
    {
        cout<<1<<endl;
        return 0;
    }
    if(mn1<=s2||mx2+18>=s1)
    {
        cout<<2<<endl;
        return 0;
    }
    cout<<3<<endl;
    return 0;
}