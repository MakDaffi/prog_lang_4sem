#include<iostream>

using namespace std;

struct list {
    int inf;
    list *next;
    list *prev;
};

void push(list*& h, list*& t, int x) { //������� �������� � ����� ������
    list * r = new list; //������� ����� �������
    r -> inf = x;
    r -> next = NULL; //������ ���������
    if (!h && !t) { //���� ������ ����
        r -> prev = NULL; //������ �������
        h = r; //��� ������
    }
    else {
        t -> next = r; //r - ��������� ��� ������
        r -> prev = t; //����� - ���������� ��� r
    }
    t = r; //r ������ �����
}


void print(list* h, list* t) { //������ ��������� ������
    list * p = h; //�������� �� ������
    while (p) { //���� �� ����� �� ����� ������
        cout << p -> inf << " ";
        p = p -> next; //������� � ���������� ��������
    }
}

list* find(list* h, list* t, int x) { //������ ��������� ������
    list * p = h; //�������� �� ������
    while (p) { //���� �� ����� �� ����� ������
        if (p->inf == x) break; // ���� �����, ���������� ����
            p = p -> next; //������� � ���������� ��������
    }
    return p; //���������� ���������
}

void insert_after(list*& h, list*& t, list* r, int y) { //��������� ����� r
    list * p = new list; //������� ����� �������
    p -> inf = y;
    if (r == t) { //���� ��������� ����� ������
        p -> next = NULL; //����������� ��-� - ���������
        p -> prev = r; //��������� ����� r
        r -> next = p;
        t = p; //������ ����� - p
    }
    else { //��������� � �������� ������
        r -> next -> prev = p; //��� ���������� �� r ��-�� ���������� - p
        p -> next = r -> next; //��������� �� p - ��������� �� r
        p -> prev = r; //p ��������� ����� r
        r -> next = p;
    }
}

void del_node(list*& h, list*& t, list* r) { //������� ����� r
    if (r == h && r == t) //������������ ������� ������
        h = t = NULL;
    else if (r == h) { //������� ������ ������
        h = h -> next; //�������� ������
        h -> prev = NULL;
    }
    else if (r == t) { //������� ����� ������
        t = t -> prev; //�������� �����
        t -> next = NULL;
    }
    else {
        r -> next -> prev = r -> prev; //��� ���������� �� r ���������� ���������� r->prev
        r -> prev -> next = r -> next; //��� ����������� �� r ��������� ���������� r->next
    }
    delete r; //������� r
}

void del_list(list*& h, list*& t) { //������� ������
    while (h) { //���� ������ �� ����
        list * p = h; //��������� �� ������
        h = h -> next; //��������� ������
        h -> prev = NULL; //��������
        delete p; //������� p
    }
}


void result(list*& h, list*& t, int max) {
    while(find(h, t, max)) del_node(h, t, find(h, t, max));
}

int main() {
    int n;
    cout << " n = "; cin >> n;
    list* head = NULL; //�������������
    list* tail = NULL; //�������������
    int x, max = -10000;
    cout << "Enter your list  ";
    for (int i = 0; i < n; i++) { //������� ����
        cin >> x;
        if (x > max) max = x;
        push(head, tail, x);
    }
    result(head, tail, max); //���������
    print(head, tail);
    cout << endl;
    return 0;
}