class Solution {
public:
    int maxArea(vector<int>& height) {
        int width, minH;
        int left = 0, right = height.size()-1;
        int maxArea = 0;

        while(left<right){
            width = right - left;
            minH = min(height[left], height[right]);

            int area = width * minH;
            maxArea = max(area, maxArea);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }

        return maxArea;
    }
};