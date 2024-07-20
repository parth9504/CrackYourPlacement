class Solution {
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        vector<long long>arr1,arr2;
        int i;
        for(i=0;i<n;i++){
            arr1.push_back(a[i]);
            arr2.push_back(b[i]);}
            
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end(),[](int a,int b){
            return a>b;});
            int f=0;
            for(i=0;i<n;i++){
                if(arr1[i]+arr2[i]<k){
                    f=1;
                    break;}}
                if(f==0){
                    return true;}
        return false;}};