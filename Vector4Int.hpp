#pragma once

struct Vector4Int {
  int data[4]{};

  int& at(int i) {
    return data[i];
  }
};
