#include <iostream>​

using namespace std; ​

char * PrintBasicOperation(int x, int y, char operation)​
{
    char* buffer = (char*)malloc(100 * sizeof(char));
    int result = 0; ​
    switch (operation)​
    { ​
        case '+':​
            result = x + y; ​
            break; ​
        case '-':​
            result = x - y; ​
            break; ​
        case '/':​
            result = x / y; ​
            break; ​
        case '*':​
            result = x * y; ​
            break; ​
        case '%':​
            result = x % y; ​
            break; ​
        case '<':​
            result = x << y; ​
            break; ​
    }​

    sprintf(buffer, "%d %c %d = %d\0", x, operation, y, result); ​

    return buffer; ​

}​;


int main()​
{
        int x = 5;

        int y = 7;

        std::cout << PrintBasicOperation(x, y, '+') << "\t"

        << PrintBasicOperation(x, y, '-') << "\t"

        << PrintBasicOperation(x, y, '*') << "\t"

        << PrintBasicOperation(y, x, '%') << "\t"

        << PrintBasicOperation(x, y, '/') << endl;

        printf("%s\t%s\t%s\t%s", PrintBasicOperation(x, y, '+'), PrintBasicOperation(x, y, '-'), PrintBasicOperation(x, y, '*'), PrintBasicOperation(x, y, '/')); ​
            printf("The sizeof(%s) is %d", typeid(T).name(), sizeof(T));
}