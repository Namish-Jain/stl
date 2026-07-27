#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class MaxHeap {
private:
    std::vector<int> maxHeap;

    int parent(int i) { return (i - 1) >> 1; }
    int left(int i)   { return (i << 1) + 1; }
    int right(int i)  { return (i << 1) + 2; }

public:
    bool isEmpty() const { return maxHeap.empty(); }
    int getMax() const { return maxHeap[0]; }

    void insertItem(int val) {
        maxHeap.push_back(val);
        upHeap((int)maxHeap.size() - 1);
    }

    void upHeap(int i) {
        while (i > 0 && maxHeap[i] > maxHeap[parent(i)]) {
            std::swap(maxHeap[i], maxHeap[parent(i)]);
            i = parent(i);
        }
    }

    void downHeap(int i) {
        int n = (int)maxHeap.size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int temp = i;

            if (l < n && maxHeap[l] > maxHeap[temp]) temp = l;
            if (r < n && maxHeap[r] > maxHeap[temp]) temp = r;

            if (temp == i) return;
            std::swap(maxHeap[i], maxHeap[temp]);
            i = temp;
        }
    }

    int removeMax() {
        int maxNum = maxHeap[0];
        std::swap(maxHeap[0], maxHeap.back());
        maxHeap.pop_back();
        if (!maxHeap.empty()) downHeap(0);
        return maxNum;
    }
};

int main() {
    MaxHeap priorityQueue;

    if (priorityQueue.isEmpty()) cout << "isEmpty() function works";
    else cout << "isEmpty() function does not work";

    priorityQueue.insertItem(10);
    priorityQueue.insertItem(25);
    priorityQueue.insertItem(30);
    priorityQueue.insertItem(40);
    priorityQueue.insertItem(50);

    cout << "\n" <<  priorityQueue.getMax() << endl;
    cout << "\n" << priorityQueue.removeMax() << endl;
    cout << "\n" << priorityQueue.getMax() << endl;

    if (priorityQueue.isEmpty()) cout << "isEmpty() function does not work";
    else cout << "isEmpty() function works";

    return 0;
}