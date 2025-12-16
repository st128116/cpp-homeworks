#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor {
private:
    stack<char> left;
    stack<char> right;

public:
    TextEditor() {
        // èíèöèàëèçàöèÿ ïóñòîãî ðåäàêòîðà
    }

    void addText(const string& text) {
        for (char c : text) {
            left.push(c);
        }
    }

    int deleteText(int k) {
        int deleted = 0;
        while (k > 0 && !left.empty()) {
            left.pop();
            k--;
            deleted++;
        }
        return deleted;
    }

    string cursorLeft(int k) {
        while (k > 0 && !left.empty()) {
            right.push(left.top());
            left.pop();
            k--;
        }
        return getLeftText();
    }

    string cursorRight(int k) {
        while (k > 0 && !right.empty()) {
            left.push(right.top());
            right.pop();
            k--;
        }
        return getLeftText();
    }

private:
    string getLeftText() {
        // Íóæíî âåðíóòü ñòðîêó ñëåâà îò êóðñîðà
        // íî ñòåê ïåðåâ¸ðíóò — âðåìåííî êîïèðóåì
        string result;
        stack<char> temp = left;

        while (!temp.empty()) {
            result.push_back(temp.top());
            temp.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};