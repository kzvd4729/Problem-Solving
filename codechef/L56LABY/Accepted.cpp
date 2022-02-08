/****************************************************************************************
*  @author: kzvd4729                                         created: 27-01-2018 21:37:49                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.37 sec                                        memory_used: 20.5M                                
*  problem: https://www.codechef.com/LTIME56/problems/L56LABY
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,mat[1003][1003],vl,r,c,rr,cc;
int dr[]= {0,0,1,-1};
int dc[]= {1,-1,0,0};
queue<pair<int,pair<int,int> > >q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        while(q.size())q.pop();
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>x;
                if(x>0)
                {
                    mat[i][j]=0;
                    q.push({x+1,{i,j}});
                }
                else mat[i][j]=x;
            }
        }
        while(q.size())
        {
            vl=q.front().first;
            r=q.front().second.first;
            c=q.front().second.second;
            q.pop();
            if(mat[r][c]>=vl)continue;
            mat[r][c]=vl;
            if(vl==1)continue;
            for(int i=0; i<4; i++)
            {
                rr=r+dr[i];
                cc=c+dc[i];
                if(rr<1||rr>n||cc<1||cc>m)continue;
                if(mat[rr][cc]==-1)continue;
                q.push({vl-1,{rr,cc}});
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(mat[i][j]==-1)cout<<'B';
                else if(mat[i][j]==0)cout<<'N';
                else cout<<'Y';
            }
            cout<<endl;
        }
    }
    return 0;
}