#include "lambda.h"

#include <string>
#include <cctype>

bool has_uppercase(std::string password) {
  for(int i = 0; i < password.size(); i++) {
    if(isupper(password[i]))
        return true;
  }
  return false;
}

