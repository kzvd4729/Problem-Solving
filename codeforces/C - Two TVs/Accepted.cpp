/****************************************************************************************
*  @author: kzvd4729#                                        created: Aug/22/2017 20:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 6200 KB                              
*  problem: https://codeforces.com/contest/845/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
priority_queue<pair<long,long> >pq;
pair<long,long>a,b;
long n,u,v,c,d,one,two;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--)
    {
        cin>>u>>v;
        pq.push({-u,-v});
    }
    a={-1,-1};
    b={-1,-1};
    while(!pq.empty())
    {
         c=-pq.top().first;
        d=-pq.top().second;
        pq.pop();
        if(a.first==-1)
        {
            a={c,d};
        }
        else
        {
            if(c>a.second)
            {
                a={c,d};
            }
            else
            {
                if(b.first==-1)
                {
                    b={c,d};
                }
                else
                {
                    if(c>b.second)
                    {
                        b={c,d};
                    }
                    else
                    {
                        cout<<"NO"<<endl;
                        return 0;
                    }
                }
            }
        }
     }
    cout<<"YES"<<endl;
     return 0;
}
 