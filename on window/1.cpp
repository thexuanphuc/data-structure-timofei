/* Аргументы в функцию передаются по значению, т.е.
 * при вызове функции для хранения фактических переданных значений
 * создаются временные переменные - ячейки памяти на сегменте STACK.
 * После выхода из функции эти переменные уничтожаются.
 *
*/
#include <iostream>
struct phuc
{
    int a;
    int b;
};
phuc return_phuc(int x, int y)
{
    phuc result;
    result.a = x + 1;
    result.b = y + 1;
    return result;
}

void increment(int a) // При вызове появится переменная a с копией значения b.
{
    std::cout << a << '\n';
    a = a + 1;        // Значение a увеличится на 1.
    std::cout << a << '\n';
}                     // Однако, при выходе из функции переменная a уничтожится.

int main()
{
    using namespace std;
    int b = 3;
    
    increment(b);     // Здесь число 3 будет скопировано из b во временную a.
    cout << b << endl;   // Естественно, вызов функции inc(b) не изменил b.
    cout << return_phuc(9,6).a << endl;
    
    return 0;
}