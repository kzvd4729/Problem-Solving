/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-01 01:46:34                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-674
****************************************************************************************/
#include<iostream>
#include<cstring>
using namespace std;
int n,way[5][7490];
int coin[]= {1,5,10,25,50};
int i,j;
void dp(void)
{
    memset(way,0,sizeof(way));
    for(i=0; i<5; i++)
    {
        for(j=0; j<7490; j++)
        {
            if(j==0||i==0)way[i][j]=1;
            else
            {
                if(j>=coin[i])way[i][j]=way[i-1][j]+way[i][j-coin[i]];
                else way[i][j]=way[i-1][j];
            }
        }

    }

}
int main()
{
    dp();
    while(cin>>n)
    {

        cout<<way[4][n-1]<<endl;

    }

    return 0;
}