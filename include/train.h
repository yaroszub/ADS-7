// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
    struct Car {
        bool light;
        Car* next;
        Car* prev;
    };

    int operations;   // счётчик переходов
    Car* head;        // первый вагон
    Car* now;         // текущий вагон

    void resetCounter() { operations = 0; }
    void moveForward();
    void moveBackward();

 public:
    Train();
    ~Train();
    void addCar(bool light);
    int getLength();
    int getOpCount() const;
};

#endif // INCLUDE_TRAIN_H_
