#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream file1("input.txt");
	ofstream file2("output.txt");
	long long n, s, to;
	file1 >> n >> s >> to;
	s--;
	to--;
	vector<bool> visited(n, false);
	vector<vector<long long>> matrix(n, vector<long long>(n, 0));
	vector<vector<int>> edges;
	vector<int> prev(n, 0);
	edges.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			file1 >> matrix[i][j];
			if (matrix[i][j] != -1) {
				edges[i].push_back(j);
			}
		}		
	}
	vector<long long> d(n, 1000000000);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		long long v = -2;
		for (int j = 0; j < n; j++) {
			if (!visited[j] && (v == -2 || d[j] < d[v])) {
				v = j;
			}
		}
		if (d[v] == 1000000000) break;                               
		visited[v] = true;
		for (int e = 0; e < edges[v].size(); e++) {
			if (d[v] + matrix[v][edges[v][e]] < d[edges[v][e]]) {  
				d[edges[v][e]] = d[v] + matrix[v][edges[v][e]];
				prev[edges[v][e]] = v;
			}
		}
	}
	if (d[to] == 1000000000) {
		file2 << -1;
	}
	else {
		file2 << d[to];
		/*vector<int> ans;
		int pos = to;
		ans.push_back(pos);
		while (pos != s) {
			pos = prev[pos];
			ans.push_back(pos);
		}
		for (int i = ans.size() - 1; i >= 0; i--) {
			file2 << ans[i] + 1 << " ";
		}*/
	}
	system("pause");
	return 0;
}