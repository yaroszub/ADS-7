#include <cstdlib>
#include <ctime>
#include <iostream>
#include "train.h"

int main() {
    std::srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "n\tfalse\t\ttrue\t\trndom\n";

    for (int n = 2; n <= 100; n++) {
        int stepsFalse, stepsTrue, stepsRandom;

        // Все лампочки выключены
        {
            Locomotive train;
            for (int i = 0; i < n; i++)
                train.appendWagon(false);
            train.measureLength();
            stepsFalse = train.getSteps();
        }

        // Все лампочки включены
        {
            Locomotive train;
            for (int i = 0; i < n; i++)
                train.appendWagon(true);
            train.measureLength();
            stepsTrue = train.getSteps();
        }

        // Случайные состояния
        {
            Locomotive train;
            for (int i = 0; i < n; i++)
                train.appendWagon(std::rand() % 2);
            train.measureLength();
            stepsRandom = train.getSteps();
        }

        std::cout << n << "\t"
                  << stepsFalse << "\t\t"
                  << stepsTrue << "\t\t"
                  << stepsRandom << "\n";
    }

    return 0;
}
