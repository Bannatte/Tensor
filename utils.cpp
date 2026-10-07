#include "utils.hpp"

Matrix4Int matrix_addition(const Matrix4Int& A, const Matrix4Int& B) // A + B = C
{
  Matrix4Int C;

  for (int i = 0; i < 16; i++) {
    C.data[i] = A.data[i] + B.data[i];
  }

  return C;
}

Matrix4Int matrix_subtraction(const Matrix4Int& A, const Matrix4Int& B) // A - B = C
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

Vector4Int get_row(const Matrix4Int& A, int r)
{
  Vector4Int result;

  for (int i = 0; i < 4; i++) {
    result.data[i] = A.data[4 * r + i];
  }

  return result;
}

Vector4Int get_col(const Matrix4Int& A, int c)
{
  Vector4Int result;

  for (int i = 0; i < 4; i++) {
    result.data[i] = A.data[c + 4 * i];
  }

  return result;
}

Matrix4Int matrix_multiplacation(const Matrix4Int& A, const Matrix4Int& B) // A * B = C
{
  Matrix4Int C;

  for (int i = 0; i < 16; i++) {
    int r = A.get_row(i / 4);
    int c = B.get_col(i % 4);

    C.data[i] = dot_product(r, c);
  }

  return C;
}
