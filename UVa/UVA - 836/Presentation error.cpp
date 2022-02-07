/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-02 22:08:10                      
*  solution_verdict: Presentation error                      language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-836
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s[30];
int arr[30][30];
int l;
void input(void)
{
    int i,j;
    getchar();
    cin>>s[0];
    l=s[0].size();
    for(i=1; i<l; i++)
    {
        cin>>s[i];
    }
    for(i=0; i<l; i++)
    {
        for(j=0; j<l; j++)
        {
            arr[i+1][j+1]=s[i][j]-'0';
        }
    }

}
void qm(void)
{
    int i,j;
    for(i=1; i<=l; i++)
    {
        for(j=2; j<=l; j++)
        {
            arr[i][j]=arr[i][j]+arr[i][j-1];
        }
    }
    for(i=2; i<=l; i++)
    {
        for(j=1; j<=l; j++)
        {
            arr[i][j]=arr[i][j]+arr[i-1][j];
        }
    }
}
int main()
{
    int t,i,q,mx,j,x,y,tc;
    while(cin>>t)
    {
        getchar();
        tc=t;
        while(tc--)
        {
            if(tc-1!=t)cout<<endl;
            memset(arr,0,sizeof(arr));
            input();
            qm();
            mx=0;
            for(i=1; i<=l; i++)
            {
                for(j=1; j<=l; j++)
                {
                    for(x=i; x<=l; x++)
                    {
                        for(y=j; y<=l; y++)
                        {
                            q=arr[x][y]-arr[x][j-1]-arr[i-1][y]+arr[i-1][j-1];
                            if((x-i+1)*(y-j+1)==q)
                            {
                                if(q>mx)mx=q;
                            }
                        }
                    }
                }
            }
            cout<<mx<<endl;
        }
    }
    return 0;
}