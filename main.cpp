#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <bitset>
#include "competitions.h"

using namespace std;



int main(){
    int n,m,temp;

    while (scanf("%d", &n) || n){
        vi values;
        values.assign(n,0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &temp);
            values[i] = temp;
        }
        sort(values.begin(),values.end());
        scanf("%d", &m);
        while (m--){
            scanf("%d", &temp);
            auto low = lower_bound(values.begin(),values.end(), temp);
            int upper_limit = low - values.begin();
            int minimum = 100000000;
            int delta = minimum;
            if (upper_limit < values.size()){
                if(upper_limit){
                    minimum = values[upper_limit] + values[0];
                } else {
                    minimum = values[upper_limit] + values[upper_limit + 1];
                }
                delta = abs(temp - minimum);
            }

            // lower set
            for (int i = upper_limit-1; i > 0 ; --i) {
                if(!delta){
                    break;
                }
                int temp_diff = 1000000;
                for (int j = 0; j < i; ++j) {
                    int total = values[i] + values[j];
                    int diff = abs(total-temp);
                    if (diff > temp_diff){
                        break;
                    }
                    temp_diff = diff;
                    if (delta > diff){
                        minimum = total;
                        delta = diff;
                    }
                }
            }
            printf("::%d\n", minimum);
        }
    }
    return 0;
}