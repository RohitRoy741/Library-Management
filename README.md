# LIBRARY MANAGEMENT APLLICATION

## Overview
<p>Greetings, this is one of the simplest Library management applications coded in C. The application 
provides basic features of a library like memebership, book issue, book return, database, etc. To keep things simple the application uses <b>Command line</b> as its interface and <b>File Handling</b> to store data.</p>


## Facilities

### Member
- Members can login into their account and can signup to create a new account.
- Each Member has a special dedicated file that stores his/her interaction with the library.
- Members can check the books currently issued to them.
- Members can check library database.
- Members can issue and return books (at most 3 at a time).
### Admin
- Admin can check Member and Books database
- Admin can add or remove books
- Admin can add or remove members

## How to setup
1. Clone the repo to your local machine (containing c compiler).
2. Open command prompt/terminal in the repo folder
3. Compile the header files through the following commands:
    - gcc books.h
    - gcc Members.h
4. Compile and execute Main.c to access member facilities
5. Compile and execute Admin.c to access Admin facilities

##### Login Credentials
- Member: Registration Number: 189301127 <br>Password: Alohmora
- Admin: Username: Salamander <br>Password: FairyTail