//
// Created by HeshanPadmasiri on 8/27/2018.
//

#include <string>
#include <vector>
#include <sstream>

#ifndef UVA_COMPETITIONS_H
#define UVA_COMPETITIONS_H

#endif //UVA_COMPETITIONS_H

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;

vector<string> split_string(const string& string, const char& delimiter){
    vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(string);
    while (getline(tokenStream,token,delimiter)){
        tokens.push_back(token);
    }
    return tokens;

}