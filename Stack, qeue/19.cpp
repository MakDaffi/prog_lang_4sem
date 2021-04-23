#include<iostream>

using namespace std;

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

void result(queue*& h, queue*& t, int max) {
    for (int i = 0; i < max; i++) {
        int x = pop(h, t); //������� ������ �������
        push(h, t, x); //���������� � ���������
    }
}

int main() {
    int n;
    cout << " n = "; cin >> n;
    queue* head = NULL; //�������������
    queue* tail = NULL; //�������������
    int x, max = -100000, maxi;
    cout << "Enter your queue  ";
    for (int i = 0; i < n; i++) { //������� ����
        cin >> x;
        if (x > max) {
            max = x;
            maxi = i;
        }
        push(head, tail, x);
    }
    result(head, tail, maxi); //���������
    while (head)
        cout << pop(head, tail) << " "; //������� �� �����
    cout << endl;
    return 0;
}