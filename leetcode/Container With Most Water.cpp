#112 milli secs for large data setclass Solution {public:    int maxArea(vector<int> &height) {        if (height.size() < 2) return 0;        int i = 0, j = height.size() - 1;        int maxarea = 0;        while(i < j) {            int area = 0;            if(height[i] < height[j]) {                area = height[i] * (j-i);                ++i;            } else {                area = height[j] * (j-i);                --j;            }            if(maxarea < area) maxarea = area;        }        return maxarea;    }};