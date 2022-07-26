/*
题目描述：标准的Web浏览器包含在最近访问过的页面中向后和向前移动的功能。
实现这些特性的一种方法是使用两个栈来跟踪前后移动可以到达的页面。支持以下命令。
• BACK：将当前页面推到前向栈的顶部。从后向栈的顶部弹出页面，使其成为新的当前页面。如果后向栈为空，则忽略该命令。
• FORWARD：将当前页面推到后向栈的顶部。从前向栈顶部弹出页面，使其成为新的当前页面。如果前向栈为空，则忽略该命令。
• VISIT：将当前页面推到后向栈的顶部，使URL成为新的当前页面。前向栈清空。
• QUIT：退出浏览器。
假设浏览器的最初页面为URL ***###.acm.org/（对“http://”用“***”代替，对“www”用“###”代替）。
输入：输入是一系列BACK、FORWARD、VISIT、QUIT命令。
URL没有空白，最多有70个字符。任何时候，在每个栈中都不会超过100个元素。QUIT命令表示输入结束。
输出：对于除QUIT外的每个命令，如果不忽略该命令，则在执行该命令后单行输出当前页的URL，
否则输出“Ignored”。QUIT命令没有输出。

分析：前进后退两个操作，调用两个栈来解决
（1）初始时，当前页面cur为“***###.acm.org/”。
（2）BACK：如果后向栈为空，则忽略该命令；否则将当前页面放入前向栈，从后向栈的顶部弹出页面，使其成为新的当前
（3）FORWARD：如果前向栈为空，则忽略该命令；否则将当前页面放入后向栈，从前向栈的顶部弹出页面，使其成为新的当前页面。
            输出当前页面。
（4）VISIT：将当前页面放入后向栈的顶部，并使URL成为新的当前页面。前向栈清空。输出当前页面。
（5）QUIT：退出浏览器。
*/

#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    stack<string>backward;
    stack<string>forward;
    string c;
    string cur = "http://www.acm.com";
    while (cin >> c && c != "QUIT") {
        if (c == "VISIT") {
            backward.push(cur);
            cin >> cur;
            cout << cur << endl;
            while (!forward.empty()) {
                forward.pop();
            }
        }
        else if (c == "BACK") {
            if (backward.empty()) {
                cout << "Ignored" << endl;
            }
            else {
                forward.push(cur);
                cur = backward.top();
                backward.pop();
                cout << cur << endl;
            }
        }
        else {
            if (forward.empty()) {
                cout << "Ignored" << endl;
            }
            else {
                backward.push(cur);
                cur = forward.top();
                forward.pop();
                cout << cur << endl;
            }
        }
    }

    return 0;
}

/*
测试用例              输出样例
VISIT pornhub           pornhub
VISIT Xvideo            Xvideo
BACK                    pornhub
BACK                    http://www.acm.com
BACK                    Ignored
FORWARD                 pornhub
VISIT 91porn            91porn
BACK                    pornhub
BACK                    http://www.acm.com
FORWARD                 pornhub
FORWARD                 91porn
FORWARD                 Ignored
QUIT

*/