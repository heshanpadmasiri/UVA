#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <bitset>
#include "competitions.h"

using namespace std;



int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int n;
        scanf("%d", &n);
        vi sales;
        int count,current;
        count = 0;
        sales.assign(n,0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &current);
            sales[i] = current;
            for (int j = 0; j < i; ++j) {
                if (sales[j] <= current){
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}