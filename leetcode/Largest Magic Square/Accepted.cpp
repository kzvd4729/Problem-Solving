/****************************************************************************************
*  @author: kzvd4729                                         created: 06/12/2021 20:56                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 52 ms                                           memory_used: 11.1 MB                              
*  problem: https://leetcode.com/problems/largest-magic-square
****************************************************************************************/
class Solution 
{
public:
    int largestMagicSquare(vector<vector<int>>& a) 
    {
        int n=a.size(),m=a[0].size();
                vector<vector<int> >r(n);      
        vector<vector<int> >c(n);
                for(int i=0;i<n;i++)
        {
            r[i].push_back(a[i][0]);
            for(int j=1;j<m;j++)
            {
                r[i].push_back(r[i].back()+a[i][j]);
            }
        }
                c[0]=a[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                c[i].push_back(c[i-1][j]+a[i][j]);
            }
        }
                for(int k=min(n,m);k>=1;k--)
        {
            for(int i=0;i<n;i++)
            {
                if(i+k-1>=n)continue;
                for(int j=0;j<m;j++)
                {
                    if(j+k-1>=m)continue;
                                        int sm=0;
                    for(int l=0;l<k;l++)sm+=a[i+l][j+l];
                    //if(k==2 && i==1 && j==1)cout<<sm<<endl;
                                        int ii=i,jj=j+k-1,tmp=0;
                    for(int l=0;l<k;l++)tmp+=a[ii+l][jj-l];
                                        if(tmp!=sm)continue; 
                                        int f=1;
                    for(int l=0;l<k;l++)
                    {
                        int now=r[i+l][j+k-1];
                        if(j)now-=r[i+l][j-1];
                                                if(now!=sm)f=0;
                    }
                    if(f==0)continue;
                                                            f=1;
                    for(int l=0;l<k;l++)
                    {
                        int now=c[i+k-1][j+l];
                        if(i)now-=c[i-1][j+l];
                                                if(now!=sm)f=0;
                    }
                    if(f==0)continue;
                                                            return k;
                                    }
            }
        }
        return -1;
    }
};