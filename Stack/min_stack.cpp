// 155. Min Stack

class MinStack {

    stack<int> main;
    stack<int> mini;
public:
    MinStack() {    }

    void push(int x) {
        main.push(x);

        if(mini.empty() || mini.top()>=x)
            mini.push(x);
    }

    void pop() {

        if(mini.top() == main.top())
            mini.pop();

        main.pop();
    }

    int top() {
        return main.top();
    }

    int getMin() {
        return mini.top();
    }
};
