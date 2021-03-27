#include <vector>
#include <iostream>

int main() {
  int tests;
  std::cin >> tests;

  for (int test = 0; test < tests; ++test) {
    int cj, jc;
    std::string s;
    std::cin >> cj >> jc >> s;
    int ans = 0;
    char last_char = 'X';
    int qs = 0;
    for (int i = 0; i < s.size(); ++i) {
      switch (s[i]) {
        case '?':
          ++qs;
          break;
        case 'C':
          if (last_char == 'J') {
            ans += jc;
          } else if (last_char == 'X') {
            /*
            if(qs > 0 && jc < 0) {
              ans += jc;
              --qs;
            }
            if (jc + cj < 0) {
              ans+=(qs/2)*(jc+cj);
            }
            */

          }
          qs = 0;
          last_char = 'C';
          break;
        case 'J':
          if (last_char == 'C') {
            ans += cj;
          }
          last_char = 'J';
          qs = 0;
          break;
      }
    }


    std::cout << "Case #" << (test + 1) << ": " << ans << "\n";
  }
}
