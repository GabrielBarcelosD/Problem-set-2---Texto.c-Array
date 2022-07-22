#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void stringCipher(string text, int key);

int main(int argc, string argv[])
{
    if(argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");
    stringCipher(plaintext, key);
}

void stringCipher(string text, int key) {
    char cypher[strlen(text)];

    string lowerAlphabet = "abcdefghijklmnopqrstuvwxyz";
    string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i = 0; i < strlen(text); i++) {
        if(isalpha(text[i])) {
            if(islower(text[i])) {
                int position = text[i] - 97;
                int c = (position + key) % 26;
                cypher[i] = lowerAlphabet[c];
            } else if(isupper(text[i])) {
                int position = text[i] - 65;
                int c = (position + key) % 26;
                cypher[i] = upperAlphabet[c];
            }
        } else {
                cypher[i] = text[i];
        }
    }
    printf("ciphertext: %s\n", cypher);
}