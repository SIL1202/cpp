#include <algorithm>
#include <iostream>
#include <stack>

std::string rearrange(const std::string &library) {
  std::stack<std::string> stack;
  stack.push("");

  for (char ch : library) {
    if (ch == '/') {
      stack.push("");
    } else if (ch == '\\') {
      std::string books = stack.top();
      stack.pop();
      std::reverse(books.begin(), books.end());
      stack.top() += books;
      std::cout << "stack.top() = " << stack.top() << std::endl;
      std::cout << "books = " << books << std::endl;
    } else {
      stack.top() += ch;
      std::cout << "stack.top() = " << stack.top() << std::endl;
      std::cout << "ch = " << ch << std::endl;
    }
  }
  return stack.top();
}

int main() {
  std::string input;
  std::cin >> input;
  std::string output = rearrange(input);
  std::cout << output;
}
