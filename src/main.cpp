// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
    std::srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "n\tfalse\t\ttrue\t\trandom\n";

    for (int n = 2; n <= 100; ++n) {
        int opFalse, opTrue, opRandom;

        // Все лампочки выключены
        {
            Train train;
            for (int i = 0; i < n; ++i)
                train.addCar(false);
            train.getLength();
            opFalse = train.getOpCount();
        }

        // Все лампочки включены
        {
            Train train;
            for (int i = 0; i < n; ++i)
                train.addCar(true);
            train.getLength();
            opTrue = train.getOpCount();
        }

        // Случайные состояния
        {
            Train train;
            for (int i = 0; i < n; ++i)
                train.addCar(std::rand() % 2);
            train.getLength();
            opRandom = train.getOpCount();
        }

        std::cout << n << "\t"
                  << opFalse << "\t\t"
                  << opTrue << "\t\t"
                  << opRandom << "\n";
    }

    return 0;
}
