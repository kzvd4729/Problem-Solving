/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-15 22:22:13                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-DISUBSTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t;
map<string,long>mp;
string s,tmp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>s;
        mp.clear();
        for(long i=0;i<s.size();i++)
        {
            tmp.clear();
            for(long j=i;j<s.size();j++)
            {
                tmp.push_back(s[j]);
                mp[tmp]=1;
            }
        }
        cout<<mp.size()<<endl;
    }
    return 0;
}