/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2017 00:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 530 ms                                          memory_used: 14500 KB                             
*  problem: https://codeforces.com/contest/39/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
string s1,s2;
char x;
long fre[10000],cnt,ans;
vector<long>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s1>>s2;
    for(long i=0;i<s1.size();i++)
    {
        fre[s1[i]]++;
    }
    for(long i=0;i<s2.size();i++)
    {
        fre[s2[i]]--;
    }
    for(long i=0;i<=1000;i++)
    {
        if(fre[i]!=0)
        {
            cnt++;
            x=(char)i;
        }
    }
    if(cnt!=1)
    {
        cout<<0<<endl;
        return 0;
    }
    s2.push_back('#');
    for(long i=0;i<s1.size();i++)
    {
        if(s1[i]!=s2[i])
        {
            for(long k=i;k>=0;k--)
            {
                if(s1[k]==x)
                {
                    ans++;
                    v.push_back(k+1);
                }
                else break;
            }
            for(long k=i+1;k<s1.size();k++)
            {
                if(s1[k]==x)
                {
                    ans++;
                    v.push_back(k+1);
                }
                 else break;
            }
            break;
        }
    }
    cout<<ans<<endl;
    sort(v.begin(),v.end());
    for(long i=0;i<ans;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}