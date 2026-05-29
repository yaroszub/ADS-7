#ifndef TRAIN_H
#define TRAIN_H

class Train {
private:
    struct Car {
        bool light;
        Car* next;
        Car* prev;
    };

    int operations;   // счётчик переходов (раньше countOp)
    Car* head;        // первый вагон
    Car* now;         // текущий вагон (раньше current)

    void resetCounter() { operations = 0; }
    void moveForward();   // переход вперёд + счётчик
    void moveBackward();  // переход назад + счётчик

public:
    Train();
    ~Train();
    void addCar(bool light);
    int getLength();
    int getOpCount() const;
};

#endif
