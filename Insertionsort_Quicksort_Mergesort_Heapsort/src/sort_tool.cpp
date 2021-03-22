// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2021/02/26 Hsien-Chia Chen]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>
#include<limits>
// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    int length = data.size();
    int i = 0;
    for (int j=1;j<length;j++){
        int key = data[j];
        i = j-1;
        while(i>=0 && data[i]>key){
            data[i+1] = data[i];
            i -= 1;
        }
        data[i+1] = key;
    }
    return;
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data){
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    if (low<high){
        int q = Partition(data, low, high);
        QuickSortSubVector(data, low, q-1);
        QuickSortSubVector(data, q+1, high);
    }
    return;
}

int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    // Hint : Textbook page 171
    int pivot = data[high];
    int i = low-1;
    int temp = 0;
    for (int j=low;j<high;j++){
        if (data[j]<=pivot){
            i+=1;
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    temp = data[i+1];
    data[i+1] = data[high];
    data[high] = temp;
    return i+1;
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    if (low < high){
        int q = (low+high)/2;
        MergeSortSubVector(data, low, q);
        MergeSortSubVector(data, q+1, high);
        Merge(data, low, q, high);
    }
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    int n1 = middle-low+1;
    int n2 = high-middle;
    int* L = new int[n1+1];
    // cout << n1<<"    "<<(sizeof(L)/sizeof(*L)) <<endl;
    int* R = new int[n2+1];
    for (int i=0;i<n1;i++){
        L[i] = data[low+i];
    }
    for (int i=0;i<n2;i++){
        R[i] = data[middle+i+1];
    }
    L[n1] = std::numeric_limits<int>::max();
    R[n2] = std::numeric_limits<int>::max();
    int i = 0;
    int j = 0;
    for (int k=low;k<=high;k++){
        if (L[i]<=R[j]){
            data[k] = L[i];
            i += 1;
        }
        else{
            data[k] = R[j];
            j += 1; 
        }
    }
    return;
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
	int tmp = 0;
    for (int i = data.size() - 1; i >= 1; i--) {
		tmp = data[i];
		data[i] = data[0];
		data[0] = tmp;
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
    int l = 2*root;
    int r = 2*root+1;
    int largest = 0;
    int temp = 0;
    if (l<heapSize && data[l]>data[root]){
        largest = l;
    }
    else{
        largest = root;
    }
    if (r<heapSize && data[r]>data[largest]){
        largest = r;
    }
    if (largest != root){
        temp = data[root];
        data[root] = data[largest];
        data[largest] = temp;
        MaxHeapify(data, largest);
    }
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
    // heapSize = data.size()-1;
    for (int i=data.size()/2;i>=0;i--){
        MaxHeapify(data, i);
    }

}
