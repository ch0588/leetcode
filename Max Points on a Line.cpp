/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 /*
 N^2logN
 trick same points and rate==0,otherwise calc the rate with map
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.empty()) return 0;
        int ans = 0;
        for(int i=0; i<points.size(); ++i){
            int zero = 0, same = 0;
            map<double,int>H;
            for(int j=0; j<points.size(); ++j){
                if(points[i].x==points[j].x){
                    if(points[i].y==points[j].y) same++; //at same points
                    else zero++; //not same,but Rate=0
                }
                else{
                    double t = (double)(points[i].y-points[j].y)/(double)(points[i].x-points[j].x);
                    if(H.find(t)==H.end()) H[t]=1;
                    else H[t] = H[t] + 1;
                }
            }
            int cnt = zero;
            for(map<double,int>::iterator it=H.begin(); it!=H.end(); it++){
                cnt = max(cnt,it->second);
            }
            ans = max(ans,cnt+same);
        }
        return ans;
    }
};
