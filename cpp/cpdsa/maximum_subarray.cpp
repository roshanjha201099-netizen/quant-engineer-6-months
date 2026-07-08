class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sub=-999999;
        int sum=0;
        for(int num:nums){
            sum+=num;
            max_sub=max(sum,max_sub);
            if(sum<=0)
            {
                sum=0;
            }
        }
        return max_sub;
    }
};
//this is kadane algo it say ki jo abhi tak aaya hai vo aagey jaake mera profit kam karega ya badhayega 
//toh basically agar sum >0 to mere aagey wale ko by something badhayega gathayega nai but agar -ve hua toh hamesha 
//gatahyea hi islie ussey get rid hoke naya start karo 
//that is the essence of kadane algo