//b)Program to demonstrate the encryption and decryption of your full name using Verman cipher.
#include<stdio.h> 
char arr[26][26];
char message[22]="pratikshyamahat",key[22]="wwonderfulmusic",emessage[22],retMessage[22];
int findRow(char);
int findColumn(char);
int findDecRow(char,int);
int main() {
	int i=0,j,k,r,c;
	//clrscr();
	k=96;
	for (i=0;i<26;i++) {
		k++;
		for (j=0;j<26;j++) {
			arr[i][j]=k++;
			if(k==123) 
			    k=97;
		}
	}

	// Encryption 
	for (i=0;key[i]!='\0';i++) {
		c=findRow(key[i]);
		r=findColumn(message[i]);
		emessage[i]=arr[r][c];
	}
	emessage[i]='\0';
	printf("\n Encrypted message is:\n\n");
	for (i=0;emessage[i]!='\0';i++) 
	 printf("%c",emessage[i]);
     
	//decryption 
	for (i=0;key[i]!='\0';i++) {
		c=findColumn(key[i]);
		r=findDecRow(emessage[i],c);
		retMessage[i]=arr[r][0];
	}
	retMessage[i]='\0';
	printf("\n\nMessage Retrieved is:\n\n");
	for (i=0;retMessage[i]!='\0';i++) 
	  printf("%c",retMessage[i]);
	//getc();
	return(0);
}
int findRow(char c) {
	int i;
	for (i=0;i<26;i++) {
		if(arr[0][i]==c) 
		   return(i);
	}
}
int findColumn(char c) {
	int i;
	for (i=0;i<26;i++) {
		if(arr[i][0]==c) 
		   return(i);
	}
}
int findDecRow(char c,int j) {
	int i;
	for (i=0;i<26;i++) {
		if(arr[i][j]==c) 
		   return(i);
	}
}
