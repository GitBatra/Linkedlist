#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int main()
{
    int hr, min, sec;
    cout << "=============" << endl;
    cout << "ENTER TIME : ";
    cin >> hr >> min >> sec;

    if (hr > 12 || min > 60 || sec > 60)
    {
        cout << "[ERROR!!!!]  ENTER VALID TIME" << endl;
        exit(0);
    }

    while (true)
    {
        system("cls");
        cout << "\t**************\n";
        cout << "\t" << hr << " : " << min << " : " << sec << endl;
        cout << "\t**************\n";
        sec++;
        if (sec == 60)
        {
            min++;
            sec = 0;
            if (min == 60)
            {
                hr++;
                min = 0;
                if (hr > 12)
                {
                    hr = 1;
                }
            }
        }
        sleep(1);
    }
    return 0;
}