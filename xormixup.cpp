#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll test_cases;
    cin >> test_cases;
    while (test_cases--) {
        ll num_elements, element, xor_of_elements_except_i = 0, index_of_element_to_check = 0;
        cin >> num_elements;
        vector<ll> elements;
        bool flag = true;
        
        for (int i = 0; i < num_elements; ++i) {
            cin >> element;
            elements.push_back(element);
        }
        
        sort(elements.begin(), elements.end(), greater<ll>());
        index_of_element_to_check = num_elements - 1;
        
        while (flag) {
            for (int i = 0; i < num_elements; ++i) {
                if (i != index_of_element_to_check) {
                    xor_of_elements_except_i ^= elements[i];
                }
            }
            
            if (xor_of_elements_except_i == elements[index_of_element_to_check]) {
                flag = false;
            } else {
                xor_of_elements_except_i = 0;
                index_of_element_to_check--;
            }
        }
        
        cout << xor_of_elements_except_i << endl;
    }
    return 0;
}
