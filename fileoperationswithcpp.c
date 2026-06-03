#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct spell{
    int id;
    char incantation[100];
    char spellname[100];
    char effect[100];
    char light[100];
};
struct spell spells[100];
int cnt =0;
void readfile(const char *filename)
{
    FILE *file = fopen(filename,"r");
    if(filename== NULL )
{
        printf("File not found !\n");
return;
}    
char line [300];
cnt =0;
while(fgets(line,sizeof(line),file))
{
    
}




}