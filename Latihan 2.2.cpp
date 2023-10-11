#include<iostream>
using namespace std;

// Maksimum ukuran circular queue
#define MAX_SIZE 5

// Deklarasi kelas circular queue
class CircularQueue {
private:
    int front, rear;
    int data[MAX_SIZE];

public:
    // Konstruktor
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Fungsi untuk menambahkan elemen ke dalam circular queue
    void enqueue(int item) {
        if ((rear + 1) % MAX_SIZE == front) {
            cout << "Circular Queue penuh. Enqueue tidak bisa dilakukan." << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % MAX_SIZE;
            data[rear] = item;
            cout << "Elemen " << item << " ditambahkan ke dalam circular queue." << endl;
        }
    }

    // Fungsi untuk menghapus elemen dari circular queue
    void dequeue() {
        if (front == -1) {
            cout << "Circular Queue kosong. Dequeue tidak bisa dilakukan." << endl;
        } else {
            cout << "Elemen " << data[front] << " dihapus dari circular queue." << endl;
            if (front == rear) {
                // Jika elemen yang dihapus adalah elemen terakhir
                front = -1;
                rear = -1;
            } else {
                // Pindahkan front ke elemen berikutnya secara circular
                front = (front + 1) % MAX_SIZE;
            }
        }
    }

    // Fungsi untuk menampilkan isi circular queue
    void display() {
        if (front == -1) {
            cout << "Circular Queue kosong." << endl;
        } else {
            cout << "Isi circular queue: ";
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
    CircularQueue myCircularQueue;

    myCircularQueue.enqueue(1);
    myCircularQueue.enqueue(2);
    myCircularQueue.enqueue(3);
    myCircularQueue.display();

    myCircularQueue.dequeue();
    myCircularQueue.display();

    myCircularQueue.enqueue(4);
    myCircularQueue.display();

    myCircularQueue.dequeue();
    myCircularQueue.dequeue();
    myCircularQueue.display();

    myCircularQueue.dequeue(); // Akan menampilkan pesan bahwa circular queue kosong
    myCircularQueue.display();

    return 0;
}