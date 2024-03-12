#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;

void DecToBinary (int *array, int n, int value, int *ret) {
    int *bit = new int[n];
    // int bit[8];
    int j1 = 0;
    int tmp;
    for (int i = 0; i < value; i++) {
        tmp = *(array + i);
        for (int j = 0; j < n; j++) {
            *(bit + j) = tmp % 2;
            tmp /= 2;
        }
        for (int j = n - 1; j >= 0; j--, j1++) {
            *(ret + j1) = *(bit + j);
        }
    }
    delete[] bit;
}

void BinaryToDec (int *array, int *ret6, int n, int value) {
    int ccc = 0;
    for (int i = 0; i < value / n; i++) {
        for (int j = n - 1; j >= 0; j--, ccc++) {
            array[i] += ret6[ccc] * pow(2, j);
        }
    }
}
int main () {
    setlocale (LC_ALL, "Russian");
    
    char mass[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int *K;
    char *key;
    int *ret;
    int *ret6;
    int *ret8;
    int *sobr;
    int *sobr1;
    int *arrayInput0;
    int *arrayInput2;
    char *arrayInput1;

    ifstream fi;
    ofstream fo;

    const int N = 256;
    int S[N];
    char T[N];

    char s;
    int key_number;
    int g0;
    int i0, j0;
    int g1;
    int jj;
    int count;
    int g0b;
    int vv;

    cout << "RC4" << endl << "Выберите операцию" << endl;
    cout << "Отменить - 0/ Зашифровать - 1/ Расшифровать - 2: ";
    cin >> vv;
    if (vv == 0) return 0;
    cout << "RC4" << endl << "Введите колличество символов в ключе: " << endl;
    cin >> key_number;

    key = new char[key_number];
    cout << "Введите ключ: " << endl;
    cin >> key;

    // подсчёт символов в файле
    {
        g0 = 0;
        fi.open ("input.txt");
            while (!fi.eof ()) {
                fi.get (s);
                if (!fi.eof ()) {
                    g0++;
                }
            }
        fi.close ();
    }
    // запись в массив коды аски
    {
        if (vv == 1) arrayInput0 = new int[g0];
        if (vv == 2) arrayInput1 = new char[g0];
        fi.open ("input.txt");
            for (int i = 0; i < g0; i++) {
                fi.get (s);
                if (vv == 1) arrayInput0[i] = (unsigned int)s;
                if (vv == 2) arrayInput1[i] = s;
            }
        fi.close ();
    }
    // создание "эс" - блока
    {
        for (int i = 0; i < 256; i++) {
            S[i] = i;
            T[i] = key[i % key_number];
        }
        delete[] key;
        jj = 0;
        for (int i = 0; i < 256; i++) {
            jj = ( jj + S[i] + T[i] ) % 256;
            swap (S[i], S[jj]);
        }
    }
    // генерация псевдо-случайной ключевой последовательности
    {
        i0 = 0;
        j0 = 0;
        g1 = g0;
        count = 0;
        K = new int[g0];
        while (g1 > 0) {
            i0 = (i0 + 1) % 256;
            j0 = (j0 + S[i0]) % 256;
            swap (S[i0], S[j0]);
            K[count] = S[ (S[i0] + S[j0]) % 256]; 
            g1--;
            count++;
        }
    }
    if (vv == 1) {
        // xor
        {
            for (int i = 0; i < g0; i++) {
                arrayInput0[i] ^= K[i];
                cout << (arrayInput0[i]) << endl;
            }
            delete[] K;
        }
        // binary
        {
            ret = new int[g0 * 8];
            DecToBinary(arrayInput0, 8, g0, ret);
            delete[] arrayInput0; 
        
            if ((g0 * 8) % 6 != 0) g0b = g0*8 + 6 - (g0*8 + 6) % 6;
            else g0b = g0 * 8;

            ret6 = new int[g0b];
            for (int i = 0; i < g0b; i++) {
                ret6[i] = 0;
            }
            for (int i = 0; i < g0 * 8; i++) {
                ret6[i] = ret[i];
            }

            delete[] ret;
            cout << endl;
        }
        // переход в десятичную систему счисления из двоичной которая меньше 2^6
        {
            sobr = new int[g0b/ 6];
            for (int i = 0; i < g0b / 6; i++) sobr[i] = 0;
            BinaryToDec (sobr, ret6, 6, g0b);

            for (int i = 0; i < g0b / 6; i++) {
                cout << sobr[i] << endl;
            }
            delete[] ret6;
        }
        // собирание в символы base64
        {
            fo.open ("input.txt");
                for (int i = 0; i < g0b / 6; i++) {
                    fo << mass[sobr[i]];
                }
            fo.close ();
            delete[] sobr;
        }
    } else if (vv == 2) {
        // считывание кодов символов по base64
        {
            arrayInput2 = new int[g0]; // Выделяем память индексы символов по base64
            fi.open ("input.txt");
                for (int i = 0; i < g0; i++) {
                    for (int j = 0; j < 64; j++) {
                        if (mass[j] == arrayInput1[i]) {
                            arrayInput2[i] = j;
                            cout << arrayInput2[i] << endl;
                        }
                    }
                }
            fi.close();
            delete[] arrayInput1;
        }

        // dec -> binary
        {
						std::cout<<std::endl;

            ret = new int[g0 * 6];
            DecToBinary (arrayInput2, 6, g0, ret);
            for (int i = 0; i < g0 * 6; i++) {
                if (i % 6 == 0) cout << endl;
                cout << ret[i];
            }
        
            if ( (g0 * 6) % 8 != 0) {
                g0b = (g0 * 6) - (g0 * 6) % 8;
            } else {
                g0b = (g0 * 6);
            }
            cout << endl << g0 << endl;
            cout << g0b << endl;
            ret8 = new int[g0b];
            for (int i = 0; i < g0b; i++) {
                ret8[i] = ret[i];
            }
            cout << endl;
            for (int i = 0; i < g0b; i++) {
                if (i % 8 == 0) cout << endl;
                cout << ret8[i]; 
            }
						std::cout << std::endl;
            delete[] ret;
            delete[] arrayInput2;
        }

        // binary -> dec
        {
            sobr1 = new int[g0b / 8];
            for (int i = 0; i < g0b / 8; i++) {
                sobr1[i] = 0;
            }
            cout << endl;
            BinaryToDec (sobr1, ret8, 8, g0b);
            for (int i = 0; i < g0b / 8; i++) {
                cout << sobr1[i] << endl; 
            }
        }

        // xor => переход в текстовый режим => запись
        {
            fo.open ("input.txt");
                for (int i = 0; i < g0b / 8; i++) {
                    sobr1[i] ^= K[i];
                    cout << (unsigned char)(sobr1[i]);
                    fo << (unsigned char)(sobr1[i]);
                }
                delete[] K;
                delete[] ret8;
                delete[] sobr1;
                cout << endl;
            fo.close ();
        }
    }

    cout << endl;
    return 0;
}
