#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main () {
    setlocale(LC_ALL, "Russian");
    cout << "Зашифровать - 1" << endl;
    cout << "Расшифровать - 2" << endl;

    char mass[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int yyyy;
    char s;
    int g1;
    int g3;
    int e1 = 0;
    int j1;
    int tmp;
    int g2;
    int ccc;
	ifstream fi;
	ofstream fo;
	cin >> yyyy;
	if (yyyy == 1) {
	    fi.open ("input.txt");
	    g1 = 0;
	    while (!fi.eof()) {
	        fi.get(s);
	        if (!fi.eof()) {
	            g1++;
	        }
	    }
	    fi.close();
	    int *InputArray = new int[g1];
	    fi.open("input.txt");
	    for (int i = 0; i < g1; i++) {
	        fi.get(s);
	        InputArray[i] = (unsigned int)s;
	        // cout << InputArray[i] << endl;
	    }
	    fi.close();

	    int Bit8[8];
	    int *InputArrayBin = new int[8 * g1];
	    j1 = 0;
	    for (int i = 0; i < g1; i++) {
	    	tmp = InputArray[i];
	    	for (int j = 0; j < 8; j++) {
	    		Bit8[j] = tmp % 2;
	    		tmp /= 2;
	    	}
	    	for (int j = 7; j >= 0; j--, j1++) {
	    		InputArrayBin[j1] = Bit8[j];
	    	}
	    }
	    delete[] InputArray;

	    if ((g1 * 8) % 6 != 0) g2 = g1*8 + 6 - (g1*8 + 6) % 6;
	    else g2 = g1 * 8;
	    
	    int *ArrayBit6 = new int[g2];
	    for (int i = 0; i < g2; i++) {
	    	ArrayBit6[i] = 0;
	    }
	    for (int i = 0; i < g2; i++) {
	    	ArrayBit6[i] = InputArrayBin[i];
	    }
	    delete[] InputArrayBin;
	    int *arrayE = new int[g2 / 6];
	    ccc = 0;
	    for (int i = 0; i < g2 / 6; i++) arrayE[i] = 0;
	    for (int i = 0; i < g2 / 6; i++) {
	    
	    	for (int j = 5; j >= 0; j--, ccc++) {
	    		arrayE[i] += ArrayBit6[ccc] * pow(2, j);
	    	}
	    }
	    delete[] ArrayBit6;
	    fo.open("input.txt");
	    for (int i = 0; i < g2 / 6; i++) {
	    	cout << mass[arrayE[i]];
	    	fo << mass[arrayE[i]];
	    }
	    cout << endl;
	    fo.close();	    
	    delete[] arrayE;
	} else {
		fi.open ("input.txt");
		while (!fi.eof ()) {
			fi.get (s);
			if (!fi.eof ()) {
				e1++;
			}
		}
		fi.close();
		fi.open("input.txt");
		char *rra = new char[e1];
		int *trr = new int[e1]; 
		for (int i = 0; i < e1; i++) {
			fi.get(s);
			rra[i] = s;
			for (int j = 0; j < 65; j++) {
				if (rra[i] == mass[j]) {
					trr[i] = j;
					cout << i << " " << trr[i] << endl;
				}
			}
		}
		fi.close();
		delete[] rra;
		int Bitt6[6];
		j1 = 0;
		int *InputArrayBin = new int[e1 * 6];
		for (int i = 0; i < e1 * 6; i++) {
			InputArrayBin[i] = 0;
		}
		for (int i = 0; i < e1; i++) {
	    	tmp = trr[i];
	    	for (int j = 0; j < 6; j++) {
	    		Bitt6[j] = tmp % 2;
	    		tmp /= 2;
	    	}
	    	for (int j = 5; j >= 0; j--, j1++) {
	    		InputArrayBin[j1] = Bitt6[j];
	    	}
	    }
	    delete[] trr;
	    for (int i = 0; i < e1 * 6; i++) {
	    	if (i % 6 == 0) cout << "\n";
	    	cout << InputArrayBin[i];
	    }
	    cout << endl;
	    if ( (e1 * 6) % 8 != 0) {
	    	g3 = (e1 * 6) - (e1 * 6) % 8;
	    } else {
	    	g3 = (e1 * 6);
	    }
	    cout << endl << g3 << endl;
	    cout << e1 * 6 << endl;
	    int *InputArrayBin8x = new int[g3];
	    for (int i = 0; i < g3; i++) {
	    	InputArrayBin8x[i] = 0;
	    }
	    for (int i = 0; i < g3; i++) {
	    	InputArrayBin8x[i] = InputArrayBin[i];
	    }
	    delete[] InputArrayBin;
	    cout << endl;
	    for (int i = 0; i < g3; i++) {
	    	if ( i % 8 == 0) cout << "\n";
	    	cout << InputArrayBin8x[i];
	    }
	    cout << endl;
	    ccc = 0;
	    int *sobr = new int[g3 / 8];
	    for (int i = 0; i < g3 / 8; i++) {
	    	sobr[i] = 0;
	    }
	   	for (int i = 0; i < g3 / 8; i++) {
	    	for (int j = 7; j >= 0; j--, ccc++) {
	    		sobr[i] += InputArrayBin8x[ccc] * pow(2, j);
	    	}
	    }
	    cout << endl;
	    delete[] InputArrayBin8x;

	    fo.open ("input.txt");
	    for (int i = 0; i < g3 / 8; i++) {
	    	cout << (char)sobr[i];
	    	fo << (char)[i];
	    }
	    delete[] sobr;
	    fo.close ();
	}
    return 0;
}
