/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-02 18:25:08                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 220                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12467
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,kmp[4000000],now;
string s,fs,rs;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>rs;
        fs=rs;
        reverse(rs.begin(),rs.end());
        s=fs+"#"+rs;
        for(int i=0;i<s.size();i++)kmp[i]=0;
        for(int i=1;i<s.size();i++)
        {
            now=kmp[i-1];
            while(true)
            {
                if(s[now]==s[i])
                {
                    kmp[i]=now+1;
                    break;
                }
                if(now==0)break;
                now=kmp[now-1];
            }
        }
        int mx=0;
        string ans;
        for(int i=fs.size()+1;i<s.size();i++)mx=max(mx,kmp[i]);
        for(int i=0;i<mx;i++)ans.push_back(fs[i]);
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}