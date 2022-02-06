/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/10/2018 00:05                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 452 ms                                          memory_used: 9600 KB                              
*  problem: https://codeforces.com/contest/371/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,cap[200005],now[200005],ty,id,add,root[200005],rt,finl,q;
vector<long>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(int i=1;i<=n;i++)cin>>cap[i];
    for(int i=1;i<=n;i++)root[i]=i;
    cout<<endl;
    cin>>q;
    while(q--)
    {
        cin>>ty;
        if(ty==1)
        {
            cin>>id>>add;
            rt=id;
            v.clear();
            while(true)
            {
                while(rt!=root[rt])root[rt]=root[root[rt]],rt=root[rt];
                v.push_back(rt);
                if(now[rt]<cap[rt])
                {
                    if(add>(cap[rt]-now[rt]))
                    {
                        add=add-(cap[rt]-now[rt]);
                        now[rt]=cap[rt];
                    }
                    else
                    {
                        now[rt]+=add;
                        add=0;
                        finl=rt;
                    }
                }
                if(rt==n)finl=n,add=0;
                if(add==0)break;
                rt++;
            }
            for(auto x:v)root[x]=finl;
//            for(int i=1;i<=n;i++)cout<<root[i]<<" ";
//            cout<<endl;
        }
        else
        {
            cin>>id;
            cout<<now[id]<<endl;
        }
     }
    return 0;
}