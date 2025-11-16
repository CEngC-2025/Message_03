#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

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

int main() {

    ios_base::sync_with_stdio(false);

    string code, decimal = "", binary = "", decrypted = "", binary_segment = "";
    getline(cin, code);

    for (int i = 0; i < code.length(); i++) {
        if (code[i] == ' ') {
            binary += decimal_to_binary(stoi(decimal)) + " ";
            decimal = "";
            i++;
        }
        decimal += code[i];
    }
    binary += decimal_to_binary(stoi(decimal));
    reverse(binary.begin(), binary.end());
    
    char asciiChar;

    for (int i = 0; i < binary.length(); i++) {
        if (binary[i] == ' ') {
            asciiChar = binary_to_decimal(binary_segment);
            decrypted.push_back(asciiChar);
            binary_segment = "";
            i++;
        }
        binary_segment += binary[i];
    }
    asciiChar = binary_to_decimal(binary_segment);
    decrypted.push_back(asciiChar);

    reverse(decrypted.begin(), decrypted.end());

    cout<<decrypted<<endl;

    return 0;
}