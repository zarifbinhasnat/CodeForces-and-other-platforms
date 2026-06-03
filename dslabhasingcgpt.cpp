#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>  // for std::abs
#include <limits> // for std::numeric_limits
#include <iomanip> // for std::fixed and std::setprecision

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    unordered_map<double, int> freqmap;

    // Input pairs and populate the frequency map for slopes
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});

        // Handle division by zero for vertical lines
        if (a != 0) {
            double slope = -(double)b / a;
            freqmap[slope]++;
        } else {
            // Special case for vertical lines (e.g., slope is "infinity")
            freqmap[std::numeric_limits<double>::infinity()]++;
        }
    }

    // Find the slope with the highest frequency
    int maxFreq = 0;
    double mostFreqSlope = 0.0;
    for (const auto& it : freqmap) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            mostFreqSlope = it.first;
        }
    }

    // Find the intercept 'c' for the most frequent slope
    double c = 0.0;
    for (int i = 0; i < n; i++) {
        int a = v[i].first;
        int b = v[i].second;

        // Calculate slope only if a != 0
        double slope = (a != 0) ? -(double)b / a : numeric_limits<double>::infinity();

        // Allow a small tolerance for floating point comparison
        if (std::abs(slope - mostFreqSlope) < 1e-6) {
            c = b - mostFreqSlope * a;
            break;
        }
    }

    cout << "y = " << fixed << setprecision(2) << mostFreqSlope << " x + " << c << endl;
    return 0;
}