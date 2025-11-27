#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// A custom implementation of a Max Priority Queue (Max Heap)
class MaxPriorityQueue {
private:
    vector<int> heap;

    // Helper function to maintain the Max Heap property upwards (swim/sift-up)
    void heapifyUp(int index) {
        // While the current node is not the root (index > 0)
        // and its value is greater than its parent's value
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            // Swap with the parent
            swap(heap[index], heap[(index - 1) / 2]);
            // Move up to the parent's position
            index = (index - 1) / 2;
        }
    }

    // Helper function to maintain the Max Heap property downwards (sink/sift-down)
    void heapifyDown(int index) {
        int n = heap.size();
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Find the largest among the node, its left, and its right child
        if (left < n && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < n && heap[right] > heap[largest]) {
            largest = right;
        }

        // If largest is not the current node, swap and continue heapifying down
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Check if the priority queue is empty
    bool isEmpty() const {
        return heap.empty();
    }

    // Insert an element into the priority queue
    void insert(int value) {
        heap.push_back(value); // Add the new element to the end of the array
        heapifyUp(heap.size() - 1); // Restore the heap property by sifting up
        cout << "Inserted " << value << ". Heap size: " << heap.size() << "\n";
    }

    // Get the element with the highest priority (maximum value)
    int peekMax() const {
        if (isEmpty()) {
            throw out_of_range("Priority Queue is empty. Cannot peek.");
        }
        return heap.front(); // In a Max Heap, the max element is always the root (index 0)
    }

    // Remove and return the element with the highest priority
    int extractMax() {
        if (isEmpty()) {
            throw out_of_range("Priority Queue is empty. Cannot extract max.");
        }

        // 1. The max element is at the root
        int max_val = heap.front();

        // 2. Move the last element to the root
        heap[0] = heap.back();
        heap.pop_back(); // Remove the last element

        // 3. Restore the heap property by sifting down the new root
        if (!heap.empty()) {
            heapifyDown(0);
        }

        cout << "Extracted Max: " << max_val << ". Remaining size: " << heap.size() << "\n";
        return max_val;
    }

    // Display the current state of the heap (the internal vector)
    void displayHeap() const {
        cout << "Current Heap Content: ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << "\n";
    }
};

int main() {
    MaxPriorityQueue pq;

    try {
        pq.insert(40);
        pq.insert(10);
        pq.insert(30);
        pq.insert(5);
        pq.insert(20);
        
        pq.displayHeap(); // Should show the heap structure (not necessarily sorted)

        cout << "\nPeeking Max: " << pq.peekMax() << "\n\n"; // Should be 40

        pq.extractMax(); // Extracts 40
        pq.displayHeap();

        pq.insert(100); // Insert a new max element
        pq.displayHeap();

        pq.extractMax(); // Extracts 100
        pq.extractMax(); // Extracts 30
        
        pq.displayHeap();
        
        cout << "\nIs Empty? " << (pq.isEmpty() ? "Yes" : "No") << "\n";
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}