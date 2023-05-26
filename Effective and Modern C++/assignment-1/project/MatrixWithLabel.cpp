//
// Created by artur on 3/15/22.
//

#include "MatrixWithLabel.h"

const std::string &MatrixWithLabel::getLabel() {
    return label;
}

void MatrixWithLabel::setLabel(const std::string &label) {
    this->label = label;
}

MatrixWithLabel::MatrixWithLabel(const std::string label, int N, int M) : label(label), Matrix(N,M){};

MatrixWithLabel::MatrixWithLabel(const std::string label, const std::initializer_list<std::initializer_list<double>>& init_list) : label(label), Matrix(init_list){}

MatrixWithLabel::MatrixWithLabel(const MatrixWithLabel &matrix) : Matrix(matrix), label(matrix.label) {};


