//by brute force 
#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& h) {
    int maxArea = 0;
    for (int i = 0; i < h.size() - 1; i++){
        for (int j = i + 1; j < h.size(); j++){
            int weidth = j-i;
            int height = min(h[i], h[j]);
            int area = weidth * height;
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}
int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    return 0;
}
/*int maxArea(vector<int>& height) {
    int maxArea = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
        int width = right - left;
        int minHeight = min(height[left], height[right]);
        int area = width * minHeight;
        maxArea = max(maxArea, area);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}*/