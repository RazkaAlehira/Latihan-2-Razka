#include<iostream>
using namespace std;

// Maksimum ukuran queue
#define MAX_SIZE 5

// Deklarasi kelas queue
class Queue {
private:
    int front, rear;
    int data[MAX_SIZE];

public:
    // Konstruktor
    Queue() {
        front = -1;
        rear = -1;
    }

    // Fungsi untuk menambahkan elemen ke dalam queue
    void enqueue(int item) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue penuh. Enqueue tidak bisa dilakukan." << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            data[rear] = item;
            cout << "Elemen " << item << " ditambahkan ke dalam queue." << endl;
        }
    }

    // Fungsi untuk menghapus elemen dari queue
    void dequeue() {
        if (front == -1) {
            cout << "Queue kosong. Dequeue tidak bisa dilakukan." << endl;
        } else {
            cout << "Elemen " << data[front] << " dihapus dari queue." << endl;
            if (front == rear) {
                // Jika elemen yang dihapus adalah elemen terakhir
                front = -1;
                rear = -1;
            } else {
                // Pindahkan front ke elemen berikutnya
                front++;
            }
        }
    }

    // Fungsi untuk menampilkan isi queue
    void display() {
        if (front == -1) {
            cout << "Queue kosong." << endl;
        } else {
            cout << "Isi queue: ";
            for (int i = front; i <= rear; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};

// Program utama
int main() {
    Queue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.display();

    myQueue.dequeue();
    myQueue.display();

    myQueue.enqueue(4);
    myQueue.display();

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.display();

    myQueue.dequeue(); // Akan menampilkan pesan bahwa queue kosong
    myQueue.display();

    return 0;
}