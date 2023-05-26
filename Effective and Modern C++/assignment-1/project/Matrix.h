//
// Created by artur on 3/15/22.
//

#ifndef EMCPP_MATRIX_H
#define EMCPP_MATRIX_H


class Matrix {
private:
    int N = 0, M = 0; //matrix' dimensions NxM
    double* data = nullptr; //one dimensional array representing the matrix
public:
    Matrix() = default;

    Matrix(int, int);

    Matrix(std::initializer_list<std::initializer_list<double>>);

    friend std::ostream& operator<<(std::ostream&, const Matrix&);

    double operator()(int, int);

    Matrix(const Matrix&); //copy constructor

    Matrix& operator=(const Matrix&);

    ~Matrix();

    int findMaxRow(const std::initializer_list<std::initializer_list<double>>&);

    Matrix& operator-();

    Matrix(Matrix&&);

    Matrix& operator=(Matrix&&);
};


#endif //EMCPP_MATRIX_H
