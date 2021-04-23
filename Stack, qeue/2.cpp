#include<iostream>

using namespace std;

struct stack
{
    int inf;
    stack *next;
};

void push(stack*& h, int x) {//�������
    stack *r = new stack;
     r -> inf = x;
     r -> next = h; 
     h = r;
}  

int pop(stack*& h) { //��������
    int i = h -> inf;
    stack *r = h;
    h = h -> next;
    delete r;
    return i;
}

void reverse(stack*& h) { //"���������"�����
    stack *head1 = NULL; //������������� ��������� �����
    while (h) //���� ���� �� ����
        push(head1, pop(h)); //������������ �� ������ ����� � ������
    h = head1; //�������������� ���������
}

stack* result(stack*& h) {
    stack *res = NULL; //�������������
    stack *h1 = NULL;
    while (h) {
        int x = pop(h); //������� ������ �������
        if (x % 2) push(res, x); //���������� � ���������
        if (x % 2 == 0) push(h1, x); //���������� � ���������
    }
    reverse(h1);
    while (h1) {
        int x = pop(h1); //������� ������ �������
        push(res, x); //���������� � ���������
    }

    reverse(res); //�������������� �������������� ����
    return res;
}

int main() {
    int n;
    cout << " n = ";
    cin >> n;
    stack * head = NULL; //�������������
    int x;
    for (int i = 0; i < n; i++) { //������� ����
        cin >> x;
        push(head, x);
    }
    reverse(head); //�������������� ����
    stack *res = result(head); //���������
    while (res)
        cout << pop(res) << " "; //������� �� �����
        cout << endl;
    return 0;
}


