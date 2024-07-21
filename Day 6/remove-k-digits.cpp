class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        string res="";
        int i;
        for(i=0;i<num.length();i++){
            while(!st.empty() && k>0 && (st.top()-48)>(num[i]-48)){
                st.pop();
                k--;}
            st.push(num[i]);}
        //delete extra characters which are left..
        while(k>0){
            st.pop();
            k--;}
        if(st.empty()) return "0";
        while(!st.empty()){
            res+=st.top();
            st.pop();}
        while(res.size()!=0 && res.back()=='0'){
        res.pop_back();}
        if(res.empty()) return "0";
        reverse(res.begin(),res.end());
        return res;}};
       