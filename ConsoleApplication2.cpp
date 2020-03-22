//Selen Nazlı Başa
/*Zıp zıp kurbağa bir nehri karşıdan karşıya geçmek istemektedir. Nehrin iki kenarı arasında N adet taş vardır. Kurbağa
sadece ileri doğru ve tek bir seferde rastgele olarak 1, 2 veya 3 sonraki taşa zıplamaktadır. N adet taş verildiğinde nehrin
bir kenarından diğer kenarına kaç farklı şekilde ulaşabileceği bulmaya yarayan bir programdır:)
*/



#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;

#define _TEST_ITERATIVE_
#define _TEST_RECURSIVE_

//recursive function
//ilk 3 durum icin degerleri kendimiz dondurduk
//30 dan sonra yavaslamaya baslar
//yavaslamasinin nedeni cagirmasi gereken fonksiyonların artiyor olmasidir
long long recursiveFunction(int n)
{
    if ((n <= 1) || (n == 2)) {
        return(n);
    }
    else if (n == 3) {
        return n + 1; 
    }
    else {
        return(recursiveFunction(n - 1) + recursiveFunction(n - 2) + recursiveFunction(n - 3));
    }
}

//iterative funtion
long long iterativeFunction(int n)
{

    double i = 0, i2 = 0, i3 = 1, sum;

    if (n == 0) {
        return 0;

    }
    else if (n == 1) {
        return 1;
    }
    else {
        for (int c = 0;c < n;c++)
        {
            sum = i + i2 + i3;
            i = i2;
            i2 = i3;
            i3 = sum;

        }
    }
    return sum;

}



int main()
{
    const int MAX_NUMBER_OF_STONES{ 72 };

    cout << setfill(' ');

    cout.imbue(locale(""));

    for (auto i = 1; i <= MAX_NUMBER_OF_STONES; ++i)
    {

#ifdef _TEST_ITERATIVE_
        {
            long long tempResult = { 0 };

            auto start = std::chrono::steady_clock::now();
            tempResult = iterativeFunction(i);
            auto stop = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();


            cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
        }
#endif

#ifdef _TEST_RECURSIVE_
        {
            long long tempResult = { 0 };

            auto start = std::chrono::steady_clock::now();
            tempResult = recursiveFunction(i);
            auto stop = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

            cout << "recursive" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n\n";
        }
#endif

    }

    return 0;
}
