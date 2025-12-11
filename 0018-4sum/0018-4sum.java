class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                Map<Long,Integer> mp = new HashMap<>();
                for(int k = j+1;k<nums.length;k++){
                    long need = (long)target - nums[i] - nums[j] - nums[k];
                    
                    if(mp.containsKey(need)) {
                        List<Integer> temp = Arrays.asList(nums[i], nums[j], nums[k], nums[mp.get(need)]);
                        Collections.sort(temp);
                        if(!ans.contains(temp)) ans.add(temp);
                    }
                    
                    mp.put((long)nums[k], k);
                }
            }
        }
        return ans;
    }
}