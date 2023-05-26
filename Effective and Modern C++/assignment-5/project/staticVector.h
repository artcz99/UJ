#include <iostream>
#include <stdexcept>

template<typename T, int N>
class Vector;

template<typename T, int N>
std::ostream &operator<<(std::ostream &, const Vector<T, N> &);


template<typename T, int N>
class Vector {
private:
    int n{};
    static T array[];

public:
    using value_type = typeof(T);

    Vector() : n(N) {

    }

    Vector(const Vector &vec);

    Vector(std::initializer_list<T> init_list);

    explicit Vector(const Vector<T, 0> vec) {
        n = vec.size();
    }

    T at(int i) const;

    int size() const;

    friend std::ostream &operator<< <>(std::ostream &, const Vector &);

    Vector operator+(const Vector &vec) {
//        if (this->n != vec.size()) {
        // throw std::invalid_argument("incompatible dimensions");
//        }
        Vector<T, N> return_vec;
        for (int i = 0; i < n; i++) {
            return_vec.array[i] = this->array[i] + vec.array[i];
        }
        return return_vec;
    }

    friend Vector operator+(const Vector& vec1, const Vector<T, 0>& vec2) {
        Vector<T, N> return_vec(vec1.n);
        for (int i = 0; i < vec1.n; i++) {
            return_vec.array[i] = vec1.array[i] + vec2.array[i];
        }
        return return_vec;
    }

    T operator[](int i) const;

    T &operator[](int i);
};

template<typename T, int N>
T Vector<T, N>::at(int i) const {
    return array[i];
}

template<typename T, int N>
int Vector<T, N>::size() const {
    return n;
}

template<typename T, int N>
T Vector<T, N>::array[N] = {};

template<typename T, int N>
std::ostream &operator<<(std::ostream &os, const Vector<T, N> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec.at(i) << " ";
    }
    return os;
}

template<typename T, int N>
Vector<T, N>::Vector(std::initializer_list<T> init_list) : n(init_list.size()) {
    this->array[n];
    if (this->n == 0) {
        return;
    }

    typename std::initializer_list<T>::iterator it;

    int i = 0;
    for (it = init_list.begin(); it != init_list.end(); it++, i++) {
        array[i] = *it;
    }
}

template<typename T, int N>
T Vector<T, N>::operator[](int i) const {
    return array[i];
}

template<typename T, int N>
T &Vector<T, N>::operator[](int i) {
    return array[i];
}

template<typename T, int N>
Vector<T, N>::Vector(const Vector &vec) {
    this->n = vec.size();
    this->array[n];
    std::copy(vec.array, vec.array + vec.size(), this->array);
}

