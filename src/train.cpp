#include "train.h"

Train::Train() : operations(0), head(nullptr), now(nullptr) {}

Train::~Train() {
    if (!head) return;
    Car* temp = head->next;
    while (temp != head) {
        Car* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    delete head;
}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    if (!head) {
        head = newCar;
        head->next = head;
        head->prev = head;
        now = head;
    } else {
        Car* tail = head->prev;
        tail->next = newCar;
        newCar->prev = tail;
        newCar->next = head;
        head->prev = newCar;
    }
}

void Train::moveForward() {
    now = now->next;
    ++operations;
}

void Train::moveBackward() {
    now = now->prev;
    ++operations;
}

int Train::getLength() {
    if (!head) return 0;
    resetCounter();
    now = head;

    // если лампочка выключена – включаем
    if (!now->light) now->light = true;

    int length = 0;
    bool finished = false;

    while (!finished) {
        // идём вперёд до первого горящего вагона
        while (true) {
            moveForward();
            ++length;
            if (now->light) {
                now->light = false;   // гасим
                break;
            }
        }

        // возвращаемся назад на length шагов
        for (int i = 0; i < length; ++i) moveBackward();

        // если лампочка погашена – мы у начала
        if (!now->light) finished = true;
        else length = 0;   // иначе начинаем заново
    }

    return length;
}

int Train::getOpCount() const {
    return operations;
}
