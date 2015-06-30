/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    const double INF = 1e60;
    int maxPoints(vector<Point> &points) {
        map<double,int> mp;
        
        int n = points.size();
        int same,ans = 0;
        for (int i = 0; i < n; ++i) {
            same = 0;
            mp.clear();
            mp[INF] = 0;
            for (int j = 0; j < n; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++same;
                    continue;
                }
                if (points[i].x == points[j].x) {
                    mp[INF]++;
                } else  {
                    double tmp = (double)(points[i].y-points[j].y)/(double)(points[i].x-points[j].x);
                    mp[tmp]++;
                }
            }
            for (auto it = mp.begin(); it != mp.end(); ++it) {
                ans = max(ans,it->second + same);
            }
        }
        return ans;
    }
};
