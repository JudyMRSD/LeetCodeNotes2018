#include <iostream>
#include <vector>

using namespace std;

bool found(vector<vector<char>>& board, int i, int j, string word, int start);
bool exist(vector<vector<char>>& board, string word) {
    int numRows = board.size();
    int numCols = board[0].size();
    for (int i=0; i<numRows; i++){
        for(int j=0; j<numCols; j++){
            if(found(board, i, j, word, 0)){
                return true;
            }
        }
    }
    return false;
}

bool found(vector<vector<char>>& board, int i, int j, string word, int start){
    int numRows = board.size();
    int numCols = board[0].size();
    //finish check all characters in the word
    if(start>=word.size()){return true;}
    //check for out of bounds
    if(i<0 || i>=numRows || j<0 || j>= numCols){
        return false;
    }
    if(board[i][j]==word[start]){
        start++;
        char c = board[i][j];
        //shouldn't go backward and check already checked grid cells
        board[i][j] = '#';
        bool res = found(board, i+1, j, word, start) ||
                   found(board, i-1, j, word, start) ||
                   found(board, i, j+1, word, start) ||
                   found(board, i, j-1, word, start);
        board[i][j] = c;
        return res;
    }
    return false;
}

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";

    bool result = exist(board,word);
    cout<<result<<endl;
    return 0;
}