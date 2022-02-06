/****************************************************************************************
*  @author: kzvd4729                                         created: 06/10/2021 19:24                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/robot-bounded-in-circle
****************************************************************************************/
class Solution {
public:
    bool isRobotBounded(string s) 
    {
        s+=s;
        int x=0,y=0,dx=0,dy=1;
        for(auto c:s)
        {
            if(c=='L')
            {
                if(dx==0)
                {
                    dx=-dy;
                    dy=0;
                }
                else 
                {
                    dy=dx;
                    dx=0;
                }
            }
            else if(c=='R')
            {
                if(dx==0)
                {
                    dx=dy;
                    dy=0;
                }
                else 
                {
                    dy=-dx;
                    dx=0;
                }
            }
            else x+=dx,y+=dy;
        }
        return (x==0) && (y==0);
    }
};