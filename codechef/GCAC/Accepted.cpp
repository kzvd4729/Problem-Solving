/****************************************************************************************
*  @author: kzvd4729                                         created: 06-08-2017 08:54:11                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.22 sec                                        memory_used: 24.4M                                
*  problem: https://www.codechef.com/AUG17/problems/GCAC
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int t,n,m,m_sal[1004],i,j,mat[1003][1003],vis[1003];
string s[1003];
struct data
{
    long long int id;
    long long int sal;
    long long int vac;
}off[1003];
bool cmp(data A,data B)
{
    return A.sal>B.sal;
}
void input(void)
{
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>m_sal[i];
    for(i=1;i<=m;i++)
    {
        cin>>off[i].sal;
        cin>>off[i].vac;
        off[i].id=i;
    }
    sort(off+1,off+m+1,cmp);
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            mat[i][j]=(int)(s[i-1][j-1]-'0');
        }
    }
    memset(vis,0,sizeof(vis));
}
int main()
{
    cin>>t;
    while(t--)
    {
        input();
        long long int t_sal=0,t_st=0,t_co=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(off[j].sal>=m_sal[i]&&off[j].vac>0&&mat[i][off[j].id]==1)
                {
                    t_sal+=off[j].sal;
                    off[j].vac--;
                    t_st++;
                    vis[j]=1;
                    break;
                }
            }
        }
        for(i=1;i<=m;i++)
        {
            if(vis[i]==0)t_co++;
        }
        cout<<t_st<<" "<<t_sal<<" "<<t_co<<endl;
    }
    return 0;
}