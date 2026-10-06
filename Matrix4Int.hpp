#pragma once

struct Matrix4Int {
  int data[16] = {
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1
  };

  int& at(int r, int c) {
    return data[4 * r + c];
  }
};
