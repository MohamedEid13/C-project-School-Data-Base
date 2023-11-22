#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void string_convert(int *str);
void reverse_string(char *str);
int string_compare(char *s1,char*s2);
void swap_char(char *xp, char *yp);
void string_scan(char *str,int maxsize);
int string_compareNotCaseSenstive(char *s1,char*s2);
int string_len(char*str);
void reverseWord(char*str,int f,int l);
void string_reverseWords(char* str);
char*string_longestWord(char*str);
char*string_Rec(char*str);
void string_copyNoRepeat(char*str,char*copy);
void string_copyNoRepeat2(char*str,char*copy);
char string_firstRepeatedChar(char*str);
void swap_pointer(char**pp1,char**pp2);


/* ----------------------------------------------------------------------*/


int string_len(char*str)
{
    int i;
    for(i=0; str[i]; i++);
    return i;

}

void reverseWord(char*str,int f,int l)
{
    int i=f,j=l;
    char temp;
    for(; i<=j;)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }

}


void string_reverseWords(char* str)
{
    int len=string_len(str);
    int i,f,l;
    reverseWord(str,0,len-1);
    f=0;
    for(i=0; str[i]; i++)
    {
        if(str[i]==' ')
        {
            l=i-1;
            reverseWord(str,f,l);
            f=i+1;
        }
        else
        {

        }
    }
    reverseWord(str,f,len-1 );
}



char*string_longestWord(char*str)
{
    int i,j,c=0,max=0,index=0;

    for(i=0; str[i]; i++)
    {
        if(str[i]==' ')
        {
            if(c>=max)
            {
                max=c;
                index=i;
            }
            c=0;
        }
        else
        {
            c++;
        }
    }
    if(c>=max)
    {
        max=c;
        index=i;
    }
    printf("%d  %d   %c\n",max,index,str[index-1]);
    char*word=(char*)malloc(max+1);
    j=index-max;
    for(i=0; i<max; i++)
    {
        word[i]=str[j];
        j++;
    }
    word[i]=0;
    return word;
}


char*string_Rec(char*str)
{
    int i,n1=0,n2=0,n3=0,flag=0;
    for(i=0; str[i]; i++)
    {
        if(str[i]==' ')
        {
            flag++;
        }
        else
        {
            if(flag==0)
            {
                n1=(n1*10)+(str[i]-'0');
            }
            else if(flag==1)
            {
                n2=(n2*10)+(str[i]-'0');
            }
            else if(flag==2)
            {
                n3=(n3*10)+(str[i]-'0');
            }
        }
    }
    printf("%d   %d   %d\n",n1,n2,n3);
    if((flag!=2)||((n1+n2)<n3)||((n1+n3)<n2)||((n3+n2)<n1))
    {
        return "Not triangle";
    }
}



void string_copyNoRepeat(char*str,char*copy)
{
    int i,j,flag,k=0;

    for(i=0; str[i]; i++)
    {
        flag=1;
        for(j=0; j<i; j++)
        {
            if(str[i]==str[j])
            {
                flag=0;
            }
        }
        if(flag==1)
        {
            copy[k]=str[i];
            k++;
        }
    }
    copy[k]=0;

}

void string_copyNoRepeat2(char*str,char*copy)
{
    int i,k=0;
    char count[256]= {0};
    for(i=0; str[i]; i++)
    {

        if(count[str[i]]==0)
        {
            copy[k]=str[i];
            k++;
            count[str[i]]=1;
        }
    }
    copy[k]=0;
}


char string_firstRepeatedChar(char*str)
{
    int i,k=0;
    char count[256]= {0};
    for(i=0; str[i]; i++)
    {
        count[str[i]]++;
        if(count[str[i]]==2&&str[i]!=' ')
        {
            return str[i];
        }
    }
}



void swap_pointer(char**pp1,char**pp2)
{
    int* temp;
    temp=*pp1;
    *pp1=*pp2;
    *pp2=temp;

}


void string_scan(char*str,int maxSize)
{
    int i=0;
    fflush(stdin);
    scanf("%c",&str[i]);
    for(; str[i]!='\n'&&i<maxSize-1;)
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;

}


void string_print(char*str)
{
    int i;

//printf("f:lens=%d  size= %d\n",string_len(str),sizeof(str));
    for(i=0; str[i]; i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}


void string_convert(int *str)
{
    for(int i=0; str[i]; i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i]=str[i]-32;
        }
    }


}


void reverse_string(char *str)
{
    int i,j=string_len(str)-1;
    for(i=0; i<=j; i++)
    {
        swap_char(&str[i],&str[j]);
        j--;
    }


}


void swap_char(char *xp, char *yp)
{
    char temp=*xp;
    *xp=*yp;
    *yp=temp;

}


int string_compare(char *s1,char*s2)
{
    int i,j=string_len(s1),k=string_len(s2);
    if(j!=k)
    {
        for(i=0; s1[i]; i++)
        {
            if(s1[i]!=s2[i])
            {
                return 0;
            }
        }
    }
    return 1;
}



int string_compareNotCaseSenstive(char *s1,char*s2)
{
    int i,j=string_len(s1),k=string_len(s2),flag=0;
    if(j!=k)
    {
        flag= 0;
    }
    else if(j==k)
    {
        for(i=0; s1[i]; i++)
        {
            if(s1[i]==s2[i] || (s1[i]==s2[i]-32 || s1[i]==s2[i]+32) )
            {
                flag=1;
            }
            else
            {
                return 0;
            }

        }

    }
    if (flag==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
