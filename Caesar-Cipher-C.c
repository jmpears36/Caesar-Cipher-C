#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Rotation "caesar" cipher for CS50

string encrypt(string plain, int key);

int main(int argc, string argv[])
{

    //make sure exactly two command line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //check if cipher key is entirely alphabetical
    string checka = argv[1];
    for (int i = 0; i < strlen(checka); i++)
    {
        if isalpha(checka[i])
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //retrieve plaintext, pass plaintext through encrypt function to receive cipher text, then printf
    string plain = get_string("plaintext:  ");

    int key = atoi(argv[1]);

    string cipher = encrypt(plain, key);

    printf("ciphertext: %s\n", cipher);

    return 0;

}

string encrypt(string plain, int key)
{

    int len = strlen(plain);
    int i = 0;
    int j = 0;
    string c = "";

    //encipher every character of plaintext unless non-alphabetical
    for (j = 0; j < len; j++)
    {
        if isupper(plain[j])
        {
            //convert plaintext character from ascii to 0 index
            plain[j] = plain[j] - 'A';
            //use formula to encipher (cipher = (plaintext + key) % 26)
            plain[j] = ((plain[j] + key) % 26);
            //convert back to ascii
            plain[j] += 'A';
        }
        else if islower(plain[j])
        {
            plain[j] = plain[j] - 'a';
            plain[j] = ((plain[j] + key) % 26);
            plain[j] += 'a';
        }
    }
    return (plain);
}


