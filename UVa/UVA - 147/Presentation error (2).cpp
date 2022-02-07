/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-01 16:06:41                      
*  solution_verdict: Presentation error                      language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-147
****************************************************************************************/
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
long long int coin[]={1,2,4,10,20,40,100,200,400,1000,2000};
long long int n,i,j;
double nn;
long long int t[20][6006];
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

        /*for(j=0;j<=6000;j++)
        {
            cout<<t[10][j]<<" ";
        }
        cout<<endl;*/


}
int main()
{
    dp();
    while(cin>>nn)
    {
        if(nn==0.00)break;
        n=ceil(nn*20.00);
        printf("%.2lf%17lld\n",nn,t[10][n]);//%6lld

    }
    return 0;
}