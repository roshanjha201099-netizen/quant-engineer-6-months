//m1->knowning the best option from the future using array and resevrse one pass 
// class Solution {
// public:
//     int maxProfit(vector<int>& arr) {
//         int len=arr.size();
//         if(len==1)return 0;
//         vector<int>suff_max(len);
//         suff_max[len-1]=arr[len-1];
//         for(int i=len-2;i>=0;i--)
//         {
//             suff_max[i]=max(arr[i],suff_max[i+1]);
//         }
//         int max_prof=-9999;
//         for(int i=0;i<len-1;i++)
//         {
//             max_prof=max(max_prof,abs(arr[i]-suff_max[i]));
//         }
//         return max_prof;
//     }

// };

//m2->while travesrsing knowning the lowest value 
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int len=arr.size();
        int max_prof=-99999;
        int min_val=999999;
        for(int i=0;i<len;i++)
        {
            max_prof=max(max_prof,arr[i]-min_val);
            min_val=min(min_val,arr[i]);
        }
        return max_prof<=0?0:max_prof;
    }

};