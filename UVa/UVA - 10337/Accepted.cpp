/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-13 19:46:48                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10337
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int x,z,mat[12][1008];
int dp[12][1008][1008];
int fx(int row,int col,int v)
{
    int call1,call2,call3;
    if(row==9&&col==z)return v;
    if(row>9||row<0||col>=z)return 999999;
    if(dp[row][col][v]!=-1)return dp[row][col][v];
    call1=fx(row-1,col+1,v+60-mat[row][col]);
    call2=fx(row,col+1,v+30-mat[row][col]);
    call3=fx(row+1,col+1,v+20-mat[row][col]);
    return dp[row][col][v]=min(min(call1,call2),call3);
}
int main()
{
    int t,i,j;
    cin>>t;
    while(t--)
    {
        memset(mat,0,sizeof(mat));
        cin>>x;
        z=x/100;
        for(i=0;i<=9;i++)
        {
            for(j=0;j<z;j++)
            {
                cin>>mat[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        cout<<fx(9,0,0)<<endl<<endl;

        /*for(i=0;i<=9;i++)
        {
            for(j=0;j<z;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
    }
    return 0;
}