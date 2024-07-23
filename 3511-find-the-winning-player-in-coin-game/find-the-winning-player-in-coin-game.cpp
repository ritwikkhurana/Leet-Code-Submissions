class Solution {
public:
    string losingPlayer(int x, int y) {
        int winner = 1;
        while (x >= 1 && y >= 4) {
            winner = (winner == 1) ? 0 : 1;
            x--;
            y = y-4;
        }
        return winner == 0 ? "Alice" : "Bob";
    }
};