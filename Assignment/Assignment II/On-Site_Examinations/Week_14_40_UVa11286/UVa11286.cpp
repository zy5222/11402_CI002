#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        map<vector<int>, int> combo_counts;
        
        for (int i = 0; i < n; ++i) {
            vector<int> courses(5);
            for (int j = 0; j < 5; ++j) {
                cin >> courses[j];
            }
            sort(courses.begin(), courses.end());
            combo_counts[courses]++;
        }

        int max_count = 0;
        int total_students = 0;

        for (auto const& [combo, count] : combo_counts) {
            if (count > max_count) {
                max_count = count;
                total_students = count;
            } else if (count == max_count) {
                total_students += count;
            }
        }

        cout << total_students << "\n";
    }

    return 0;
}
