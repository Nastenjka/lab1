/*Виклик заголовного файлу стандартного модуля вводу-виводу.
* В коді використовуються такі функції: printf(), scanf().*/
#include <stdio.h>
/* Виклик заголовного файлу модуля математичних функцій.
 * В коді використовуються такі функції:  exp(), cos(), sqrt(), pow()*/
#include <math.h>

/*Для уникнення повторів код винесений у функції*/
int getParamsType(); // отримання 1 при default значеннях та 2 при введенні даних з клавіатури
void LinearCalculating(int paramsType); // розрахунок по заданих формулах, Task1
void IntervalCalculating(int paramsType);  //розрахунок інтервалу, Task2

/*Головна функція коду*/
int main() {
    int taskType = 0; // Оголошення змінної, яка відповідатиме за тип завдання (задані формули чи інтервал)

    /*Запитуємо користувача про вибір номеру завдання
     * Очікуваний результат: введення 1 або 2*/
    printf ("Hello! Let's choose which task to perform: \n");
    printf("(1) calculating x and y by formulas\n(2) calculating y in a loop\n");
    printf("Please, choose the number 1 or 2: ");
    scanf("%d", &taskType);

    /*якщо користувач обрав 1, то обчислюємо задані формули*/
    if (taskType == 1) {
        int paramsType = getParamsType(); // default значення чи введення з клавіатури
        LinearCalculating(paramsType); // Task1

    }
    /*якщо користувач обрав 2, то обчислюємо інтервал*/
    else if (taskType == 2) {
        int paramsType = getParamsType(); // default значення чи введення з клавіатури
        IntervalCalculating(paramsType); // Task2
    }
    else {
        /*якщо користувач обрав ні 1, ні 2*/
        printf("You have to choose only 1 or 2! Please, try again.\n");
    }
}
/*Кінець головного блоку коду*/

/* Функція для використання default значень або введення користувачем з клавіатури*/
int getParamsType() {
    int paramsType = 0; // Оголошення змінної, яка відповідатиме за тип значень (задані чи введенні з клавіатури)
    printf("Great!\nWhat values do you want to use?\n");
    printf("(1) use the specified values \n");
    printf("(2) enter these values from the keyboard\n");
    printf("Please, choose the number 1 or 2: ");
    scanf("%d", &paramsType);
    if (paramsType != 1 && paramsType !=2) {
        /*якщо користувач обрав ні 1, ні 2, то з'явиться повідомлення про помилку та прохання повторити спробу;
        * програма припиняє свою роботу, необхідно запустити її ще раз із правильним вибором типу значень (1 або 2)*/
        printf("You have to choose only 1 or 2! Try again.\n");
    }
    return paramsType; //отримуємо цілий тип значень (1 або 2)
}

/*Виконання Task1*/
void LinearCalculating(int paramsType) {
    double a = 0.0, b = 0.0, c = 0.0;

    if (paramsType == 1) {
        /*default значення*/
        a = 3.4;
        b = 1.1;
        c = 9;
    }
    else if (paramsType == 2) {
        /*Введення даних з клавіатури*/
        printf("Please, enter value for a: \n");
        scanf("%lf", &a);
        printf("Please, enter value for b:\n");
        printf("*Note that b will be used in the division, so it can not be 0*\n");
        scanf("%lf", &b);
        if (fabs(b) < 1e-9) {
            /*якщо число b близьке до нуля*/
            printf("You can't divide by zero. Try another value for b.\n");
            return;
        }
        printf("Please, enter value for c: \n");
        scanf("%lf", &c);
    }

    double x = a * exp(-b * c) * cos(b);
    double y = 0.315 * sqrt(a * pow(c, 3) / b);
    printf("The results of calculating are:\nX = %.5lf\nY = %.5lf", x, y);
    /*В результаті отримуємо виведення значень х та у*/
}

/* Функція для обчислення інтервалу за заданими параметрами */
void IntervalCalculating(int paramsType) {
    double a = 0.0, b = 0.0;
    double step_size = 0.0;
    int min_interval = 0;
    int max_interval = 0;
    const double pi = 3.14159265359;

    if (paramsType == 1) {
        /*default значення*/
        a = 2.8;
        b = 2 * pi;
        step_size = 0.2;
        min_interval = -1;
        max_interval = 1;
    }
    else if (paramsType == 2) {
        /*Введення даних з клавіатури*/
        printf("Please, enter value for a: \n");
        scanf("%lf", &a);
        printf("Please, enter value for b:\n");
        printf("*Note that b will be used in the division, so it can not be 0*\n");
        scanf("%lf", &b);
        /*якщо число b близьке до нуля*/
        if (fabs(b) < 1e-9) {
            printf("You can't divide by zero! Try another value\n");
            return;
        }
        printf("Please, enter value for step size: \n");
        scanf("%lf", &step_size);
        printf("Please, enter value for min element from interval (int): \n");
        scanf("%d", &min_interval);
        printf("Please, enter value for max element from interval (int): \n");
        scanf("%d", &max_interval);

        /*Якщо серед введених даних виявилось, що мінімальне число проміжку більше за максимальне, то програма припиняється*/
        if (min_interval > max_interval) {
            printf("The min element of interval can't be bigger than the max element!\n");
            return;
        }
    }
    /*Циклом проходимо через всі значення від -1 до 1 з кроком 0.2, обчислюємо, відповідно значенню х, у і виводимо їх*/
    for (double x = min_interval; x <= max_interval; x += step_size) {
        double y;
        if (x <= 0.4) {
            y = (a * x)/(1 + pow(x, 2)) + 1 / (1 + a * pow(x, 2));
            printf("X = %.5lf, Y = %.5lf\n", x, y);
        }
        else {
                y = (a * sin(b * x)) / (b * x);
                printf("X = %.5lf, Y = %.5lf\n", x, y);
            }
        }
    }
