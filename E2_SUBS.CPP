//Program to implement substituion
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
char az[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char pt[30];
int key,i,l,a,t;
char ct[30],ch;
int a_code[30],charval;
char dc[30],ans;
void main()
{
	clrscr();
	FILE *p,*c,*d;
	printf("Substitution Cipher Technique:Ceaser Cipher\n");
       //	printf("Enter the plain text\n");
       //	scanf("%s",pt);
       //	p=fopen("p.txt","w");
       //	fputs(pt,p);
       //	fclose(p);
	p=fopen("p.txt","r");
	i=-1;
	while((ch=getc(p))!=EOF)
		pt[++i]=ch;
	fclose(p);
	printf("Enter key\n");
	scanf("%d",&key);
	do
       {printf("1. Encipher\n");
	printf("2. Decipher\n");
	printf("3. Exit\n");
	printf("Enter your choice:");
	scanf("%d",&t);
	printf("Entered Plain Text\t");
	puts(pt);
	l=strlen(pt);
	switch(t)
	{case 1:
	{
	  //p=fopen("p.txt","r");
	 // while((ch=getc(p))!=EOF)
	//	pt[++i]=ch;
	  for(i=0; i<l; i++)           //Estimating numeric value of plain text
		for(a=0; a<26; a++)
		{
			if(pt[i]==az[a])
				a_code[i]=a;
		}
	for(i=0; i<l; i++)          //Enciphering plain text
	{
		charval=a_code[i];
		ct[i]=az[(charval+key)%26];
	}
	printf("Enciphered Text:\t");
	c=fopen("ci.txt","w");
	fputs(ct,c);
	fclose(c);
	c=fopen("ci.txt","r");
	while((ch=getc(c))!=EOF)
	{	putc(ch,c);
		printf("%c",ch);
	}
	fclose(c);
	}
	break;
	case 2:
	{
	printf("\nEnciphered Text:\t");
	c=fopen("ci.txt","r");
	i=-1;
	while((ch=getc(c))!=EOF)
	{
		ct[++i]=ch;
		printf("%c",ch);
	}

	fclose(c);
       //	for(i=0; i<l; i++)
	 //	printf("%c",ct[i]);
	printf("\n");
	for(i=0; i<l; i++)           //Estimating numeric value of cipher text
		for(a=0; a<26; a++)
		{
			if(ct[i]==az[a])
				a_code[i]=a;
		}
	for(i=0; i<l; i++)          //Enciphering plain text
	{
		charval=a_code[i];
		dc[i]=az[(charval+26-key)%26];
	}
	printf("Deciphered Text:\t");
       //	for(i=0; i<l; i++)
	 //	printf("%c",dc[i]);
	d=fopen("di.txt","w");
	fputs(dc,d);
	fclose(d);
	d=fopen("di.txt","r");
	while((ch=getc(d))!=EOF)
		printf("%c",ch);
	fclose(d);
	printf("\n");
	}
	break;
	case 3:exit(0);
	default:printf("wrong choice\n");
	break;
	}
	printf("\nDo u want to continue (y/n)\n");
	scanf("%s",&ans);
	}while(ans=='y');
	printf("\nEnd");
	exit(0);
}
/*OUTPUT
Substitution Cipher Technique:Ceaser Cipher
Enter key
5
1. Encipher
2. Decipher
3. Exit
Enter your choice:1
Entered Plain Text      computerworld
Enciphered Text:        htruzyjwbtwqi
Do u want to continue (y/n)
y
1. Encipher
2. Decipher
3. Exit
Enter your choice:2
Entered Plain Text      computerworld

Enciphered Text:        htruzyjwbtwqi
Deciphered Text:        computerworld

Do u want to continue (y/n)
n
                                                                                
End                                                                             
                                                                                

*/