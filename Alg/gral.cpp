#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef vector < vector < pair<int, int>>> graph;

//Создание структуры очередь
struct queue {
	int inf;
	queue* next;
};

void push(queue*& h, queue*& t, int x) { //вставка элемента в очередь
	queue* r = new queue; //создаем новый элемент
	r->inf = x;
	r->next = NULL; //всегда последний
	if (!h && !t) { //если очередь пуста
		h = t = r; //это и голова и хвост
	}
	else {
		t->next = r; //r - следующий для хвоста
		t = r; //теперь r - хвост
	}
}


int pop(queue*& h, queue*& t) { //удаление элемента из очереди
	queue* r = h; //создаем указатель на голову
	int i = h->inf; //сохраняем значение головы
	h = h->next; //сдвигаем указатель на следующий элемент
	if (!h) //если удаляем последний элемент из очереди
		t = NULL;
	delete r; //удаляем первый элемент
	return i;
}

//Создание графа
graph create(int n, int m) {
	graph gr;
	gr.resize(n);
	int a;
	cout << "Is graph orient? (1 - Yes, 2 - No) "; cin >> a;
	while (m != 0)
	{
		int x, y, z;
		cout << "Enter edge: ";
		cin >> x >> y >> z;
		if (a == 1)
			if (x > n || y > n) continue;
			else gr[x].push_back(make_pair(y, z));
		else
			if (x > n || y > n) continue;
			else {
				gr[x].push_back(make_pair(y, z));
				gr[y].push_back(make_pair(x, z));
			}
		m -= 1;
	}
	//sort(gr.begin(), gr.end());
	for (int i = 0; i < gr.size(); i++) {
		gr[i].erase(unique(gr[i].begin(), gr[i].end()), gr[i].end());
		sort(gr[i].begin(), gr[i].end());
	}
	return gr;
}

//Обход в глубину
void deep(int x, vector<int>& used, vector<int>& path, graph gr) {
	used[x] = 1;
	path.push_back(x);
	for (int i = 0; i < gr[x].size(); i++) {
		bool a = true;
		for (int j = 0; j < path.size(); j++)
			if (path[j] == gr[x][i].first) a = false;
		if (a) deep(gr[x][i].first, used, path, gr);
	}
}

//Обход в ширину
void width(int x, vector<int>& used, vector<int>& path, graph gr, queue*& h, queue*& t) {
	used[x] = 1;
	path.push_back(x);
	push(h, t, x);
	while (h) {
		int y = pop(h, t);
		for (int i = 0; i < gr[y].size(); i++) {
			bool a = true;
			for (int j = 0; j < path.size(); j++)
				if (path[j] == gr[y][i].first) a = false;
			if (a) {
				used[gr[y][i].first] = 1;
				path.push_back(gr[y][i].first);
				push(h, t, gr[y][i].first);
			}
		}
	}
}

//Вывод графа на экран
void print(graph gr) {
	for (int i = 0; i < gr.size(); i++) {
		cout << i << ": ";
		for (int j = 0; j < gr[i].size(); j++)
			cout << "(" << i << "," << gr[i][j].first << "," << gr[i][j].second << ") ";
		cout << endl;
	}
}

void deikstra(graph gr, int n) {
	for (int k = 0; k < n; k++) {
		vector<int> d, p;
		for (int i = 0; i < gr.size(); i++) {
			d.push_back(10000000);
			p.push_back(0);
		}
		d[k] = 0;
		vector<bool> u(n);
		for (int i = 0; i < n; i++) {
			int v = -1;
			for (int j = 0; j < n; ++j)
				if (!u[j] && (v == -1 || d[j] < d[v]))
					v = j;
			if (d[v] == 10000000)
				break;
			u[v] = true;
			for (int j = 0; j < gr[v].size(); j++) {
				int to = gr[v][j].first, len = gr[v][j].second;
				if (d[v] + len < d[to]) {
					d[to] = d[v] + len;
					p[to] = v;
				}
			}
		}
		for (int i = 0; i < gr.size(); i++)
			if(d[i] == 10000000)
				cout << "(" << k << ", " << i << ") = " << 0 << endl;
			else cout << "(" << k << ", " << i << ") = " << d[i] << endl;
	}
}

void prim(graph gr) {
	vector<bool> a(gr.size(), false);
	vector<pair<int,pair<int, int>>> g;
	a[0] = true;
	for (int j = 0; j < gr.size(); j++)
		sort(gr[j].begin(), gr[j].end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {return lhs.second < rhs.second; });
	for (int k = 0; k < gr.size() - 1; k++) {
		int min = 999999999;
		int imin = 0;
		int jmin = 0;
		for (int i = 0; i < gr.size(); i++) 
			for (int j = 0; j < gr[i].size(); j++)
				if (!a[i] && a[gr[i][j].first] && min > gr[i][j].second) {
					min = gr[i][j].second;
					imin = i;
					jmin = j;
				}
		a[imin] = true;
		g.push_back(make_pair(gr[imin][jmin].first, make_pair(imin, gr[imin][jmin].second)));
	}
	sort(g.begin(), g.end());
	for (int i = 0; i < g.size(); i++)
		cout << "(" << g[i].first << "," << g[i].second.first << "," << g[i].second.second << ") " << endl;
}

int main() {
	graph gr;
	int n, m;
	cout << "Enter number of vertices in the graph "; cin >> n;
	cout << "Enter number of edges in the graph "; cin >> m;
	gr = create(n, m);
	char t;
	print(gr);
	cout << "Enter your algorithm ((p) prim's algorithm, (d) dijkstra's algorithm) ";
	cin >> t;
	if (t == 'd') deikstra(gr, n);
	else prim(gr);
}