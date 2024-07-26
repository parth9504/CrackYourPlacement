class StockSpanner {
public:
    vector<int>st;
    StockSpanner() {
    }
    
    int next(int price) {
        int i,count=1;
        st.push_back(price);
        for(i=st.size()-2;i>=0;i--){
            if(st[i]>price){
                break;}
            count++;}
        return count;}};
         