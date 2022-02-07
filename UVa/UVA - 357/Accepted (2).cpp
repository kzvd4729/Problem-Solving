/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-01 16:23:37                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-357
****************************************************************************************/
#include<iostream>
#include<cstring>
using namespace std;
long long int coin[]={1,5,10,25,50};
long long int n,i,j;
long long int t[5][30003];
void dp(void)
{
    memset(t,0,sizeof(t));

    t[0][0]=1;

    for(i=0;i<5;i++)
    {
        for(j=0;j<=30000;j++)
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
        if(t[4][n]==1)cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
        else cout<<"There are "<<t[4][n]<<" ways to produce "<<n<<" cents change."<<endl;
        //cout<<t[4][n]<<endl;

    }
    return 0;
}