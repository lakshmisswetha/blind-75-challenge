class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxVol = 0;

        for (int i = left;i<height.size();i++){
            int vol = min(height[left],height[right])*(right-left);
            maxVol = max(vol,maxVol);
            if (height[left]<height[right])left++;
            else right--;
        }

        return maxVol;
        
    }
};