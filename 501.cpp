#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

//74
using namespace std;

int main(){
    int m,n,temp,i,j,k;
    i = j = k = 0;
    scanf("%d %d",&m,&n);
    vector<int> A;
    while (m--){
        scanf("%d", &temp);
        A.push_back(temp);
    }
    vector<int> U;
    while (n--){
        scanf("%d", &temp);
        U.push_back(temp);
    }
    multiset<int> blackBox;
    while (k < U.size() && j < A.size()){
        if(j == U[k]){
            // get
            int val = *next(blackBox.begin(),i);
            printf("%d\n",val);
            i++;
            k++;
        } else {
            // insert
            blackBox.insert(A[j]);
            j++;
        }
    }
    return 0;
}