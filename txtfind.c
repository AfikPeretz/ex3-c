#include <stdio.h>
#include <string.h>
#define line 256
#define word 30
int getLine(char s[]);
int getword(char w[]);
int similar(char *s, char *t, int n);
int substring(char *str1, char *str2);
void print_similar_words(char *str);
void print_lines(char *str);


int getline(char s[])
{
    if(fgets(s, line, stdin) == NULL)
    {
        return -1;
    }
    return strlen(s);
}

int getword(char w[])
{
    int size = 0;
    char c = getchar();
    while (c != '\n' && c != '\t' && c != ' ' && c != EOF && size < WORD )
    {
        w[size] = c;
        size++;
        c = getchar();
    }
    w[size] = '\0';
    return size;
}

int substring(char *str1, char *str2)
{
    int i = 0;
    while (*str1 != '\0' && *str1 != '\r' && str1 != '\t' && *str1 != '\n')
    {
        if (*str1 == *(str2 + j)) //move on the small string 
        {
            j++;

            if (j == strlen(str2))
            {
                return 1; //true
            }
        }
        else
        {
            j = 0; 
        }
        str1++; //move on the big string while we escape the terms
    }
    return 0; //false
}

int similar (char *s, char *t, int n)
{
    int variable1 = 0;
    int variable2 = 0;
    while(*(s+variable1)!='\0')
    {
        if(*(s+variable1)!=*(t+variable2)){
            n--;
            variable1++;
        }
        else if(n<0){
            return 0;
        }
        else{
            variable1++;
            variable2++;
        }
    }
    if(*(t+variable2)=='\0'&&n>=0)
    {
        return 1;
    }
    return 0;   
}

void print_lines(char *str){
    char segment[line]; //The length of the segment is a line (256)
    while(get_line(segment)!=-1)
    {
        if(substring(segment, str))
            printf("%s", segment);
    }
}

void print_similar_words(char *str)
{
    char w[WORD];
    int a = getword(w);
    while (a != 0)
    {
        if (similar(w, str, 1) == 1){
            printf("%s\n", w);
        }
        a = getword(w);
    }
}

int main()
{
    char start[WORD];
    getword(start);
    char c;
    scanf("%c\n", &c);
    if (c == 'a'){
        print_lines(start);
    }
    else if (c == 'b'){
        print_similar_words(start);
    }
    
}