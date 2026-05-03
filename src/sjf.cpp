#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string id[20];
    int at[20], bt[20], ct[20], wt[20], tat[20];
    bool done[20] = {false};

    for(int i = 0; i < n; i++) {
        cin >> id[i] >> at[i] >> bt[i];
    }

    int time = 0, completed = 0;

    while(completed < n) {
        int idx = -1, min_bt = 9999;

        for(int i = 0; i < n; i++) {
            if(!done[i] && at[i] <= time && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        if(idx == -1) {
            time++;
            continue;
        }

        time += bt[idx];

        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        done[idx] = true;
        completed++;
    }

    cout << "ID AT BT CT TAT WT\n";
    for(int i = 0; i < n; i++) {
        cout << id[i] << " " << at[i] << " " << bt[i] << " "
             << ct[i] << " " << tat[i] << " " << wt[i] << endl;
    }
}
