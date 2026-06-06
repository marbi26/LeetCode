#include<iostream>
#include<vector>
#include <limits.h>
using namespace std;


bool isValid(vector<int> &arr, int m, int n, int maxTime){
    int painter = 1, time = 0;
          
    for(int i=0; i<n; i++){
              
        if(arr[i] > maxTime){
            return false;
        }
              
        if(time + arr[i] <= maxTime){ 
            time += arr[i];
        } else{
            painter++;
            time = arr[i];
        }
    }
    return painter <= m;
}
int minTimetoPaint(vector<int> &arr, int m, int n) {
    if(m > n){
        return -1;
    }
    int sum = 0, maxVal = INT_MIN;
    for(int i=0; i<n;i++){
        sum +=arr[i];
        maxVal = max(maxVal, arr[i]);
    
    }      
    int ans = -1;
    int st = maxVal, end = sum; //range of possible ans
          
    while(st <= end){
        int mid = st + (end-st)/2;
        if(isValid(arr, m, n, mid)){
            ans = mid;
            end = mid-1;
        }else{
            st = mid+1;   
        }
    }
    return ans;
}

int main(){
    vector<int> arr ={40,30,10,20};
    int n = 4, m = 2;

    cout<< minTimetoPaint(arr, m, n)<<endl;
    return 0;
}
