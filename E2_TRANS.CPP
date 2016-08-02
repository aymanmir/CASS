#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
void main()
{
clrscr();
char ch,cstr[100];
char pt[5][5],ct[5][5],dc[5][5];
int i=-1,j,t,l;
int b;
printf("Transposition Cipher\n");
FILE *p,*d,*c;
p=fopen("plain.txt","r");
if(p==NULL)
{
	printf("Error!!\n");
}
printf("\nPlain text:\t");
do
{
ch=fgetc(p);
if(feof(p))
	break;
printf("%c",ch);
cstr[++i]=ch;
}while(1);
printf("\n");
fclose(p);
l=i;
t=0;
char ans;
do
{
	printf("\n1. Encrypt\n2. Decrypt\n3. Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&b);
	switch(b)
	{
		case 1:

			for(i=0; i<5; i++)
			for(j=0; j<5; j++)
				pt[i][j]='*';
			printf("\nPlain text with padding:\n");
			for(i=0; i<5; i++)
			{	for(j=0; j<5; j++)
				{
				if(t<=l)
				pt[i][j]=cstr[t++];
				printf("%c ",pt[i][j]);
				}
			printf("\n");
			}
			printf("\nEnciphered Text:\n");
			c=fopen("ciper_text","w");
			for(i=0; i<5; i++)
			{	for(j=0; j<5; j++)
				{

				ct[i][j]=pt[j][i];
				printf("%c ",ct[i][j]);
				putc(ct[i][j],c);
				}
				printf("\n");
			}
			fclose(c);


			break;
		case 2:
			{
			c=fopen("ciper_text","r");
			for(i=0; i<5; i++)
			for(j=0; j<5; j++)
			fscanf(c,"%c",&ct[i][j]);

			printf("\nDeciphered Text:\n");
			for(i=0; i<5; i++)
			{	for(j=0; j<5; j++)
				{

				dc[i][j]=ct[j][i];
				if(dc[i][j]!='*')
				{
				printf("%c",dc[i][j]);
				}
				}
			}

			}
			break;
		case 3: exit(0);
		default:printf("Wrong choice\n");
			break;
	}
	printf("Do u want to continue(y/n)");
	scanf("%s",&ans);
}while(ans=='y');
getch();
}
/*OUTPUT

Plain text:     We are waiting.

1. Encrypt
2. Decrypt
3. Exit
Enter your choice
1

Plain text with padding:
W e   a r
e   w a i
t i n g .
* * * * *
* * * * *

Enciphered Text:
W e t * *
e   i * *
  w n * *
a a g * *
r i . * *
Do u want to continue(y/n)n
tion
`

Enciphered Text:
W e t * *
e   i * *
  w n * *
a a g * *
r i . * *

Do u want to continue(y/n)y

1. Encrypt
2. Decrypt
3. Exit
Enter your choice
2

Deciphered Text:
W e   a r e   w a i t i n g .
Do u want to continue(y/n)y

1. Encrypt
2. Decrypt
3. Exit
Enter your choice
3


*/