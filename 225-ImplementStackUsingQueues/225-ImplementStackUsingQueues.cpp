// Last updated: 07/08/2025, 12:50:48
class MyStack {
public:
    queue<int> q;

    void push(int x) {
        queue<int> s;
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        q.push(x);
        while (!s.empty()) {
            q.push(s.front());
            s.pop();
        }
    }
    
    int pop() {
        int answer = q.front();
        q.pop();
        return answer;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */