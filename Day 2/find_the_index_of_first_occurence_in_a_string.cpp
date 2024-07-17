class Solution {
public:
    int strStr(string haystack, string needle) {
        int i;
        if(haystack.length()<needle.length()){
            return -1;}
        
        for (i = 0; i <= haystack.length() - needle.length(); i++) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};
