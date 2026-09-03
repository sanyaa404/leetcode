class TicTacToe {
public:
    vector<pair<int, int>> rowCnt;
    vector<pair<int, int>> colCnt;
    vector<pair<int, int>> diagCnt;
    int n;
    TicTacToe(int sze) {
        n = sze;
        // board.resize(n, vector<int>(n,0));
        rowCnt.resize(n, {0,0});
        colCnt.resize(n, {0,0});
        diagCnt.resize(2, {0,0});
    }

    bool checkRow(int row, int player){
        if(player == 2) return (rowCnt[row].second == n);
        return (rowCnt[row].first == n);
    }
    
    bool checkCol(int col, int player){
        if(player == 2) return (colCnt[col].second == n);
        return (colCnt[col].first == n);
    }

    bool checkDiag(int player) {
        if(player == 2){
            return (diagCnt[0].second == n) || (diagCnt[1].second == n);
        }
        return (diagCnt[0].first == n) || (diagCnt[1].first == n);
    }
    
    int move(int row, int col, int player) {
        if(player == 1){
            rowCnt[row].first++;
            colCnt[col].first++;
            if(row == col) diagCnt[0].first++;
            if(row + col == n-1) diagCnt[1].first++;
        }else{
            rowCnt[row].second++;
            colCnt[col].second++;
            if(row == col) diagCnt[0].second++;
            if(row + col == n-1) diagCnt[1].second++;
        }
        bool chr =  checkRow(row, player);
        bool chc =  checkCol(col, player);
        bool chd =  checkDiag(player);

        if(chr || chc || chd) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */