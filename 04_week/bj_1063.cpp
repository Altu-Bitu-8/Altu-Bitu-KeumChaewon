#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 방향을 문자열에서 좌표 변화량으로 변환하는 매핑
unordered_map<string, pair<int, int>> directionMap = {
    {"R", {0, 1}}, {"L", {0, -1}}, {"B", {1, 0}}, {"T", {-1, 0}}, 
    {"RT", {-1, 1}}, {"LT", {-1, -1}}, {"RB", {1, 1}}, {"LB", {1, -1}}
};

int main() {
    string kingPos, stonePos;
    int n;

    cin >> kingPos >> stonePos >> n;

    // 현재 위치를 행, 열 좌표로 변환
    int kingRow = 8 - (kingPos[1] - '0');  // 행 변환 (1~8 → 7~0)
    int kingCol = kingPos[0] - 'A';        // 열 변환 ('A'~'H' → 0~7)

    int stoneRow = 8 - (stonePos[1] - '0');
    int stoneCol = stonePos[0] - 'A';

    for (int i = 0; i < n; ++i) {
        string move;
        cin >> move;

        // 이동할 방향 계산
        int dr = directionMap[move].first;
        int dc = directionMap[move].second;

        int newKingRow = kingRow + dr;
        int newKingCol = kingCol + dc;

        // 킹이 이동할 위치가 체스판을 벗어나지 않는지 확인
        if (newKingRow >= 0 && newKingRow < 8 && newKingCol >= 0 && newKingCol < 8) {
            // 킹이 이동했을 때 돌과 같은 위치로 가는지 확인
            if (newKingRow == stoneRow && newKingCol == stoneCol) {
                int newStoneRow = stoneRow + dr;
                int newStoneCol = stoneCol + dc;

                // 돌이 체스판을 벗어나면 이동 불가
                if (newStoneRow >= 0 && newStoneRow < 8 && newStoneCol >= 0 && newStoneCol < 8) {
                    stoneRow = newStoneRow;
                    stoneCol = newStoneCol;
                    kingRow = newKingRow;
                    kingCol = newKingCol;
                }
            } else {
                // 돌과 충돌이 없으면 킹만 이동
                kingRow = newKingRow;
                kingCol = newKingCol;
            }
        }
    }

    // 최종 위치 출력
    cout << char(kingCol + 'A') << 8 - kingRow << "\n";
    cout << char(stoneCol + 'A') << 8 - stoneRow << "\n";

    return 0;
}
