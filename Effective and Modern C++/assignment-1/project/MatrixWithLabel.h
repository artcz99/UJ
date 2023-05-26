//
// Created by artur on 3/15/22.
//

#ifndef EMCPP_MATRIXWITHLABEL_H
#define EMCPP_MATRIXWITHLABEL_H


#include "Matrix.h"

class MatrixWithLabel : public Matrix {
private:
    std::string label = "A";
public:
    using Matrix::Matrix;

    const std::string& getLabel();

    void setLabel(const std::string&);

    MatrixWithLabel(const std::string, int, int);

    MatrixWithLabel(const std::string, const std::initializer_list<std::initializer_list<double>>&);

    MatrixWithLabel(const MatrixWithLabel&);

    MatrixWithLabel(MatrixWithLabel&&) = default;

    MatrixWithLabel& operator=(MatrixWithLabel&&) = default;
};


#endif //EMCPP_MATRIXWITHLABEL_H
