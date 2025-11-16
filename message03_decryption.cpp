#include "message03_decryption.h"

#include <algorithm>
#include <cmath>

string decimal_to_binary(int dec) {
    string bin = "";
    while (dec > 0) {
        int i = dec % 2;
        bin += to_string(i);
        dec /= 2;
    }
    reverse(bin.begin(), bin.end());
    while(bin.length() < 8) { //pads with leading 0s to ensure returns 8 bits
        bin = "0" + bin;      //was what was causing error when bits were reversed (e.g. 00001101 -> 10110000 not 1011, and unrecognized ascii)
    }
    return bin;
}

int binary_to_decimal(string bin) {
    int dec = 0, length = bin.length();
    for (int i = 0; i < length; i++) {
        if (bin[length - 1 - i] == '1') {
            dec += pow(2, i);
        }
    }
    return dec;
}
