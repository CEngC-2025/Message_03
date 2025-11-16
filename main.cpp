#include "message03_decryption.h"
#include <algorithm>

using namespace std;

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