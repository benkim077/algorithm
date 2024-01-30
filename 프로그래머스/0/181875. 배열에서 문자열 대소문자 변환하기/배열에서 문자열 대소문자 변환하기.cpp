#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    const int gap = 'a' - 'A';
    vector<string> ans;
    for(int i = 0; i < strArr.size(); i++) {
        if(i % 2) {
            for(int j = 0; j < strArr[i].size(); j++) {
                if(strArr[i][j] >= 97) strArr[i][j] -= gap;
            }
        }
        else {
            for(int j = 0; j < strArr[i].size(); j++) {
                if(strArr[i][j] < 97) strArr[i][j] += gap;
            }
        }
        ans.push_back(strArr[i]);
        
    }
    
    return ans;
}