/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-11 19:40:43                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10189
****************************************************************************************/
#include<iostream>
using namespace std;
char grid[110][110];
int dr[]={0,0,1,1,1,-1,-1,-1};
int dc[]={1,-1,0,1,-1,0,1,-1};
int main()
{

    int r,c,i,j,ii,jj,cnt,k,tc=0;
    while(cin>>r>>c)
    {
        if(r==0&&c==0)break;
        if(tc)cout<<endl;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                cin>>grid[i][j];
            }
        }

        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                cnt=0;
                for(k=0;k<8;k++)
                {
                    ii=i+dr[k];
                    jj=j+dc[k];
                    if(ii>=1&&jj>=1&&ii<=r&&jj<=c&&grid[ii][jj]=='*')
                    {
                        cnt++;
                    }
                }
                if(grid[i][j]=='.')grid[i][j]=cnt+'0';
            }
        }

        cout<<"Field #"<<++tc<<":"<<endl;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                cout<<grid[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}