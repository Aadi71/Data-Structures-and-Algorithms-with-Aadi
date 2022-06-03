// https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
		int first = 0;
		if(len == 1){
			return ;
		}
		int i = len - 2;
		while( i >= 0 && nums[i] >=nums[i+1] ){
			i--;
		}
		if(i == -1){
			sort(nums.begin(),nums.end());
			return;
		}

		int j = len - 1;
		while( nums[i] >= nums[j]){
			j--;

		}
		int temp = nums[j];
		nums[j] = nums[i];
		nums[i] = temp;

		first = i+ 1;    
		int last = len - 1;
		while( first < last ){  
			int temp = nums[first];
			nums[first] = nums[last];
			nums[last] = temp  ;
			first++;
			last--;
		}
	}
};
