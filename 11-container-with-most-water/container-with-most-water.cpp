class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxArea = 0;

        while(l<r){
            int maxWidth = r - l;
            int minH = min(height[l], height[r]);
            maxArea = max(maxArea, maxWidth*minH);

            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }

        return maxArea;
    }
};