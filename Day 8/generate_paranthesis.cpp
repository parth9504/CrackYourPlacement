class Solution {
public:
    int check_valid(string s){
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push('(');}
            else{
                if(st.empty()){
                    return -1;}
                else{
                    st.pop();}}}
        return 1;}
    vector<string> generateParenthesis(int n) {
        //generate all permutations for the brackets..
        string s;
        int i;
        vector<string>res;
        for(i=0;i<n;i++){
            s+="(";}
        for(i=0;i<n;i++){
            s+=")";}
        do{
            if(check_valid(s)==1){
                res.push_back(s);}}
        while(next_permutation(s.begin(),s.end()));
        return res;}};
           