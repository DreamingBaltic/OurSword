//n^2logn
//可自环
typedef pair<int, int> pii;
int n;
vector<int> adj[maxn];
int dis[maxn], pre[maxn], Ans[maxn];
int ans = inf, final;
int vis[maxn];

int dij(int st) {
	memset(pre, 0, sizeof pre);/*记录路径*/
	memset(dis, 0x3f, sizeof dis);
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	for (int i : adj[st]) {
		Q.push({1, i});//本题各边都是1，按实际需要修改距离
		dis[i] = 1;
		pre[i] = st;
	}
	while (!Q.empty()) {
		int d = Q.top().first, u = Q.top().second;
		Q.pop();
		if (d > dis[u])	continue;
		
		for (int i : adj[u]) {
			if (dis[i] > dis[u] + 1) {
				dis[i] = dis[u] + 1;
				pre[i] = u;
				if (i == st)	return dis[i];
				Q.push({dis[i], i});
			}
		}
	}
	return dis[st];
}

void print(int cur) {
	if (vis[cur])	return;
	vis[cur] = 1;
	print(Ans[cur]);
	cout << s[cur] << " ";
}

int main() {
	//建图
	for (int i = 1; i <= n; i++) {/*对于每个点跑他的最短环*/
		int tmp = dij(i);
		if (ans > tmp) {
			ans = tmp;
			final = i;
			memcpy(Ans, pre, sizeof pre);
		}
	}
	if (ans == inf) {//图中无环
		puts("SHIP IT");
	} else {
		print(final);
	}
}
