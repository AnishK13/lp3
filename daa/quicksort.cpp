#include<bits/stdc++.h>
using namespace std;

int deterministic_partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

int randomized_partition(vector<int>& arr, int low, int high){
    int pivot = low+rand()%(high-low+1);
    swap(arr[pivot],arr[high]);
    return deterministic_partition(arr,low,high);
}

void deterministic_quicksort(vector<int>& arr, int low, int high){
    if(low<high){
        int pi = deterministic_partition(arr,low,high);
        deterministic_quicksort(arr,low,pi-1);
        deterministic_quicksort(arr,pi+1,high);
    }
}

void randomized_quicksort(vector<int>& arr, int low, int high){
    if(low<high){
        int pi = randomized_partition(arr,low,high);
        randomized_quicksort(arr,low,pi-1);
        randomized_quicksort(arr,pi+1,high);
    }
}

int main(){
    vector<int>arr = {4,8,1,6,2,1};
    randomized_quicksort(arr,0,arr.size()-1);

    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}