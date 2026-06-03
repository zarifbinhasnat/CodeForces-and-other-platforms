/* 15619692	459	Graph Connectivity	Accepted	C++	0.000	2015-06-12 11:35:35 */
#include<bits\stdc++.h>
using namespace std;
int n;
vector<int> G[30];
bool V[30];
void DFS(int cur){
	V[cur] = true;
	for (int i = 0; i < G[cur].size(); i++){
		int target = G[cur][i];
		if (!V[target])
			DFS(target);
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	getchar();
	getchar();
	while (t--){
		char str[5];
		gets(str);
		n = str[0] - 'A' + 1;
		for (int i = 1; i <= n; i++)
			G[i].clear();
		while (gets(str) && str[0]!='\0'){
			int a = str[0] - 'A' + 1;
			int b = str[1] - 'A' + 1;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		int ans = 0;
		memset(V, false, sizeof(V));
		for (int i = 1; i <= n; i++)
			if (!V[i])
				DFS(i), ans++;
		printf("%d\n", ans);
		if (t)
			putchar('\n');
	}
	return 0;
}