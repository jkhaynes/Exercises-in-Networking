#include "util.hh"

#include <stdio.h>
#include <string.h>

#define N 256

//Helper method to clear an array and end it with a null terminating character
void clear(char* arr){
	int i;
	for(i = 0; i < N; i++)
		arr[i] = '\0';
	//arr[N-1] = '\0';
}

void hash(char* message, char* output)
{
	//Hash
	int i = 0;
    while (i < strlen(message)-1){
  		output[i % N] += message[i];
  		i++;
  	}
  	output[strlen(message)-1] = '\0';
 
}

//Encrypt the given message and store encryption in output array
void encryption(char* message, int key, char* output)
{
	int i = 0;
	while (i < strlen(message)){
		output[i] = message[i] + key;
		i++;
	}
	output[N-1] = '\0';
}

//Decrypt the given message and store the decryption in output array
void decryption(char* message, int key, char* output)
{
	encryption(message, -key, output);
}

