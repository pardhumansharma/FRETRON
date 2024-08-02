#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int rows = 9;
const int cols = 10;

bool isValidMove(int x, int y, vector<vector<int>>& board) {
    return x >= 1 && x <= rows && y >= 1 && y <= cols && board[x][y] == 1;
}

void dfs(int x, int y, vector<vector<int>>& board, vector<pair<int, int>>& path) {
    if (x == 1 && y == 2) {
        cout << "Path " << path.size() << ":\n";
        cout << "=======\n";
        for (const auto& p : path) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << "\nArrive (1,2)\n\n";
        return;
    }

    if (isValidMove(x + 1, y, board)) {
        board[x + 1][y] = 0;
        path.push_back({x + 1, y});
        dfs(x + 1, y, board, path);
        path.pop_back();
        board[x + 1][y] = 1;
    }

    if (isValidMove(x, y - 1, board)) {
        board[x][y - 1] = 0;
        path.push_back({x, y - 1});
        dfs(x, y - 1, board, path);
        path.pop_back();
        board[x][y - 1] = 1;
    }
}

int main() {
    int numSoldiers;
    cout << "Enter the number of soldiers: ";
    cin >> numSoldiers;

    vector<pair<int, int>> soldiers(numSoldiers);
    cout << "Enter coordinates for soldiers:\n";
    for (int i = 0; i < numSoldiers; ++i) {
        cin >> soldiers[i].first >> soldiers[i].second;
    }

    vector<vector<int>> board(rows + 1, vector<int>(cols + 1, 0));
    for (const auto& s : soldiers) {
        board[s.first][s.second] = 1;
    }

    pair<int, int> castle;
    cout << "Enter the coordinates for your 'special' castle: ";
    cin >> castle.first >> castle.second;

    vector<pair<int, int>> path;
    path.push_back(castle);
    board[castle.first][castle.second] = 0;

    dfs(castle.first, castle.second, board, path);

    cout << "Thanks. There are " << path.size() << " unique paths for your 'special_castle'\n";

    return 0;
}
