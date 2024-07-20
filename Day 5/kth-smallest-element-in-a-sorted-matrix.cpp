class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int i,j;
        for(i=0;i<matrix.size();i++){
        for(j=0;j<matrix.size();j++){
            pq.push(matrix[i][j]);}}
        int count=1;
        while(!pq.empty() && count<k){
            pq.pop();
            count++;}
        return pq.top();}};