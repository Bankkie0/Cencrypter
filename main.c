#include <stdio.h>
#include <stdlib.h>
#include "stringfunc.c"
#include <time.h>
void print_menu();
void gen_key();
int settings();
void print_settings_menu();
void encrypt_message();
void decrypt_message();
void encrypt_file();
void decrypt_file();
char key[256];
char alphabet[256];


int main(){
	FILE *pf;
	if((pf = fopen("./data.txt", "r")) == NULL){
		FILE *temp = fopen("./data.txt", "w");
		fputs("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890\n", temp);
		fputs("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n", temp);
		fclose(temp);
	}
	pf = fopen("./data.txt", "r");
	fpos_t a; fpos_t k;
	fgetpos(pf, &a);
	fgets(alphabet, 256, pf);
	fgetpos(pf, &k);
	fgets(key, 256, pf);
	fclose(pf);
	while(true){
		remove_nlc(alphabet);
		remove_nlc(key);
		print_menu();
		char choice;
		scanf(" %c", &choice);
		switch(choice){
			case 'K':
			case 'k': gen_key();
					  break;
			case 'S':
			case 's': settings();
					  break;
			case 'E':
			case 'e': encrypt_message();
					  break;
			case 'D':
			case 'd': decrypt_message();
					  break;
			case 'F':
			case 'f': encrypt_file();
					  break;
			case 'O':
			case 'o': decrypt_file();
					  break;
			case 'Q':
			case 'q': pf = fopen("./data.txt", "w");
					  fprintf(pf, "%s\n", alphabet);
					  fputs(key, pf);
					  fclose(pf);
					  return 0;
					  break;
			default: continue;
		}
	}
return 0;
}

void print_menu(){
	system("clear");
	printf("########################################################################\n");
	printf("#                                                                      #\n");
	printf("#                          The Cencrypter App                          #\n");
	printf("#                                                                      #\n");
	printf("#                 Generate key (K) |  Settings (S)                     #\n");
	printf("#                                                                      #\n");
	printf("#              Encrypt Message (E) |  Decrypt Message (D)              #\n");
	printf("#                                                                      #\n");
	printf("#              Encrypt File (F)    |  Decrypt File (O)                 #\n");
	printf("#                                                                      #\n");
	printf("#                               Quit (Q)                               #\n");
	printf("#                                                                      #\n");
	printf("# KEY:|%-64s#\n", key);
	printf("########################################################################\n");
	printf("Enter an option: ");
}

void gen_key(){
	clear(key);
	srand(time(0));
	while(len(key) != len(alphabet)){
		size_t rng = rand() % len(alphabet);
		if(!isthere(key, alphabet[rng])){
			append(key, alphabet[rng]);
		}
	}
	printf("%s\n%s\n", key, alphabet);
}
void encrypt_message(){
	system("clear");
	printf("Enter a message: ");
	char message[250] = "";
	char encryption[250] = "";
	scanf(" ");
	fgets(message, 250, stdin);
	for(size_t i = 0; i < len(message); i++){
		size_t place = locate(alphabet, message[i]);
		encryption[i] = key[place];
	}
	reverse(encryption);
	printf("%s\n", message);
	while(true){
		printf("the encrypted message is: %s\n", encryption);
		printf("Enter (Q) to quit: ");
		char input;
		scanf("%c", &input);
		if(input == 'q' || input == 'Q'){
			break;
		}
	}
}
void decrypt_message(){
	system("clear");
	printf("Enter a message to decrypt: ");
	char message[250] = "";
	char decryption[250] = "";
	scanf(" ");
	fgets(message, 250, stdin);
	for(size_t i = 0; i < len(message); i++){
		size_t place = locate(key, message[i]);
		decryption[i] = alphabet[place];
	}
	reverse(decryption);
	while(true){
		printf("the decrypted message is: %s\n", decryption);
		printf("Enter (Q) to quit: ");
		char input;
		scanf("%c", &input);
		if(input == 'q' || input == 'Q'){
			break;
		}
	}
}
int settings(){

	while(true){
		remove_nlc(alphabet);
		remove_nlc(key);
		print_settings_menu();
		char choice;
		scanf(" %c", &choice);
		switch(choice){
			case 'K':
			case 'k': system("clear");
					  printf("Enter updated key: ");
					  scanf(" ");
					  fgets(key, 256, stdin);
					  break;
			case 'A':
			case 'a': system("clear");
					  printf("Enter updated Alphabet: ");
					  scanf(" ");
					  fgets(alphabet, 256, stdin);
					  break;
			case 'Q':
			case 'q': return 0;
		}
	}
}
void print_settings_menu(){
	system("clear");
	printf("########################################################################\n");
	printf("# <--(Q)                                                               #\n");
	printf("#							   settings							   	   #\n");
	printf("#                                                                      #\n");
	printf("# Change key(K):                                                       #\n");
	printf("# %-69s#\n", key);
	printf("#                                                                      #\n");
	printf("# Change alphabet(A):                                                  #\n");
	printf("# %-69s#\n", alphabet);
	printf("########################################################################\n");
	printf("Enter an option: ");
}
void encrypt_file(){
	system("clear");
	printf("Enter the file you would like to encrypt: ");
	char file_name[25];
	scanf(" ");
	fgets(file_name, 25, stdin);
	remove_nlc(file_name);
	FILE *pf = fopen(file_name, "r+");
	if(pf != NULL){
		while(true){
			fpos_t a;
			fpos_t b;
			fgetpos(pf, &a);
			char buff = fgetc(pf);
			fgetpos(pf, &b);
			if(buff == EOF){
				break;
			}
			else if(buff == '\n'){
				continue;
			}
			else{
				size_t location = locate(alphabet, buff);
				fsetpos(pf, &a);
				fputc(key[location], pf);
				fsetpos(pf, &b);
			}
		}
		printf("\"%s\" has now been encryted\n", file_name);
		fclose(pf);
	}
	else{
	system("clear");
	printf("could not find: \"%s\"\n", file_name);
	}
	while(true){
		printf("press (Q) to go back: ");
		char choice;
		scanf(" %c", &choice);
		if(choice == 'Q' || choice == 'q'){
			break;
		}
	}
}
void decrypt_file(){
	system("clear");
	printf("Enter the file you would like to decrypt: ");
	char file_name[25];
	scanf(" ");
	fgets(file_name, 25, stdin);
	remove_nlc(file_name);
	FILE *pf = fopen(file_name, "r+");
	if(pf != NULL){
		while(true){
			fpos_t a;
			fpos_t b;
			fgetpos(pf, &a);
			char buff = fgetc(pf);
			fgetpos(pf, &b);
			if(buff == EOF){
				break;
			}
			else if(buff == '\n'){
				continue;
			}
			else{
				size_t location = locate(key, buff);
				fsetpos(pf, &a);
				fputc(alphabet[location], pf);
				fsetpos(pf, &b);
			}
		}
		printf("\"%s\" has now been decryted\n", file_name);
		fclose(pf);
	}
	else{
	system("clear");
	printf("could not find: \"%s\"\n", file_name);
	}
	while(true){
		printf("press (Q) to go back: ");
		char choice;
		scanf(" %c", &choice);
		if(choice == 'Q' || choice == 'q'){
			break;
		}
	}
}
