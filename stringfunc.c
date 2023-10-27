#include <stdbool.h>
size_t len(char arr[]){

	size_t count = 0;
	for(; arr[count] != '\0'; count++){}

	return count;
}
void append(char arr[], char x){

	size_t length = len(arr);
	arr[length + 1] = '\0';
	arr[length] = x;
}
bool isthere(char arr[], char x){
	for(size_t i = 0; i < len(arr); i++){
		if(arr[i] == x){
			return true;
		}
	}
	return false;
}
void clear(char arr[]){
	size_t length = len(arr);
	arr[0] = '\0';
}
void set(char arr[], char newarr[]){
	clear(arr);
	for(size_t i = 0; i <= len(newarr); i++){
		arr[i] = newarr[i];
	}
}
int locate(char arr[], char x){
	int count = 0;
	for(size_t i = 0; arr[i] != x && arr[i] != '\0'; i++){
		count++;
	}
	return count;
}
void lower(char arr[]){
	for(size_t i = 0; i < len(arr); i++){
		switch(arr[i]){
			case 'A': arr[i] = 'a'; break;
			case 'B': arr[i] = 'b'; break;
			case 'C': arr[i] = 'c'; break;
			case 'D': arr[i] = 'd'; break;
			case 'E': arr[i] = 'e'; break;
			case 'F': arr[i] = 'f'; break;
			case 'G': arr[i] = 'g'; break;
			case 'H': arr[i] = 'h'; break;
			case 'I': arr[i] = 'i'; break;
			case 'J': arr[i] = 'j'; break;
			case 'K': arr[i] = 'k'; break;
			case 'L': arr[i] = 'l'; break;
			case 'M': arr[i] = 'm'; break;
			case 'N': arr[i] = 'n'; break;
			case 'O': arr[i] = 'o'; break;
			case 'P': arr[i] = 'p'; break;
			case 'Q': arr[i] = 'q'; break;
			case 'R': arr[i] = 'r'; break;
			case 'S': arr[i] = 's'; break;
			case 'T': arr[i] = 't'; break;
			case 'U': arr[i] = 'u'; break;
			case 'V': arr[i] = 'v'; break;
			case 'W': arr[i] = 'w'; break;
			case 'X': arr[i] = 'x'; break;
			case 'Y': arr[i] = 'y'; break;
			case 'Z': arr[i] = 'z'; break;
		}
	}
}
void reverse(char arr[]){
	size_t length = len(arr);
	char newarr[length];
	newarr[length] = '\0';
	for(size_t i = 0; arr[i] != '\0'; i++){
		newarr[--length] = arr[i];
	}
	printf("%s\n%s\n", arr, newarr);
	set(arr, newarr);
}
void remove_nlc(char arr[]){
	int num = len(arr);
	if(arr[num-1] == '\n'){
		arr[num-1] = '\0';
	}
}
