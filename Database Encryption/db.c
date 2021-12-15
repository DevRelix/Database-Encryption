#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <crypt.h>

//Username Encryption
void usernameEncryption (char username[], int usernameEncryptionKey)        //Getting the username and the encryption key from the user to encrypt the username.
{
    for (int i=0;i<strlen(username) ;i++)                                   //Getting the length of the password.
    {
        username[i] = username[i] - usernameEncryptionKey;                  //Password gets encrypted with the key.
    }
}
//Password Encryption
void passwordEncryption (char password[], int passwordEncryptionKey)        //Getting the username and the encryption key from the user to encrypt the username.
{
    for (int i=0;i<strlen(password) ;i++)                                   //Getting the length of the password.
    {
        password[i] = password[i] - passwordEncryptionKey;                  //Password gets encrypted with the key.
    }
}
//Username Decryption

void usernameDecryption (char username[], int usernameEncryptionKey)        //Getting the username and the encryption key from the user to decrypt the username.
{
    for (int i=0;i<strlen(username) ;i++)                                   //Getting the length of the password.
    {
        username[i] = username[i] + usernameEncryptionKey;                  //Password gets decrypt with the key.
    }
}
//Password Decryption

void passwordDecryption (char password[], int passwordEncryptionKey)        //Getting the username and the encryption key from the user to decrypt the username.
{
    for (int i=0;i<strlen(password) ;i++)                                   //Getting the length of the password.
    {
        password[i] = password[i] + passwordEncryptionKey;                  //Password gets decrypted with the key.
    }
}

int main()
{
    char username[50], password[50];

    FILE *encryptedDB = fopen("database/encryptedDB.txt", "a+");
    FILE *databaseDB = fopen("database/databaseDB.txt", "a+");

    printf("\e[38;2;255;0;187mDB-Database\n");

    printf("\n\e[38;2;255;0;0mPlease enter the username : \e[38;2;0;255;0m");
    scanf("%s", username);                                            //User types in the username.
    usernameEncryption(username, 0XAED);                              //The username then gets encrypted with the encryption key.
    printf("\e[38;2;0;255;0m%s", username);
    fprintf(encryptedDB, "Encrypted Username: %s | ", username);      //Then the encrypted username gets writen to the encryptedDB.txt file
    usernameDecryption(username, 0XAED);
    printf("\n\e[38;2;0;255;0m%s\n", username);
    fprintf(databaseDB, "Decrypted Username: %s || ", username);      //Then the decrypted username gets writen to the databaseDB.txt file

    printf("\n\e[38;2;255;0;0mPlease enter the password: \e[38;2;0;255;0m");
    scanf("%s", password);                                            //User types in the password.
    passwordEncryption(password, 0XAED);                              //The password then gets encrypted with the encryption key.
    printf("\e[38;2;0;255;0m%s", password);
    fprintf(encryptedDB, "Encrypted Password: %s | \n", password);    //Then the encrypted password gets writen to the encryptedDB.txt file
    passwordDecryption(password, 0XAED);
    printf("\n\e[38;2;0;255;0m%s\n", password);
    fprintf(databaseDB, "Decrypted Password: %s \n", password);       //Then the decrypted password gets writen to the databaseDB.txt file

    printf("\n\e[38;2;255;0;187mEncrypted Username and Password has successfully been stored in \"encryptedDB.txt\"\n");
    printf("\e[38;2;255;0;187mRegular Decrypted Username and Password has successfully been stored in \"databaseDB.txt\"\n\e[38;2;255;255;255m");

    fclose(encryptedDB);
    fclose(databaseDB);
    return 0;
}