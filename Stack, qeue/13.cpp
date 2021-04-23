#include<iostream>

using namespace std;

struct queue {
    int inf;
    queue* next;
};

void push(queue*& h, queue *&t, int x) { //вставка элемента в очередь
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


int pop(queue*& h, queue*&t) { //удаление элемента из очереди
    queue* r = h; //создаем указатель на голову
    int i = h->inf; //сохраняем значение головы
    h = h->next; //сдвигаем указатель на следующий элемент
    if (!h) //если удаляем последний элемент из очереди
        t = NULL;
    delete r; //удаляем первый элемент
    return i;
}

void result(queue*& h, queue*& t, int n, int k) {
    int i = 0;
    while (i != k) {
        int x = pop(h, t); //удаляем первый элемент
        push(h, t, x); //записываем в результат
        if (x % n == 0) push(h, t, 0); //если число кратно n запимываем в очередь 0
        i++;
    }
}

int main() {
    int n;
    cout << " n = "; cin >> n;
    queue* head = NULL; //инициализация
    queue* tail = NULL; //инициализация
    int y, x;
    cout << " x = "; cin >> y;
    cout << "Enter your queue  ";
    for (int i = 0; i < n; i++) { //создаем стек
        cin >> x;
        push(head, tail, x);
    }
    result(head, tail, y, n); //результат
    while (head)
        cout << pop(head, tail) << " "; //выводим на экран
    cout << endl;
    return 0;
}