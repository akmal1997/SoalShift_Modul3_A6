#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
pthread_t tid[100];

char word[1500];
char search[200];
int i = 1;

void *cek() {
    FILE *f;
        f=fopen("Novel.txt", "r");
        scanf("%s", search);
        while (!feof(f)) {
        fscanf(f, "%s", word);
            if (word==search){
            printf("\n %i %s ", i, word);
            i++;}
        }
        fclose(f);
}
int main()
{
    int err;
    err=pthread_create(&(tid[0]),NULL,&cek,NULL);
    if(err) printf("error ma bro\n");
    return 0;
}
