#include <vector>
#include <iostream>


using namespace std;

void print(vector<vector<char> > &vecMap)
{
    for (auto iter: vecMap) {
        for (auto iter2: iter) {
            cout << iter2 << ' ';
        }
        cout << endl;
    }
}

void dfs(vector<vector<char> > &vecMap, size_t row, size_t col)
{
    if (row < 0 || row > vecMap.size() ||
        col < 0 || col > vecMap[0].size())
        return;
    if (vecMap[row][col] != 'O')
        return;

    vecMap[row][col] = 'Y';
    dfs(vecMap, row - 1, col);
    dfs(vecMap, row + 1, col);
    dfs(vecMap, row, col - 1);
    dfs(vecMap, row, col + 1);
}

void solution(vector<vector<char> > &vecMap)
{
    if (vecMap.size() < 2 || vecMap[0].size() < 2)
        return;

    for (size_t row = 0; row < vecMap.size(); row++) {
        dfs(vecMap, row, 0);
        dfs(vecMap, row, vecMap[0].size() - 1);
    }
    for (size_t col = 0; col < vecMap[0].size(); col++) {
        dfs(vecMap, 0, col);
        dfs(vecMap, vecMap.size() - 1, col);
    }
    for (size_t row = 0; row < vecMap.size(); row++) {
        for (size_t col = 0; col < vecMap[0].size(); col++) {
            if (vecMap[row][col] == 'Y')
                vecMap[row][col] = 'O';
            else if (vecMap[row][col] == 'O')
                vecMap[row][col] = 'X';
        }
    }
}

int main()
{
    vector<vector<char> > vecMap;
    vector<char> temp;
    temp.push_back('O');
    temp.push_back('X');
    temp.push_back('X');
    temp.push_back('X');
    vecMap.push_back(temp);
    temp.clear();

    temp.push_back('O');
    temp.push_back('X');
    temp.push_back('O');
    temp.push_back('X');
    vecMap.push_back(temp);
    temp.clear();

    temp.push_back('X');
    temp.push_back('O');
    temp.push_back('O');
    temp.push_back('X');
    vecMap.push_back(temp);
    temp.clear();

    temp.push_back('X');
    temp.push_back('X');
    temp.push_back('X');
    temp.push_back('X');
    vecMap.push_back(temp);
    temp.clear();

    print(vecMap);
    solution(vecMap);
    cout << endl;
    print(vecMap);
    return 0;
}
