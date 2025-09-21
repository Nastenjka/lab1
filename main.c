/*Виклик головного модуля функцій введення-виведенння.
* В коді використовуються такі функції: printf(), scanf().*/
#include <stdio.h>
/* Виклик головного модуля математичних функцій.
 * В коді використовуються такі функції:  exp(), cos(), sqrt(), pow()*/
#include <math.h>

/*Щоб частина коду не повторювалась, а також для відділення окремих логічних частин, обчислення винесені в функції*/

int getParamsType(); // Функція для викристання default значень або введення користувачем з клавіатури
void defaultLinearCalculating(); // Функція для обчислення заданих формул за заданими параметрами
void userLinearCalculating();  // Функція для обчислення заданих формул за введеними з клавіатури параметрами
void defaultIntervalCalculating();  // Функція для обчислення інтервалу за заданими параметрами
void userIntervalCalculating(); // Функція для обчислення інтервалу за введеними з клавіатури параметрами

/*Головна функція коду*/
int main() {
    int taskType = 0; // Оголошення змінної, яка відповідатиме за тип завдання (задані формули чи інтервал)

    /*Запитуємо користувача, який тип завдання він хотів би бачити в консолі
     * Очікуваний результат: введення 1 або 2*/
    printf ("Hello! Firstly, let's choose which task to perform: \n");
    printf("(1) calculating x and y using the specified formulas\n");
    printf("(2) calculating y in a loop using different formulas depending on the value of x\n");
    printf("Please, choose the number 1 or 2: ");
    scanf("%d", &taskType);

    /*якщо користувач обрав 1, то виконуватиметься код для обчислення за заданими формулами*/
    if (taskType == 1) {
        int paramsType = getParamsType(); //запитуємо користувача про вибір числа 1 чи 2
        /*отримуємо число 1, якщо користувач обрав задані дані,
        або отримуємо число 2, якщо користувач хоче ввести дані самостійно*/
        if (paramsType == 1) {
            defaultLinearCalculating(); /*якщо користувач обрав 1, то викликається функція, яка обчислить результат
            за заданими форумалми та параметрами*/
        }
        else if (paramsType == 2) {
            userLinearCalculating(); /*якщо користувач обрав 2, то викликається функція, яка обчислить результат
            за заданими формулами, але з параметрами, які ввів користувач*/
        }
        else {
            /*якщо користувач обрав ні 1, ні 2, то з'явиться повідомлення про помилку та прохання повторити спробу;
            * програма припиняє свою роботу, необхідно запустити її ще раз із правильним вибором типу значень (1 або 2)*/
            printf("You have to choose only 1 or 2! Try again.\n");
        }
    }

    /*якщо користувач обрав 2, то виконуватиметься код для обчислення інтервалу*/
    else if (taskType == 2) {
        int paramsType = getParamsType(); //запитуємо користувача про вибір числа 1 чи 2
        /*отримуємо число 1, якщо користувач обрав задані дані,
        або отримуємо число 2, якщо користувач хоче ввести дані самостійно*/

        if (paramsType == 1) {
            defaultIntervalCalculating(); /*якщо користувач обрав 1, то викликається функція, яка обчислить результат
            за заданими параметрами в інтервалі*/
        }
        else if (paramsType == 2) {
            userIntervalCalculating(); /*якщо користувач обрав 2, то викликається функція, яка обчислить результат
            за введеними з клавіатури користувачем параметрами в інтервалі*/
        }
        else {
            /*якщо користувач обрав ні 1, ні 2, то з'явиться повідомлення про помилку та прохання повторити спробу;
            * програма припиняє свою роботу, необхідно запустити її ще раз із правильним вибором типу значень (1 або 2)*/
            printf("You have to choose only 1 or 2! Try again.\n");
        }
    }
    else {
        /*якщо користувач обрав ні 1, ні 2, то з'явиться повідомлення про помилку та прохання повторити спробу;
        * програма припиняє свою роботу, необхідно запустити її ще раз із правильним вибором типу завдання (1 або 2)*/
        printf("You have to choose only 1 or 2! Please, try again.\n");
    }
} /*Кінець головного блоку коду*/

/* Функція для викристання default значень або введення користувачем з клавіатури*/
int getParamsType() {
    int paramsType = 0; // Оголошення змінної, яка відповідатиме за тип значень (задані чи введенні з клавіатури)
    printf("Great!\n");
    printf("What values do you want to use?\n");
    printf("(1) use the specified values of the calculation parameters\n");
    printf("(2) enter these values from the keyboard\n");
    printf("Plase, choose the number 1 or 2: ");
    scanf("%d", &paramsType);
    return paramsType; //отримуємо цілий тип значень (1 або 2)
}

/* Функція для обчислення заданих формул за заданими параметрами*/
void defaultLinearCalculating() {
    const double A = 3.4;
    const double B = 1.1;
    const double C = 9;

    double x = A * exp(-B * C) * cos(B);
    double y = 0.315 * sqrt(A * pow(C, 3) / B);

    printf("The results of calculating are:\nX = %.5lf\nY = %.5lf", x, y);
    /*В результаті отримуємо виведення значень х та у*/
}

/*Функція для обчислення заданих формул за введеними з клавіатури параметрами*/
void userLinearCalculating() {
    double a = 0.0, b = 0.0, c = 0.0;
    /* Просимо ввести користувача необхідні дані*/
    printf("Please, enter value for a: \n");
    scanf("%lf", &a);
    printf("Please, enter value for b:\n");
    printf("*Note that b will be used in the division, so it can not be 0*\n");
    scanf("%lf", &b);
    printf("Please, enter value for c: \n");
    scanf("%lf", &c);

    /* Оскільки у формулі потрібно поділити на b, то необхідно, щоб це число не було нулем.
     * Проте через похибки обчислень в мові С нам необхідно перевірити, чи є b меншим, ніж
     * число 1e-9, яке настільки мале, що ми можемо ставитись до нього як до нуля.
     * Оскільки число b може бути від'ємним, нам необхідно взяти його модуль, щоб запобігти будь-яким помилкам.*/

    if (fabs(b) < 1e-9) {
        /*якщо число b близьке до нуля, то з'явиться повідомлення про помилку та прохання повторити спробу.*/
        printf("You can't divide by zero. Try another value for b.\n");
    }
    else {
        double x = a * exp(-b * c) * cos(b);
        double y = 0.315 * sqrt(a * pow(c, 3) / b);
        printf("The results of calculating are:\nX = %.5lf\nY = %.5lf", x, y);
        /*В результаті отримуємо виведення значень х та у*/
    }
}

/* Функція для обчислення інтервалу за заданими параметрами */
void defaultIntervalCalculating() {
    const double A = 2.8;
    const double PI = 3.14159265359;
    const double B = 2 * PI;
    const double STEP_SIZE = 0.2;
    const int MIN_INTERVAL = -1;
    const int MAX_INTERVAL = 1;

    /*Циклом проходимо через всі значення від -1 до 1 з кроком 0.2, обчислюємо, відповідно значенню х, у і виводимо їх*/
    for (double x = MIN_INTERVAL; x <= MAX_INTERVAL; x += STEP_SIZE) {
        double y;
        if (x <= 0.4) {
            y = (A * x)/(1 + pow(x, 2)) + 1 / (1 + A * pow(x, 2));
            printf("X = %.5lf, Y = %.5lf\n", x, y);
        }
        else {
            y = (A * sin(B * x)) / (B * x);
            printf("X = %.5lf, Y = %.5lf\n", x, y);
        }
    }
}

/* Функція для обчислення інтервалу за введеними з клавіатури параметрами*/
void userIntervalCalculating() {
    double a = 0.0, b = 0.0;
    double step_size = 0.0;
    int min_interval = 0;
    int max_interval = 0;

    /* Просимо ввести користувача необхідні дані*/
    printf("Please, enter value for a: \n");
    scanf("%lf", &a);
    printf("Please, enter value for b:\n");
    printf("*Note that b will be used in the division, so it can not be 0*\n");
    scanf("%lf", &b);
    printf("Please, enter value for step size: \n");
    scanf("%lf", &step_size);
    printf("Please, enter value for min element from interval (int): \n");
    scanf("%d", &min_interval);
    printf("Please, enter value for max element from interval (int): \n");
    scanf("%d", &max_interval);

    /*Якщо серед введених даних виявилось, що мінімальне числ опроміжку більше за максимальне, то програма припиняється*/
    if (min_interval > max_interval) {
        printf("The min element of interval can't be bigger than the max element!\n");
        return;
    }
    /*Циклом проходимо через всі значення від мінімального до максимального числа з певним кроком,
     *обчислюємо, відповідно значенню х, у і виводимо їх*/
    for (double x = min_interval; x <= max_interval; x += step_size) {
        double y;
        if (x <= 0.4) {
            y = (a * x)/(1 + pow(x, 2)) + 1 / (1 + a * pow(x, 2));
            printf("X = %.5lf, Y = %.5lf\n", x, y);
        }
        else {
            /*якщо добуток числа b та х близьке до нуля, то з'явиться повідомлення про помилку та прохання повторити спробу.*/
            if (fabs(b * x) < 1e-9) {
                printf("You can't divide by zero! Try another value\n");
                return;
            }
            else {
                y = (a * sin(b * x)) / (b * x);
                printf("X = %.5lf, Y = %.5lf\n", x, y);
            }
        }
    }
}
