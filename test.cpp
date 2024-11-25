#include <iostream>
#include <iterator>
#include <map>
using namespace std;

struct TrieNode {
  map<char, TrieNode *> children;
  vector<int> indices;
};

class SuffixTrie {
private:
  TrieNode *root;

public:
  SuffixTrie() { root = new TrieNode(); }

  void insertSuffix(const string &s, int index) {
    TrieNode *current = root;

    for (char c : s) {
      if (!current->children[c]) {
        current->children[c] = new TrieNode();
      }
      current = current->children[c];
    }
    current->indices.push_back(index);
  }

  void build(const string &s) {
    for (int i = 0; i < s.length(); i++) {
      insertSuffix(s.substr(i), i);
    }
  }
};

int main() {
  SuffixTrie root;
  string s;
  cin >> s;
  root.build(s);
}
