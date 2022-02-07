/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-10 23:04:56                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10100
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s1,s2,x[1001],y[1001];
int l1,l2,len1,len2;
int grid[1001][1001];
void check(void)
{
    for(int i=1;i<=len1;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;

    for(int i=1;i<=l2;i++)
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
    int tc=0,i,j,m,n,k;
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
            m=0;
            k=0;
            for(i=m;i<=l1;i++)
            {
                if((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z'))
                {

                }
                else
                {
                    x[++k]=s1.substr(m,i-m);
                    m=i+1;
                }
            }
            len1=k;
            m=0;
            k=0;
            for(i=m;i<=l2;i++)
            {
                if((s2[i]>='a'&&s2[i]<='z')||(s2[i]>='A'&&s2[i]<='Z'))
                {

                }
                else
                {
                    y[++k]=s2.substr(m,i-m);
                    m=i+1;
                }
            }
            len2=k;
            memset(grid,0,sizeof(grid));
            //check();
            int ans=LCS();
            cout<<setw(2)<<++tc<<". Length of longest match: "<<ans<<endl;
        }


    }


    return 0;
}