#include<iostream>
using namespace std;

double myPow(double x, int n) {
    long binForm = n;
    if(n<0){
        x = 1/x;
        binForm = -binForm;
    }
    double result = 1;
    while(binForm>0){
        if(binForm % 2 ==1){ // n=1 
            result = result*x;
        }
        x = x*x;
        binForm = binForm/2;
    }
    return result;    
}

int main(){
    cout << myPow(3.0, 5) << endl; // 243
    cout << myPow(2.0, 10) << endl; // 1024.0000
    cout << myPow(2.10000, 3) << endl; // 9.26100
    cout << myPow(2.0, -2) << endl; // 0.25000


}