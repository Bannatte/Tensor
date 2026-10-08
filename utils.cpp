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

Matrix4Int _sub_matrix(const Matrix4Int& A, int r, int c)
{
  Matrix4Int result;
  int index = 0;
  
  for (int i = 0; i < 16; i++) {
    if ((i / 4 == r) || (i % 4 == c)) {
      continue;
    }

    result.data[index] = A.data[i];
    index++;
  }

  return result;
}

int det(const Matrix4Int& A)
{
    const int a = A.data[0];
    const int b = A.data[1];
    const int c = A.data[2];
    const int d = A.data[3];

    const int e = A.data[4];
    const int f = A.data[5];
    const int g = A.data[6];
    const int h = A.data[7];

    const int i = A.data[8];
    const int j = A.data[9];
    const int k = A.data[10];
    const int l = A.data[11];

    const int m = A.data[12];
    const int n = A.data[13];
    const int o = A.data[14];
    const int p = A.data[15];

    const int kp_lo = k * p - l * o;
    const int jp_ln = j * p - l * n;
    const int jo_kn = j * o - k * n;

    const int ip_lm = i * p - l * m;
    const int io_km = i * o - k * m;
    const int in_jm = i * n - j * m;

    return a * (f * kp_lo - g * jp_ln + h * jo_kn)
         - b * (e * kp_lo - g * ip_lm + h * io_km)
         + c * (e * jp_ln - f * ip_lm + h * in_jm)
         - d * (e * jo_kn - f * io_km + g * in_jm);
}
