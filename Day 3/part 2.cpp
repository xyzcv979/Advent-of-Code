#include <bits/stdc++.h>
using namespace std;


/*
--- Part Two ---
As you finish identifying the misplaced items, the Elves come to you with another issue.

For safety, the Elves are divided into groups of three. Every Elf carries a badge that identifies their group. For efficiency, within each group of three Elves, the badge is the only item type carried by all three Elves. That is, if a group's badge is item type B, then all three Elves will have item type B somewhere in their rucksack, and at most two of the Elves will be carrying any other item type.

The problem is that someone forgot to put this year's updated authenticity sticker on the badges. All of the badges need to be pulled out of the rucksacks so the new authenticity stickers can be attached.

Additionally, nobody wrote down which item type corresponds to each group's badges. The only way to tell which item type is the right one is by finding the one item type that is common between all three Elves in each group.

Every set of three lines in your list corresponds to a single group, but each group can have a different badge item type. So, in the above example, the first group's rucksacks are the first three lines:

vJrwpWtwJgWrhcsFMMfFFhFp
jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
PmmdzqPrVvPwwTWBwg
And the second group's rucksacks are the next three lines:

wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
ttgJtRGJQctTZtZT
CrZsJsPPZsGzwwsLwLmpwMDw
In the first group, the only item type that appears in all three rucksacks is lowercase r; this must be their badges. In the second group, their badge item type must be Z.

Priorities for these items must still be found to organize the sticker attachment efforts: here, they are 18 (r) for the first group and 52 (Z) for the second group. The sum of these is 70.

Find the item type that corresponds to the badges of each three-Elf group. What is the sum of the priorities of those item types?

*/


int main(){
    // open file read only
    ifstream fin("input.txt");
    if(!fin){
        cout << "File not found" << endl;
        return 0;
    }

    string line;
    int priorities = 0;
    vector<string> lines;
    while(getline(fin, line)){
        lines.push_back(line);
        if(lines.size() == 3) {
            vector<set<int>> threeSets(3);

            for(int i = 0; i < lines.size(); i++) {
                string currLine = lines[i];
                for(auto c : currLine) {
                    threeSets[i].insert(c);
                    if(threeSets[0].count(c) && threeSets[1].count(c) && threeSets[2].count(c)) {
                        if(isupper(c)) {
                            priorities += c - 'A' + 1 + 26;
                        } else {
                            priorities += c - 'a' + 1;
                        }
                        break;
                    }
                }
            }

            lines = vector<string>();
        }
        
    }

    cout << priorities << endl;
    return 0;
}