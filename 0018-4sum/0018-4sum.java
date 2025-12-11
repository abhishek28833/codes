class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                int left = j+1;
                int right = n-1;
                
                while(left < right){
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        List<Integer> temp = new ArrayList<>(Arrays.asList(nums[i],nums[j],nums[left],nums[right]));
                        if(!ans.contains(temp))
                            ans.add(temp);
                        left+=1;
                        right-=1;    
                    }else if(sum > target){
                        right--;
                    }else{
                        left++;
                    }
                }
            }
        }
        return ans;
    }
}