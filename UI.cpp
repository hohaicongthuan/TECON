#include <iostream>

using namespace std;

void first_ui(int);
void second_ui(int);

void first_ui(int)
{
    //hàng đầu tiên
    cout << char(201);
    for(int i = 1; i <= 41; ++i)
        cout << char(205);
    cout << char(187) << endl;

    //hàng thứ 1
    cout << char(186);
    for(int i = 1; i <= 40; ++i)
        cout << " ";
    cout << " " << char(186) << endl;

    //hang thứ 2 (hàng chữ thứ 1)
    cout << char(186);
    cout << " " << " " << " ";
    cout << char(201) << char(205) << char(203) << char(205) << char(187) << " "; //T
    cout << char(201) << char(205) << char(205) << char(205) << char(187) << " "; //E
    cout << char(201) << char(205) << char(203) << char(205) << char(187) << " "; //T
    cout << char(201) << char(205) << char(205) << char(205) << char(187) << " "; //R
    cout << " " << char(203) << " " << " ";                                       //I
    cout << char(201) << char(205) << char(205) << char(205) << char(187) << " "; //S
    cout << " " << " " << " " << " ";
    cout << char(186) << endl;

    // hàng thứ 3 (hàng chữ thứ 2)
    cout << char(186);
    cout << " " << " " << " ";
    cout << " " << " " << char(186) << " " << " " << " "; //T
    cout << char(186) << " " << " " << " " << " " << " "; //E
    cout << " " << " " << char(186) << " " << " " << " "; //T
    cout << char(186) << " " << " " << " " << char(186) << " "; //R
    cout << " " << char(186) << " " << " "; // I
    cout << char(186) << " " << " " << " " << " " << " "; //S
    cout << " " << " " << " " << " ";
    cout << char(186) << endl;

    // hàng thứ 4 (hàng chữ thứ 3)
    cout << char(186);
    cout << " " << " " << " ";
    cout << " " << " " << char(186) << " " << " " << " "; //T
    cout << char(204) << char(205) << char(205) << char(205) << char(185) << " "; //E
    cout << " " << " " << char(186) << " " << " " << " "; //T
    cout << char(204) << char(205) << char(203) << char(205) << char(188) << " "; //R
    cout << " " << char(186) << " " << " "; // I
    cout << char(200) << char(205) << char(205) << char(205) << char(187) << " "; //S
    cout << " " << " " << " " << " ";
    cout << char(186) << endl;

    //hàng thứ 5 (hàng chữ thứ 4)
    cout << char(186);
    cout << " " << " " << " ";
    cout << " " << " " << char(186) << " " << " " << " "; //T
    cout << char(186) << " " << " " << " " << " " << " "; //E
    cout << " " << " " << char(186) << " " << " " << " "; //T
    cout << char(186) << " " << char(186) << " " << " " << " "; //R
    cout << " " << char(186) << " " << " "; // I
    cout << " " << " " << " " << " " << char(186) << " "; //S
    cout << " " << " " << " " << " ";
    cout << char(186) << endl;

    //hàng thứ 6(hàng chữ thứ 5)
    cout << char(186);
    cout << " " << " " << " ";
    cout << " " << " " << char(202) << " " << " " << " "; //T
    cout << char(200) << char(205) << char(205) << char(205) << char(188) << " "; //E
    cout << " " << " " << char(202) << " " << " " << " "; //T
    cout << char(200) << " " << char(200) << char(205) << char(188) << " "; //R
    cout << " " << char(202) << " " << " "; // I
    cout << char(200) << char(205) << char(205) << char(205) << char(188) << " "; //S
    cout << " " << " " << " " << " ";
    cout << char(186) << endl;

    //hàng thứ 7 đến hàng thứ 14 (7 hàng)
    for(int j = 1; j <= 8; ++j)
        {
            cout << char(186);
            for(int i = 1; i <= 40; ++i)
                cout << " ";
            cout << " " << char(186) << endl;
        }
    //hàng thứ 15
    cout << char(186);
    cout << " " << " " << " " << " " << " " << " " << " ";
    cout << "Press any key to continue";
    cout << " " << " " << " " << " " << " " << " " << " " << " ";
    cout << " " << char(186) << endl;

    //hàng thứ 16 đến hàng thứ 20 (5 hàng)
    for(int j = 1; j <= 5; ++j)
        {
            cout << char(186);
            for(int i = 1; i <= 40; ++i)
                cout << " ";
            cout << " " << char(186) << endl;
        }

    //hàng cuối cùng
    cout << char(200);
    for(int i = 1; i <= 41; ++i)
        cout << char(205);
    cout << char(188) << endl;
}

void second_ui(int)
{
    //hàng đầu tiên
    cout << char(201);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(203);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(187) << endl;

    //hàng thứ 2 đến hàng thứ 19
    for(int j = 1; j <= 20; ++j)
    {
        cout << char(186);
        for(int i = 1; i <= 20; ++i)
            cout << " ";
        cout << char(186);
        for(int i = 1; i <= 20; ++i)
            cout << " ";
        cout << char(186) << endl;
    }

    //hàng cuối cùng
    cout << char(200);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(202);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(188) << endl;
}

int main()
{
    first_ui(1);
    return 0;
}
