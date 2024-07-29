class Solution {
public:
    vector<int>nge(vector<int>arr){
        vector<int>res(arr.size());
        stack<int>st;
        int i;
        for(i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();}
            res[i]=st.empty()?-1:st.top();
            st.push(i);
            }
            return res;}
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res(nums1.size());
        int i,j;
        //store the indices of occurences of nums1 elements in nums2
        unordered_map<int,int>mp;
        for(i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;}
        
        //compute the next greater element for nums2
        vector<int>a=nge(nums2);
        for(i=0;i<a.size();i++){
            cout<<a[i]<<" ";}
        
        for(i=0;i<nums1.size();i++){
            int ind=mp[nums1[i]];
            res[i]=a[ind]==-1?-1:nums2[a[ind]];}
        return res;}};
           