int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

class POLYNOMIAL {
public:
    static int overloaded;
    int degree;
    int *polynom;

    POLYNOMIAL();

    POLYNOMIAL(int, ...);

    POLYNOMIAL(const POLYNOMIAL &);

    ~POLYNOMIAL();

    POLYNOMIAL operator=(const POLYNOMIAL &);

    POLYNOMIAL operator+(const POLYNOMIAL &) const;

    POLYNOMIAL operator-(const POLYNOMIAL &) const;

    POLYNOMIAL operator*(const POLYNOMIAL &) const;

    POLYNOMIAL operator/(const POLYNOMIAL &);

    POLYNOMIAL operator%(const POLYNOMIAL &);

    POLYNOMIAL operator+=(const POLYNOMIAL &);

    POLYNOMIAL operator-=(const POLYNOMIAL &);

    POLYNOMIAL operator*=(const POLYNOMIAL &);

    POLYNOMIAL operator/=(const POLYNOMIAL &);

    POLYNOMIAL operator%=(const POLYNOMIAL &);

    POLYNOMIAL operator-() const;

    POLYNOMIAL operator++();

    POLYNOMIAL operator--();

    POLYNOMIAL operator++(int);

    POLYNOMIAL operator--(int);

    POLYNOMIAL operator<<(int);

    POLYNOMIAL operator>>(int);

    POLYNOMIAL operator>>=(int);

    POLYNOMIAL operator<<=(int);

    void *operator new(size_t amount);

    void operator delete(void *pointer);

    void shift();

    void GCD() const;
};

bool operator==(const POLYNOMIAL &, const POLYNOMIAL &);

bool operator!=(const POLYNOMIAL &, const POLYNOMIAL &);

bool operator<(const POLYNOMIAL &, const POLYNOMIAL &);

bool operator<=(const POLYNOMIAL &, const POLYNOMIAL &);

bool operator>(const POLYNOMIAL &, const POLYNOMIAL &);

bool operator>=(const POLYNOMIAL &, const POLYNOMIAL &);

void POLYNOMIAL::GCD() const {
    int a = this->polynom[0];
    for (int i = 1; i < this->degree + 1; i++) {
        a = gcd(this->polynom[i], a);
    }
    if (a == 1) return;
    if (a < 0) a = -a;
    for (int i = 0; i < this->degree + 1; i++)
        this->polynom[i] /= a;
}

POLYNOMIAL::POLYNOMIAL() {
    this->degree = 0;
    this->polynom = new int[0 + 1];
    this->polynom[0] = 0;
}

POLYNOMIAL::POLYNOMIAL(int degree, ...) {
    if (degree < 0) {
        this->degree = 0;
        this->polynom = new int[this->degree + 1];
        return;
    }
    this->degree = degree;
    this->polynom = new int[this->degree + 1];
    va_list args;
    va_start(args, degree);
    for (int i = 0; i < this->degree + 1; i++) {
        this->polynom[i] = va_arg(args, int);
    }
    va_end (args);
    if (this->degree == 0 && this->polynom[0] == 0) return;
    this->GCD();
}

POLYNOMIAL::~POLYNOMIAL() {
    delete[] this->polynom;
}

POLYNOMIAL::POLYNOMIAL(const POLYNOMIAL &polynomial) {
    this->degree = polynomial.degree;
    this->polynom = new int[this->degree + 1];
    for (int i = 0; i < this->degree + 1; i++) {
        this->polynom[i] = polynomial.polynom[i];
    }
}

POLYNOMIAL POLYNOMIAL::operator=(const POLYNOMIAL &polynomial) {
    delete[] this->polynom;
    this->degree = polynomial.degree;
    this->polynom = new int[this->degree + 1];
    for (int i = 0; i < this->degree + 1; i++) {
        this->polynom[i] = polynomial.polynom[i];
    }
    return *this;
}

bool operator==(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    if (a.degree == b.degree) {
        for (int i = 0; i < a.degree + 1; i++) {
            if (a.polynom[i] != b.polynom[i]) return false;
        }
        return true;
    }
    return false;
}

bool operator!=(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    return !(a == b);
}

bool operator<(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    if (a.degree < b.degree) return true;
    if (a.degree > b.degree) return false;
    for (int i = a.degree; i >= 0; i--) {
        if (a.polynom[i] < b.polynom[i]) return true;
        if (a.polynom[i] > b.polynom[i]) return false;
    }
    return false;
}

bool operator>(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    if (a.degree > b.degree) return true;
    if (a.degree < b.degree) return false;
    for (int i = a.degree; i >= 0; i--) {
        if (a.polynom[i] > b.polynom[i]) return true;
        if (a.polynom[i] < b.polynom[i]) return false;
    }
    return false;
}

bool operator<=(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    return a == b || a < b;

}

bool operator>=(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    return a == b || a > b;
}

POLYNOMIAL POLYNOMIAL::operator-() const {
    POLYNOMIAL c(this->degree);
    delete[] c.polynom;
    c.polynom = new int[this->degree + 1];
    for (int i = 0; i < this->degree + 1; i++) {
        c.polynom[i] = -this->polynom[i];
    }

    return c;
}

void POLYNOMIAL::shift() {
    int i = this->degree;
    while (this->polynom[i] == 0) {
        i--;
        if (i < 0) {
            delete[] this->polynom;
            this->degree = 0;
            this->polynom = new int[this->degree + 1];
            this->polynom[0] = 0;
            return;
        }
    }
    int *new_polynom = new int[i + 1];
    for (int j = 0; j < i + 1; j++) {
        new_polynom[j] = this->polynom[j];
    }
    delete[] this->polynom;
    this->degree = i;
    this->polynom = new_polynom;
}

POLYNOMIAL POLYNOMIAL::operator+=(const POLYNOMIAL &polynomial) {
    *this = *this + polynomial;
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator-=(const POLYNOMIAL &polynomial) {
    *this = *this - polynomial;
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator<<(int value) {
    POLYNOMIAL c(*this);
    if (value < 0 || c.degree - value < 0) {
        c.degree = 0;
        delete[] c.polynom;
        c.polynom = new int[c.degree + 1];
        c.polynom[0] = 0;
        return c;
    }
    if (value == 0) {
        return c;
    }
    int *new_polynom = new int[c.degree - value + 1];
    for (int i = value; i < c.degree + 1; i++) {
        new_polynom[i - value] = c.polynom[i];
    }
    delete[] c.polynom;
    c.degree = c.degree - value;
    c.polynom = new_polynom;

    c.shift();
    if (c.degree == 0 && c.polynom[0] == 0) return *this;
    c.GCD();

    return c;
}

POLYNOMIAL POLYNOMIAL::operator>>(int value) {
    POLYNOMIAL c(*this);
    if (value < 0) {
        c.degree = 0;
        delete[] c.polynom;
        c.polynom = new int[c.degree + 1];
        c.polynom[0] = 0;
        return c;
    }
    if (value == 0) {
        return c;
    }
    int *new_polynom = new int[c.degree + value + 1];
    int i;
    for (i = 0; i < value; i++) {
        new_polynom[i] = 0;
    }
    for (; i < c.degree + value + 1; i++) {
        new_polynom[i] = c.polynom[i - value];
    }
    delete[] c.polynom;
    c.degree = c.degree + value;
    c.polynom = new_polynom;

    c.shift();
    if (c.degree == 0 && c.polynom[0] == 0) return *this;
    c.GCD();

    return c;
}

POLYNOMIAL POLYNOMIAL::operator<<=(int value) {
    *this = *this << value;
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator>>=(int value) {
    *this = *this >> value;
    return *this;
}

ostream &operator<<(ostream &stream, const POLYNOMIAL &polynomial) {
    stream << "( ";
    for (int i = 0; i < polynomial.degree; i++)
        stream << polynomial.polynom[i] << ", ";
    stream << polynomial.polynom[polynomial.degree] << " )";
    return stream;
}

istream &operator>>(istream &stream, POLYNOMIAL &polynomial) {
    delete[] polynomial.polynom;
    stream >> polynomial.degree;
    if (polynomial.degree < 0) {
        polynomial.degree = 0;
        polynomial.polynom = new int[polynomial.degree + 1];
        *(polynomial.polynom) = 0;
        return stream;
    }
    if (polynomial.degree == 0) {
        polynomial.polynom = new int[polynomial.degree + 1];
        stream >> *(polynomial.polynom);
        if (*(polynomial.polynom) == 0) return stream;
    } else {
        polynomial.polynom = new int[polynomial.degree + 1];
        for (int i = 0; i < polynomial.degree + 1; i++)
            stream >> polynomial.polynom[i];
    }
    polynomial.GCD();
    return stream;
}

POLYNOMIAL POLYNOMIAL::operator+(const POLYNOMIAL &b) const {
    if (this->degree >= b.degree) {
        POLYNOMIAL c(this->degree);
        for (int i = 0; i < this->degree + 1; i++) {
            c.polynom[i] = this->polynom[i];
            if (i < b.degree + 1)
                c.polynom[i] += b.polynom[i];
        }
        c.shift();
        if (c.degree == 0 && c.polynom[0] == 0) return c;
        c.GCD();
        return c;
    } else {
        POLYNOMIAL c(b.degree);
        for (int i = 0; i < b.degree + 1; i++) {
            if (i < this->degree + 1)
                c.polynom[i] = this->polynom[i];
            else
                c.polynom[i] = 0;
            c.polynom[i] += b.polynom[i];
        }
        c.shift();
        if (c.degree == 0 && c.polynom[0] == 0) return c;
        c.GCD();
        return c;
    }
}

POLYNOMIAL POLYNOMIAL::operator-(const POLYNOMIAL &b) const {
    if (this->degree >= b.degree) {
        POLYNOMIAL c(this->degree);
        for (int i = 0; i < this->degree + 1; i++) {
            c.polynom[i] = this->polynom[i];
            if (i < b.degree + 1)
                c.polynom[i] -= b.polynom[i];
        }
        c.shift();
        if (c.degree == 0 && c.polynom[0] == 0) return c;
        c.GCD();
        return c;
    } else {
        POLYNOMIAL c(b.degree);
        for (int i = 0; i < b.degree + 1; i++) {
            if (i < this->degree + 1)
                c.polynom[i] = this->polynom[i];
            else
                c.polynom[i] = 0;
            c.polynom[i] -= b.polynom[i];
        }
        c.shift();
        if (c.degree == 0 && c.polynom[0] == 0) return c;
        c.GCD();
        return c;
    }
}

POLYNOMIAL POLYNOMIAL::operator++(int) { //z++
    POLYNOMIAL tmp(*this);
    operator++();
    return tmp;
}

POLYNOMIAL POLYNOMIAL::operator++() { //++z
    for (int i = 0; i < this->degree + 1; i++) {
        ++this->polynom[i];
    }
    this->shift();
    if (this->degree == 0 && this->polynom[0] == 0) return *this;
    this->GCD();
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator--(int) { //z--
    POLYNOMIAL tmp(*this);
    operator--();
    return tmp;
}

POLYNOMIAL POLYNOMIAL::operator*(const POLYNOMIAL &b) const {
    if ((this->degree == 0 && this->polynom[0] == 0) || (b.degree == 0 && b.polynom[0] == 0)) {
        POLYNOMIAL c;
        return c;
    }
    POLYNOMIAL c(this->degree + b.degree);
    delete[] c.polynom;
    c.polynom = new int[c.degree + 1];
    for (int i = 0; i < c.degree + 1; i++)
        c.polynom[i] = 0;

    for (int i = 0; i < this->degree + 1; i++) {
        for (int j = 0; j < b.degree + 1; j++)
            c.polynom[i + j] += this->polynom[i] * b.polynom[j];
    }

    c.shift();
    if (c.degree == 0 && c.polynom[0] == 0) return c;
    c.GCD();
    return c;
}

POLYNOMIAL POLYNOMIAL::operator--() { //--z
    for (int i = 0; i < this->degree + 1; i++) {
        --this->polynom[i];
    }
    this->shift();
    if (this->degree == 0 && this->polynom[0] == 0) return *this;
    this->GCD();
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator*=(const POLYNOMIAL &polynomial) {
    *this = *this * polynomial;
    return *this;
}

void *POLYNOMIAL::operator new(size_t amount) {
    overloaded++;
    return ::operator new(amount);
}

void POLYNOMIAL::operator delete(void *pointer) {
    overloaded--;
    ::operator delete(pointer);
}

POLYNOMIAL POLYNOMIAL::operator/=(const POLYNOMIAL &polynomial) {
    *this = *this / polynomial;
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator%=(const POLYNOMIAL &polynomial) {
    *this = *this % polynomial;
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator/(const POLYNOMIAL &polynomial) {
    if (polynomial.degree == 0 && polynomial.polynom[0] == 0) return POLYNOMIAL();
    if (this->degree < polynomial.degree) return POLYNOMIAL();
    if (*this == polynomial) return POLYNOMIAL(0, 1);
    if (polynomial.degree == 0 && polynomial.polynom[0] == -1) return *this * polynomial;
    if (polynomial.degree == 0 && polynomial.polynom[0] == -1) return *this;

    /*       numerator/denominator        */
    class FRACTION {
    public:
        int numerator;
        int denominator;

        void neg() {
            if (numerator < 0 && denominator < 0) {
                numerator *= -1;
                denominator *= -1;
                return;
            }
            if (numerator >= 0 && denominator < 0) {
                numerator *= -1;
                denominator *= -1;
                return;
            }
        }
    };

    /*    divident/divisor = quotient     */
    int divident_size = this->degree + 1;
    int divisor_size = polynomial.degree + 1;
    int quotient_size = this->degree - polynomial.degree + 1;

    FRACTION *divident = new FRACTION[divident_size];
    FRACTION *divisor = new FRACTION[divisor_size];
    FRACTION *quotient = new FRACTION[quotient_size];


    for (int i = 0; i < this->degree + 1; i++) {
        divident[i].numerator = this->polynom[this->degree - i];
        divident[i].denominator = 1;
    }

    for (int i = 0; i < polynomial.degree + 1; i++) {
        divisor[i].numerator = polynomial.polynom[polynomial.degree - i];
        divisor[i].denominator = 1;
    }

    int k = 0;

    while (k != quotient_size) {
        quotient[k].numerator = divident[k].numerator * divisor[0].denominator;
        quotient[k].denominator = divident[k].denominator * divisor[0].numerator;
        quotient[k].neg();

        FRACTION *temp_divisor = new FRACTION[divisor_size];

        for (int j = 0; j < divisor_size; j++) {
            temp_divisor[j].numerator = divisor[j].numerator * quotient[k].numerator;
            temp_divisor[j].denominator = divisor[j].denominator * quotient[k].denominator;
            temp_divisor[j].neg();
        }

        for (int j = 0; j < divident_size; j++) {
            divident[j].numerator *= quotient[0].denominator;
            divident[j].denominator *= quotient[0].denominator;
        }

        for (int i = 0; i < divisor_size; i++) {
            divident[k + i].numerator -= temp_divisor[i].numerator;
        }

        delete[] temp_divisor;
        k++;
    }

    int temp = divisor[0].numerator;
    int temp2 = divisor[0].numerator;
    if (temp2 < 0) temp2 *= -1;
    if (temp < 0) temp *= -1;


    for (int i = quotient_size - 2; i >= 0; i--) {
        quotient[i].numerator *= temp;
        quotient[i].denominator *= temp;
        temp *= temp2;
    }

    POLYNOMIAL c(this->degree - polynomial.degree);

    for (int i = 0; i < this->degree - polynomial.degree + 1; i++) {
        c.polynom[i] = quotient[this->degree - polynomial.degree - i].numerator;
    }

    delete[] divident;
    delete[] divisor;
    delete[] quotient;


    c.shift();
    if (c.degree == 0 && c.polynom[0] == 0) return c;
    c.GCD();
    return c;
}

POLYNOMIAL POLYNOMIAL::operator%(const POLYNOMIAL &polynomial) {
    if (polynomial.degree == 0 && polynomial.polynom[0] == 0) return POLYNOMIAL(*this);
    if (this->degree < polynomial.degree) return POLYNOMIAL(*this);
    if (*this == polynomial) return POLYNOMIAL();
    if (polynomial.degree == 0 && polynomial.polynom[0] == 0) return POLYNOMIAL();
    if (this->degree < polynomial.degree) return POLYNOMIAL();
    if (*this == polynomial) return POLYNOMIAL(0, 1);


    /*       numerator/denominator        */
    class FRACTION {
    public:
        int numerator;
        int denominator;

        void neg() {
            if (numerator < 0 && denominator < 0) {
                numerator *= -1;
                denominator *= -1;
                return;
            }
            if (numerator >= 0 && denominator < 0) {
                numerator *= -1;
                denominator *= -1;
                return;
            }
        }
    };

    /*    divident/divisor = quotient     */
    int divident_size = this->degree + 1;
    int divisor_size = polynomial.degree + 1;
    int quotient_size = this->degree - polynomial.degree + 1;

    FRACTION *divident = new FRACTION[divident_size];
    FRACTION *divisor = new FRACTION[divisor_size];
    FRACTION *quotient = new FRACTION[quotient_size];


    for (int i = 0; i < this->degree + 1; i++) {
        divident[i].numerator = this->polynom[this->degree - i];
        divident[i].denominator = 1;
    }

    for (int i = 0; i < polynomial.degree + 1; i++) {
        divisor[i].numerator = polynomial.polynom[polynomial.degree - i];
        divisor[i].denominator = 1;
    }

    int k = 0;

    while (k != quotient_size) {
        quotient[k].numerator = divident[k].numerator * divisor[0].denominator;
        quotient[k].denominator = divident[k].denominator * divisor[0].numerator;
        quotient[k].neg();


        FRACTION *temp_divisor = new FRACTION[divisor_size];

        for (int j = 0; j < divisor_size; j++) {
            temp_divisor[j].numerator = divisor[j].numerator * quotient[k].numerator;
            temp_divisor[j].denominator = divisor[j].denominator * quotient[k].denominator;
            temp_divisor[j].neg();
        }

        for (int j = 0; j < divident_size; j++) {
            divident[j].numerator *= quotient[0].denominator;
            divident[j].denominator *= quotient[0].denominator;
        }

        for (int i = 0; i < divisor_size; i++) {
            divident[k + i].numerator -= temp_divisor[i].numerator;
        }

        delete[] temp_divisor;
        k++;
    }

    POLYNOMIAL c(polynomial.degree - 1);

    int i = 0;
    while(c.degree + 1 != i) {
        c.polynom[i] = divident[divident_size - 1 - i].numerator;
        i++;
    }


    delete[] divident;
    delete[] divisor;
    delete[] quotient;


    c.shift();
    if (c.degree == 0 && c.polynom[0] == 0) return c;
    c.GCD();
    return c;
}