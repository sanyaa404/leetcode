class TicTacToe {
public:
    vector<vector<int>> board;
    int n;
    TicTacToe(int sze) {
        n = sze;
        board.resize(n, vector<int>(n,0));
    }

    bool checkRow(int row, int player){
        for(int j=0; j<n; j++){
            if(board[row][j] != player) return false;
        } return true;
    }
    
    bool checkCol(int col, int player){
        for(int i=0; i<n; i++){
            if(board[i][col] != player) return false;
        } return true;
    }

    bool checkDiag(int row, int col, int player) {
        if(row == col) {
            bool ok = true;
            for(int i = 0; i < n; i++) {
                if(board[i][i] != player) {
                    ok = false;
                    break;
                }
            }
            if(ok) return true;
        }
        if(row + col == n - 1) {
            bool ok = true;

            for(int i = 0; i < n; i++) {
                if(board[i][n - 1 - i] != player) {
                    ok = false;
                    break;
                }
            }
            if(ok) return true;
        }
        return false;
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        bool chr =  checkRow(row, player);
        bool chc =  checkCol(col, player);
        bool chd =  checkDiag(row, col, player);

        if(chr || chc || chd) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */