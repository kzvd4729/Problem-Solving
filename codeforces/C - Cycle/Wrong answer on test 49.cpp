/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/30/2019 19:31                        
*  solution_verdict: Wrong answer on test 49                 language: GNU C++14                               
*  run_time: 560 ms                                          memory_used: 37400 KB                             
*  problem: https://codeforces.com/contest/117/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
 using namespace std;
 #define S scanf
#define P printf
#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
     //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
    V<int>v;
string grid[5002];
int n,visited_time[5002];
bool cycle,visited[5002],in_cycle[5002];
 void run_dfs(int x,int t)
{
    if(cycle)return;
    v.PSB(x);
    visited[x]=1;
    in_cycle[x]=true;
    visited_time[x]=t;
    for(int i=0;i<n;i++)
    {
        if(cycle)return;
        if(grid[x][i] == '1')
        {
            if(!in_cycle[i+1]&&!visited[i+1])run_dfs(i+1,t+1);
            else if(visited_time[i+1] <= visited_time[x]-2)
            {
                int j,l,x1,y1,z1;
                l=v.SZ;
                x1=v[0],y1=v[1];
                for(j=2;j<l;j++)
                {
                    z1=v[j];
                    if(grid[z1][x1-1] == '1')
                    {
                        cout << x1 << ' ' << y1 << ' ' << z1;
                        cycle=true;
                        return;
                    }
                    x1=y1,y1=z1;
                }
            }
        }
    }
    if(cycle)return;
    v.PPB;
    in_cycle[x]=0;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,l,x,y,z;
    string s;
    cin >> n;
    for(i=1;i<=n;i++)cin >> grid[i];
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            run_dfs(i,1);
            if(cycle)return 0;
        }
    }
    cout << "-1";
    return 0;
}