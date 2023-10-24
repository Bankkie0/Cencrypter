#include <stdio.h>
#include <stdlib.h>
#include "stringfunc.c"
#include <time.h>
void print_menu();
void gen_key();
void encrypt_message();
void decrypt_message();
int settings();
void print_settings_menu();
char key[256] = "";
char alphabet[256] = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

int main(){
	while(true){
		print_menu();
		char choice;
		scanf(" %c", &choice);
		//printf("%c\n", choice);
		switch(choice){
			case 'K':
			case 'k': gen_key();
					  break;
			case 'Q':
			case 'q': return 0;
					  break;
			case 'E':
			case 'e': encrypt_message();
					  break;
			case 'D':
			case 'd': decrypt_message();
					  break;
			case 'S':
			case 's': settings();
			default: continue;
		}
	}
return 0;
}

void print_menu(){
	system("clear");//find way of clearing the terminal without including stdlib.h
	printf("########################################################################\n");
	printf("#                                                                      #\n");
	printf("#                   The Cencrypter App                                 #\n");
	printf("#                                                                      #\n");
	printf("#           Generate key (K) |  Settings (S)                           #\n");
	printf("#                                                                      #\n");
	printf("#        Encrypt Message (E) |  Decrypt Message (D)                    #\n");
	printf("#                                                                      #\n");
	printf("#                          Quit (Q)                                    #\n");
	printf("#                                                                      #\n");
	printf("# KEY:|%-64s#\n", key);
	printf("########################################################################\n");
	printf("Enter an option: ");
}

void gen_key(){
	clear(key);
	srand(time(0));//create my own time and rand functions
	while(len(key) != len(alphabet)){
		//print_menu();
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
	//reverse(message);
	//lower(message);
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
	//lower(message);
	for(size_t i = 0; i < len(message); i++){
		size_t place = locate(key, message[i]);
		decryption[i] = alphabet[place];
	}
	//printf("%s\n", message);
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
	printf("#                                                                      #\n");
	printf("#                    settings                                          #\n");
	printf("#                                                                      #\n");
	printf("# Change key(K):                                                       #\n");
	printf("# %-69s#\n", key);
	printf("#                                                                      #\n");
	printf("# Change alphabet(A):                                                  #\n");
	printf("# %-69s#\n", alphabet);
	printf("########################################################################\n");
	printf("Enter an option: ");
}
