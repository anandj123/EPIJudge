#include "test_framework/generic_test.h"
bool IsPalindromeNumber(int x) {
  if (x<0) return false;
  if (x<10) return true;
  std::string s=std::to_string(x);
  for(int i=0, j=s.length()-1;i<j;++i,--j){
    if (s[i] != s[j]) return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "is_number_palindromic.cc",
                         "is_number_palindromic.tsv", &IsPalindromeNumber,
                         DefaultComparator{}, param_names);
}
