class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> arr) {
        //sort the array
        vector<int>res(2);
        sort(arr.begin(),arr.end());
        //Approah 1 : use linear search..
        /*int ceil,floor,i;
        //for floor, find the first index where arr[i]<=x
        if(x<arr[0]){
            res[0]=-1;}
        else{
        for(i=arr.size()-1;i>=0;i--){
            if(arr[i]<=x){
                break;}}
            res[0]=arr[i];}
        
        //for ceil, find the first index where arr[i]>=x
        if(x>arr[arr.size()-1]){
            res[1]=-1;}
        else{
            for(i=0;i<arr.size();i++){
                if(arr[i]>=x){
                    break;}}
            res[1]=arr[i];}
            return res;}};*/
            
        //Approach 2 : Binary Search
         int low=0,high=arr.size()-1,f=INT_MIN;
        if(x<arr[0]){
            res[0]=-1;}
        else{
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<=x){
                if(arr[mid]>f){
                    f=arr[mid];}
                else{
                    low++;}}
            else if(arr[mid]>x){
                high--;}}
        res[0]=f;}
        
        if(x>arr[arr.size()-1]){
            res[1]=-1;}
        else{
        low=0;
        high=arr.size()-1;
        int c=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=x){
                if(arr[mid]<c){
                    c=arr[mid];}
                else{
                    high--;}}
            else if(arr[mid]<x){
                low++;}}
        res[1]=c;}
        
        return res;}};