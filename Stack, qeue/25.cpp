#include<iostream>

using namespace std;

struct stack
{
    int inf;
    stack* next;
};

void push(stack*& h, int x) {//�������
    stack* r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

double pop(stack*& h) { //��������
    int i = h->inf;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}

void reverse(stack*& h) { //"���������"�����
    stack* head1 = NULL; //������������� ��������� �����
    while (h) //���� ���� �� ����
        push(head1, pop(h)); //������������ �� ������ ����� � ������
    h = head1; //�������������� ���������
}

stack* result(string h) {
    stack* res = NULL; //�������������
    for (int i = 0; i < h.size(); i++) {
        char x = h[i];
        if ((x >= '0') && (x <= '9'))
        {
            int y = x - 48;
            push(res, y); //���������� � ���������
        }
        else
        {
            int a = pop(res);
            int b = pop(res);
            switch (x)
            {
            case '+':
                push(res, a + b);
                break;
            case '-':
                push(res, b - a);
                break;
            case '*':
                push(res, b * a);
                break;
            case '/':
                push(res, b / a);
                break;
            default:
                break;
            }
        }
    }
    return res;
}

int main() {
    string s;
    cout << " Enter your string :\n";
    cin >> s;
    stack* res = result(s); //���������
    while (res)
        cout << pop(res) << " "; //������� �� �����
    cout << endl;
    return 0;
}