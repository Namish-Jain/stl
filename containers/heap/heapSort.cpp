#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;


void shiftDown(vector<int>& arr, int i, int n) {
    while (true) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        if (largest == i) break;
        std::swap(arr[largest], arr[i]);
        i = largest;
    }
}

// Heapify an array of size n 
void heapify(vector<int>& arr) {

    int n = (int) arr.size();
    for (int i = n/2 - 1; i >= 0; i--) {
        shiftDown(arr, i, n);
    }
}

void heapSort(vector<int>& arr) {
    heapify(arr);
    for (int i = arr.size() - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        shiftDown(arr, 0, i);
    }
}

int main() {
    vector<int> arr = { 9, 4, 3, 8, 10, 2, 5 };
    heapSort(arr);
    for (int x : arr) std::cout << x << " ";
}