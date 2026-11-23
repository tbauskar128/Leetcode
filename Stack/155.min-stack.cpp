/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start

class Node {

  public:
    int value;
    int min_value;

    Node* next;

    Node(int value, int min_value, Node* next) {
        this->value = value;
        this->min_value = min_value;
        this->next = next;
    }

    Node(int value, int min_value) {
        this->value = value;
        this->min_value = min_value;
        this->next = nullptr;
    }
};

class MinStack {

    Node* head = nullptr;

  public:
    MinStack() {}

    ~MinStack() {
        while (head) {
            Node* garbage = head;
            head = head->next;
            delete garbage;
        }
    }

    void push(int value) {
        if (head == nullptr)
            head = new Node(value, value);
        else
            head = new Node(value, min(head->min_value, value), head);
    }

    void pop() {
        Node* garbage = head;
        head = head->next;
        delete garbage;
    }

    int top() { return head->value; }

    int getMin() { return head->min_value; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
