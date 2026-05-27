#ifndef TRAIN_H
#define TRAIN_H
class Locomotive {
private:
    struct Wagon {
        bool light;   // состояние лампочки
        Wagon* next;
        Wagon* prev;
    };
    int steps;        // счётчик переходов между вагонами
    Wagon* head;      // первый вагон (точка входа)
    Wagon* current;   // текущий вагон
    void resetSteps() { steps = 0; }
    void forward();   // переход вперёд с увеличением счётчика
    void backward();  // переход назад с увеличением счётчика
public:
    Locomotive();
    ~Locomotive();
    void appendWagon(bool light);    // добавить вагон
    int measureLength();             // вычислить длину состава
    int getSteps() const;            // получить число переходов
};
#endif
