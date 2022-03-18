#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

double A1, B, C, X, Y, Z, U2;

int height = 10;
int weight = 40;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position = { 0, 0 };

enum { Nolb, FIRST_U, SECOND_U, THIRD_U};

//Рамка с 1 строкой снизу
void Frame1(int weight, int height);

//Рамка с 2 строками снизу
void Frame2(int weight, int height);

//Главный экран
void mainScreen(int height, int weight);

//Рабочий экран
void operationScreen(int height, int weight);

//Экран ошибки
void errorScreen(int height, int weight);

//Завершающий экран
void endScreen(int height, int weight);

//Поиск максимума минимума
double  find_max(double a, double b, double c);
double  find_min(double  a, double  b, double  c);

//Проверка, является ли введенное число типом инт
bool is_number(char number[]);
//Перевод из чар числа в инт число
int char_to_int(char number[]);
//Перевод цифры из чар в инт
int char_to_int(char number);
//Перевод из чара в дабл
double char_to_double(char number[]);
//Проверка является ли введенное число типом дабл
bool is_double(char number[]);
//Поиск областей к которым принадлежат x и y
int graphic(double  x, double  y);

//Поиск значения U
double find_U(int value_U, double x, double y, double z);
//Основная функция
void lifeCycle(double& a, double& b, double& c, double& x, double& y, double& z, double& U, int height_in_fun, int weight_in_fun);
//Вывод информации
void show_info(double _a, double _b, double _c, double _x, double _y, double _z, double _U, int graphic, int height_in_fun, int weight_in_fun);
//Ввод информации
void input_data(double& _a, double& _b, double& _c, int height_in_fun, int weight_in_fun);



/////////////////////////////////////////////////////////



int main(){
    setlocale(LC_ALL, "rus");

    lifeCycle(A1, B, C, X, Y, Z, U2, height, weight);

}



/////////////////////////////////////////////////////////



//Поиск минимума максимума
double  find_max(double a, double b, double c) {
    if (a == b && b == c) return a;
    if (a > b && a > c) return a;
    if (b > a && b > c) return b;
    if (c > a && c > b) return c;
}
double  find_min(double  a, double  b, double  c) {
    if (a == b && b == c) return a;
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    if (c < a && c < b) return c;
}

//Рамка с 1 строкой снизу
void Frame1(int weight, int height) {
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

    cout << "\n";

    for (int i = 0; i < height - 1; i++) {

        for (int j = 0; j <= weight; j++)
        {
            if (j == 0 || j == weight) cout << "|";
            else cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

    cout << "\n";

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j <= weight; j++) {
            if (j == 0 || j == weight)
                cout << "|";
            else
                cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

}

//Рамка с 2 строками снизу
void Frame2(int weight, int height) {
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

    cout << "\n";

    for (int i = 0; i < height - 1; i++) {

        bool i_is_not_a_second_third_fourth = (i == 2 || i == 3 || i == 4) ? 0 : 1;

        for (int j = 0; j <= weight; j++)
        {
            if (j == 0 || j == weight) cout << "|";
            else cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

    cout << "\n";

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= weight; j++) {
            if (j == 0 || j == weight)
                cout << "|";
            else
                cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

}

//Главный экран
void mainScreen(int height, int weight) {

    Frame1(weight, height);

    position = { 15, 3 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Программа";

    position = { 12, 4 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Область на графике";

    position = { 7, 5 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Рыбаков Павел Алексеевич";

    position = { 15, 6 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Гр. 1092";


    position = { 8 , 11 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Esc - Выход, Enter - Далее";

    position = { 0, 13 };
    SetConsoleCursorPosition(hConsole, position);
}

//Рабочий экран
void operationScreen(int height, int weight) {

    Frame1(weight, height);

    position = { 11, 4 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Введите А: ";

    position = { 11, 5 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Введите B: ";

    position = { 11, 6 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Введите C: ";

    position = { 14, 11 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Enter - Ввод";

    position = { 0, 12 };
    SetConsoleCursorPosition(hConsole, position);

}

//Экран ошибки
void errorScreen(int height, int weight) {

    system("cls");

    Frame2(weight, height);

    position = { 11, 4 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Введите А: ";

    position = { 11, 5 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Введите B: ";

    position = { 11, 6 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Введите C: ";

    position = { 8, 11 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Ошибка, попробуйте снова";

    position = { 7, 12 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Данные не соотв. ожидаемым";

    
}

//Экран ответа
void answerScreen(int height_in_fun, int weight_in_fun, double _a, double _b, double _c, double _x, double _y, double _z, double _U, int graphic) {

    system("cls");

    Frame1(height_in_fun, weight_in_fun);

    position = { 5, 1 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Значение A: " << _a;
    
    position = { 5, 2 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Значение B: " << _b;
    
    position = { 5, 3 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Значение C: " << _c;

    position = { 5, 4 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Значение X: " << _x;

    position = { 5, 5 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Значение Y: " << _y;

    position = { 5, 6 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Значение Z: " << _z;

    position = { 5, 7 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Значение U: " << _U;

    switch (graphic) {
    case 1: 
        position = { 5, 8 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Значения X и Y в области D1";
        break;
    case 2:
        position = { 5, 8 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Значения X и Y в области D2";
        break;
    case 3:
        position = { 5, 8 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Значения X и Y ни в 1 из областей";
        break;
    }

    position = { 7, 11 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Enter - Далее, Esc - Выход";
    


}

//Завершающий экран
void endScreen(int height, int weight) {

    Frame1(weight, height);

    position = { 16,3 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Программа";

    position = { 11,4 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Область на графике";

    position = { 10,5 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Завершила свою работу";

    position = { 13,11 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "До новых встреч";


    position = { 0, 13 };
    SetConsoleCursorPosition(hConsole, position);

}

//Ввод информации
void input_data(double& _a, double& _b, double& _c, int height_in_fun, int weight_in_fun) {
    char a[100];
    char b[100];
    char c[100];
    position = { 22, 4 };
    SetConsoleCursorPosition(hConsole, position);
    cin >> a;
    while (!is_double(a)) {

        system("cls");
        errorScreen(height_in_fun, weight_in_fun);
        position = { 22, 4 };
        SetConsoleCursorPosition(hConsole, position);
        cin >> a;
    }
    _a = char_to_double(a);

    position = { 22, 5 };
    SetConsoleCursorPosition(hConsole, position);
    cin >> b;
    while (!is_double(b)) {
        system("cls");

        errorScreen(height_in_fun, weight_in_fun);

        position = { 22, 4 };
        SetConsoleCursorPosition(hConsole, position);
        cout << char_to_double(a);

        position = { 22, 5 };
        SetConsoleCursorPosition(hConsole, position);
        cin >> b;
    }
    _b = char_to_double(b);

    position = { 22, 6 };
    SetConsoleCursorPosition(hConsole, position);
    cin >> c;
    while (!is_double(c)) {

        system("cls");

        errorScreen(height_in_fun, weight_in_fun);

        position = { 22, 4 };
        SetConsoleCursorPosition(hConsole, position);
        cout << _a;

        position = { 22, 5 };
        SetConsoleCursorPosition(hConsole, position);
        cout << _b;

        position = { 22, 6 };
        SetConsoleCursorPosition(hConsole, position);
        cin >> c;
    }
    _c = char_to_double(c);
}

//Проверка, является ли введенное число типом инт
bool is_number(char number[]) {
    for (int i = 0; i < 100; i++) {
        if ((char)number[i] != -52 && number[i] != '\0') {
            if (!((char)number[i] >= 48 && (char)number[i] <= 57 && number[i]))
                return false;
        }
        else
            return true;
    }
}
//Перевод из чар числа в инт число
int char_to_int(char number[]) {
    int number_of_digits = 0;

    for (int i = 0; number[i] != '\0'; i++) {
        if ((char)number[i] != -52) {
            number_of_digits++;
        }
    }

    if (number_of_digits == 1) {
        return ((char)(number[0] - 48));
    }
    if (number_of_digits == 2) {
        return ((char)(number[0] - 48) * 10 + (char)(number[1] - 48));
    }
    if (number_of_digits == 3) {
        return (((char)(number[0] - 48) * 100) + (((char)(number[1])) - 48) * 10 + (char)(number[2]) - 48);
    }
}

//Перевод цифры из чар в инт
int char_to_int(char number) {
    return ((char)(number - 48));
}

//Перевод из чара в дабл
double char_to_double(char number[]) {
    double sum = 0;
    int cnt_chisel_do_tochki = 0;
    int cnt_dot = 0;
    int drobnaya_chast = 1;
    bool is_int = true;

    //Поиск кол-ва точек
    for (int i = 0; number[i]; i++){
        if (number[i] == '.') cnt_dot++;
    }

    if (number[0] == '-') {
        //Поиск целой части до точки и запись в сумму
        /////////////////////////////////////////////
        for (int i = 0; is_int && number[i]; i++) {
            if (number[i] != '.' && number[i] != '-') cnt_chisel_do_tochki++;
            else if (number[i] == '-') { }
            else is_int = false;
        }
        for (int i = 0; i < cnt_chisel_do_tochki; i++) {
            if (number[i] == '-') { i++; cnt_chisel_do_tochki++; };
            double razryad = 1;

            for (int j = 0; j < cnt_chisel_do_tochki - i - 1; j++) {
                razryad *= 10;
            }

            sum += (double)char_to_int(number[i]) * razryad;
        }
        ////////////////////////////////////////////
    }
    else {
        for (int i = 0; is_int && number[i]; i++) {
            if (number[i] != '.') cnt_chisel_do_tochki++;
            else is_int = false;
        }
        for (int i = 0; i < cnt_chisel_do_tochki; i++) {
            int razryad = 1;

            for (int j = 0; j < cnt_chisel_do_tochki - i - 1; j++) {
                razryad *= 10;
            }

            sum += (double)char_to_int(number[i]) * razryad;
        }
    }

    

    //возврат целой части
    if (cnt_dot == 0) {
        if (number[0] == '-') return (sum - (sum * 2));
        else return sum;
    }
    else {
        if (cnt_dot == 1) {
            for (int i = cnt_chisel_do_tochki + 1; number[i]; i++) {
                sum += char_to_int(number[i]) / pow(10, i - cnt_chisel_do_tochki);
            }
        }
    }

    
    if (number[0] == '-') return (sum - (sum * 2));
    return sum;
}

//Проверка является ли введенное число типом дабл
bool is_double(char number[]) {
    int cnt_dot = 0;
    int cnt_numbers = 0;
    for (int i = 0; i < number[i]; i++){
        if ((char)number[i] >= 48 && (char)number[i] <= 57 && number[i]) cnt_numbers++;
    }
    for (int i = 0; number[i]; i++) {
        
        if (number[i] == '-') {
            i++;
            if (!((char)number[i] >= 48 && (char)number[i] <= 57 && number[i]) && number[i] != '.') return false;
        }
        else 
            if (!((char)number[i] >= 48 && (char)number[i] <= 57 && number[i]) && number[i] != '.') return false;

        if (number[i] == '.') cnt_dot++;
    }
    if (cnt_numbers == 0) return false;
    if (cnt_dot > 1) return false;
    return true;
}

//Поиск областей к которым принадлежат x и y
int graphic(double  x, double  y) {
    if ((y <= 1) && (y >= -2) && (x >= -3) && (x <= -2)) return FIRST_U;
    if ((pow(x, 2) + pow(y, 2)) <= 1) return SECOND_U;
    else
        if (((y > 1) && (y < -2) && (x < -3) && (x > -2)) || ((pow(x, 2) + pow(y, 2)) >= 1)) return THIRD_U;

}

//Поиск значения U
double find_U(int value_U, double x, double y, double z) {
    if (value_U == FIRST_U) return log10(abs(x + y));
    else if (value_U == SECOND_U) return x - y + z;
    else {
        if (value_U == THIRD_U) return 1;
    }
}

//Основная функция
void lifeCycle(double& a, double& b, double& c, double& x, double& y, double& z, double& U, int height_in_fun, int weight_in_fun) {

    bool life_cycle = true;
    char chose;

    mainScreen(height_in_fun, weight_in_fun);

    do {
        //ASCII "Esc" = 27, ASCII "Enter" = 13;

        life_cycle = ((chose = _getch()) == 27) ? 0 : 1;

        if (chose == 27) {
            life_cycle = false;
            system("cls");
        }
        else if (chose == 13) {
            system("cls");
            operationScreen(height_in_fun, weight_in_fun);
            input_data(a, b, c, height_in_fun, weight_in_fun);

            x = find_min(a + b, a + c, b + c);
            y = find_max(a, 2 * b, 3 * c);
            z = x / y;

            U = find_U(graphic(x, y), x, y, z);

            show_info(a, b, c, x, y, z, U, graphic(x, y), weight_in_fun, height_in_fun);

            cout << "\n\n";
        }
        else {
            system("cls");
            mainScreen(height_in_fun, weight_in_fun);
        }

    } while (life_cycle);

    endScreen(height_in_fun, weight_in_fun);

    cout << "\n\n\n";
}

//Вывод информации
void show_info(double _a, double _b, double _c, double _x, double _y, double _z, double _U, int graphic, int height_in_fun, int weight_in_fun) {
    system("cls");
    answerScreen(height_in_fun, weight_in_fun, _a, _b, _c, _x, _y, _z, _U, graphic);
}