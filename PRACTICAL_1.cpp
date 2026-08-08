// In this Practical we coverting the sorting algorithm present in cpp

#include <iostream>
using namespace std;

// This is the function of Selection sort
void SelectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int Min = i;

        for(int j = i + 1; j < n; j++){
            if(arr[Min] > arr[j]){
                Min = j;
            }
        }
        swap(arr[Min], arr[i]);
    }
}


// This is the function of Bubble sort
void BubbleSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        bool swapped = false;

        for(int j = 0; j < n - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if(swapped == false){
            break;
        }
    }
}

// This is the function of Insertion sort
void InsertionSort(int arr[], int n){

    for(int i = 1; i < n; i++){

        int temp = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

// This is the function of Merge sort
void Merge(int arr[], int st, int mid, int end) {
    int i = st;
    int j = mid + 1;
    int k = 0;

    int temp[end - st + 1];

  
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

   
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

   
    while (j <= end) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    
    for (int idx = 0; idx < k; idx++) {
        arr[st + idx] = temp[idx];
    }
}

void MergeSort(int arr[], int st, int end) {
    if (st >= end) {
        return;
    }

    int mid = (st + end) / 2;

    MergeSort(arr, st, mid);
    MergeSort(arr, mid + 1, end);

    Merge(arr, st, mid, end);
}

// This is the function of Quick sort
int Partition(int arr[], int s, int e){

    int pivot = arr[s];

    int count = 0;

    for(int i = s + 1; i <= e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    int pivotIndex = s + count;

    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex){

        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void QuickSort(int arr[], int s, int e){

    if(s >= e){
        return;
    }

    int p = Partition(arr, s, e);

    QuickSort(arr, s, p - 1);
    QuickSort(arr, p + 1, e);
}

// This function is used to print the Array Before Sorting
void PrintingArrayBefore(int arr[], int n){
    cout << "Printing the Array Elements Before Sorting: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " , ";
    }
    cout << endl;
}

// This function is used to print the Array After Sorting
void PrintingArray(int arr[], int n){
    cout << "Printing the  Array Elements After Sorting: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " , ";
    }
    cout << endl;
}

int main(){

    //while(1){

        int n, choice;

        cout << "Enter the size of array: ";
        cin >> n;

        const int MAX_SIZE = 100;
        int arr[MAX_SIZE];

        cout << "Enter the elements of array : ";
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        // Developing a user level selection for Sorting
    while(1){
        cout << "\n\n><====================================================================><\n";
        cout << "1.Selection Sort\n";
        cout << "2.Insertion Sort\n";
        cout << "3.Bubble Sort\n";
        cout << "4.Merge Sort\n";
        cout << "5.Quick Sort\n";
        cout << "6.Exit the Program..\n\n";

        cout << "Enter Your choice (1-6) :- ";
        cin >> choice;

        switch(choice){

            case 1:
                cout << endl;
                PrintingArrayBefore(arr, n);
                cout << endl;
                cout << "We are sorting the Array with the help of Selection Sort.\n";
                SelectionSort(arr, n);
                cout << endl;
                PrintingArray(arr, n);
                cout << endl;
                break;

            case 2:
                cout << endl;
                PrintingArrayBefore(arr, n);
                cout << endl;
                cout << "We are sorting the Array with the help of Insertion Sort.\n";
                InsertionSort(arr, n);
                cout << endl;
                PrintingArray(arr, n);
                cout << endl;
                break;

            case 3:
                cout << endl;
                PrintingArrayBefore(arr, n);
                cout << endl;
                cout << "We are sorting the Array with the help of Bubble Sort.\n";
                BubbleSort(arr, n);
                cout << endl;
                PrintingArray(arr, n);
                cout << endl;
                break;

            case 4:
                cout << endl;
                PrintingArrayBefore(arr, n);
                cout << endl;
                cout << "We are sorting the Array with the help of Merge Sort.\n";
                MergeSort(arr, 0, n - 1);
                cout << endl;
                PrintingArray(arr, n);
                cout << endl;
                break;

            case 5:
                cout << endl;
                PrintingArrayBefore(arr, n);
                cout << endl;
                cout << "We are sorting the Array with the help of Quick Sort.\n";
                QuickSort(arr, 0, n - 1);
                cout << endl;
                PrintingArray(arr, n);
                cout << endl;
                break;

            case 6:
                cout << "You are Exiting the Program.........." << endl;
                cout << "Thanking you..............." << endl;
                return 0;

            default:
                cout << "Enter a Valid choice..\n\n";
        }
    }

    return 0;
}
