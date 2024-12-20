#include <iostream>
#include <queue>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void Insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        // step 1 inserting the element of the last node replacing the root
        arr[1] = arr[size];
        size--;

        // take root node to its correct postition
        int i = 1;
        while (i < size)
        {
            int left_index = 2 * i;
            int right_index = 2 * i + 1;
            if (left_index < size and arr[left_index] > arr[i])
            {
                swap(arr[i], arr[left_index]);
                i = left_index;
            }
            else if (right_index < size and arr[right_index] > arr[i])
            {
                swap(arr[i], arr[right_index]);
                i = right_index;
            }
            else
            {
                return;
            }
        }
    }
};
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    // we have added equals to sign because in case of 0 based indexing
    if (left <= size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
    return;
}
void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}
int main()
{
    heap h;
    h.Insert(50);
    h.Insert(55);
    h.Insert(53);
    h.Insert(52);
    h.Insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "Printing the array now" << endl;
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout << " element at top" << pq.top() << endl;
    pq.pop()
    cout << " element at top" << pq.top() << endl;
    cout<< pq.size() <<endl;
    if(pq.empty()){
        cout<< " pq is empty"<<endl;

    }
    else{
        cout<<"pq is not empty"<<endl;
    }
    // min heap
    priority_queue<int , vector<int> , greater <int>  > minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);


    return 0;
}