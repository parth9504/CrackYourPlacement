class Solution {
public:
    string updated_string(string s){
        stack<char>st;
        int i;
        string res;
        for(i=0;i<s.length();i++){
            if(s[i]!='#') {
                st.push(s[i]);}
            else{
                if(!st.empty()){
                    st.pop();}}}
        while(!st.empty()){
            res+=st.top();
            st.pop();}
            return res;}
        
    bool backspaceCompare(string s, string t) {
        string a=updated_string(s);
        string b=updated_string(t);
        return a==b;}};