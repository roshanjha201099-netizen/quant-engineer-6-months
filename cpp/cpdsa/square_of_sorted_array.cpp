class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // O(n)+O(nlogn)--->time
        // O(n)--->space
    //   multiset<int> ms;
    //   for(auto num:nums)ms.insert(num*num);
    //   int i=0;
    //   for(auto x:ms){nums[i++]=x;}
    //   return nums;
        // for(int i=0;i<nums.size();i++)
        // {
        //     nums[i]=nums[i]*nums[i];
        // }
        // sort(nums.begin(),nums.end());
        // return nums; O(n)+O(nlogn)--->time
        // O(1)--->space
         
        //  they saying that ki two pointers allowed hai bcoz 
        //  array is sorted hai and aayega toh kisi dono side se hi 
        //  true that ki aayega toh usi side se jiska abs value dusre side se bada hota 
        //  but kya mujhe ye tab karna padta jab -ve no nahi rehta well -ve 
        //  nahi rehta toh q bhi nahi rehta 
        //  baat samjh iska simple meaning yahi baan ke aata hai ki jaha apan sure hai ki
        //  ki do hi direction mein jaa sakta hai 
        int n=nums.size();
        vector<int>ans(n);
        int pos=n-1;
        int right=n-1;
        int left=0;
        while(left<=right)
        {
            if(abs(nums[left])>abs(nums[right]))
            {
                ans[pos--]=nums[left]*nums[left++];
            }else{
                ans[pos--]=nums[right]*nums[right--];
            }
        } 
        return ans;
    
    }
};