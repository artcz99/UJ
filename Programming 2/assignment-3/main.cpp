using namespace std;

string Clear(string str, int i = 1, string temp_str = "") {
    if (!(str[0] != '0' || i >= str.length())) {
        temp_str += str[i];
        i++;
        return Clear(str, i, temp_str);
    } else return str[0] == '0' ? temp_str : str;
}


string convert(string str, int i = 1, string temp_str = "") {
    if (str[0] != '-' || i >= str.length()) return str[0] == '-' ? temp_str : str;
    else {
        temp_str += str[i];
        i++;
        return convert(str, i, temp_str);
    }
}

string Algorithm(string str, int i) {
    if (str[str.length() - i] == '0') {
        str[str.length() - i] = '9';
        i++;
        return Algorithm(str, i);
    }
    str[str.length() - i]--;
    return str;
}

string Delete(string str, int i = 1, string temp_str = "") {
    if (i >= str.length()) return temp_str;
    temp_str += str[i];
    i++;
    return Delete(str, i, temp_str);
}

bool isNegative(string str) { return str[0] == '-'; }

bool isZero(string s, int i = 0, int zeroamount = 0) {
    if (s.length() > i) {
        if (s[i] != '0') {
            i++;
            return isZero(s, i, zeroamount);
        } else {
            zeroamount++;
            i++;
            return isZero(s, i, zeroamount);
        }
    }
    if (s[0] != '-' ? s[0] != '+' || zeroamount != s.length() - 1 : zeroamount != s.length() - 1) {
        if (s[0] != '-' ? zeroamount == s.length() : s[0] != '+' && zeroamount == s.length()) return true;
    } else return true;

    return false;
}

string Zero(string str, int n) {
    string temp_str = "0";
    temp_str += str;
    str = temp_str;
    n--;
    return n > 0 ? Zero(str, n) : str;
}



string AddUntil(string str, int index, string Output) {
    char ch = str[index];
    string temp_str = " ";
    temp_str[0] = ch;
    temp_str += Output;
    index--;
    Output = temp_str;
    return index >= 0 ? AddUntil(str, index, Output) : Output;
}

void DeleteUntil(string &a, string &b) {
    if (a[0] != b[0]) return;
    a = Delete(a);
    b = Delete(b);
    DeleteUntil(a, b);
}

string Remove(string str, int i = 0, string temp_str = "") {
    if (str[i] == '-' || str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' ||
        str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
        temp_str += str[i];
    i++;
    return i < str.length() ? Remove(str, i, temp_str) : temp_str;
}

string Translate(int a) {
    if (a == 0) return "0";
    if (a == 1) return "1";
    if (a == 2) return "2";
    if (a == 3) return "3";
    if (a == 4) return "4";
    if (a == 5) return "5";
    if (a == 6) return "6";
    if (a == 7) return "7";
    if (a == 8) return "8";
    if (a == 9) return "9";
    return "0";
}

string Addition(string a, string b, int i = 1, string Output = "", int next = 0) {
    int temp_sum = 0;
    string str;
    if (i <= a.length()) {
        if (next == 1) {
            if ((int) (a[a.length() - i] - 48) != 9) {
                a[a.length() - i]++;
            } else if ((int) (b[b.length() - i] - 48) == 9) {
                str = Translate(9);
                str += Output;
                Output = str;
                next = 1;
                i++;
                return Addition(a, b, i, Output, next);
            } else {
                a[a.length() - i]++;
            }
        }
        temp_sum = (int) (a[a.length() - i] - 48) + (int) (b[b.length() - i] - 48);
        next = temp_sum / 10;
        temp_sum %= 10;
        str = Translate(temp_sum);
        str += Output;
        Output = str;
        i++;
        return Addition(a, b, i, Output, next);
    } else return Output;
}

string Substract(string a, string b, int i = 1, string Output = "") {
    int difference = 0;
    string temp_str;
    if (i > b.length()) return Clear(AddUntil(a, a.length() - b.length() - 1, Output));
    difference = ((int) (a[a.length() - i] - 48) - (int) (b[b.length() - i] - 48));
    char ch;
    if (difference >= 0) {
        temp_str = Translate(difference);
        temp_str += Output;
        Output = temp_str;
        i++;
        return Substract(a, b, i, Output);
    } else {
        ch = a[a.length() - i];
        a[a.length() - i] = '!';
        a = Algorithm(a, i + 1);
        a[a.length() - i] = ch;
        int temp2 = 10;
        temp2 -= (int) (b[b.length() - i] - 48);
        temp2 += (int) (a[a.length() - i] - 48);
        temp_str = Translate(temp2);
        temp_str += Output;
        Output = temp_str;
        i++;
        return Substract(a, b, i, Output);
    }

}
bool Check(string a, string b, int i) {
    if ((int) (a[i] - 48) == (int) (b[i] - 48)) {
        i++;
        return Check(a, b, i);
    } else return (int) (a[i] - 48) <= (int) (b[i] - 48);
}

string substractHelp(string a, string b, int i = 0, const string &result = "") {
    if (a == b) {
        return "0";
    } else {
        if (a[0] == b[0])
            DeleteUntil(a, b);
        if ((int) (a[i] - 48) <= (int) (b[i] - 48)) {
            if (Check(a, b, i)) {
                string temp_str = a;
                a = b;
                b = temp_str;;
                return '-' + Substract(a, b);
            }
            return Substract(a, b);
        }
        return Substract(a, b);
    }
}

string ActualSum(string a, string b) {
    string temp_str;
    if (b.length() > a.length()) {
        temp_str = a;
        a = b;
        b = temp_str;
    }
    temp_str = "0";
    temp_str += a;
    a = temp_str;
    b = Zero(b, a.length() - b.length());
    temp_str = Addition(a, b);
    return Clear(temp_str);
}
string ClearZeros(string str, int i = 0, string Output = "", int check = 0) {
    if (isZero(str)) return "0";
    if (str == "0") return "0";
    if (str.length() < i) return Output;
    if (str[i] == '-') Output += str[i];
    if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' ||
        str[i] == '7' || str[i] == '8' || str[i] == '9') {
        check = 1;
        Output += str[i];
    }
    if (str[i] == '0' && check == 1) Output += str[i];
    i++;
    return ClearZeros(str, i, Output, check);
}

string Minus(string a, string b) {
    string str;
    string Minus = "-";
    string Output;
    if (isNegative(a)) {
        str = a;
        a = b;
        b = str;
    }
    b = convert(b);
    if (a.length() >= b.length()) return a.length() > b.length() ? Substract(a, b) : substractHelp(a, b);
    else {
        Output = Substract(b, a);
        Minus += Output;
        Output = Minus;
        return Output;
    }
}

string Sum_Function(int data, const string *array, string Output) {
    string temp_str;

    if (!isNegative(array[data - 1]) == !isNegative(Output)) {
        if (!isNegative(array[data - 1]) && !isNegative(Output))
            Output = ActualSum(ClearZeros(Output), ClearZeros(array[data - 1]));
        else {
            temp_str = "-";
            temp_str += ActualSum(ClearZeros(convert(Output)), ClearZeros(convert(array[data - 1])));
            Output = temp_str;
        }
    } else Output = Minus(ClearZeros(Output), ClearZeros(array[data - 1]));
    Output = ClearZeros(Remove(Output));
    data--;
    return data > 0 ? Sum_Function(data, array, Output) : Output;
}

void Sum(string *ptr, int data, const string *array) {
    string Output = "0";
    *ptr = Sum_Function(data, array, Output);
}

void Sum(string &s, int data, const string *array) {
    string Output = "0";
    s = Sum_Function(data, array, Output);
}

string Sum(int data, const string *array) {
    string Output = "0";
    return Sum_Function(data, array, Output);
}

string Sum_Help(const string &s, string Output) {
    string temp_str;
    if (!isNegative(s) == !isNegative(Output)) {
        if (isNegative(s)) {
            temp_str = "-";
            temp_str += ActualSum(ClearZeros(convert(Output)), ClearZeros(convert(s)));
            Output = temp_str;
        } else {
            if (!isNegative(Output)) Output = ActualSum(ClearZeros(Output), ClearZeros(s));
            else {
                temp_str = "-";
                temp_str += ActualSum(ClearZeros(convert(Output)), ClearZeros(convert(s)));
                Output = temp_str;
            }
        }
    } else Output = Minus(ClearZeros(Output), ClearZeros(s));
    Output = ClearZeros(Remove(Output));
    return Output;
}

void Input(va_list arguments, string &Output, int a, int i) {
    Output = Sum_Help((string) va_arg(arguments, char *), Output);
    i++;
    if (i < a) Input(arguments, Output, a, i);
}


string Sum(int a, ...) {
    string Output;
    int i = 0;
    va_list arguments;
    arguments = NULL;
    va_start(arguments, a);
    if (i < a) Input(arguments, Output, a, i);
    va_end(arguments);
    return Output;
}

void Sum(string *ptr, int a, ...) {
    string Output;
    int i = 0;
    va_list arguments;
    arguments = NULL;
    va_start(arguments, a);
    if (i < a) Input(arguments, Output, a, i);
    va_end(arguments);
    *ptr = Output;
}

void Sum(string &s, int a, ...) {
    string Output;
    va_list arguments;
    arguments = NULL;
    va_start(arguments, a);
    int i = 0;
    if (i < a) Input(arguments, Output, a, i);
    va_end(arguments);
    s = Output;
}

string Sum_help(int j, string a, string Output = "0") {
    if (j <= 0) return Output;
    Output = ActualSum(Output, a);
    return Sum_help(j - 1, a, Output);
}

string Multiplicate(string a, string b, int i, string Output = "") {
    int j = 0;
    j = (int) (b[i - 1] - 48);
    Output = Sum_help(j, a, Output);
    a += "0";
    i--;
    return i > 0 ? Multiplicate(a, b, i, Output) : Output;
}

string Mult_help(const string &s, string Output) {
    string temp_str;
    if (isZero(s) || isZero(Output)) return "0";
    if (!isNegative(s) != !isNegative(Output)) {
        temp_str = "-";
        temp_str += Multiplicate(ClearZeros(convert(Output)), ClearZeros(convert(s)), convert(ClearZeros(s)).length());
        Output = temp_str;
    } else Output = Multiplicate(ClearZeros(convert(Output)), ClearZeros(convert(s)), convert(ClearZeros(s)).length());

    Output = Remove(Output);
    return Output;
}

void readVA(va_list arguments, string &Output, int a, int i) {
    Output = Mult_help((string) va_arg(arguments, char *), Output);
    i++;
    if (i < a) readVA(arguments, Output, a, i);
}

string Mult(int a, ...) {
    string Output = "1";
    va_list arguments;
    arguments = NULL;
    va_start(arguments, a);
    int i = 0;
    if (i < a) readVA(arguments, Output, a, i);
    va_end(arguments);
    return Output;
}

void Mult(string *ptr, int a, ...) {
    string Output = "1";
    int i = 0;
    va_list arguments;
    arguments = NULL;
    va_start(arguments, a);
    if (i < a) readVA(arguments, Output, a, i);
    va_end(arguments);
    *ptr = Output;
}

void Mult(string &s, int a, ...) {
    string Output = "1";
    int i = 0;
    va_list arguments;
    arguments = NULL;
    va_start(arguments, a);
    if (i < a) readVA(arguments, Output, a, i);
    va_end(arguments);
    s = Output;
}
string Multiplication(int data, const string *array, string Output) {
    if (isZero(Output) || isZero(array[data - 1])) return "0";
    string str;
    if (Output == "0" || array[data - 1] == "0") return "0";
    if (!isNegative(array[data - 1]) != !isNegative(Output)) {
        str = "-";
        str += Multiplicate(ClearZeros(convert(Output)), ClearZeros(convert(array[data - 1])),
                            convert(ClearZeros(array[data - 1])).length());
        Output = str;
    } else
        Output = Multiplicate(ClearZeros(convert(Output)), ClearZeros(convert(array[data - 1])),
                              convert(ClearZeros(array[data - 1])).length());
    Output = Remove(Output);
    data--;
    return data > 0 ? Multiplication(data, array, Output) : Output;

}


string Mult(int data, const string *array) {

    string Output = "1";
    return Multiplication(data, array, Output);
}

void Mult(string *ptr, int data, const string *array) {
    string Output = "1";
    *ptr = Multiplication(data, array, Output);
}

void Mult(string &s, int data, const string *array) {
    string Output = "1";
    s = Multiplication(data, array, Output);
}

void va_to_array(va_list arguments, int a, string *array, int i) {
    if (i >= a) return;
    array[i] = (string) va_arg(arguments, char *);
    i++;
    va_to_array(arguments, a, array, i);
}

string Operation(string(*Procedure)(int, const string *), int data, const string *array) {
    return Procedure(data, array);
}

void Operation(string *ptr, string(*Procedure)(int, const string *), int data, const string *array) {
    *ptr = Procedure(data, array);
}

void Operation(string &s, string(*Procedure)(int, const string *), int data, const string *array) {
    s = Procedure(data, array);
}

string Operation(string(*Procedure)(int, const string *), int a, ...) {
    va_list arguments;
    va_start(arguments, a);
    string *array = new string[a];
    va_to_array(arguments, a, array, 0);
    string Output = Procedure(a, array);
    delete[] array;
    return Output;
}

void Operation(string *ptr, string(*Procedure)(int, const string *), int a, ...) {
    va_list arguments;
    va_start(arguments, a);
    string *array = new string[a];
    va_to_array(arguments, a, array, 0);
    string Output = Procedure(a, array);
    delete[] array;
    *ptr = Output;
}

void Operation(string &s, string(*Procedure)(int, const string *), int a, ...) {
    va_list arguments;
    va_start(arguments, a);
    string *array = new string[a];
    va_to_array(arguments, a, array, 0);
    string Output = Procedure(a, array);
    delete[] array;
    s = Output;
}