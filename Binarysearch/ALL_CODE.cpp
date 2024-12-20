#include<iostream>
#include<vector>
using namespace std;
int binarysearchRec(vector<int> & arr , int target , int lo , int hi)
{
    int mid = lo + (hi -lo)/2;
    // base case
    if(lo > hi)
    {
        return -1;
    }
    
    if(arr[mid] < target)
    {
        int left = binarysearchRec(arr, target , mid + 1 , hi);
        return left;
    }
    else{
        int right = binarysearchRec(arr , target , lo , mid - 1);
        return right;
    }
    
    return mid;
}
int binarySearchIt(vector<int> & arr , int target)
{
    int n = arr.size();
    int lo = 0;
    int hi = n - 1;
    
    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] < target)
        {
            lo = mid + 1;
        }
        else if(arr[mid] > target){
            hi = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int firstOccurence(vector<int> arr , int target)
{
    int n =arr.size();
    int lo = 0;
    int hi = n - 1;
    int idx = -1;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] < target)
        {
            lo = mid + 1;
        }
        else {
            
            hi = mid -1;
            if(arr[mid] == target)
            {
                idx = mid;
            }
        }
        
    }
    return idx;
}
int binarySearchSquareRoot(int target)
{
    int lo = 1;
    int hi = target;
    int ans;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(mid*mid > target)
        {
            hi = mid - 1;
        }
        else{
            ans = mid;
            lo = mid +1;
        }
    }
    return ans;
}
vector<int> firstAndLast(vector<int> &arr , int target)
{
    int lo = 0;
    int hi = arr.size() - 1;
    vector<int> res(2 , -1);
    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] >= target)
        {
            hi = mid - 1;
            res[0] = mid;
        }
        else
        {
            lo = mid + 1;
        }
        
    }
    if(arr[res[0]] != target){
        res[0] = -1;
        res[1] = -1;
        return res;
        
    }
    lo = 0;
    hi = arr.size() - 1;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] > target)
        {
            hi = mid - 1;
            
        }
        else
        {
            lo = mid + 1;
            res[1] = mid;
        }
        
    }
    
    return res;
}
int minSortedRotated(vector<int> &arr)
{
    if(arr.size() == 1)
    {
        return 0;
    }
    int lo = 0;
    int hi = arr.size() - 1;
    if(arr[lo] < arr[hi])
    {
        return 0;
    }
    else
    {
        while(lo <= hi)
        {
            int mid = lo + (hi - lo)/2;
            if(arr[mid] > arr[mid + 1] && (mid < arr.size() - 1))
            {
                return mid + 1;
            }
            else if(arr[mid] < arr[mid - 1])
            {
                return mid;
            }
            else if(arr[mid] > arr[lo])
            {
                lo = mid +1;
            }
            else if(arr[mid] < arr[lo])
            {
                hi = mid -1;
            }
        }
    }
    return -1;
}

// in two ways we can find the element in sorted rotated array 
//  1. by searching in two part of arrays using index of min ele 
// or by following way
int targetInRotatedSortedArray(vector<int> & arr ,int target)
{
    int lo = 0;
    int hi = arr.size() - 1;
    if(arr[lo] > arr[hi])
    {
        while(lo <= hi)
        {
            int mid = lo + (hi - lo)/2;
            if(arr[mid] == target) return mid;
            if(arr[lo] <= arr[mid])
            {
                if(target <= arr[mid] && target >= arr[lo])
                {
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            else
            {
                if(target >= arr[mid] && target <= arr[hi])
                {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
        }
    }
    return -1;
}
int peakInMountain(vector<int> arr)
{
    int ans = -1;
    int lo = 0;
    int hi = arr.size() - 1;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo )/2;
        if(arr[mid] > arr[mid - 1])
        {
            lo = mid + 1;
            ans = mid;
        }
        else
        {
            hi = mid -1;
        }
    }
    return ans;
    
}
int peakInUnsortedArray(vector<int> arr)
{
    int lo = 0;
    int hi = arr.size() -1;
    int mid = lo + (hi - lo)/2;
    int n = arr.size();
    while(lo <= hi)
    {
        if(mid == 0)
        {
            if(arr[mid] > arr[mid +1]) return 0;
            else return 1;
        }
        else if( mid == n -1)
        {
            if(arr[mid] > arr[mid-1])
            {
                return mid;
            }
            else return mid - 1;
        }
        else {
            if(arr[mid] > arr[mid +1] && arr[mid] > arr[mid - 1])
            {
                return mid;
                
            }
            else if(arr[mid] > arr[mid - 1])
            {
                lo = mid +1;
            }
            else hi = mid - 1;
        }
    }
    return -1;
}
pair<int , int> binarySearchIn2Dmatrix(vector<vector<int> > arr , int target)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<int> l;
    
    for(int i = 0 ;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            l.push_back(arr[i][j]);
        }
    }
    int lo = 0;
    int hi = n*m -1;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        if(l[mid] == target)
        {
            int x = mid/m;
            int y = mid% m;
            return {x , y};
        }
        else if(l[mid] < target)
        {
            lo = mid +1;
        }
        else{
            hi = mid - 1;
        }
    }
    return make_pair(-1 , -1);
}
bool canDistChoco(vector<int> arr ,int mid ,  int s)
{
    int stu_req = 1;
    int curr_sum = 0;
    int n = arr.size();
    for(int i =0;i < n;i++)
    {
        if(arr[i] > mid) return false;
        else if(curr_sum + arr[i] > mid)
        {
            stu_req++;
            curr_sum = arr[i];
            if(stu_req > s) return false;
        }
        else{
            curr_sum += arr[i];
        }
    }
    return true;
}
int distChoco(vector<int> arr ,int s)
{
    int lo = 0;
    int hi = 0;
    for(int i =0 ;i < arr.size();i++)
    {
        hi+=arr[i];
    }
    int ans;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        
        if(canDistChoco(arr , mid , s))
        {
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return ans;
}// time complexity --> O(n * log(summation of ai));
bool canRace(vector<int> arr ,int mid , int s)
{
    int n = arr.size();
    int last = arr[0];
    int childNo = 1;
    for(int i = 1;i < n;i++)
    {
        if(arr[i] - arr[0] >= mid){
            last = arr[i];
            childNo++;
            
        }
        
    }
    if(childNo == s) return true;
    
    return false;
    
}

int race(vector<int> arr , int s)
{
    int lo = arr[0];
    int hi = arr[arr.size() - 1] - arr[0];
    int ans;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        if(canRace(arr ,mid , s)){
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi  = mid - 1;
        }
    }
    return ans;
    
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
    int target;
    cin >> target;
    vector<int> ans(2);
    // ans = firstAndLast(arr , target);
    // cout << ans[0] << " " << ans[1] << " ";
    int idx = targetInRotatedSortedArray(arr , target);
    cout << idx << "\n";
    return 0;
}