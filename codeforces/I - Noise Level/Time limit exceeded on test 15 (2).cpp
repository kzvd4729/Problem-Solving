/****************************************************************************************
*  @author: JU_AAA: aniks2645, kzvd4729, prdx9_abir          created: Sep/18/2017 23:01                        
*  solution_verdict: Time limit exceeded on test 15          language: GNU C++14                               
*  run_time: 5000 ms                                         memory_used: 2700 KB                              
*  problem: https://codeforces.com/contest/847/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int x[]= {-1,0,1,0};
int y[]= {0,1,0,-1};
int n,m,p,q,i,j,k,px,py,rslt,rsltval[255][255],vis[255][255],val[255][255];
char ara[255][255];
queue<pair<int,int> >qu;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        cin>>n>>m>>q>>p;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>ara[i][j];
         }
    }
     memset(rsltval,0,sizeof(rsltval));
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
             if(ara[i][j]>='A'&&ara[i][j]<='Z')
            {
                 memset(vis,0,sizeof(vis));
                memset(val,0,sizeof(val));
                qu.push(make_pair(i,j));
                vis[i][j]=1;
                val[i][j]=(ara[i][j]-'A'+1)*q;
                rsltval[i][j]+=val[i][j];
                while(!qu.empty())
                {
                    pair<int,int>u=qu.front();
                    qu.pop();
                    for(k=0; k<4; k++)
                    {
                        px=u.first+x[k];
                        py=u.second+y[k];
                        if(px>=0&&px<n&&py>=0&&py<m&&ara[px][py]!='*')
                            if(vis[px][py]==0)
                            {
                                qu.push(make_pair(px,py));
                                vis[px][py]=1;
                                val[px][py]=val[u.first][u.second]/2;
                                 rsltval[px][py]+=val[px][py];
                            }
                    }
                }
            }
        }
     }
    rslt=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
             if(rsltval[i][j]>p)rslt++;
        }
     }
    cout<<rslt<<endl;
     return 0;
}