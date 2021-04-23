#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//�������� ��������� �������
struct queue {
	int inf;
	queue* next;
};

void push(queue*& h, queue*& t, int x) { //������� �������� � �������
	queue* r = new queue; //������� ����� �������
	r->inf = x;
	r->next = NULL; //������ ���������
	if (!h && !t) { //���� ������� �����
		h = t = r; //��� � ������ � �����
	}
	else {
		t->next = r; //r - ��������� ��� ������
		t = r; //������ r - �����
	}
}


int pop(queue*& h, queue*& t) { //�������� �������� �� �������
	queue* r = h; //������� ��������� �� ������
	int i = h->inf; //��������� �������� ������
	h = h->next; //�������� ��������� �� ��������� �������
	if (!h) //���� ������� ��������� ������� �� �������
		t = NULL;
	delete r; //������� ������ �������
	return i;
}

//�������� �����
vector<vector<int>> create(int n, int m ){
	vector<vector<int>> gr;
	gr.resize(n);
	int a;
	cout << "Is graph orient? (1 - Yes, 2 - No) "; cin >> a;
	while (m != 0)
	{
		int x, y;
		cout << "Enter edge: ";
		cin >> x >> y;
		if (a == 1)
			if (x > n || y > n) continue;
			else gr[x].push_back(y);
		else
			if (x > n || y > n) continue;
			else {
				gr[x].push_back(y);
				gr[y].push_back(x);
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

//����� � �������
void deep(int x, vector<int>& used, vector<int>& path, vector<vector<int>> gr) {
	used[x] = 1;
	path.push_back(x);
	for (int i = 0; i < gr[x].size(); i++) {
		bool a = true;
		for (int j = 0; j < path.size(); j++)
			if (path[j] == gr[x][i]) a = false;
		if (a) deep(gr[x][i], used, path, gr);
	}
}

//����� � ������
void width(int x, vector<int>& used, vector<int>& path, vector<vector<int>> gr, queue*& h, queue*& t) {
	used[x] = 1;
	path.push_back(x);
	push(h, t, x);
	while (h) {
		int y = pop(h, t);
		for (int i = 0; i < gr[y].size(); i++) {
			bool a = true;
			for (int j = 0; j < path.size(); j++)
				if (path[j] == gr[y][i]) a = false;
			if (a) {
				used[gr[y][i]] = 1;
				path.push_back(gr[y][i]);
				push(h, t, gr[y][i]);
			}
		}
	}
}

//����� ����� �� �����
void print(vector<vector<int>> gr) {
	for (int i = 0; i < gr.size(); i++) {
		cout << i << ":";
		for (int j = 0; j < gr[i].size(); j++)
			cout << gr[i][j] << " ";
		cout << endl;
	}
}

//��� ����������������� ����. ������� �� ����� ��� �������, �� ������� � ������.
void task1(vector<vector<int>> gr) {
	int a;
	cout << "Enter your vertex "; cin >> a;
	for (int i = 0; i < gr.size(); i++)
	{
		bool b = true;
		for (int j = 0; j < gr[a].size(); j++)
			if (gr[a][j] == i) {
				b = false;
				break;
			}
		if (b) cout << i << " ";
	}
}

//��� ��������������� ����. �������� � ���� �����, ����������� ������� A � B.
void task2(vector<vector<int>> &gr) {
	int a, b;
	cout << "Enter your verteces " << endl << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	vector<int> c;
	c.push_back(b);
	gr.push_back(c);
	gr[a].push_back(gr.size() - 1);
	print(gr);
}

//��� ��������������� ����. ���������� ����������� ������ ������ �������.
void task3(vector<vector<int>> gr) {
	for (int i = 0; i < gr.size(); i++)
		cout << i << " : " << gr[i].size() << endl;
}

//��� ����������������� ����. ��������, �������� �� ���� �������.
void task4(vector<vector<int>> gr) {
	int x = 0;
	vector<int> used, path;
	for (int i = 0; i < gr.size(); i++) 
		used.push_back(0);
	deep(x, used, path, gr);
	if (path.size() == gr.size()) cout << "Connected graph " << endl;
	else cout << "Unconnected graph " << endl;
}

//�������������� ����� � ������ ��������� ��� ������� 5
void width2(int x, vector<int>& used, vector<int>& path, vector<vector<int>> gr, queue*& h, queue*& t, vector<int> &path2) {
	used[x] = 1;
	path.push_back(x);
	push(h, t, x);
	while (h) {
		int y = pop(h, t);
		for (int i = 0; i < gr[y].size(); i++) {
			bool a = true;
			path2[gr[y][i]] = 1;
			for (int j = 0; j < path.size(); j++)
				if (path[j] == gr[y][i]) 
					a = false;
			if (a) {
				used[gr[y][i]] = 1;
				path.push_back(gr[y][i]);
				push(h, t, gr[y][i]);
			}
		}
	}
}

//��� ��������������� ����. ������� ��� ������ �����.
void task5(vector<vector<int>> gr) {
	vector<int> used, path, path2;
	for (int i = 0; i < gr.size(); i++) {
		used.push_back(0);
		path2.push_back(0);
	}
	queue *h = NULL, *t = NULL;
	for(int i = 0; i < gr.size(); i++)
		width2(i, used, path, gr, h, t, path2);
	cout << "Origins: ";
	for (int i = 0; i < path2.size(); i++)
		if (path2[i] == 0) cout << i << " ";
}

//��� ��������������� ����. ������� ��� �������, ������������ �� ������.
void task6(vector<vector<int>> gr) {
	int x;
	vector<int> used, path;
	for (int i = 0; i < gr.size(); i++)
		used.push_back(0);
	cout << "Enter your vertex "; cin >> x;
	deep(x, used, path, gr);
	for (int i = 0; i < used.size(); i++)
		if (used[i] == 0) cout << i << " ";
}

int main() {
	vector<vector<int>> gr;
	int n, m;
	cout << "Enter number of vertices in the graph "; cin >> n;
	cout << "Enter number of edges in the graph "; cin >> m;
	gr = create(n, m);
	int t;
	print(gr);
	cout << "Enter number of task (1 - 6) "; cin >> t;
	switch (t)
	{
	case 1:
		task1(gr);
		break;
	case 2:
		task2(gr);
		break;
	case 3:
		task3(gr);
		break;
	case 4:
		task4(gr);
		break;
	case 5:
		task5(gr);
		break;
	case 6:
		task6(gr);
		break;
	default: cout << "Number undefind!" << endl;
		break;
	}
}
