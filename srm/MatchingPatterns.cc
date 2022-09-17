// BEGIN CUT HERE

// END CUT HERE
#line 5 "MatchingPatterns.cc"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MatchingPatterns {
	public:
	string solve(int N, vector <int> L, vector <string> patterns) {
    // TODO: find length
    int first_word_length = 0;
    for(int i = 0; i < patterns.size(); i++) {
      int word_length = 0;
      for(int j = 0; j < patterns[i].size(); j++) {
        char curr = patterns[i][j];
        if(curr >= 'a' && curr <= 'z') {
          word_length++;
        } else {
          word_length += L[curr - 'A'];
        }
      }
      if(i == 0)
        first_word_length = word_length;
      if(first_word_length != word_length)
        return "";
    }
    vector<vector<char> > variables;
    for(int i = 0; i < N; i++) {
      variables.push_back(vector<char>(L[i], 0));
    }

    vector<char> solution(first_word_length);
    int changes = 1;
    while (true) {
      if(changes == 0) {
        bool full = true;
        for(int i = 0; i < solution.size(); i++) {
          if(solution[i] == 0) {
            full = false;
            solution[i] = 'a';
            break;
          }

        }
        if(full)
          break;
      }
      changes = 0;
      for(int i = 0; i < patterns.size(); i++) {
        int word_length = 0;
        for(int j = 0; j < patterns[i].size(); j++) {
          char curr = patterns[i][j];
          if(curr >= 'a' && curr <= 'z') {
            if(curr == solution[word_length]) {
            } else if(solution[word_length] != 0) {
              return "";
            } else {
              changes++;
              solution[word_length] = curr;
            }
            word_length++;
          } else {
            int variable_index = curr - 'A';

            for(int k = 0; k < L[curr - 'A']; k++) {
              if(variables[variable_index][k] == solution[word_length]) {

              } else if(variables[variable_index][k] == 0) {
                variables[variable_index][k] = solution[word_length];
                changes++;
              } else {
                if(solution[word_length] != 0) {
                  return "";
                }
                solution[word_length] = variables[variable_index][k];
                changes++;
              }

              word_length++;
            }
          }


        }
      }
    }

    return string(solution.begin(), solution.end());
	}
};
