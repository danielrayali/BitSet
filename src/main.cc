#include <iostream>
#include <bitset>
#include "bitset.h"
#include "timing.h"

using namespace std;

void timing() {
  BitSet my_bitset(1000000);
  std::bitset<1000000> std_bitset;

  uint64 my_set_total = 0, std_set_total = 0;
  uint64 my_read_total = 0, std_read_total = 0;
  uint64 before = 0, after = 0;
  for (int i = 0; i < 1000000; ++i) {
    size_t index = rand() % 1000000;
    before = GetTimeMs64();
    my_bitset.Set(index);
    after = GetTimeMs64();
    my_set_total += (after - before);

    before = GetTimeMs64();
    my_bitset.IsSet(index);
    after = GetTimeMs64();
    my_read_total += (after - before);


    before = GetTimeMs64();
    std_bitset[index] = 1;
    after = GetTimeMs64();
    std_set_total += (after - before);

    before = GetTimeMs64();
    std_bitset[index];
    after = GetTimeMs64();
    std_read_total += (after - before);
  }

  cout << "My average time to set is " << float(my_set_total / 1000000.0f) << endl;
  cout << "My average time to read is " << float(my_read_total / 1000000.0f) << endl;
  cout << "Standard average time to set is " << float(std_set_total / 1000000.0f) << endl;
  cout << "Standard average time to check is " << float(std_read_total / 1000000.0f) << endl;
}

void printing() {
  srand(time(0));
  BitSet bit_set(100);
  for (size_t i = 0; i < 50; ++i) {
    bit_set.Set(rand() % 100);
  }

  BitSet bit_set2 = bit_set;
  BitSet bit_set3 = bit_set2;
  cout << bit_set << bit_set2 << bit_set3;
}

int main(int argc, char* argv[]) {
  timing();
  return 0;
}

