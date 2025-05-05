#include <bits/stdc++.h>
using namespace std;
class ArrayStack
{
private:
    vector<int> stack;

public:
    int size()
    {
        return stack.size();
    }
    bool isempty()
    {
        return stack.size() == 0;
    }
    int top()
    {
        if (isempty())
            throw out_of_range("Õ»Îª¿Õ");
        return stack.back();
    }
    void push(int num)
    {
        stack.push_back(num);
    }
    int pop()
    {
        int num = top();
        stack.pop_back();
        return num;
    }
    vector<int> tovector()
    {
        return stack;
    }
};

int main(){
    ArrayStack s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        s.push(i);
    cout << s.size() << '\n';
    cout << s.pop() << '\n';
    cout << s.pop() << '\n';
}