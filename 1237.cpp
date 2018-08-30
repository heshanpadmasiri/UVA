#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;

int main(){
    int t,d,q;
    scanf("%d", &t);
    while (t--){
        scanf("%d", &d);
        vector<string> makers;
        vector<ii> prices;
        int l,h;
        char m[21];
        for (int i = 0; i < d; ++i) {
            scanf("%s %d %d", m, &l, &h);
            string maker = m;
            makers.emplace_back(maker);
            prices.emplace_back(ii(l,h));
        }
        scanf("%d", &q);
        vector<int> targets;
        bitset<1001> tests;
        bitset<1001> skip;
        skip.set();
        tests.set();
        targets.assign(q,0);
        int temp = 0;
        for (int j = 0; j < q; ++j) {
            scanf("%d",&temp);
            targets[j] = temp;
        }
        vector<string> answers;
        answers.assign(q,"UNDETERMINED");
        for (int k = 0; k < d; ++k) {
            ii current = prices[k];
            int i = 0;
            while (i < targets.size()){
                if (skip[i]){
                    int target = targets[i];
                    if (current.first <= target && current.second >= target){
                        if (tests[i]){
                            answers[i] = makers[k];
                            tests.set(i,false);
                        } else {
                            answers[i] = "UNDETERMINED";
                            skip.set(i,false);
                        }
                    }
                }
                i++;
            }
        }
        for (int n = 0; n < q; ++n) {
            printf("%s\n",answers[n].c_str());
        }
    }
    return 0;
}