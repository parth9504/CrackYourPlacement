class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        int i;
        for(i=0;i<n;i++){
            if((i==0 && arr[i]>=arr[i+1])||(i==n-1 && arr[i]>=arr[i-1]) ||
            (i>0 && i<n-1 && arr[i]>=arr[i-1] && arr[i]>=arr[i+1])){
                return i;}}
        return -1;}};