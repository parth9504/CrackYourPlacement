class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int i;
        for(i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                st.push(stoi(tokens[i]));}
            else{
                if(st.size()>=2){
                    int res;
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    if(tokens[i]=="+"){
                        res=(a+b);}
                    else if(tokens[i]=="-"){
                        res=(b-a);}
                    else if(tokens[i]=="*"){
                        res=(a*b);}
                    else{
                        res=(b/a);}
                    st.push(res);}}}
            return st.top();}};
                   