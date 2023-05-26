#include <memory>


template<typename T>
class Vector<T, 0>;

template<typename T>
std::ostream &operator<<(std::ostream &, const Vector<T, 0> &);


template<typename T>
class Vector<T, 0> {
private:
    int n;
    std::unique_ptr<T[]> array;
public:
    using value_type = typeof(T);


    Vector(const Vector<T, 3> vec) : n(vec.size()), array(std::make_unique<T[]>(n)) {
        for(int i = 0; i < n; i++) {
            array[i] = vec[i];
        }
    }

    Vector(int size) : n(size), array(std::make_unique<T[]>(n)) {
        for(int i = 0; i < n; i++) {
            array[i] = 0;
        }
    }

    Vector(std::initializer_list<T> init_list) : n(init_list.size()), array(std::make_unique<T[]>(n)) {
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

    Vector(const Vector &vec) : n(vec.size()), array(std::make_unique<T[]>(n)) {
        for(int i = 0; i < n; i++) {
            array[i] = vec[i];
        }
    }

    int size() const;

    void resize(int newSize);

    T operator[](int i) const;

    T &operator[](int i);

    friend std::ostream &operator<< <>(std::ostream &, const Vector &);

    Vector operator+(const Vector &vec) {
        if(n != vec.size()) throw std::runtime_error("sizes do not match.");
        Vector<T, 0> return_vec(n);
        for (int i = 0; i < n; i++) {
            return_vec.array[i] = this->array[i] + vec.array[i];
        }
        return return_vec;
    }


};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T, 0> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << " ";
    }
    return os;
}

template<typename T>
T Vector<T, 0>::operator[](int i) const {
    return array[i];
}

template<typename T>
T &Vector<T, 0>::operator[](int i) {
    return array[i];
}

template<typename T>
int Vector<T, 0>::size() const {
    return n;
}

template<typename T>
void Vector<T, 0>::resize(int newSize) {
    if(n == newSize) return;
    if(n < newSize) {
        std::unique_ptr<T[]> temp(new T[newSize]);
        for(int i = 0; i < n; i++) {
            temp[i] = array[i];
        }
        for(int i = n; i < newSize; i++) {
            temp[i] = 0;
        }
        array.reset(new T[newSize]);
        for(int i = 0; i < newSize; i++) {
            array[i] = temp[i];
        }
        n = newSize;
    } else {
        std::unique_ptr<T[]> temp(new T[newSize]);
        for(int i = 0; i < newSize; i++) {
            temp[i] = array[i];
        }
        array.reset(new T[newSize]);
        for(int i = 0; i < newSize; i++) {
            array[i] = temp[i];
        }
        n = newSize;
    }
}