#include <bits/stdc++.h>

using namespace std;

int main() {
  // multiple values in pair = tuple
  tuple<string, int, float> tup = {"Cpp", 17, 19.2};
  cout << "tuple: " << get<1>(tup) << "\n";

  // vector
  vector<int> int_vec;
  for(int i = 0; i < 8; ++i) int_vec.push_back(i + 1);
  cout << "capacity of vector: " << int_vec.capacity() << "\n";
  int_vec.push_back(2);
  cout << "added 1 element and capacity doubled: " << int_vec.capacity() << "\n";
  cout << "size remained predictable: " << int_vec.size() << "\n";

  int_vec.pop_back();
  cout << "removed 1 element but capacity of vector: " << int_vec.capacity() << "\t (it doesn't reduce on pop)\n";
}