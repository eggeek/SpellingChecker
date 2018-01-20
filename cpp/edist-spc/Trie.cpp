#include <string>
#include <vector>
using namespace std;
const int DICTSIZE = 26;

class TrieNode {
public :
  int id;
  bool end;
  int son[DICTSIZE];
  void insert(const string& s, int& counter);
};

class Trie {
public:
  int root, size, counter;
  vector<TrieNode> nodes;

  Trie(int size): root(0), size(size), counter(0) {
    nodes.resize(size);
    for (int i=0; i<size; i++) {
      nodes[i].id = -1;
      nodes[i].end = false;
      memset(nodes[i].son, -1, sizeof(nodes[i].son));
    };
  }

  void initNode(int tid) {
    nodes[tid].id = tid;
    nodes[tid].end = false;
    memset(nodes[tid].son, -1, sizeof(nodes[tid].son));
  }

  int insert(const string& s) {
    int cur = root;
    for (int i=0; i<(int)s.length(); i++) {
      int v = (int)(s[i] - 'a');
      if (nodes[cur].son[v] == -1) {
        nodes[cur].son[v] = ++counter;
        initNode(counter);
      }
      cur = nodes[cur].son[v];
    }
    nodes[cur].end = true;
    return cur;
  }
};
