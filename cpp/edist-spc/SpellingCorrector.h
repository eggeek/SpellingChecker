#ifndef _SPELLINGCORRECTOR_H_
#define _SPELLINGCORRECTOR_H_

#include <vector>
#include <set>
#include <map>
#include <queue>
#include "Trie.cpp"
using namespace std;

const int MAXSIZE = 500000;
const int MAXL = 200;
const double INF = 1e10;
const double EPS = 1e-4;
const int TOP = 5;
typedef pair<double, string> word_rating;


class SpellingCorrector {
private:
  double dp[MAXSIZE][MAXL];

  struct Status {
    int tid, cur;
    double dist;
    Status(int tid, int cur, double dist): tid(tid), cur(cur), dist(dist) {}
  };

  struct cmp {
    bool operator () (Status& lhs, Status& rhs) {
      return lhs.dist > rhs.dist;
    }
  };

public:
  set<char> vowel{'a', 'e', 'i', 'o', 'u'};
  set<char> blast{'b','d','k','p','t'};
  set<char> consonant{'c','f','g','h','j','k','l','m','n','q','r','s','u','v','w','x','y','z'};
  double f2[DICTSIZE][DICTSIZE];
  double f[DICTSIZE];
  Trie trie;
  int total_words;
  map<string, int> words;
  map<int, string> rwords;
  priority_queue<word_rating, vector<word_rating>, greater<word_rating> > loss;
  priority_queue<Status, vector<Status>, cmp> q;
  void load(const std::string& filename);
  vector<word_rating> search(const string &s);
  vector<word_rating> trie_search(const string&s);
  std::string correct(const std::string& word);
  double cost(int pos, int len);
  double dist(const pair<string, int> &u, const string &v);
  bool isOptimal(Status s, map<pair<int, int>, double> &best);
  inline double factor(char u, char v);
  inline double factor(char u);

  void setFactor(char u, char v, double var) {
    f2[(int)(u-'a')][(int)(v-'a')] = var;
    f2[(int)(v-'a')][(int)(u-'a')] = var;
  }

  void setFactor(char u, double var) {
    f[(int)(u-'a')] = var;
  }

  SpellingCorrector(): trie(MAXSIZE) {
    for (int i=0; i<DICTSIZE; i++)
      for (int j=0; j<DICTSIZE; j++) f2[i][j] = 1.0;
    for (int i=0; i<DICTSIZE; i++) f[i] = 1.0;
    for (char i: vowel) {
      for (char j: vowel) if (i != j) setFactor(i, j, 0.5);
      for (char j: blast) setFactor(i, j, 5.0);
    }
    for (char i: consonant) {
      for (char j: blast) setFactor(i, j, 5.0);
    }
    for (char i: blast) {
      for (char j: blast) if (i != j) setFactor(i, j, 5.0);
    }
    setFactor('s', 'c', 0.2);
    setFactor('m', 'n', 0.2);
    setFactor('c', 'x', 0.2);
    setFactor('y', 's', 2.0);
    setFactor('b', 'p', 0.5);
    for (char i: vowel) setFactor(i, 'r', 2.0);
    for (char i: vowel) setFactor(i, 's', 2.0);
    for (char i: vowel) setFactor(i, 'c', 2.0);

    for (char i: blast) setFactor(i, 2.0);
    for (char i: vowel) setFactor(i, 0.5);
    setFactor('w', 2.0);
    setFactor('x', 2.0);
    setFactor('y', 2.0);
    setFactor('r', 0.5);
    setFactor('c', 2.0);
    setFactor('l', 2.0);
  }
};

#endif
