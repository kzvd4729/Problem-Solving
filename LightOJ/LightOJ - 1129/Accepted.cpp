/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-15 15:52:18                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 316                                        memory_used (MB): 21                              
*  problem: https://vjudge.net/problem/LightOJ-1129
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,id,tc;
string s[10004];
struct dat
{
    long link[11];
    long flag;
} trie[200006];
bool insrt(string s)
{
    long now=0,f=0;
    for(long i=0; i<s.size(); i++)
    {
        long z=s[i]-'0';
        if(trie[now].flag==1)
        {
            if(f==0)return true;
        }
        if(trie[now].link[z]==-1)
        {
            f=1;
            trie[now].link[z]=++id;
        }
        now=trie[now].link[z];
    }
    trie[now].flag=1;
    if(f==0)return true;
    return false;
}
int main()
{
    ///ofstream cout("out.txt");
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    cin>>t;
    while(t--)
    {
        id=0;
        memset(trie,-1,sizeof(trie));
        cin>>n;
        for(long i=1; i<=n; i++)
        {
            cin>>s[i];
        }
        long ck=0;
        for(long i=1; i<=n; i++)
        {
            bool xx=insrt(s[i]);
            if(xx)
            {
                ck=1;
                cout<<"Case "<<++tc<<": NO"<<endl;
                break;
            }
        }
        if(ck==0)
        {
            cout<<"Case "<<++tc<<": YES"<<endl;
        }
    }
    return 0;
}