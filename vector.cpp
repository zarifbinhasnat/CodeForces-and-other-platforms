#include <iostream>
#include <vector>  // Include the vector header
using namespace std;

int main() {
  std::cout << "Hello World!\n";

  vector<int> v;  // Corrected typo
  v.push_back(1);
  v.push_back(2);

  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
//range base loop
  for(int i : v) {
    cout << i << endl;
  }    
  
  return 0;
}