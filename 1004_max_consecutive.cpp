#include<iostream> 
#include<vector>
using namespace std;

int longestOnes(vector <int> &nums, int k){
    int i = 0;
    int zeroCount = 0;
    int ans = 0;

    for(int j = 0; j < nums.size(); j++){

        if(nums[j] == 0){
            zeroCount++;
        }
        while(zeroCount > k){
            if(nums[i] == 0){
                zeroCount--;
            }
            i++;
        }
        ans = max(ans, j-i+1);
    }
    return ans;
}

int main() {
    vector<int> nums = {1,1,1,0,0,1,1,1,1,0};
    int k = 2;
    cout << longestOnes(nums, k);

    return 0;
}