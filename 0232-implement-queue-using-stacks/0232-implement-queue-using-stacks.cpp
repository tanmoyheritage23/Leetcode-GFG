class MyQueue
{
    private:
    stack<int> first;
    stack<int> second;
    public:
        MyQueue() {}

    void push(int x)
    {
        first.push(x);
    }

    int pop()
    {
        while (!first.empty())
        {
            second.push(first.top());
            first.pop();
        }

        int poped = second.top();
        second.pop();

        while (!second.empty())
        {
           	// putting all the elements (except the removed one) into their first place again
            first.push(second.top());
            second.pop();
        }
        return poped;
    }

    int peek()
    {
        while (!first.empty())
        {
            second.push(first.top());
            first.pop();
        }

        int topElement = second.top();

        while (!second.empty())
        {
           	// putting all the elements into their first place again
            first.push(second.top());
            second.pop();
        }
        return topElement;
    }

    bool empty()
    {
        return first.empty();
    }
};

/**
 *Your MyQueue object will be instantiated and called as such:
 *MyQueue* obj = new MyQueue();
 *obj->push(x);
 *int param_2 = obj->pop();
 *int param_3 = obj->peek();
 *bool param_4 = obj->empty();
 */