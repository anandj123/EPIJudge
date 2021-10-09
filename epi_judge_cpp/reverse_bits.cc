#include "test_framework/generic_test.h"
using namespace std;

unsigned long long ReverseBits(unsigned long long x) {
  vector<int> lookup(64);
  unsigned long long mask = 1;
  fill(lookup.begin(), lookup.end(),0);
  for(int i=0;i<64;++i){
    //cout << "and value with x: " << (x & mask << i) << endl;
    if (x & mask << i) lookup[i] = 1;
  }
  // for(int i=0;i<64;++i){
  //   cout << "i : " << i << " bit: " << lookup[i] << endl;
  // }
  unsigned long long ans = 0;
  // int lz = -1;
  // for(int i=63;i>=0;--i){
  //   if(lookup[i]) {
  //     lz = i;
  //     break;
  //   }
  // }
  for(int i=0;i<64;++i){
    if (lookup[i]) ans |= mask << (63-i);
  }
  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
