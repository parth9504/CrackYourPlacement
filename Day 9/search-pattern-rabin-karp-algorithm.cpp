#define d 256
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int>res;
            int p=INT_MAX;
            int m=pat.length(),n=txt.length();
            int i,j;
            int hash_pat=0,hash_txt=0;
            int h=1;
            
            for(i=0;i<m-1;i++){
                h=(h*d)%p;}
            
            //for calculating hash or pattern and txt(upto m length)
            for(i=0;i<m;i++){
                hash_pat=(d*hash_pat+pat[i])%p;
                hash_txt=(d*hash_txt+txt[i])%p;}
            
            //slide now
            for(i=0;i<=n-m;i++){
                if(hash_pat==hash_txt){
                    //check if the strings are equal
                    for(j=0;j<m;j++){
                        if(txt[i+j]!=pat[j]){
                            break;}}
                        if(j==m){
                            res.push_back(i+1);}}
                        if(i<n-m){
                            //update the hash for txt
                            hash_txt=(d*(hash_txt-txt[i]*h)+txt[i+m])%p;
                            if(hash_txt<0){
                                hash_txt+=p;}}}
                            return res;}};