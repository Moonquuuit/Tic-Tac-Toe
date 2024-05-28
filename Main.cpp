#include <iostream>
#include <vector>
#include <cctype>
#include <stdexcept> 
using namespace std;

void drawBoard(const vector<vector<char>>& board) {
    cout << "   A   B   C\n";
    for (int i = 0; i < 3; ++i) {
        cout << " " << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  ---|---|---\n";
    }
}

pair<int, int> convertMove(const string& move) {
    if (move.length() != 2) {
        throw invalid_argument("Недійсний формат переміщення. Використовуйте формат '1A', '2B', etc.");
    }

    int row = move[0] - '1';
    int col = toupper(move[1]) - 'A';

    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        throw invalid_argument("Вийти за межі.");
    }

    return { row, col };
}