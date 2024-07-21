class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int> pq;
        int i;
        for (i = 0; i < m; i++) {
            pq.push(nums1[i]);
        }
        for (i = 0; i < n; i++) {
            pq.push(nums2[i]);
        }
        //resize nums1 array
        nums1.resize(m+n);
        i = m+n - 1;
        while (!pq.empty()) {
            nums1[i--] = pq.top();
            pq.pop();
        }
    }
};
