/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/11/2018 11:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2500 KB                              
*  problem: https://codeforces.com/contest/545/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long cnt;
string s,t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s>>t;
    for(long i=0;i<s.size();i++)if(s[i]!=t[i])cnt++;
    if(cnt%2==1)
    {
        cout<<"impossible"<<endl;
        return 0;
    }
    cnt=cnt/2;
    string ans;
    for(long i=0;i<s.size();i++)
    {
        if(s[i]==t[i])ans.push_back(s[i]);
        else if(cnt)
        {
            ans.push_back(s[i]);
            cnt--;
        }
        else ans.push_back(t[i]);
    }
    cout<<ans<<endl;
    return 0;
}