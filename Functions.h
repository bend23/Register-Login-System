#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

string crypto_Key(string token);
string decrypt_Key(string decrypt);

int integer_Crypting(int num);
int integer_Decrypting(int num);

bool check_User(const char* file_name, string existing_Users);
bool verify_Username(const char* file_name, string registered_Users);
bool verify_Passw(const char* file_name, string registered_Passw);