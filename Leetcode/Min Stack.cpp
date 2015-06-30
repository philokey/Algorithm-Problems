class MinStack {
private:
    stack<int> sta, minsta;
public:
    void push(int x) {
        if (!minsta.empty()) {
            int tp = minsta.top();
            if (x <= tp) {
                minsta.push(x);
            }
        } else {
            minsta.push(x);
        }
        sta.push(x);
    }

    void pop() {
        int tp = sta.top();
        sta.pop();
        if (tp == minsta.top()) {
            minsta.pop();
        }
    }

    int top() {
        return sta.top();
    }

    int getMin() {
        return minsta.top();
    }
};
