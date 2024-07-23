class Solution {
public:
    string reverseWords(string s) {
        vector<string>res;
        int i;
        s+=" ";
        string p="";
        for(i=0;i<s.length();i++){
            if(s[i]!=' '){
                p+=s[i];}
            else if(p.length()>0 && p[0]!=' '){
                res.push_back(p);
                p="";}}
        string result;
        for(i=res.size()-1;i>0;i--){
            result+=res[i]+" ";}
        result+=res[0];
        return result;}};
           