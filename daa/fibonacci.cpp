#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){  
    if(n<=1) return 0;
    if(n==2) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}


int main(){
    int a = 0;
    int b = 1;
    vector<int>series = {0,1};

    int sum = a+b;

    while(sum<=100){
        series.push_back(sum);
        a=b;
        b=sum;
        sum=a+b;
    }

    for(auto i: series){
        cout<<i<<" ";
    }
    cout<<endl;


    cout<<fibonacci(7)<<endl;
}