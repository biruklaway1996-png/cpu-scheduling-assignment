#include <iostream>
using namespace std;

int main() {
    int n, tq;
    cin >> n;

    string id[20];
    int at[20], bt[20], rt[20], ct[20], wt[20], tat[20];

    for(int i = 0; i < n; i++) {
        cin >> id[i] >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int time = 0;

    while(true) {
        bool done = true;

        for(int i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = false;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;

                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    rt[i] = 0;
                }
            }
        }

        if(done) break;
    }

    cout << "ID AT BT CT TAT WT\n";
    for(int i = 0; i < n; i++) {
        cout << id[i] << " " << at[i] << " " << bt[i] << " "
             << ct[i] << " " << tat[i] << " " << wt[i] << endl;
    }
}
