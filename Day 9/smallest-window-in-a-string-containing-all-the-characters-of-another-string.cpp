class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        //using sliding window
        //store frequencies of chars in string p..
        int i;
        vector<int>mp(26,0);
        vector<int>mp_s(26,0);
        for(i=0;i<p.length();i++){
            mp[p[i]-97]++;}
        int left=0,right=0,mini=INT_MAX;
        string res="-1";
        while(right<s.length()){
            int f=0;
            mp_s[s[right]-97]++;
            //check if frequencies are same in mp_s and mp..
            for(i=0;i<26;i++){
                if(mp[i]>0 && mp[i]>mp_s[i]){
                    f=1;
                    break;}}
        //if string p is found ina window,minimise it now
            while(f==0 && left<=right){
                if(right-left+1<mini){
                    mini=right-left+1;
                    res=s.substr(left,mini);}
                    mp_s[s[left]-97]--;
                    left++;
                    for(i=0;i<26;i++){
                        if(mp[i]>0 && mp[i]>mp_s[i]){
                            f=1;
                            break;}}}
                right++;}
       return res;}};