#include <iostream>
#define MAX 100 // Define maximum size of the array

using namespace std;

class HeapSort {
    private:
        int arr[MAX]; // Array to store the heap
        int size;     // Number of elements in the heap

        // Function to heapify a subtree rooted with node i
        void heapify(int n, int i) {
            int largest = i; // Initialize largest as root
            int left = 2 * i + 1; // left = 2*i + 1
            int right = 2 * i + 2; // right = 2*i + 2

            // If left child is larger than root
            if (left < n && arr[left] > arr[largest])
                largest = left;

            // If right child is larger than largest so far
            if (right < n && arr[right] > arr[largest])
                largest = right;

            // If largest is not root
            if (largest != i) {
                swap(arr[i], arr[largest]); // Swap root with largest

                // Recursively heapify the affected subtree
                heapify(n, largest);
            }
        }

    public:
        HeapSort(int arr[], int size) {
            for (int i = 0; i < size; i++) {
                this->arr[i] = arr[i];
            }
            this->size = size;
        }

        // Function to perform heap sort
        void sort() {
            // Build max heap
            for (int i = size / 2 - 1; i >= 0; i--) {
                heapify(size, i);
            }

            // One by one extract elements from heap
            for (int i = size - 1; i > 0; i--) {
                swap(arr[0], arr[i]); // Move current root to end
                heapify(i, 0); // call max heapify on the reduced heap
            }
        }

        // Function to print the sorted array
        void printArray() {
            cout << "Sorted array: ";
            for (int i = 0; i < size; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
};

int main() {
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout<<"Enter array elements:"<<endl;
    for(int i=0; i<size; i++)
    {
    	cin>>arr[i];
	}

    HeapSort hs(arr, size);
    hs.sort();
    hs.printArray(); // Output the sorted array

    return 0;
}

