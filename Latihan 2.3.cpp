#include<iostream>
using namespace std;

// Maksimum ukuran deque
#define MAX_SIZE 5

// Deklarasi kelas deque
class Deque {
private:
    int front, rear;
    int data[MAX_SIZE];

public:
    // Konstruktor
    Deque() {
        front = -1;
        rear = -1;
    }

    // Fungsi untuk menambahkan elemen ke depan deque
    void enqueueFront(int item) {
        if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
            cout << "Deque penuh. EnqueueFront tidak bisa dilakukan." << endl;
        } else {
            if (front == -1) {
                front = 0;
                rear = 0;
            } else if (front == 0) {
                front = MAX_SIZE - 1;
            } else {
                front--;
            }
            data[front] = item;
            cout << "Elemen " << item << " ditambahkan ke depan deque." << endl;
        }
    }

    // Fungsi untuk menambahkan elemen ke belakang deque
    void enqueueRear(int item) {
        if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
            cout << "Deque penuh. EnqueueRear tidak bisa dilakukan." << endl;
        } else {
            if (front == -1) {
                front = 0;
                rear = 0;
            } else if (rear == MAX_SIZE - 1) {
                rear = 0;
            } else {
                rear++;
            }
            data[rear] = item;
            cout << "Elemen " << item << " ditambahkan ke belakang deque." << endl;
        }
    }

    // Fungsi untuk menghapus elemen dari depan deque
    void dequeueFront() {
        if (front == -1) {
            cout << "Deque kosong. DequeueFront tidak bisa dilakukan." << endl;
        } else {
            cout << "Elemen " << data[front] << " dihapus dari depan deque." << endl;
            if (front == rear) {
                // Jika elemen yang dihapus adalah elemen terakhir
                front = -1;
                rear = -1;
            } else if (front == MAX_SIZE - 1) {
                front = 0;
            } else {
                front++;
            }
        }
    }

    // Fungsi untuk menghapus elemen dari belakang deque
    void dequeueRear() {
        if (front == -1) {
            cout << "Deque kosong. DequeueRear tidak bisa dilakukan." << endl;
        } else {
            cout << "Elemen " << data[rear] << " dihapus dari belakang deque." << endl;
            if (front == rear) {
                // Jika elemen yang dihapus adalah elemen terakhir
                front = -1;
                rear = -1;
            } else if (rear == 0) {
                rear = MAX_SIZE - 1;
            } else {
                rear--;
            }
        }
    }

    // Fungsi untuk menampilkan isi deque
    void display() {
        if (front == -1) {
            cout << "Deque kosong." << endl;
        } else {
            cout << "Isi deque: ";
            int i = front;
            do {
                cout << data[i] << " ";
                i = (i + 1) % MAX_SIZE;
            } while (i != (rear + 1) % MAX_SIZE);
            cout << endl;
        }
    }
};

// Program utama
int main() {
    Deque myDeque;

    myDeque.enqueueRear(1);
    myDeque.enqueueRear(2);
    myDeque.enqueueFront(3);
    myDeque.display();

    myDeque.dequeueFront();
    myDeque.display();

    myDeque.enqueueFront(4);
    myDeque.display();

    myDeque.dequeueRear();
    myDeque.display();

    myDeque.enqueueRear(5);
    myDeque.enqueueRear(6); // Akan menampilkan pesan bahwa deque penuh
    myDeque.display();

    return 0;
}