#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
  public:
    char letter;
    unsigned int wi;
    Node(char l, unsigned int wi): letter(l), wi(wi) { }
};

vector<int> solve(string s) {
  unsigned int wi = 0;
  unsigned int prev_wi = 0;
  unsigned int new_wi = 0;
  vector<Node*> ldata(s.length());
  unordered_map<char, unsigned int> letters;
  unordered_map<char, unsigned int>::iterator it;
  for (unsigned int i = 0; i < s.length(); ++i) {
    char letter = s[i];
    Node* node = new Node(letter, wi);
    ldata[i] = node;
    wi++;
    it = letters.find(letter);
    if (it == letters.end()) {
      letters[letter] = i;
      continue;
    }
    unsigned int prev_pos = it->second;
    it->second = i;
    new_wi = ldata[prev_pos]->wi;
    prev_wi = new_wi;
    for (unsigned int j = i; j > prev_pos; --j) {
      if(ldata[j]->wi == new_wi) break;
      if(ldata[j]->wi != prev_wi) wi--;
      prev_wi = ldata[j]->wi;
      ldata[j]->wi = new_wi;
    }
  }
  prev_wi = 0;
  vector<int> result(wi);
  unsigned int count = 0;
  for(auto n : ldata) {
    if (n->wi != prev_wi) {
      result[prev_wi++] = count;
      count = 0;
    }
    count++;
  }
  result[prev_wi++] = count;
  return result;
}

int main (int argc, char**argv) {
  vector<int> res = solve(argv[1]);
  for (auto n : res) {
    std::cout << n << " ";
  }
  std::cout << "\n";
}
