/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-01 15:23:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 40                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-674
****************************************************************************************/
#include<iostream>
#include<cstring>
using namespace std;
int coin[]={1,5,10,25,50};
int n,i,j;
int t[5][7490];
void dp(void)
{
    memset(t,0,sizeof(t));

    t[0][0]=1;

    for(i=0;i<5;i++)
    {
        for(j=0;j<=7489;j++)
        {
           if(i==0)
           {
               if(j>=coin[i])t[i][j]=t[i][j-coin[i]];
           }
           else
           {
               if(j>=coin[i])t[i][j]=t[i-1][j]+t[i][j-coin[i]];
               else t[i][j]=t[i-1][j];
           }
        }
    }
    /*for(i=0;i<5;i++)
    {
        for(j=0;j<=7489;j++)
        {
            cout<<t[i][j];
        }
        cout<<endl;
    }*/

}
int main()
{
    dp();
    while(cin>>n)
    {
        cout<<t[4][n]<<endl;

    }
    return 0;
}