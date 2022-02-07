/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-09 14:59:17                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-108
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,arr[101][101],x,y,ans,mx;
    while(cin>>n)
    {
        memset(arr,0,sizeof(arr));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                arr[i][j]=arr[i][j]+arr[i-1][j];
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                arr[i][j]=arr[i][j]+arr[i][j-1];
            }
        }
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }*/

        mx=0;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                for(x=i;x<=n;x++)
                {
                    for(y=j;y<=n;y++)
                    {
                        ans=arr[x][y]-arr[i-1][j]-arr[i][j-1]+arr[i-1][j-1];
                        if(ans>mx)mx=ans;
                    }
                }
            }
        }

        cout<<mx<<endl;



    }


    return 0;
}
/*
4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
*/