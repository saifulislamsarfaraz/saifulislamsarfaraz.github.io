#include<bits/stdc++.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<queue>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
//Group ID: 8
//Name : Md Saiful
//Id : 2019-2-60-040
//Name :Jekrul Islam Shajib
//ID : 2019-2-60-046

sem_t empty1;
sem_t empty2;
sem_t empty3;
sem_t barber_ready;
sem_t finished;
sem_t payment;
sem_t receipt;
queue<int> shop;
queue<int> sofa;
queue<int> chair;
queue<int> barbr;
queue<int> paymnt;

pthread_mutex_t lock1;
pthread_mutex_t lock2;
pthread_mutex_t lock3;
pthread_mutex_t lock4;
pthread_mutex_t lock5;
pthread_mutex_t lock6;
void init_semaphore()
{

	sem_init(&empty1,0,20);
	sem_init(&empty2,0,4);
	sem_init(&empty3,0,3);
	sem_init(&barber_ready,0,0);
	sem_init(&finished,0,0);
	sem_init(&payment,0,0);
	sem_init(&receipt,0,0);
}
int cnt = 0;
int cut = 0;
int seat_sofa;
int getup_sofa;
int seat_chair;
int take_payment;
void * customer(void * arg)
{

    int* customer_id = (int*)arg;
    printf("I am Customer %d\n",customer_id);
    sem_wait(&empty1);
    printf("Enter room customer number %d\n",customer_id);
    cnt++;
    shop.push(cnt);

    sem_wait(&empty2);
    sleep(1);
    pthread_mutex_lock(&lock1);
    int push_sofa=shop.front();
    sofa.push(push_sofa);

    shop.pop();
    printf("Customer seat sofa %d\n",push_sofa);
    pthread_mutex_unlock(&lock1);
    sleep(2);
    sem_wait(&empty3);
    pthread_mutex_lock(&lock2);
    int push_chair=sofa.front();
    printf("Get up from sofa %d\n",push_chair);
    chair.push(push_chair);
    sofa.pop();
    pthread_mutex_unlock(&lock2);
    sleep(1);
    pthread_mutex_lock(&lock3);
    int push_barber=chair.front();
    barbr.push(push_barber);
    chair.pop();
    printf("Seat in barber chair %d\n",push_barber);
    sem_post(&barber_ready);
    sem_post(&empty2);
    pthread_mutex_unlock(&lock3);


    sem_wait(&finished);

    pthread_mutex_lock(&lock5);

    take_payment=paymnt.front();
    paymnt.pop();
    printf("make payment %d\n",take_payment);
    sem_post(&payment);

    sem_wait(&receipt);
    printf("Exit from shop %d\n",take_payment);
    pthread_mutex_unlock(&lock5);
    sem_post(&empty1);
}



void * barber(void * arg)
{
    int* barber_id = (int*)arg;
	while(true){

            sem_wait(&barber_ready);
            pthread_mutex_lock(&lock4);
            int cs=barbr.front();
            paymnt.push(cs);
            barbr.pop();
            printf("Barber %d cutting hair %d\n",barber_id, cs);
            sem_post(&finished);
            pthread_mutex_unlock(&lock4);
            sem_post(&empty3);



	}
}



void * cashier(void * arg)
{

	while(true)
	{

        sem_wait(&payment);
        printf("Accept payments from %d\n",take_payment);
        sem_post(&receipt);

	}

}


int main(void)
{
    printf("\t\t\t\tGroup: 8\n");
	printf("\t\t\t\tName: Md Saiful\n");
	printf("\t\t\t\tID: 2019-2-60-040\n");

    ////
	pthread_t thread1[20];
	pthread_t thread2[3];
	pthread_t thread3;
    int x[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    //int x[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int y[3] = {1, 2, 3};
    init_semaphore();



	for (int i = 0; i < 20; i++){
        pthread_create(&thread1[i], NULL, customer, (void*) *(x+i));
	}
    for(int i = 0; i < 3; i++){
	   pthread_create(&thread2[i], NULL, barber, (void*) *(y+i));
    }
    pthread_create(&thread3,NULL,cashier,NULL);




	while(1);
	return 0;
}
