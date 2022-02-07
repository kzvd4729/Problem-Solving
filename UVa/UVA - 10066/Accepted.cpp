/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-07 17:44:19                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10066
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,i,j,k,x,y,z,mm[103],nn[103],t[103][103],tc=0;
    while(cin>>m>>n)
    {
        if(m==0&&n==0)break;

        memset(t,0,sizeof(t));

        for(i=1;i<=m;i++)
        {
            cin>>mm[i];
        }
        for(i=1;i<=n;i++)
        {
            cin>>nn[i];
        }

        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(mm[i]==nn[j])t[i][j]=t[i-1][j-1]+1;
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }

        cout<<"Twin Towers #"<<++tc<<endl;
        cout<<"Number of Tiles : "<<t[m][n]<<endl<<endl;;


    }


    return 0;
}