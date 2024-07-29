class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int>>v;
        int i,profit=0,c=0;
        for(i=0;i<n;i++){
            v.push_back({arr[i].dead,arr[i].profit});}
            //sort in descending order of profit
        sort(v.begin(),v.end(),[](auto a,auto b){
            return a.second>b.second;});
    //find the max deadline
    int max_dead=v[0].first;
    for(i=1;i<n;i++){
        max_dead=max(max_dead,v[i].first);}
    
    //freq arr of size max_dead+1
    vector<int>freq(max_dead+1,0);
    for(i=0;i<n;i++){
        if(freq[v[i].first]==0){
            freq[v[i].first]=1;
            c++;
            profit+=v[i].second;}
        else{
            int j=v[i].first-1;
            while(j>0){
                if(freq[j]==0){
                    freq[j]=1;
                    c++;
                    profit+=v[i].second;
                    break;}
                j--;}}}
              return {c,profit};}};