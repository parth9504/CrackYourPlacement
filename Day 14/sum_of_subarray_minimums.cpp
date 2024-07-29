class Solution {
public:
    //next smaller element
    vector<int>nse(vector<int>arr){
        vector<int>res(arr.size());
        stack<int>st;
        int i;
        for(i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();}
            res[i]=st.empty()?arr.size():st.top();
            st.push(i);}
        return res;}
    //previous smaller element
    vector<int>pse(vector<int>arr){
        vector<int>res(arr.size());
        stack<int>st;
        int i;
        for(i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();}
            res[i]=st.empty()?-1:st.top();
            st.push(i);}
        return res;}
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>a=nse(arr);
        vector<int>b=pse(arr);
        int total=0,mod=(int)(1e9+7),i;
        for(i=0;i<arr.size();i++){
            int right=a[i]-i;
            int left=i-b[i];
            total=(total+(static_cast<long long>(right)*left*arr[i])%mod)%mod;
        }
        return total;}};
        /*int i,j,min_ele;
        long long sum=0;
        for(i=0;i<arr.size();i++){
            min_ele=arr[i];
            for(j=i;j<arr.size();j++){
                min_ele=min(min_ele,arr[j]);
                sum+=min_ele;}}
                return sum%1000000007;}};*/
