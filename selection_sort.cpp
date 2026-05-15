#include<iostream>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int min = i;

        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void display(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;

    cout<<"Enter the number of elements: ";
    cin>>n;

    int arr[n];
    cout<<endl;

    cout<<"Enter elements: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    selection_sort(arr,n);

    cout<<"Sorted Array: ";
    display(arr,n);

    return 0;
}