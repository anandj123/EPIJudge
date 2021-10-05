#include "test_framework/generic_test.h"
using namespace std;
short Parity(unsigned long long x) {
  long long mask = 1;
  int ans = 0;
  for(int i=0;i<64;++i){
    if(x & mask <<i) ++ans;
  }
  return (ans%2);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
