#include <iostream>
#include <vector>
using namespace std;

// Function to display the heap
void displayHeap(const vector<int>& heap) {
    for (int num : heap) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to maintain the heap property (Min-Heap or Max-Heap)
void heapify(vector<int>& heap, int n, int i, bool isMinHeap) {
    int chosen = i;  // Initialize as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2;  // Right child index

    if (left < n && ((isMinHeap && heap[left] < heap[chosen]) || (!isMinHeap && heap[left] > heap[chosen]))) {
        chosen = left;
    }

    if (right < n && ((isMinHeap && heap[right] < heap[chosen]) || (!isMinHeap && heap[right] > heap[chosen]))) {
        chosen = right;
    }

    if (chosen != i) {
        swap(heap[i], heap[chosen]);
        heapify(heap, n, chosen, isMinHeap);
    }
}

// Function to insert a number into the heap
void insertNumber(vector<int>& heap, int number, bool isMinHeap) {
    heap.push_back(number);
    int i = heap.size() - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if ((isMinHeap && heap[parent] > heap[i]) || (!isMinHeap && heap[parent] < heap[i])) {
            swap(heap[i], heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

int main() {
    vector<int> heap;
    int n, number, option;
    bool isMinHeap = true;

    cout << "** Heap Builder **\n";
    cout << "How many numbers to add? ";
    cin >> n;

    cout << "Enter the numbers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> number;
        heap.push_back(number);
    }

    for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
        heapify(heap, heap.size(), i, isMinHeap);
    }

    do {
        cout << "\nMenu:\n1. Build Min-Heap\n2. Build Max-Heap\n3. Insert Number\n4. Exit\nChoice: ";
        cin >> option;

        switch (option) {
            case 1:
                isMinHeap = true;
                for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
                    heapify(heap, heap.size(), i, isMinHeap);
                }
                cout << "Min-Heap: ";
                displayHeap(heap);
                break;

            case 2:
                isMinHeap = false;
                for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
                    heapify(heap, heap.size(), i, isMinHeap);
                }
                cout << "Max-Heap: ";
                displayHeap(heap);
                break;

            case 3:
                cout << "Enter number to insert: ";
                cin >> number;
                insertNumber(heap, number, isMinHeap);
                cout << "Number inserted.\n";
                break;

            case 4:
                cout << "Exiting program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (true);

    return 0;
}
