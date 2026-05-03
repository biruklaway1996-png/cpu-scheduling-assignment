#include <iostream>
using namespace std;

int main() {
    int p, r;
    cin >> p >> r;

    int allocation[10][10], max[10][10], need[10][10], available[10];

    for(int i = 0; i < p; i++)
        for(int j = 0; j < r; j++)
            cin >> allocation[i][j];

    for(int i = 0; i < p; i++)
        for(int j = 0; j < r; j++)
            cin >> max[i][j];

    for(int i = 0; i < r; i++)
        cin >> available[i];

    for(int i = 0; i < p; i++)
        for(int j = 0; j < r; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    bool finish[10] = {false};
    int safe[10], count = 0;

    while(count < p) {
        bool found = false;

        for(int i = 0; i < p; i++) {
            if(!finish[i]) {
                bool ok = true;

                for(int j = 0; j < r; j++) {
                    if(need[i][j] > available[j]) {
                        ok = false;
                        break;
                    }
                }

                if(ok) {
                    for(int j = 0; j < r; j++)
                        available[j] += allocation[i][j];

                    safe[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if(!found) {
            cout << "Not Safe\n";
            return 0;
        }
    }

    cout << "Safe sequence: ";
    for(int i = 0; i < p; i++) {
        cout << "P" << safe[i] << " ";
    }
}
