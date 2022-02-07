/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-02 23:09:57                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-111
****************************************************************************************/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
vector<int>a;
int main()
{
    long int n,arr[30],i,j,x,z,ord[30],ans[30][30],p;

    cin>>n;

    for(i=1; i<=n; i++)
    {
        cin>>p;
        arr[p]=i;
    }
    while(cin>>p)
    {
        ord[p]=1;
        for(i=2; i<=n; i++)
        {
            cin>>p;
            ord[p]=i;
        }


        memset(ans,0,sizeof(ans));


        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(arr[i]==ord[j])
                {
                    ans[i][j]=ans[i-1][j-1]+1;
                    //if(i==j)ans[i][j]++;
                    //a.push_back(arr[i]);
                }
                else
                {
                    ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
                }

            }
        }

        /*for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                cout<<ans[i][j];
            }
            cout<<endl;
        }*/

        cout<<ans[n][n]<<endl;
        /*for(i=0;i<a.size();i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;*/

    }



    return 0;
}