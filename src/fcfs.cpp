#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    string id[20];
    int at[20], bt[20], ct[20], wt[20], tat[20];

    for(int i = 0; i < n; i++) {
        cin >> id[i] >> at[i] >> bt[i];
    }

    // sort by arrival time
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(at[i] > at[j]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(id[i], id[j]);
            }
        }
    }

    int time = 0;

    for(int i = 0; i < n; i++) {
        if(time < at[i]) time = at[i];

        time += bt[i];

        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout << "ID AT BT CT TAT WT\n";
    for(int i = 0; i < n; i++) {
        cout << id[i] << " " << at[i] << " " << bt[i] << " "
             << ct[i] << " " << tat[i] << " " << wt[i] << endl;
    }
}
