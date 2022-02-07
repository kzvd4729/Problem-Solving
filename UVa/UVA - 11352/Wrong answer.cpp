/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-02-28 01:06:35                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11352
****************************************************************************************/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dr[]={-2,-1,1,2,2,1,-1,-2};
int dc[]={1,2,2,1,-1,-2,-2,-1};
int dis[101][101];
int vis[101][101];
int r[]={1,1,1,0,0,-1,-1,-1};
int c[]={1,0,-1,1,-1,1,0,-1};
queue<pair<int,int> >que;
int main()
{
    int t,i,j,ii,jj,k,s1,s2,e1,e2,uu,vv,u,v;
    char mat[101][101];
    while(cin>>t)
    {
        while(t--)
        {
            int m,n;
            cin>>m>>n;

            memset(dis,0,sizeof(dis));
            memset(vis,0,sizeof(vis));

            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    cin>>mat[i][j];
                    if(mat[i][j]=='A')
                    {
                        s1=i;
                        s2=j;

                    }
                    if(mat[i][j]=='B')
                    {
                        e1=i;
                        e2=j;
                    }
                }
            }

            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(mat[i][j]=='Z'&&vis[i][j]==0)
                    {
                        for(k=0;k<8;k++)
                        {
                            ii=i+dr[k];
                            jj=j+dc[k];
                            if(ii>=0&&jj>=0&&ii<m&&jj<n&&mat[ii][jj]!='A'&&mat[ii][jj]!='B'&&mat[ii][jj]!='Z')
                            {
                                mat[ii][jj]='Z';
                                vis[ii][jj]=1;
                            }

                        }
                    }
                }
            }


            /*for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    cout<<mat[i][j];

                }
                cout<<endl;
            }*/

            memset(vis,0,sizeof(vis));



            que.push(make_pair(s1,s2));
            vis[s1][s2]=1;

            while(!que.empty())
            {
                uu=que.front().first;
                vv=que.front().second;
                que.pop();

                for(i=0;i<8;i++)
                {
                    u=uu+r[i];
                    v=vv+c[i];
                    if(u>=0&&v>=0&&u<m&&v<n&&mat[ii][jj]!='Z'&&vis[u][v]==0)
                    {
                        que.push(make_pair(u,v));
                        vis[u][v]=1;
                        dis[u][v]=dis[uu][vv]+1;
                    }

                }

            }

            if(dis[e1][e2]==0)cout<<"King Peter, you can't go now!"<<endl;

            else cout<<"Minimal possible length of a trip is "<<dis[e1][e2]<<endl;


        }

    }

    return 0;
}