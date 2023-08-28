#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {

    }

    void push(int x) {
        q.push(x);
    }

    int pop() {
        queue<int> qTemp;
        while (q.size() != 1) {
            int x = q.front();
            qTemp.push(x);
            q.pop();
        }
        int res = q.front();
        q = qTemp;
        return res;
    }

    int top() {
        queue<int> qTemp = q;
        while (qTemp.size() != 1) qTemp.pop();
        
        return qTemp.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
	MyStack* obj = new MyStack();
	obj->push(30);
	int param_2 = obj->pop();
	int param_3 = obj->top();
	bool param_4 = obj->empty();
}