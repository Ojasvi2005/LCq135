class Solution {
public:
//two pass greedy solution.
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1) return 1;
        int sum=0;
        vector<int> temp(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                temp[i]=temp[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                temp[i]=max(temp[i],temp[i+1]+1);
            }
            sum+=temp[i];
        }
        sum+=temp[n-1];
        return sum;
    }
};
