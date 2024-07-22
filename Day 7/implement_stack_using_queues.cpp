class MyStack {
public:

queue<int>q1,q2;

    MyStack() {
    }
    void push(int x) {
        //store all the nodes in q2 first
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();}
            q2.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();}}
    int pop() {
        if(q1.size()==1){
            int val=q1.front();
            q1.pop();
            return val;}
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();}
        while(q2.size()!=1){
            q1.push(q2.front());
            q2.pop();}
            int val=q2.front();
            q2.pop();
            return val;}
    int top() {
        if(q1.size()==1){
            return q1.front();}
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();}
        while(q2.size()!=1){
            q1.push(q2.front());
            q2.pop();}
            int val=q2.front();
            q1.push(val);
            q2.pop();
            return val;}
    bool empty() {
        return q1.empty();
    }
};
