/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-01 15:40:17                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-147
****************************************************************************************/
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int coin[]={1,2,4,10,20,40,100,200,400,1000,2000};
int n,i,j;
double nn;
int t[20][6001];
void dp(void)
{
    memset(t,0,sizeof(t));

    t[0][0]=1;

    for(i=0;i<11;i++)
    {
        for(j=0;j<=6000;j++)
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
    while(cin>>nn)
    {
        if(nn==0.00)break;
        n=nn*20;
        cout<<setprecision(2)<<fixed<<nn<<"      ";
        cout<<t[10][n]<<endl;

    }
    return 0;
}