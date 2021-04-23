#include<iostream>

using namespace std;

struct queue {
    int inf;
    queue* next;
};

void push(queue*& h, queue *&t, int x) { //������� �������� � �������
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


int pop(queue*& h, queue*&t) { //�������� �������� �� �������
    queue* r = h; //������� ��������� �� ������
    int i = h->inf; //��������� �������� ������
    h = h->next; //�������� ��������� �� ��������� �������
    if (!h) //���� ������� ��������� ������� �� �������
        t = NULL;
    delete r; //������� ������ �������
    return i;
}

void result(queue*& h, queue*& t, int n, int k) {
    int i = 0;
    while (i != k) {
        int x = pop(h, t); //������� ������ �������
        push(h, t, x); //���������� � ���������
        if (x % n == 0) push(h, t, 0); //���� ����� ������ n ���������� � ������� 0
        i++;
    }
}

int main() {
    int n;
    cout << " n = "; cin >> n;
    queue* head = NULL; //�������������
    queue* tail = NULL; //�������������
    int y, x;
    cout << " x = "; cin >> y;
    cout << "Enter your queue  ";
    for (int i = 0; i < n; i++) { //������� ����
        cin >> x;
        push(head, tail, x);
    }
    result(head, tail, y, n); //���������
    while (head)
        cout << pop(head, tail) << " "; //������� �� �����
    cout << endl;
    return 0;
}