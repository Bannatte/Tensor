#pragma once

#include "Matrix4Int.hpp"
#include "Vector4Int.hpp"

Matrix4Int matrix_addition(
  const Matrix4Int& A,
  const Matrix4Int& B
);

Matrix4Int matrix_subtraction(
  const Matrix4Int& A,
  const Matrix4Int& B
);

int dot_product(
  const Vector4Int& a,
  const Vector4Int& b
);

Vector4Int get_row(
  const Matrix4Int& A,
  int r
);

Vector4Int get_col(
  const Matrix4Int& A,
  int c
);

Matrix4Int matrix_multiplacation(
  const Matrix4Int& A,
  const Matrix4Int& B
);
