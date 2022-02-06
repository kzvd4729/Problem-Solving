/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2017 01:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1714 ms                                         memory_used: 4900 KB                              
*  problem: https://codeforces.com/contest/4/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long h1,h2,n;
map<pair<long,long>,long>mp;
string s,tmp;
long _hash1(string x)
{
    long p=0;
    for(int i=0;i<x.size();i++)
    {
        p=(p*19+x[i]-'a'+1)%10000007;
    }
    return p;
}
long _hash2(string x)
{
    long p=0;
    for(int i=0;i<x.size();i++)
    {
        p=(p*17+x[i]-'a'+1)%1000000007;
    }
    return p;
}
string con(long z)
{
    string a;
    long r;
    while(z)
    {
        r=z%10;
        z=z/10;
        a.push_back((char)(r+'0'));
    }
    reverse(a.begin(),a.end());
    return a;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        h1=_hash1(s);
        h2=_hash2(s);
        if(h1>h2)swap(h1,h2);
        if(mp[make_pair(h1,h2)]==0)
        {
            cout<<"OK"<<endl;
            mp[make_pair(h1,h2)]=1;
        }
        else
        {
            long z;
            cout<<s<<mp[make_pair(h1,h2)]<<endl;
            tmp=s;
            ///tmp.push_back((char)(mp[make_pair(h1,h2)]+'0'));
            z=mp[make_pair(h1,h2)];
            tmp+=con(z);
            ///cout<<tmp<<endl;
            mp[make_pair(h1,h2)]++;
            h1=_hash1(tmp);
            h2=_hash2(tmp);
            if(h1>h2)swap(h1,h2);
            mp[make_pair(h1,h2)]=1;
        }
    }
    return 0;
}