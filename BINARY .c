#include <stdio.h>
#include <math.h>
#include<string.h>
#include <conio.h>
 
long int Bin_to_Dec(long int); //1:BINARY TO DECIMAL
long int Bin_to_Oct(long int); //2:BINARY TO OCTAL
long int Bin_to_Hex(long int); //3:BINARY TO HEXA-DECIMAL
long int Dec_to_Bin(long int); //4:DECIMAL TO BINARY
long int Oct_to_Bin(long int); //7:OCTAL TO BINARY
void Hex_to_Bin(char []); //10:HEXA-DECIMAL TO BINARY
int main()
{
    int op,num=1,check;
    long int bin,oct,dec;
    char hex[100];
    int i,j,space;  //  FOR PATTERN
     
    printf("\t\tWELCOME TO NUMBER SYSTEM CONVERSION\n\n");
     
    while(num!=0)
    {
        printf("\t\t>>>>>> CHOOSE THE CONVERSION <<<<<<\n\n");
     
        printf("=> BINARY <=\n");
        printf("1: Binary to Decimal.\n2: Binary to Octal.\n3: Binary to Hexa-Decimal.\n");
 
        printf("\n=> DECIMAL <=\n");
        printf("4: Decimal to Binary.\n");
 
        printf("\n=> OCTAL <=\n");
        printf("5: Octal to Binary.\n");
 
        printf("\n=> HEXA-DECIMAL <=\n");
        printf("6: Hexa-Decimal to Binary.\n");
         
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&op);
          switch(op)
        {
            case 1:
                printf("\n***BINARY TO DECIMAL***\n");
                D:
                printf("\nEnter the Number in Binary form (0s & 1s): ");
                scanf("%ld",&bin);
                // CHECKING INPUT IS IN BINARY FORM
                check=bin;
                 
                while(check!=0)
                {
                    num=check%10;
                    if(num>1)
                    {
                        printf("\n%d IS NOT BINARY NUMBER.\n",bin);
                        printf("***TRY AGAIN****\n");
                        goto D;
                    }
                    else
                    check=check/10;
                }
                 
                Bin_to_Dec(bin); break;
             
            case 2:
                printf("\n***BINARY TO OCTAL***\n");
                E:
                printf("\nEnter the Number in Binary form (0s & 1s): ");
                scanf("%ld",&bin);
                // CHECKING INPUT IS IN BINARY FORM
                check=bin;
                 
                while(check!=0)
                {
                    num=check%10;
                    if(num>1)
                    {
                        printf("\n%d IS NOT BINARY NUMBER.\n",bin);
                        printf("***TRY AGAIN****\n");
                        goto E;
                    }
                    else
                    check=check/10;
                }
                 
                Bin_to_Oct(bin); break;
             
            case 3:
                printf("\n***BINARY TO HEXA-DECIMAL***\n");
                F:
                printf("\nEnter the Number in Binary form (0s & 1s): ");
                scanf("%ld",&bin);
                // CHECKING INPUT IS IN BINARY FORM
                check=bin;
                 
                while(check!=0)
                {
                    num=check%10;
                    if(num>1)
                    {
                        printf("\n%d IS NOT BINARY NUMBER.\n",bin);
                        printf("***TRY AGAIN****\n");
                        goto F;
                    }
                    else
                    check=check/10;
                }
                 
                Bin_to_Hex(bin); break;
             
            case 4:
                printf("\n***DECIMAL TO BINARY***\n");
                printf("\nEnter the Number in Decimal form (0 to 9): ");
                scanf("%ld",&dec);
                Dec_to_Bin(dec); break;

            case 5:
                printf("\n***OCTAL TO BINARY***\n");
                A:
                printf("\nEnter the Number in Octal form (0 to 7): ");
                scanf("%ld",&oct);
                // CHECKING INPUT IS IN OCTAL FORM
                check=oct;
                 
                while(check!=0)
                {
                    num=check%10;
                    if(num>7)
                    {
                        printf("\n%d IS NOT OCTAL NUMBER.\n",num);
                        goto A;
                    }
                    else
                    {
                    check=check/10;
                    i++;
                    }
                }
                Oct_to_Bin(oct); break;
            case 6:
                printf("\n***HEXA-DECIMAL TO BINARY***\n");
                X:
                printf("\nEnter the Number in Hexa-Decimal form: ");
                scanf("%s",&hex);
                //check
                for(i=strlen(hex)-1;i>=0;i--)
                {
                    if(hex[i]>'f' && hex[i]<='z' || hex[i]>'F'&& hex[i]<='Z')
                    {
                        printf("\nYou have to Enter Hexa-Decimal Number.\n");
                        printf("'%c' IS NOT Hexa-Decimal Number.\n",hex[i]);
                        goto X;
                    }
                }
                Hex_to_Bin(hex); break;
             
            default:
                printf("\n***INVALID NUMBER***\n");
                break;                                          
        }
        printf("\n\nDO YOU WANT TO CONTINUE = (1/0) :\n");
        scanf("%d",&num);
 
    }
     
    space = 3+35;
        for( i=1;i<=3;i++)
        {
            for( j=1;j<=space;j++)
            {
                printf(" ");
            }
            space--;
            for( j=1;j<=2*i-1;j++)
            {
                printf("*");
            }
            printf("\n");
        }
        space = 37;
        for( i=1;i<=3;i++)
        {
            for( j=1;j<=space;j++)
            {
                printf(" ");
            }
            space++;
            for( j=1;j<=2*(3-i)-1;j++)
            {
                printf("*");
               
            }
            
            printf("\n");
            
        }
}
 
long int Bin_to_Dec(long int bin)
{
    int rem,sum=0,i=0;
    while(bin!=0)
    {
        rem=bin%10;
        bin=bin/10;
        sum=sum+rem*pow(2,i);
        i++;
    }
     
    printf("\nEquivalent Decimal Number : %d",sum);
}
 long int Bin_to_Oct(long int bin)
{
    int i=0,rem,sum=0,remain[100],len=0;
     
    while(bin!=0)
    {
        rem=bin%10;
        bin=bin/10;
        sum=sum+rem*pow(2,i);
        i++;
    }
    i=0;
    while(sum!=0)
    {
        remain[i]=sum%8;
        sum=sum/8;
        i++;
        len++;
    }
    printf("\nEquivalent Octal Number : ");
    for(i=len-1;i>=0;i--)
    {
        printf("%d",remain[i]);
    }
}
 
long int Bin_to_Hex(long int bin)
{
    int rem,i=0,sum=0,remain[100],len=0;
     
    while(bin!=0)
    {
        rem=bin%10;
        bin=bin/10;
        sum=sum+rem*pow(2,i);
        i++;
    }
    i=0;
    while(sum!=0)
    {
        remain[i]=sum%16;
        sum=sum/16;
        i++;
        len++;
    }
    printf("\nEquivalent Hexa-Decimal Number : ");
    for(i=len-1;i>=0;i--)
    {
        switch(remain[i])
        {
            case 10:
                printf("A"); break;
             
            case 11:
                printf("B"); break;
                 
            case 12:
                printf("C"); break;
                 
            case 13:
                printf("D"); break;
                 
            case 14:
                printf("E"); break;
                 
            case 15:
                printf("F"); break;
                 
            default:
                printf("%d",remain[i]);
        }
         
    }
}
 
long int Dec_to_Bin(long int dec)
{
    int rem[50],i=1,len=0;
    while(dec>0)
    {
        rem[i]=dec%2;
        dec=dec/2;
        //i++;
        //len++;
        len=len+(i*rem[i]);
        i=i*10;
    }
     
    printf("\nEquivalent Binary Number : ",len);
    getch();
}
/*{
    int number,n,remainder,bin=1,place=1;
    scanf("%d",&number);
    n=number;
    while(n>0)
    {
        remainder=n%2;
        bin+=remainder*place;
        place*=10;
        n/=2;
    }
    printf("Binary number is %d",bin);
}*/
long int Oct_to_Bin(long int oct)
{
    int rem[50],len=0,decimal=0,i=0,num,ans;
     
    while(oct!=0)
    {
        ans=oct % 10;
        decimal = decimal + ans * pow(8,i);
        i++;
        oct = oct/10;
    }
     
    i=0;
    do
    {
        rem[i]=decimal%2;
        decimal=decimal/2;
        i++;
        len++;
    }
    while(decimal!=0);
     
    printf("\nEquivalent Binary Number : ");
    for(i=len-1;i>=0;i--)
    {
        printf("%d",rem[i]);
    }
}
void Hex_to_Bin(char hex[])
{
    int i=0;
    printf("\nEquivalent Binary Number : ");
    for(i=0;i<strlen(hex);i++)
    {
        switch (hex[i])
        {
        case '0':
            printf("0000"); break;
        case '1':
            printf("0001"); break;
        case '2':
            printf("0010"); break;
        case '3':
            printf("0011"); break;
        case '4':
            printf("0100"); break;
        case '5':
            printf("0101"); break;
        case '6':
            printf("0110"); break;
        case '7':
            printf("0111"); break;
        case '8':
            printf("1000"); break;
        case '9':
            printf("1001"); break;
        case 'A':
        case 'a':   
            printf("1010"); break;
        case 'B':
        case 'b':
            printf("1011"); break;
        case 'C':
        case 'c':   
            printf("1100"); break;
        case 'D':
        case 'd':   
            printf("1101"); break;
        case 'E':
        case 'e':   
            printf("1110"); break;
        case 'F':
        case 'f':   
            printf("1111"); break;
         
        default:
            printf("\n Invalid hexa digit %c ", hex[i]);            
        }
    }
 
}

 
