#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
pthread_t tred[5];
int statuskep=100;
int statusloh=100;
int status=100;
int at=0;
void *reductionkep() {
   while(statuskep>0||statuskep<=100) {
        sleep(1);
        statuskep-=10;
   }
	return 0;
}

void *reductionloh() {
   while(statusloh>0||statusloh<=100) {
        sleep(1);
        statusloh-=15;
   }
	return 0;
}
void printstatus() {
  printf("Kepiting: %d",statuskep);
  if(statuskep<50) printf("(lapar)   ");
  else printf("(kenyang)   ");
  printf("Lohan: %d",statusloh);
  if(statusloh<50) printf("(lapar)\n");
  else printf("(kenyang)\n");
}

void *seken() {
   while(statuskep>=0||statusloh>=0) {
    printstatus();
    printf("1. Beri makan kepiting \n2. Beri makan lohan \n Masukkan angka: ");
    scanf("%d",&at);
    if(at==1) statuskep+=10;
    else if(at==2) statusloh+=10;
   if(statuskep<=0||statuskep>100||statusloh<=0||statusloh>100) break;
   // printf("kepiting: %d  lohan: %d \n",statuskep,statusloh);
    }
}

int main()
{
//while(1) {
    int err;
    err=pthread_create(&(tred[0]),NULL,&reductionkep,NULL);
    if(err!=0) printf("threadnya error\n");
    err=pthread_create(&(tred[1]),NULL,&reductionloh,NULL);
    if(err!=0) printf("threadnya error\n");
    err=pthread_create(&(tred[2]),NULL,&seken,NULL);
    if(err!=0) printf("threadnya error\n");
	pthread_join(tred[2],NULL);
	return 0;
}
