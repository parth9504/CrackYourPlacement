class Solution {
public:
    string convert_binary(int n){
        string res="";
        while(n>0){
            res+=to_string(n%2);
            n/=2;}
        return res;}
    vector<int> countBits(int n) {
        vector<int>res(n+1,0);
        int i,j;
        for(i=1;i<=n;i++){
            string s=convert_binary(i);
            for(j=0;j<s.length();j++){
                if(s[j]=='1'){
                    res[i]++;}}}
        return res;}};
              