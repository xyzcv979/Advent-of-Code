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
    priority_queue<int> pq;
    while(getline(fin, line)){
        if(line.empty()) {
            pq.push(sum);
            sum = 0;
        } else {
            sum += stoi(line);
        }
    }

    pq.push(sum);
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;

    return 0;
}