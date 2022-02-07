/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-02 21:57:31                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-111
****************************************************************************************/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    long int n,arr[30],i,j,x,z,ord[30],ans[30][30];
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        while(1)
        {
            for(i=1;i<=n;i++)
            {
                cin>>ord[i];
            }

            memset(ans,0,sizeof(ans));


            for(i=0;i<=n;i++)
            {
                for(j=0;j<=n;j++)
                {
                    if(i==0||j==0)ans[i][j]==0;
                    else
                    {
                        if(arr[i]==ord[j])ans[i][j]=ans[i-1][j-1]+1;
                        else ans[i][j]=max(ans[i-1][j],ans[i][j-1]);

                    }
                }
            }

            /*for(i=0;i<=n;i++)
            {
                for(j=0;j<=n;j++)
                {
                    cout<<ans[i][j];
                }
                cout<<endl;
            }*/

            cout<<ans[n][n]<<endl;

        }
    }


    return 0;
}