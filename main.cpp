#include <vector>
#include <thread>
#include <mutex>
#include <cmath>
#include <iostream>
#include <algorithm>


void consoleClear()
{

    for (short i = 0; i < 10; i++)
    {
        std::cout << "\t\n"; 
    }
    
}


// перевод строки в переменные A B C
void variableRec(int &a, int &b, int &c, int &equal, std::string input)
{
    // переменные в строковм представлении, и позиции символов для поиска
    std::string subStrok[4] {};
    int pos1, pos2;
    
    // получение переменной A
    pos1 = input.find('y');
    subStrok[0] = input.substr(0,pos1);

    // получение переменной B
    pos1 = input.find('y') + 1;
    pos2 = input.find('x') - pos1;
    subStrok[1] = input.substr(pos1,pos2);

    // получение переменной C
    pos1 = input.find('x') + 1;
    pos2 = input.find('=') - pos1;
    subStrok[2] = input.substr(pos1,pos2);

    // получение переменной после равенства
    pos1 = input.find('=') + 1;
    subStrok[3] = input.substr(pos1);



    // если У без цифр, то он равен 1 или -1
    if(subStrok[0] == "")
    {
        subStrok[0] = "1";
    }
    if(subStrok[0] == "-")
    {
        subStrok[0] = "-1";
    }

    // если Х без цифр, то он равен 1 или -1
    if(subStrok[1] == "" || subStrok[1] == "+")
    {
        subStrok[1] = "1";
    }
    if(subStrok[1] == "-")
    {
        subStrok[1] = "-1";
    }


    // перевод строк в числа, и передача значений по ссылке в главную функцию
    a = std::stoi(subStrok[0]);
    b = std::stoi(subStrok[1]);
    c = std::stoi(subStrok[2]);
    equal = std::stoi(subStrok[3]);

}

// нахождение дескриминанта
void DescrimSearch(int a, int b, int c, int &Descrim)
{
    Descrim = (b * b) - 4 * a * c;

    if(Descrim < 0)
    {
        std::cout << "нельзя найти решение" << std::endl;
    }
}

// нахождение иксов
void xSearch(int a, int b, double &x1, double &x2, int Descrim)
{
    x1 = ( -b - std::sqrt(Descrim) ) / (2 * a);   
    x2 = ( -b + std::sqrt(Descrim) ) / (2 * a);

    std::cout << std::endl << "x1 = " << x1;
    std::cout << std::endl << "x2 = " << x2;
}

// проверка ответов
void xCheck(int a, int b, int c, double x1, double x2, int equal)
{
    int solutionX1 = (a * x1 * x1) + (b * x1) + c;
    int solutionX2 = (a * x2 * x2) + (b * x2) + c;

    std::cout << std::endl << std::endl << "Проведение проверок ";

    if(solutionX1 == equal)
    {
        std::cout << std::endl << "x1 правильное решение";
    }
    else
    {
        std::cout << std::endl << "x1 не правильное решение";
    }

    if(solutionX2 == equal)
    {
        std::cout << std::endl << "x2 правильное решение";
    }
    else
    {
        std::cout << std::endl << "x2 не правильное решение";
    }
}

int main()
{
    consoleClear();
    std::cout << "для удобства:  x ^ 2 = y;" << std::endl;
    std::cout << "пример:        y+10x-39=0" << std::endl;
    std::cout << "введите уравнение: ";

    int a = 0;
    int b = 0;
    int c = 0;
    int equal = 0;

    int Descrim = 0;
    double x1 = 0;
    double x2 = 0;

    // ввод уравнения
    std::string input {};
    std::cin >> input;

    // перенос численных значений в переменные
    // переделать метод, работает калечно
    variableRec(a,b,c,equal,input);

    // Нахождение дескриминанта
    DescrimSearch(a,b,c,Descrim);

    // нахождение иксов
    xSearch(a,b,x1,x2,Descrim);

    // проверка ответов
    xCheck(a,b,c,x1,x2,equal);

    // пауза после вывода ответов
    std::cout << std::endl << std::endl;
    system("pause");

    return 0;
}
