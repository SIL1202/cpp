#include <iostream>
#include <string>

using namespace std;

class Trie {
private:
  Trie *children[26];
  bool endOfword;

public:
  Trie() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
    endOfword = false;
  }

  void Trie_insert(string word) {
    Trie *root = this;

    for (int i = 0; i < word.length(); i++) {
      int index = word[i] - 'a';
      if (!root->children[index]) {
        root->children[index] = new Trie();
      }
      root = root->children[index];
    }
    root->endOfword = true;
  }

  bool startwith(string word) {
    Trie *current = this;

    for (int i = 0; i < word.length(); i++) {
      int index = word[i] - 'a';
      if (!current->children[index])
        return false;
      current = current->children[index];
    }

    return true;
  }

  bool search(string word) {
    Trie *current = this;

    for (char c : word) {
      int index = c - 'a';
      if (!current->children[index])
        return false;
      current = current->children[index];
    }
    return current->endOfword;
  }
};

int main() {
  string a = "apple";
  Trie *root = new Trie();
  root->Trie_insert(a);

  cout << "startwith 'app': "
       << (root->startwith("app") ? "Found!" : "not Found!") << endl
       << "search 'appl': " << (root->search("appl") ? "Found!" : "not Found!");

  return 0;
}
