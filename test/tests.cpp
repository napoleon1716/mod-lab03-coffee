// Copyright 2022 UNN-IASR
#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, DefaultStateIsOff) {
  Automata a;
  EXPECT_EQ(OFF, a.getState());
}

TEST(AutomataTest, TurnOnAndCheckState) {
  Automata a;
  a.on();
  EXPECT_EQ(WAIT, a.getState());
}

TEST(AutomataTest, TurnOffAndCheckState) {
  Automata a;
  a.on();
  a.off();
  EXPECT_EQ(OFF, a.getState());
}

TEST(AutomataTest, InsertCoinInOffState) {
  Automata a;
  a.coin(100);
  EXPECT_EQ(WAIT, a.getState());
}

TEST(AutomataTest, InsertCoinInOnState) {
  Automata a;
  a.on();
  a.coin(100);
  EXPECT_EQ(ACCEPT, a.getState());
}

TEST(AutomataTest, CancelOperationInWaitState) {
  Automata a;
  int returnedCash = a.cancel();
  EXPECT_EQ(0, returnedCash);
}

TEST(AutomataTest, CancelOperationInAcceptState) {
  Automata a;
  a.on();
  a.coin(100);
  int returnedCash = a.cancel();
  EXPECT_EQ(100, returnedCash);
}

TEST(AutomataTest, ChooseDrinkInAcceptState) {
  Automata a;
  a.on();
  a.coin(100);
  a.choice(1);
  EXPECT_EQ(CHECK, a.getState());
}

TEST(AutomataTest, ChooseDrinkInCheckState) {
  Automata a;
  a.on();
  a.coin(100);
  a.choice(1);
  a.finish();
  EXPECT_EQ(WAIT, a.getState());
}

TEST(AutomataTest, FinishDrinkPreparation) {
  Automata a;
  a.on();
  a.coin(100);
  a.choice(1);
  a.finish();
  EXPECT_EQ(WAIT, a.getState());
}
