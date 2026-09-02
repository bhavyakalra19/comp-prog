class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        	int n = classroom.size();
		int m = classroom[0].size();
		
		// get start positions and number of litters and the total mask
		int x;
		int y;
		int litters = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(classroom[i][j] == 'S'){
					x = i;
					y = j;
				}
				if(classroom[i][j] == 'L'){
                    char c = (litters + '0');
                    classroom[i][j] = c;
                    litters++;
                }
			}
		}
        if(litters == 0) return 0;
		int total_mask = (1 << litters) - 1;
		queue<vector<int>> q; // x, y, mask, energy

        // cout << total_mask << endl;
		
		int moves = 1;
		q.push({x, y, 0, energy});
		
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(total_mask + 1, -1)));
		dp[x][y][0] = energy;

		vector<int> dx = {0, 1, 0, -1};
		vector<int> dy = {1, 0, -1, 0};
		
		
		while(!q.empty()){
			int size = q.size();
			while(size--){
				auto it = q.front();
                q.pop();
				int curr_x = it[0];
				int curr_y = it[1];
				int curr_mask = it[2];
				int curr_energy = it[3];

				for(int i = 0; i < 4; i++){
					int nx = curr_x + dx[i];
					int ny = curr_y + dy[i];
					int new_energy = curr_energy - 1;
					int new_mask = curr_mask;

					if(nx < 0 || nx == n || ny < 0 || ny == m || classroom[nx][ny] == 'X') continue;
				
					if(classroom[nx][ny] == 'R'){
                        new_energy = energy;
                    }else if(classroom[nx][ny] != '.' && classroom[nx][ny] != 'S'){
                        int b = (int)(classroom[nx][ny] - '0');
                        cout << b << endl;
                        new_mask = new_mask | (1 << b);
                    }
                   
					if(new_mask == total_mask) return moves;
					
					if(dp[nx][ny][new_mask] < new_energy && new_energy > 0) {
						dp[nx][ny][new_mask] = new_energy;
						q.push({nx, ny, new_mask, new_energy});
					}
				}
			}
			moves++;
		}
		return -1;
    }	
};
