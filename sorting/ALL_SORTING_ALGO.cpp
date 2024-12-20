#include<iostream>
#include<vector>
using namespace std;
void swap(int & x , int & y)
{
    int temp = x;
    x = y;
    y = temp;
    return;
}
void bubbleSort(vector<int> &arr)
{
    // sortign in insreasing order
    int n = arr.size();
    bool flag = false;
    for(int i = 0;i < n;i++)
    {
        flag = false;
        for(int j = 0;j < n - i - 1;j++)
        {
            if(arr[j] > arr[j +1 ])
            {
                flag = true;
                swap(arr[j] , arr[j + 1]);
            }
            
        }
        if(!flag)
        break;
    }
}
void selectionSort(vector<int> & arr)
{
    int n = arr.size();
    for(int i =0 ;i < n - 1;i++)
    {
        int min_idx = i;
        for(int j = i +1 ;j < n;j++)
        {
            if(arr[j] < arr[min_idx])
            min_idx = j;
            
        }
        if(min_idx != i)
        swap(arr[i] , arr[min_idx]);
    }
    return;
}
void InsertionSort(vector<int> & arr)
{
    int n = arr.size();
    for(int i =0;i < n;i++)
    {
        int j = i -1;
        int curr =arr[i];
        while(arr[j] > curr && j>=0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j +1] = curr;
    }
    return ;
    
}
void merge(vector<int> &arr , int lo , int hi , int mid)
{
    
    int ai = mid -lo + 1;
    int bi = hi - mid ;
    vector<int> a(ai);
    vector<int> b(bi);
    
    for(int i = 0;i < ai;i++)
    {
        a[i] = arr[i + lo];
    }
    for(int i = 0;i < bi;i++)
    {
        b[i] = arr[i + mid + 1];
    }
    int i = 0;
    int j = 0;
    int k = lo;
    while(i < ai && j < bi)
    {
        if(a[i] < b[j])
        {
            arr[k++] = a[i++];
        }
        else if(a[i] > b[j])
        {
            arr[k++] = b[j++];
        }
        else{
            arr[k++] = a[i++];
            j++;
        }
    }
    while(i < ai)
    {
        arr[k++] = a[i++];
    }
    while(j < bi)
    {
        arr[k++] = b[j++];
    }
    
    
}
void mergeSort(vector<int> &arr , int lo , int hi)
{
    if(lo >= hi)
    {
        return;
    }
    int mid =(lo + hi)/2;
    mergeSort(arr , lo , mid);
    mergeSort(arr , mid + 1 , hi);
    merge(arr , lo , hi , mid);
    return;
}
int partition(vector<int> &arr , int first , int last)
{
    int i= first - 1;
    int pivot = arr[last];
    for(int j = 0;j < last ;j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[i+1] , arr[last]);
    return i+1;
}
void quickSort(vector<int> & arr , int first , int last)
{
    if(first >= last)
    return;
    int pi = partition(arr ,first , last);
    quickSort(arr , first , pi - 1);
    quickSort(arr , pi +1 ,last);
    return;
}
void countSort(vector<int> &arr)
{
    int n = arr.size();
    // finding the max element
    int max_ele = INT_MIN;
    for(int i = 0;i < n;i++)
    {
        max_ele = max(max_ele , arr[i]);
    }
    // freq array
    vector<int> freq(max_ele+1 , 0);
    for(int i = 0;i < n;i++)
    {
        freq[arr[i]]++;
    }
    // cumumative freq
    for(int i = 1;i < max_ele+1;i++)
    {
        freq[i]+=freq[i-1];
    }
    
    vector<int> ans(n);
    for(int i = n-1;i >= 0;i--)
    {
        ans[--freq[arr[i]]] = arr[i];
    }
    for(int i = 0;i < n;i++)
    {
        arr[i] = ans[i];
    }
    return;
}
void countRadixSort(vector<int> & arr , int pos)
{
    vector<int> freq(10 , 0);
    int n =arr.size();
    for (int i = 0; i < n ;i++)
    {
        freq[(arr[i]/pos)%10]++;
    }
    // cumulative freq calculation
    for(int i = 1;i < 10;i++)
    {
        freq[i]+= freq[i-1];
        // cout << freq[i]<<" ";
    }
    vector<int> ans(arr.size());
    for(int i = arr.size() -1;i >= 0;i--)
    {
        ans[--freq[(arr[i]/pos)%10]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
    
    
}
void radixSort(vector<int> &arr)
{
    int n = arr.size();
    if(n == 0)return;
    int max_ele = INT_MIN;
    for(int i = 0;i<n;i++)
    {
        max_ele = max(max_ele , arr[i]);
    }
    for(int pos = 1;(max_ele/pos) > 0;pos*=10)
    {
        countRadixSort(arr , pos);
    }
    return;
}
void bucketSort(vector<int>& arr , int size)
{
    vector<vector<float> > bucket(size , vector<float> ());
    int max_ele = INT_MIN;
    int min_ele = INT_MIN;
    for(int i = 0;i < size;i++)
    {
        max_ele = max(max_ele , arr[i]);
        min_ele = min(min_ele , arr[i]);
    }
    float range = (max_ele - min_ele)/size;
    for(int i = 0;i < size;i++)
    {
        int index = (arr[i] - min_ele)/range;
        float diff = (arr[i] - min_ele)/range - index;
        if(diff == 0 && arr[i] != min_ele)
        {
            bucket[index].push_back(arr[i]);

        }
        else{
            bucket[index - 1].push_back(arr[i]);
        }
    }
    for(int i = 0;i < size;i++)
    {
        if(!bucket.empty())
        {
            sort(bucket[i].begin() , bucket[i].end());
        }
    }
    int k = 0;
    for(int i = 0;i < size;i++)
    {
        for(int j = 0;j < bucket[i].size();j++)
       arr[k++] = bucket[i][j];
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)
    {
        cin >> arr[i];
    }
    radixSort(arr);
    for(int i = 0;i < n;i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}


