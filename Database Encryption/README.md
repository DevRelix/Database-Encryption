This simple program is made to simply help protect yourself/clients info such as usernames and passwords.
Generically this is just to encrypt and store usernames and passwords and store decrypted regular usernames and passwords for general usage.

The following dependencies and packages need to be installed for either CentOS or Ubuntu.
       
              CentOS
----------------------------------
1) yum update
2) yum upgrade
3) yum install gcc -y
4) gcc db.c -o db -Wall -std=c99
5) To run the program | ./db

              Ubuntu
----------------------------------
1) apt update && apt upgrade
2) apt install gcc
3) gcc db.c -o db -Wall -std=c99
4) To run the program | ./db

All encrypted usernames and passwords get stored in ./database/encryptedDB.txt/
All decrypted regular usernames and passwords get stored in ./database/databaseDB.txt/

Hope this helps for those who feel the need to use this simple program and to simply secure your database.
