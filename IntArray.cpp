#include <iostream>
#include "IntArray.h"

int main()
{
    try {
        IntArray array(-5); //Специально создаём массив с отрицательным размером для проверки
        cout << "Array constructed!!" << endl; 
    }
    catch (const bad_size& s) {
        cout << "Caught bad_size exception: " << s.what() << endl; //Выдаст данную ошибку, так как размер отрицательный
    }

    IntArray array1(10);
    try {
        int value = array1[12]; //Пытаемся получить доступ к несуществующему элементу массива для проверки
        cout << "Value: " << value << endl;
    }
    catch (const bad_index& i) {
        cout << "Caught bad_index exception: " << i.what() << endl; 
    }

    for (int i{ 0 }; i < 10; ++i) {  //Заполняем массив числами от 1 до 10
        array1[i] = i + 1;
    }

    try {
        array1.resize(-5); //Специально пытаемся поменять размер массива на отрицательный
        cout << "Length changed!" << endl;
    }
    catch (const bad_size& s) {
        cout << "Caught bad_size exception: " << s.what() << endl;
    }

    cout << array1.getLength() << endl; //Проверим, что размер массива никак не изменился

    try {
        array1.insertBefore(33, 55); //Специально пытаемся закинуть в массив число на позицию за диапозоном
        cout << "New object added!" << endl;
    }
    catch (const bad_size& s) {
        cout << "Caught bad_index exception: " << s.what() << endl;
    }

    try {
        array1.remove(-10); //Специально пытаемся удалить элемент массива находящимся за диапозоном
        cout << "Item removed!" << endl;
    }

    catch (const bad_size& s) {
        cout << "Caught bad_index exception: " << s.what() << endl;
    }

    {
        IntArray b{ array1 }; //Проверка что процессы копирования ничего нам не ломают
        b = array1;
        b = b;
        array1 = array1;
    }

    for (int i{ 0 }; i < array1.getLength(); ++i) { //Просто выведение всех элементов массива
        cout << array1[i] << ' ';
    }

    return 0;
}
