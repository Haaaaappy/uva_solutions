#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int casenum;
    cin >> casenum;

    while (casenum--){
        int guest, stick;
        cin >> guest >> stick;
        guest += 9;
        stick += 1;

        vector<int> rvec (static_cast<unsigned long>(guest), 33000);
        vector<vector<int>> dp;
        rvec[0] = 0;
        dp.reserve(static_cast<unsigned long>(stick));
        for (int i = 0; i < stick; i++)
            dp.push_back(rvec);

        vector<int> chops;
        for (int i = 0; i < stick-1; i++){
            int node;
            cin >> node;
            chops.push_back(node);
        }
        chops.push_back(0);
        reverse(chops.begin(), chops.end());

        for (int j = 1; j < guest; j++){
            for (int i = 3*j; i < stick; i++){
                dp[i][j] = min(dp[i-1][j], dp[i-2][j-1]+(chops[i] - chops[i-1])*(chops[i] - chops[i-1]));
            }
        }

        cout << dp[stick-1][guest-1] << endl;
    }

    return 0;
}