#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string id[20];
    int at[20], bt[20], rt[20], ct[20], wt[20], tat[20];

    for(int i = 0; i < n; i++) {
        cin >> id[i] >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    int time = 0, completed = 0;

    while(completed < n) {
        int idx = -1, min_rt = 9999;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                idx = i;
            }
        }

        if(idx == -1) {
            time++;
            continue;
        }

        rt[idx]--;
        time++;

        if(rt[idx] == 0) {
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            completed++;
        }
    }

    cout << "ID AT BT CT TAT WT\n";
    for(int i = 0; i < n; i++) {
        cout << id[i] << " " << at[i] << " " << bt[i] << " "
             << ct[i] << " " << tat[i] << " " << wt[i] << endl;
    }
}
