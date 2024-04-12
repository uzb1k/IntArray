#include <iostream>
#include "IntArray.h"

int main()
{
    try {
        IntArray array(-5); //���������� ������ ������ � ������������� �������� ��� ��������
        cout << "Array constructed!!" << endl; 
    }
    catch (const bad_size& s) {
        cout << "Caught bad_size exception: " << s.what() << endl; //������ ������ ������, ��� ��� ������ �������������
    }

    IntArray array1(10);
    try {
        int value = array1[12]; //�������� �������� ������ � ��������������� �������� ������� ��� ��������
        cout << "Value: " << value << endl;
    }
    catch (const bad_index& i) {
        cout << "Caught bad_index exception: " << i.what() << endl; 
    }

    for (int i{ 0 }; i < 10; ++i) {  //��������� ������ ������� �� 1 �� 10
        array1[i] = i + 1;
    }

    try {
        array1.resize(-5); //���������� �������� �������� ������ ������� �� �������������
        cout << "Length changed!" << endl;
    }
    catch (const bad_size& s) {
        cout << "Caught bad_size exception: " << s.what() << endl;
    }

    cout << array1.getLength() << endl; //��������, ��� ������ ������� ����� �� ���������

    try {
        array1.insertBefore(33, 55); //���������� �������� �������� � ������ ����� �� ������� �� ����������
        cout << "New object added!" << endl;
    }
    catch (const bad_size& s) {
        cout << "Caught bad_index exception: " << s.what() << endl;
    }

    try {
        array1.remove(-10); //���������� �������� ������� ������� ������� ����������� �� ����������
        cout << "Item removed!" << endl;
    }

    catch (const bad_size& s) {
        cout << "Caught bad_index exception: " << s.what() << endl;
    }

    {
        IntArray b{ array1 }; //�������� ��� �������� ����������� ������ ��� �� ������
        b = array1;
        b = b;
        array1 = array1;
    }

    for (int i{ 0 }; i < array1.getLength(); ++i) { //������ ��������� ���� ��������� �������
        cout << array1[i] << ' ';
    }

    return 0;
}
