#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int applyOperation(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return 0;
    }
}

int evaluateRpnExpression(const std::string& expression) {
    std::stack<int> stack;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            stack.push(applyOperation(a, b, token[0]));
        }
        else {
            stack.push(std::stoi(token));
        }
    }

    return stack.top();
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }
        int result = evaluateRpnExpression(line);
        outputFile << line << " = " << result << std::endl;
    }

    return 0;
}
