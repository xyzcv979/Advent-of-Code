#include <bits/stdc++.h>
using namespace std;


/*
--- Part Two ---
The Elf finishes helping with the tent and sneaks back over to you. "Anyway, the second column says how the round needs to end: X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win. Good luck!"

The total score is still calculated in the same way, but now you need to figure out what shape to choose so the round ends as indicated. The example above now goes like this:

In the first round, your opponent will choose Rock (A), and you need the round to end in a draw (Y), so you also choose Rock. This gives you a score of 1 + 3 = 4.
In the second round, your opponent will choose Paper (B), and you choose Rock so you lose (X) with a score of 1 + 0 = 1.
In the third round, you will defeat your opponent's Scissors with Rock for a score of 1 + 6 = 7.
Now that you're correctly decrypting the ultra top secret strategy guide, you would get a total score of 12.

Following the Elf's instructions for the second column, what would your total score be if everything goes exactly according to your strategy guide?
*/


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
    wins['A'] = 'Y';
    wins['B'] = 'Z';
    wins['C'] = 'X';

    unordered_map<char, char> losses;
    losses['A'] = 'Z';
    losses['B'] = 'X';
    losses['C'] = 'Y';

    unordered_map<char,char> matches;
    matches['A'] = 'X';
    matches['B'] = 'Y';
    matches['C'] = 'Z';

    unordered_map<char, int> scores;
    scores['X'] = 1;
    scores['Y'] = 2;
    scores['Z'] = 3;

    // X = lose, y = draw, z = win
    while(getline(fin, line)){
        char opponent = line[0];
        char myself = line[2];

        if(myself == 'X') { // loss
            sum += scores[losses[opponent]];
        } else if(myself == 'Y') { // draw
            sum += scores[matches[opponent]];
            sum += 3;
        } else if(myself == 'Z') { // win
            sum += scores[wins[opponent]];
            sum += 6;
        }
    }
    cout << sum << endl;

    return 0;
}