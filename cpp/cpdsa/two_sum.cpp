class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // i have an array and a target to find such that arr[x]+arr[y]=tar
        //we have to return [x,y] where x<y 
        //what i can think is map will store and we will visit every arr[i] and check wheater we have tar-arr[i] in my map or not if we have we will return then and there 
       unordered_map<int,int> mp;

            for(int i = 0; i < nums.size(); i++)
            {
                if(mp.find(target - nums[i]) != mp.end())
                {
                    return {mp[target - nums[i]], i};
                }

                mp[nums[i]] = i;
            }
            return {-1,-1};
    }
};