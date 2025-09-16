class Solution {
public:
    int maxArea(vector<int>& height) {
        int width, minH;
        int l = 0, r = height.size()-1;
        int maxArea = 0;

        while(l<r){
            width = r - l;
            minH = min(height[l], height[r]);

            maxArea = max(maxArea, width*minH);

            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }

        return maxArea;
    }
};