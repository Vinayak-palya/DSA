#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minCostForDays(int n , vector<int> days , vector<int> cost)
{
    int ans = 0;
    queue<pair<int , int> > month;
    queue<pair<int , int> > week;

    for(int day: days)
    {
        // Step1: remove expired days
        while(!month.empty() && month.front().first + 30 <= day)
        {
            month.pop();
        }
        while(!week.empty() && week.front().first + 7 <= day)
        {
            week.pop();
        }
        // step 2:add cost for current days
        week.push(make_pair(day ,ans + cost[1]));
        week.push(make_pair(day , ans + cost[2]));

        // step3: ans updation
        ans = min(ans + cost[0] , min(month.front().second , week.front().second));

    }
}
int main (){
    return 0;
}