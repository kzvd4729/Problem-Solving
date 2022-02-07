/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-10 23:28:49                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10100
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s1,s2,x[1001],y[1001];
int l1,l2,len1,len2;
int grid[1001][1001];
void check_string(void)
{
    int i,j;
    for(i=1;i<=len1;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;

    for(i=1;i<=len2;i++)
    {
        cout<<y[i]<<" ";
    }
    cout<<endl;

}
int LCS(void)
{
    int i,j;
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(x[i]==y[j])
            {
                grid[i][j]=grid[i-1][j-1]+1;
            }
            else
            {
                grid[i][j]=max(grid[i-1][j],grid[i][j-1]);
            }
        }
    }
    return grid[len1][len2];

}
int main()
{
    int tc=0,i,j,m,n,k,f,st,cnt;
    while(getline(cin,s1))
    {
        getline(cin,s2);
        l1=s1.size();
        l2=s2.size();
        if(l1==0||l2==0)
        {
            cout<<setw(2)<<++tc<<". Blank!"<<endl;
        }
        else
        {
            k=0;
            f=0;
            cnt=0;
            for(i=0;i<=l1;i++)
            {
                if((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z')||(s1[i]>'0'&&s1[i]<'9'))
                {
                    if(f==0)
                    {
                        st=i;
                        f=1;
                    }

                }
                else
                {
                    if(f==1)x[++k]=s1.substr(st,i-st);
                    f=0;
                }
            }
            len1=k;
            k=0;
            f=0;
            cnt=0;
            for(i=0;i<=l2;i++)
            {
                if((s2[i]>='a'&&s2[i]<='z')||(s2[i]>='A'&&s2[i]<='Z')||(s2[i]>'0'&&s2[i]<'9'))
                {
                    if(f==0)
                    {
                        st=i;
                        f=1;
                    }

                }
                else
                {
                    if(f==1)y[++k]=s2.substr(st,i-st);
                    f=0;
                }
            }
            len2=k;
            //check_string();
            memset(grid,0,sizeof(grid));
            int ans=LCS();
            cout<<setw(2)<<++tc<<". Length of longest match: "<<ans<<endl;
        }


    }


    return 0;
}