#ifndef LAMBDA_H_
#define LAMBDA_H_

#include <string>

// TODO: has uppercase

bool has_uppercase(std::string password);

template<typename Lambda>
bool is_secure(std::string password, const Lambda& rule) {
  return false;
}
// TODO: lambda argument

template<typename C>
bool is_secure(std::string password, const C& c, int min_rules) {
}

#endif // LAMBDA_H_

