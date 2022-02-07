/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-09 19:12:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 70                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-567
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 999999999
using namespace std;
long u,v,mat[22][22],x,q,tc;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>x)
    {
        for(long i=1;i<=20;i++)
        {
            for(long j=1;j<=20;j++)
            {
                mat[i][j]=inf;
                if(i==j)mat[i][j]=0;
            }
        }
        for(long i=1;i<=19;i++)
        {
            if(i!=1)cin>>x;
            while(x--)
            {
                cin>>v;
                mat[i][v]=1;
                mat[v][i]=1;
            }

        }
        for(long k=1;k<=20;k++)
        {
            for(long i=1;i<=20;i++)
            {
                for(long j=1;j<=20;j++)
                {
                    if(mat[i][k]+mat[k][j]<mat[i][j])mat[i][j]=mat[i][k]+mat[k][j];
                }
            }
        }
        cin>>q;
        cout<<"Test Set #"<<++tc<<endl;
        while(q--)
        {
            cin>>u>>v;
            cout<<setw(2)<<u<<" to "<<setw(2)<<v<<": "<<mat[u][v]<<endl;
        }
        cout<<endl;

    }
    return 0;
}