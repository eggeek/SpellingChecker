#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <ctime>
#include <sstream>
#include <cassert>

#include "SpellingCorrector.h"

using namespace std;

SpellingCorrector checker;
typedef long long ll;
ll tot_node, tot_pop_node, max_node, max_pop_node;
vector<string> max_node_query, max_pop_query;

char filterNonAlphabetic(char& letter)
{
  if (letter < 0)
    return '-';
  if (isalpha(letter))
    return tolower(letter);
  return '-';
}

void SpellingCorrector::load(const std::string& filename)
{
  ifstream file(filename.c_str(), ios_base::binary | ios_base::in);
//  ofstream fout;
//  fout.open("words.txt");

  file.seekg(0, ios_base::end);
  std::streampos length = file.tellg();
  file.seekg(0, ios_base::beg);

  string data(static_cast<std::size_t>(length), '\0');

  file.read(&data[0], length);

  transform(data.begin(), data.end(), data.begin(), filterNonAlphabetic);

  for (string::size_type i = 0; i != string::npos;)
  {
    const string::size_type firstNonFiltered = data.find_first_not_of('-', i + 1);
    if (firstNonFiltered == string::npos)
      break;
    const string::size_type end = data.find('-', firstNonFiltered);
    string found = data.substr(firstNonFiltered, end - firstNonFiltered);
    words[found] += 1;
//    fout << found << " " << tid << endl;
    total_words++;
    i = end;
  }
  // remove freq = 1
  for (auto& it: words) {
    int tid = trie.insert(it.first);
    rwords[tid] = it.first;
  }
//  fout.close();
}

inline double SpellingCorrector::cost(int pos, int len) {
  // if (pos > len / 2) pos = len / 2;
  return 5.0 * log((double)(len + 2.0) / (double)(pos + 1.0));
}

double SpellingCorrector::dist(const pair<string, int> &it, const string &s) {
  const string &w = it.first;
  int n = (int)w.length();
  int m = (int)s.length();
  for (int i=0; i<=n; i++)
    for (int j=0; j<=m; j++) dp[i][j] = INF;
  dp[0][0] = 0.0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) if (fabs(dp[i][j] - INF) > EPS) {
      if (i < n && j < m && w[i] == s[j]) { // match without cost
        dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
      }
      if (i < n && j < m && w[i] != s[j]) { // match with cost
        dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + cost(j, m));
      }
      if (i+1 < n && j+1 < m && w[i] == s[j+1] && w[i+1] == s[j]) {
        dp[i+2][j+2] = min(dp[i+2][j+2], dp[i][j] + cost(j, m) / 2.0);
      }
      // delete j
      if (j+1 <= m) {
        if (j+1<m && s[j] == s[j+1]) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + cost(j, m) / m);
        else dp[i][j+1] = min(dp[i][j+1], dp[i][j] + cost(j, m));
      }
      // delete i
      if (i+1 <= n) {
        if (i+1<n && w[i] == w[i+1]) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + cost(i, n) / n);
        else dp[i+1][j] = min(dp[i+1][j], dp[i][j] + cost(i, n));
      }
    }
  }
  return dp[n][m];
}

bool SpellingCorrector::isOptimal(Status s, map<pair<int, int>, double> &best) {
  pair<int, int> key = {s.tid, s.cur};
  if (best.find(key) == best.end() || best[key] > s.dist) {
    best[key] =s.dist;
    return true;
  } else {
    return false;
  }
}

inline double SpellingCorrector::factor(char u, char v) { return f2[(int)(u-'a')][(int)(v-'a')]; }
inline double SpellingCorrector::factor(char u) { return f[(int)(u-'a')]; }

vector<word_rating> SpellingCorrector::trie_search(const string& s) {
  map<pair<int, int>, double> best;
  vector<word_rating> res;
  while (!q.empty()) q.pop();
  ll pop_node = 0;
  int m = (int)s.size();
  q.push(Status(0, 0, 0));
  while (!q.empty()) {
    Status cur = q.top(); q.pop();
    pop_node++;
    TrieNode& node = trie.nodes[cur.tid];
    if (cur.cur == m && node.end) {
      string found = rwords[node.id];
      if (fabs(best[{cur.tid, cur.cur}] - cur.dist) < EPS) {
        res.push_back({cur.dist, found});
      }
      if (res.size() >= TOP) break;
      continue;
    }
    if (best[{cur.tid, cur.cur}] < cur.dist) continue;
    int j = cur.cur;
    for (int i=0; i<DICTSIZE; i++) if (node.son[i] != -1) {
      int nxtid = node.son[i];
      TrieNode& nxtnode = trie.nodes[nxtid];
      char c = (char)(i + 'a');
      if (j < m && c == s[j]) { // match without cost
          Status nxt = Status(nxtid, j+1, cur.dist);
          if (isOptimal(nxt, best))
              q.push(nxt);
      } else if (j < m){ // replace and match
          Status nxt = Status(nxtid, j+1, cur.dist + cost(j, m) * (j>=1.0?factor(s[j], c): 1.0) );
          if (isOptimal(nxt, best))
              q.push(nxt);
      }
      if (j+1 <= m) { // delete j
        if (j+1<m && s[j] == s[j+1]) {
          Status nxt = Status(cur.tid, j+1, cur.dist + cost(j, m) / m * factor(s[j]));
          if (isOptimal(nxt, best))
              q.push(nxt);
        } else {
          Status nxt = Status(cur.tid, j+1, cur.dist + cost(j, m) * factor(s[j]));
          if (isOptimal(nxt, best))
              q.push(nxt);
        }
      }
      { // delte i
        if (nxtnode.son[i] != -1) {
          Status nxt = Status(nxtid, j, cur.dist + cost(j, m) / m * factor((char)(i+'a')));
          if (isOptimal(nxt, best))
              q.push(nxt);
        } else {
          Status nxt = Status(nxtid, j, cur.dist + cost(j, m) * factor((char)(i+'a')));
          // printf("nxt dist: cost=%.6lf, factor=%.6lf\n", cost(j, m), factor((char)(i+'a')));
          if (isOptimal(nxt, best))
              q.push(nxt);
        }
      }
      if (j+1 < m && s[j+1] == c && nxtnode.son[(int)(s[j]-'a')] != -1) { // swap
        Status nxt = Status(nxtnode.son[(int)(s[j]-'a')], j+2, cur.dist + cost(j, m) / 2.0);
        if (isOptimal(nxt, best))
            q.push(nxt);
      }
    }
  }
  if (max_node < (ll)q.size() + pop_node) {
    max_node = (ll)q.size() + pop_node;
    max_node_query.clear();
    max_node_query.push_back(s);
  } else if (max_node == (ll)q.size() + pop_node) {
    max_node_query.push_back(s);
  }
  if (max_pop_node < pop_node) {
    max_pop_node = pop_node;
    max_pop_query.clear();
    max_pop_query.push_back(s);
  } else if (max_pop_node == pop_node) {
    max_pop_query.push_back(s);
  }
  tot_pop_node += pop_node;
  tot_node += (ll)q.size() + pop_node;
  return res;
}

vector<word_rating> SpellingCorrector::search(const string &s) {
  vector<word_rating> res;
  while (!loss.empty()) loss.pop();
  for (const auto& it: words) {
    loss.push({dist(it, s), it.first});
  }
  while (!loss.empty()) {
    word_rating c = loss.top(); loss.pop();
    res.push_back(c);
    if (res.size() >= TOP) break;
  }
  return res;
}

string SpellingCorrector::correct(const string& word) {
  string res;
  if (words.find(word) != words.end()) res = word;
  else {
    // vector<word_rating> candidates = trie_search(word);
    vector<word_rating> candidates = search(word);
    res = candidates[0].second;
    double best = INF;
    for (auto& it: candidates) {
      double idf = log((total_words + 1) / (words[it.second] + 1)) / log((double)total_words);
      // double idf = 1.0;
      if (it.first * idf < best) {
        best = it.first * idf;
        res = it.second;
      }
    }
  }
  return res;
}

void test_cropus(const string &filename, bool verbose) {
  tot_node = tot_pop_node = 0;
  max_node = max_pop_node = 0;
  ifstream f(filename);
  printf("**********************\n");
  printf("Testing file: %s\n", filename.c_str());
  string line;
  int tot = 0, right = 0, unknow = 0;
  long long elapsed = 0;
  while (getline(f, line)) {
    string correct = line.substr(0, line.find(':'));
    string cases = line.substr(line.find(':')+1, line.length());
    istringstream iss(cases);
    string w;
    transform(correct.begin(), correct.end(), correct.begin(), filterNonAlphabetic);
    cout << "test: " << line << endl;
    while (iss >> w) {
      transform(w.begin(), w.end(), w.begin(), filterNonAlphabetic);
      tot++;
      clock_t s0 = clock();
      string actual = checker.correct(w);
      if (checker.words.find(correct) == checker.words.end()) unknow++;
      else if (actual != correct) {
        if (verbose) {
          vector<word_rating> l = checker.trie_search(w);
          printf("-------\n");
          printf("actual: `%s`, expect: `%s`, input: `%s`\n", actual.c_str(), correct.c_str(), w.c_str());
          for (auto i: l) printf("`%s`, %.6lf, freq: %d\n", i.second.c_str(), i.first, checker.words[i.second]);
          printf("-------\n");
        }
      } else right++;
      clock_t s1 = clock();
      assert(s1 - s0 >= 0);
      elapsed += (long long)(s1 - s0);
    }
    // printf("total: %d, correct: %d, unknow: %d, rate: %.6lf, time cost: %.3lfs\n",
    //     tot, right, unknow, (double)right/ tot, (double)elapsed / (CLOCKS_PER_SEC * tot));
  }
  printf("push node{total:%lld ave:%.6lf max:%lld}\n", tot_node, (double)tot_node / tot, max_node);
  printf("max node queries:");
  for (string i: max_node_query) printf(" %s", i.c_str());
  printf("\n");

  printf("max pop queries:");
  for (string i: max_pop_query) printf(" %s", i.c_str());
  printf("\n");

  printf("pop node{total:%lld ave:%.6lf max:%lld}\n", tot_pop_node, (double)tot_pop_node/ tot, max_pop_node);
  printf("total: %d, correct: %d, unknow: %d, rate: %.6lf, ave time cost: %.3lfs, total time: %.3lfs\n",
      tot, right, unknow, (double)right/ tot, (double)elapsed / (CLOCKS_PER_SEC * (ll)tot), (double)elapsed / CLOCKS_PER_SEC);
  printf("**********************\n");
}

void test_search() {
  string s;
  while (cin >> s) {
    printf("search: `%s`\n", s.c_str());
    clock_t s2 = clock();
    vector<word_rating> res = checker.search(s);
    clock_t s3 = clock();
    vector<word_rating> res2 = checker.trie_search(s);
    clock_t s4 = clock();
    printf("normal search:\n");
    for (auto &it: res) printf("find: %s, %.6lf\n", it.second.c_str(), it.first);
    cout << "search cost: " << (double)(s3 - s2) / CLOCKS_PER_SEC << endl;
    printf("----------\n");
    printf("trie search:\n");
    for (auto &it: res2) printf("find: %s, %.6lf\n", it.second.c_str(), it.first);
    cout << "search cost: " << (double)(s4 - s3) / CLOCKS_PER_SEC << endl;
  }

}

void test_correct() {
  string s;
  while (cin >> s) {
    string res = checker.correct(s);
    printf("input: %s, out: %s\n", s.c_str(), res.c_str());
  }
}

int main() {

  clock_t s0 = clock();
  checker.load("../input/big.txt");
  clock_t s1 = clock();
  printf("load cost: %.3lfs\n", (double)(s1 - s0) / CLOCKS_PER_SEC);
  // checker.trie_search("ther");
  // test_correct();
  // test_search();
  test_cropus("../input/spell-testset1.txt", true);
  //test_cropus("../input/test.txt", true);
  // test_cropus("../input/spell-testset1.txt", false);
  // test_cropus("../input/spell-testset2.txt", false);
  // test_cropus("../input/wikipedia.txt", false);
  // test_cropus("../input/aspell.txt", false);
  // test_cropus("../input/birkbeck.txt", false);
  return 0;
}
