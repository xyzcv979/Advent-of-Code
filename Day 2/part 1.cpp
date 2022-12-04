#include <bits/stdc++.h>
using namespace std;

int main(){
    // open file read only
    ifstream fin("input.txt");
    if(!fin){
        cout << "File not found" << endl;
        return 0;
    }

    // loop file line by line
    string line;
    int sum = 0;
    unordered_map<char,char> wins;
    wins['X'] = 'C';
    wins['Y'] = 'A';
    wins['Z'] = 'B';

    unordered_map<char,char> matches;
    matches['X'] = 'A';
    matches['Y'] = 'B';
    matches['Z'] = 'C';

    while(getline(fin, line)){
        char opponent = line[0];
        char myself = line[2];

        if(myself == 'X') {
            sum += 1;
        } else if(myself == 'Y') {
            sum += 2;
        } else if(myself == 'Z') {
            sum += 3;
        }

        if(wins[myself] == opponent) { // win
            sum += 6;
        } else if(matches[myself] == opponent) { // draw
            sum += 3;
        }
    }
    cout << sum << endl;

    return 0;
}