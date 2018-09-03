#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <bitset>
#include "competitions.h"

using namespace std;



int main(){
    int n,d,r,temp;
    while (scanf("%d %d %d", &n, &d, &r) && n && d && r){
        vector<int> morning;
        morning.reserve(static_cast<unsigned int>(n));

        for (int i = 0; i < n; ++i) {
            scanf("%d",&temp);
            morning.push_back(temp);
        }
        vector<int> evening;
        evening.reserve(n);
        for (int j = 0; j < n; ++j) {
            scanf("%d",&temp);
            evening.push_back(temp);
        }

        sort(morning.begin(),morning.end());
        sort(evening.begin(),evening.end(), greater<>());
        int totalCost = 0;
        for (int k = 0; k < n; ++k) {
            int cost = morning[k] + evening[k];
            if (cost > d){
                totalCost += cost-d;
            }
        }
        totalCost *= r;
        printf("%d\n",totalCost);

    }
    return 0;
}