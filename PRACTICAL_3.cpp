#include <iostream>
using namespace std;
#define MAX_SIZE 100

void Heapify(int arr[], int n, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;

    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }

    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}


void maxHeapSort(int arr[], int n){
    
    for(int i = n/2 - 1; i >= 0; i--){
        Heapify(arr, n, i);
    }
    

   
    for(int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n ){
    for (int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n ; 
    cout << "Enter the size of array : ";
    cin >> n ;

    int arr[MAX_SIZE];

    // Taking input from user
    cout << "Enter the array elements : "; 
    for (int i = 0 ; i< n ; i++){
        cin >> arr[i];
    }
    cout << endl ;


    // printing array elements before sorting 
    cout << "Array Elements before sorting : ";
    printArray(arr,n);
    maxHeapSort(arr,n);
    cout << "\n Array Elements after sorting : ";
    printArray(arr,n);


    return 0;

    
}