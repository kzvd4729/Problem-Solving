/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2018 11:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/940/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,vis[30];
string s;
char c='z',ch='a';
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    cin>>s;
    for(auto x:s)c=min(c,x),ch=max(ch,x),vis[x-'a']=1;
     if(k>n)
    {
        cout<<s;
        k-=n;
        while(k--)cout<<c;
        cout<<endl;
        return 0;
    }
    for(long i=k-1;i>=0;i--)
    {
        if(s[i]!=ch)
        {
            for(long j=s[i]-'a'+1; ;j++)
            {
                if(vis[j]==1)
                {
                    s[i]=j+'a';
                    break;
                }
            }
            break;
        }
        s[i]=c;
    }
    for(long i=0;i<k;i++)cout<<s[i];
    cout<<endl;
    return 0;
}