// Copyright 2022 UNN-IASR
#include <iostream>
#include "Automata.h"

using std::string;
using std::cout;

int main() {
    Automata a;
    int b;
    a.on();
    cout << "automat is turned on!\n";
    a.coin(200);
    cout << "deposit the money!\n";
    a.choice(1);
    cout << "great! cooking!\n";
    a.finish();
    b = a.cancel();
    cout << "change! " << b;
    a.off();
    cout << "\nautomat is turned off!\n";
}
