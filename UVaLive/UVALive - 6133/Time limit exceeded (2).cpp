/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-24 18:32:24                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6133
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m=1000003;
map<string,vector<string> >adj;

map<string, ll > nul;
void make_tree(string s,char ch)
{

    string s2=s;
    s2.push_back(ch);
    ll f=0;
    for(int i=0;i<adj[s].size();i++)
    {
        if(adj[s][i]==s2)f=1;
    }
    if(f==0)
    {
        adj[s].push_back(s2);
    }
}
ll fn(string s,char ch)
{
    if(s=="")return 1;
    if(adj[s].size()>1)return 1;
    if(nul[s]==1)return 1;
    return 0;
}
int main()
{
    ll n,i,has,j;
    string str[100005],s;
    while(cin>>n)
    {

            adj.clear();
            nul.clear();


        for(i=0;i<n;i++)
        {
            cin>>str[i];
            s="";
            for(j=0;j<str[i].size();j++)
            {
                make_tree(s,str[i][j]);
                s.push_back(str[i][j]);
            }
            nul[s]=1;
        }

        ll sum=0;
        for(i=0;i<n;i++)
        {
            s="";
            for(j=0;j<str[i].size();j++)
            {
                sum+=fn(s,str[i][j]);
                s.push_back(str[i][j]);
            }
        }
        double rslt=(sum*1.00/n);
        cout<<setprecision(2)<<fixed<<rslt<<endl;
    }
    return 0;
}