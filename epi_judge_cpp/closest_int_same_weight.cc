#include "test_framework/generic_test.h"
using namespace std;

unsigned long long ClosestIntSameBitCount(unsigned long long x) {
  unsigned long long mask = 1;
  if (x & mask) {
    for(int i=0;i<64;++i){
      if (!(x & mask<<i) ) {
        x |= mask<<i;
        x ^= mask<<(i-1);
        break;
      }
    }
  } else {
    for(int i=0;i<64;++i){
      if (x & mask<<i) {
        x ^= mask<<i;
        x |= mask<<(i-1);
        break;
      }
    }
  }
  return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
