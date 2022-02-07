/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-07 22:41:23                      
*  solution_verdict: Runtime error                           language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-116
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int r,c,i,j,grid[15][115],dp[15][115];
vector<int>ans;
int fx(int row,int col)
{
    if(col==c+1)return 0;
    if(dp[row][col]!=-1)return dp[row][col];
    int p1,p2,p3;
    if(row-1==0)p1=grid[row][col]+fx(r,col+1);
    else p1=grid[row][col]+fx(row-1,col+1);
    p2=grid[row][col]+fx(row,col+1);
    if(row+1==r+1)p3=grid[row][col]+fx(1,col+1);
    else p3=grid[row][col]+fx(row+1,col+1);
    return dp[row][col]=min(p1,min(p2,p3));
}
int main()
{
    ///ofstream cout("out.txt");
    while(cin>>r>>c)
    {
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                cin>>grid[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        int mn=99999999;
        for(i=1;i<=r;i++)
        {
            mn=min(mn,fx(i,1));
        }
        int mmn=mn;
        int mark;
        for(i=1;i<=r;i++)
        {
            if(dp[i][1]==mn)
            {
                mark=i;
                mn-=grid[i][1];
                ans.push_back(mark);
                break;
            }
        }

        int cnt=1;
        while(true)
        {
            cnt++;
            if(mark==1)
            {
                if(dp[mark][cnt]==mn)
                {
                    ans.push_back(mark);
                    mn-=grid[mark][cnt];
                }
                else if(dp[mark+1][cnt]==mn)
                {
                    mark++;
                    ans.push_back(mark);
                    mn-=grid[mark][cnt];
                }
                else if(dp[r][cnt]==mn)
                {
                    mark=r;
                    ans.push_back(mark);
                    mn-=grid[mark][cnt];
                }
            }
            else if(mark==r)
            {
                if(dp[1][cnt]==mn)
                {
                    mark=1;
                    ans.push_back(mark);
                    mn-=grid[mark][cnt];
                }
                else if(dp[mark-1][cnt]==mn)
                {
                    mark--;
                    ans.push_back(mark);
                    mn-=grid[mark][cnt];
                }
                else if(dp[mark][cnt]==mn)
                {
                    ans.push_back(mark);
                    mn-=grid[mark][cnt];
                }

            }
            else
            {
                if(dp[mark-1][cnt]==mn)
                {
                    mark--;
                    ans.push_back(mark);
                    mn-=grid[mark][cnt];
                }
                else if(dp[mark][cnt]==mn)
                {
                    ans.push_back(mark);
                    mn-=grid[mark][cnt];
                }
                else if(dp[mark+1][cnt]==mn)
                {
                    mark++;
                    ans.push_back(mark);
                    mn-=grid[mark][cnt];
                }

            }
            if(cnt==c)break;
        }

        for(i=0;i<ans.size();i++)
        {
            cout<<ans[i];
            if(i!=ans.size()-1)cout<<" ";
        }
        cout<<endl;
        cout<<mmn<<endl;
        ans.clear();

    }
    return 0;
}