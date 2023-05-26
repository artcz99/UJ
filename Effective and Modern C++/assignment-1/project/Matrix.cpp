//
// Created by artur on 3/15/22.
//

#include "Matrix.h"

Matrix::Matrix(int N, int M) : N(N), M(M) {
    this->data = new double[N * M];
    std::cout << "* constructor of " << N << "x" << M << " matrix" << std::endl;
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> init_list) {
    this->N = init_list.size();
    this->M = findMaxRow(init_list);

    if (this->N == 0 || this->M == 0) {
        this->data = nullptr;
        return;
    }

    this->data = new double[this->N * this->M];

    std::initializer_list<std::initializer_list<double>>::iterator it;
    double *data_it = this->data;

    for (it = init_list.begin(); it != init_list.end(); it++) {
        data_it = std::copy(it->begin(), it->end(), data_it);
        for (int i = 0; i < M - it->size(); i++) {
            *data_it = 0;
            data_it++;
        }
    }

    std::cout << "* constructor of " << N << "x" << M << " matrix from initializer_list" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const Matrix &matrix) {
    if (matrix.data != nullptr) {
        for (int i = 0; i < matrix.N; i++) {
            stream << "{";
            for (int j = 0; j < matrix.M; j++) {
                stream << matrix.data[(i * matrix.M) + j] << ", ";
            }
            stream << "}\n";
        }
    } else {
        stream << "empty matrix\n";
    }
    return stream;
}

double Matrix::operator()(int x, int y) {
    if (x - 1 >= this->N || y - 1 >= this->M || this->data == nullptr) return -1;
    return this->data[(x - 1) * M + (y - 1)]; //assuming we count matrix' rows and columns from 1
}

Matrix::Matrix(const Matrix &matrix) : M(matrix.M), N(matrix.N) {
    this->data = new double[this->N * this->M];
    std::copy(matrix.data, matrix.data + this->M * this->N, this->data);
    std::cout << "* copy constructor" << std::endl;
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    delete[] this->data;
    this->N = matrix.N;
    this->M = matrix.M;

    if (this->N == 0 || this->M == 0) {
        this->data = nullptr;
        return *this;
    }

    this->data = new double[this->N * this->M];

    std::copy(matrix.data, matrix.data + matrix.N * matrix.M, this->data);

    std::cout << "* copy assignment operator" << std::endl;

    return *this;
}

Matrix::~Matrix() {
    if (this->data != nullptr) {
        std::cout << "* matrix destructed" << std::endl;
        delete[] this->data;
    }
}

int Matrix::findMaxRow(const std::initializer_list<std::initializer_list<double>> &init_list) {
    int max = init_list.begin()->size();
    std::initializer_list<std::initializer_list<double>>::iterator it;
    for (it = init_list.begin() + 1; it != init_list.end(); it++) {
        if (max < it->size()) {
            max = it->size();
        }
    }
    return max;
}

Matrix& Matrix::operator-() {
    if (this->data != nullptr)
        for (int i = 0; i < this->N * this->M; i++) {
            this->data[i] = -this->data[i];
        }
    return *this;
}

Matrix::Matrix(Matrix &&matrix) {
    this->data = matrix.data;
    this->N = matrix.N;
    this->M = matrix.M;

    matrix.data = nullptr;
    matrix.N = matrix.M = 0;
    std::cout << "move constructor" << std::endl;
}

Matrix& Matrix::operator=(Matrix&& matrix) {

    std::cout << "move assignment operator" << std::endl;
    return *this;
}

