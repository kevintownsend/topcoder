#include <iostream>
#include <vector>
#include <math.h>
#include <stdint.h>
#include <float.h>

int main() {
  int t, p;
  std::cin >> t >> p;
  for (int test = 0; test < t; ++test) {
    std::vector<std::vector<int>> results(100);
    std::vector<double> skill(100);
    std::vector<double> difficulty(1000);
    for (int i = 0; i < 100; ++i) {
      results[i].resize(1000);

      std::string score;
      std::cin >> score;
      int correct = 0;
      for (int j = 0; j < 1000; ++j) {
        if(score[j] == '1') {
          results[i][j] = 1;
          ++correct;
        }
      }
      skill[i] = static_cast<double>(correct)/1000;
    }
    for (int j = 0; j < 1000; ++j) {
      int correct = 0;
      for (int i = 0; i < 100; ++i) {
        correct += results[i][j];
      }
      difficulty[j] = static_cast<double>(correct)/100;
      //std::cerr << difficulty[j] << "\n";
    }

    //std::vector<double> cheater(100);
    double max_suspision = DBL_MAX;
    int cheater = 0;
    for (int i = 0; i < 100; ++i) {
      double suspision = 1;
      for (int j = 0; j < 1000; ++j) {
        // TODO: calculate chance the were right
        double f = 1.0 / (1.0 + pow(M_E, (skill[i] - difficulty[j])*3));
        if (suspision < .00000000000001) {
          //std::cerr << suspision << "\n";
          //std::cerr << f << "\n";
          //std::cerr << j << "\n";
          //exit(1);
        }

        //suspision += abs(f - results[i][j]);
        suspision *= (1.0 - abs(f - results[i][j]))*4;

          /*
        if(results[i][j] == 1 && skill[i] < difficulty[j]) {
          //suspision += pow(2.0,  difficulty[j] - skill[i]);
          suspision += difficulty[j] - skill[i];
        }
        if(results[i][j] == 0 && skill[i] > difficulty[j]) {
          //suspision += pow(2.0, skill[i] - difficulty[j]);
          suspision += skill[i] - difficulty[j];
        }
        */
      }
      if (suspision < max_suspision) {
        //std::cerr << suspision << "\n";
        max_suspision = suspision;
        cheater = i;
      }
    }
    std::cout << "Case #" << (test + 1) << ": " << (cheater + 1) << "\n";
  }

}
