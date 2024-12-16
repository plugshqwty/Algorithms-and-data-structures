#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <climits>
#include <limits> 

using namespace std;
int intMax= numeric_limits<int>::max();
int main() {
    FILE* input = fopen("vampires.in", "r");
    FILE* output = fopen("vampires.out", "w");
    int n, m;
    fscanf(input, "%d %d", &n, &m);

    vector<string> podzem(n); 
    for (int i = 0; i < n; i++) {
        char row[2001];
        fscanf(input, "%s", row);
        podzem[i] = string(row);
    }

    queue<pair<int, int>> vampires;
    vector<vector<int>> dist(n, vector<int>(m, intMax));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (podzem[i][j] == 'V') {
                vampires.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }

   /* for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist[i].size(); j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;*/

    vector<pair<int, int>> napravl = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while (!vampires.empty()) {
        pair<int, int> p = vampires.front();
        vampires.pop();

        int x = p.first;
        int y = p.second;


        
       // cout << "Обрабатываем клетку: (" << x << ", " << y << ")" << endl;


        for (int i = 0; i < 4; i++) {
            int nx = x + napravl[i].first;
            int ny = y + napravl[i].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && podzem[nx][ny] == '.' && dist[nx][ny] == intMax) {
                dist[nx][ny] = dist[x][y] + 1;
                vampires.push(make_pair(nx, ny));
            }
        }

       /* for (int i = 0; i < dist.size(); i++) {
            for (int j = 0; j < dist[i].size(); j++) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;*/
    }
   
    int max_time = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
       
            if (podzem[i][j] == '.' && dist[i][j] != intMax) {
                max_time = max(max_time, dist[i][j]);
            }
        }
    }

    fprintf(output, "%d\n", max_time);

    fclose(input);
    fclose(output);

    return 0;
}