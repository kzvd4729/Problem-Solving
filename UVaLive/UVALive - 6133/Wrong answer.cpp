/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-24 19:12:04                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6133
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m=1000003,m2=999983;
vector<ll>adj[1000003+2],adj2[999983+2];
ll nul[1000003+2],nul2[999983+2];
void make_tree(ll has,ll has2,char ch)
{
    ll temp=has*31+ch;
    temp%=m;
    ll temp2=has2*37+ch;
    temp2%=m2;
    ll f=0;
    ll sz=min(adj[has].size(),adj2[has2].size());
    for(int i=0;i<sz;i++)
    {
        if(adj[has][i]==temp&&adj2[has2][i]==temp2)f=1;
    }
    if(f==0)
    {
        adj[has].push_back(temp);
        adj2[has2].push_back(temp2);
    }
}

ll fn(ll has,ll has2,char ch)
{
    if(has==0&&has2==0)return 1;
    if(adj[has].size()>1&&adj2[has2].size()>1)return 1;
    if(nul[has]==1&&nul2[has2]==1)return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i,has,j,has2;
    string str[100005];
    while(cin>>n)
    {
        for(i=0;i<1000003;i++)
        {
            adj[i].clear();
            nul[i]=0;
        }
        for(i=0;i<999983;i++)
        {
            adj2[i].clear();
            nul2[i]=0;
        }


        for(i=0;i<n;i++)
        {
            cin>>str[i];
            has=has2=0;
            for(j=0;j<str[i].size();j++)
            {
                make_tree(has,has2,str[i][j]);

                has*=31;
                has+=str[i][j];
                has%=m;
                has2*=37;
                has2+=str[i][j];
                has2%=m2;
            }
            nul[has]=1;
            nul2[has2]=1;
        }

        ll sum=0;
        for(i=0;i<n;i++)
        {
            has=has2=0;
            for(j=0;j<str[i].size();j++)
            {
                sum+=fn(has,has2,str[i][j]);
                has*=31;
                has+=str[i][j];
                has%=m;
                has2*=37;
                has2+=str[i][j];
                has2%=m2;
            }
        }
        double rslt=(sum*1.00/n);
        cout<<setprecision(2)<<fixed<<rslt<<endl;
    }
    return 0;
}