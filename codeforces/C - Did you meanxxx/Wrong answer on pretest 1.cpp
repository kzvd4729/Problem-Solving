/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/17/2017 21:10                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/861/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s,s1;
long sp[30003];
bool ck(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s;
    long l=s.size();
    s1.push_back('q');
    for(long i=0;i<s.size();i++)
    {
        s1.push_back(s[i]);
    }
    s=s1;
    long cnt=0;
    for(long i=1;i<=l;i++)
    {
        if(ck(s[i]))cnt=0;
        else cnt++;
        if(cnt==3)
        {
            if(s[i]!=s[i-1]||s[i]!=s[i-2])
            {
                sp[i]=1;
            }
            cnt=0;
        }
    }
    for(long i=1;i<=l;i++)
    {
        cout<<s[i];
        if(sp[i]==1)cout<<" ";
    }
    cout<<endl;
     return 0;
}