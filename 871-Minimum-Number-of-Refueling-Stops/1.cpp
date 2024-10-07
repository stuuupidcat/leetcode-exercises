#include <iostream>
#include <queue>
#include <vector>

class Solution {
   public:
    static int minRefuelStops(int target, int startFuel,
                       std::vector<std::vector<int>> &stations) {
        int ans = 0, cur = 0, prev = 0;
        int remain_fuel = startFuel;
        std::priority_queue<int> q = {};
        stations.push_back({target, 0});
        int station_num = stations.size();
        for (int i = 0; i < station_num; ++i) {
            cur = stations[i][0];
            int dist = cur - prev;
            remain_fuel -= dist;
            if (remain_fuel < 0) {
                while (remain_fuel < 0 && !q.empty()) {
                    int x = q.top();
                    q.pop();
                    remain_fuel += x;
                    ans += 1;
                }
                if (remain_fuel < 0) {
                    return -1;
                }
            }
            prev = cur;
            if (i == station_num - 1) {
                return ans;
            }
            q.push(stations[i][1]);
        }
        return ans;
    }
};

int main() {
    int target, fuel, n;
    std::vector<std::vector<int>> stations;
    std::cin >> target >> fuel >> n;
    for (int i = 0; i < n; ++i) {
        int x,y;
        std::cin >> x >> y;
        stations.push_back({x, y});
    }
    int res = Solution::minRefuelStops(target, fuel, stations);
    std::cout << res;
}