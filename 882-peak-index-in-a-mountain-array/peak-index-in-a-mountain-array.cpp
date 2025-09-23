class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, en = arr.size() - 1;

        while(st<=en){
            int mid = st + (en - st)/2;

            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }else if(arr[mid-1]<arr[mid]){
                st = mid + 1;
            }else{
                en = mid - 1;
            }
        }

        return -1;
    }
};