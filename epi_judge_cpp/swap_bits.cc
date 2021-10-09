#include "test_framework/generic_test.h"
using namespace std;

long long SwapBits(long long x, int i, int j) {
  long long mask = 1;
  long long ival, jval;
  ival = (mask<<i & x)>>i;
  jval = (mask<<j & x)>>j;
  // cout << endl << "ival: " << ival << endl;
  // cout << "jval: " << jval << endl;
  if ( ival == jval ) return x;
  x ^= mask<<i;
  x ^= mask<<j;
  return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
