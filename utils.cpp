#include "utils.hpp"

Matrix4Int matrix_addition(const Matrix4Int& A, const Matrix4Int& B) // A + B = C
{
  Matrix4Int C;

  for (int i = 0; i < 16; i++) {
    C.data[i] = A.data[i] + B.data[i];
  }

  return C;
}

Matrix4Int matrix_addition(const Matrix4Int& A, const Matrix4Int& B) // A - B = C
{
  Matrix4Int C;

  for (int i = 0; i < 16; i++) {
    C.data[i] = A.data[i] - B.data[i];
  }

  return C;
}

int dot_product(const Vector4Int& a, const Vector4Int& b)
{
  int result = 0;

  for (int i = 0; i < 4; i++) {
    result += a.data[i] * b.data[i];
  }

  return result;
}
