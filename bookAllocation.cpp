#include<iostream> //6006451359 mahesh
#include<vector>
using namespace std;


bool isValid(vector<int> &arr, int m, int n, int maxPages){
    int student = 1, pages = 0;
          
    for(int i=0; i<n; i++){
              
        if(arr[i] > maxPages){
            return false;
        }
              
        if(pages + arr[i] <= maxPages){ 
            pages += arr[i];
        } else{
            student++;
            pages = arr[i];
        }
    }
    return student > m ? false : true;
}
int findPages(vector<int> &arr, int m, int n) {
    if(m > n){
        return -1;
    }
    int sum = 0;
    for(int i=0; i<n;i++){
        sum +=arr[i];
    }
          
    int ans = -1;
    int st = 0, end = sum; //range of possible ans
          
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
    vector<int> arr ={2,1,3,4};
    int n = 4, m = 2;

    cout<< findPages(arr,m,n)<<endl;
    return 0;
}
