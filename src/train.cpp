#include "train.h"
Locomotive::Locomotive() : steps(0), head(nullptr), current(nullptr) {}
Locomotive::~Locomotive() {
    if (!head) return;
    Wagon* wagon = head->next;
    while (wagon != head) {
        Wagon* nextWagon = wagon->next;
        delete wagon;
        wagon = nextWagon;
    }
    delete head;
}
void Locomotive::appendWagon(bool light) {
    Wagon* newWagon = new Wagon{light, nullptr, nullptr};
    if (!head) {
        head = newWagon;
        head->next = head;
        head->prev = head;
        current = head;
    } else {
        Wagon* last = head->prev;
        last->next = newWagon;
        newWagon->prev = last;
        newWagon->next = head;
        head->prev = newWagon;
    }
}
void Locomotive::forward() {
    current = current->next;
    steps++;
}
void Locomotive::backward() {
    current = current->prev;
    steps++;
}
int Locomotive::measureLength() {
    if (!head) return 0;
    resetSteps();
    current = head;
    if (!current->light) {
        current->light = true;
    }
    int length = 0;
    bool found = false;
    while (!found) {
        while (true) {
            forward();
            length++;
            if (current->light) {
                current->light = false;
                break;
            }
        }
        for (int i = 0; i < length; i++) {
            backward();
        }
        if (!current->light) {
            found = true;
        } else {
            length = 0;
        }
    }
    return length;
}
int Locomotive::getSteps() const {
    return steps;
}
