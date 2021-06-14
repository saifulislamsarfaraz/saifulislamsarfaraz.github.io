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
sem_t full1;
sem_t empty2;
sem_t full2;
sem_t empty3;
sem_t full3;
sem_t barber_ready;
sem_t finished;
sem_t leave_chair;
sem_t payment;
sem_t receipt;
queue<int*> shop;
queue<int*> sofa;
queue<int*> chair;
int *payment_id=0;
pthread_mutex_t lock1;
pthread_mutex_t lock2;
pthread_mutex_t lock3;
pthread_mutex_t lock4;
pthread_mutex_t lock5;
pthread_mutex_t lock6;
pthread_mutex_t lock7;
pthread_mutex_t lock8;
pthread_mutex_t lock9;
void init_semaphore()
{

	sem_init(&empty1,0,20);
	sem_init(&full1,0,0);
	sem_init(&empty2,0,4);
	sem_init(&full2,0,0);
	sem_init(&empty3,0,3);
	sem_init(&full3,0,0);
	sem_init(&barber_ready,0,0);
	sem_init(&finished,0,0);
	sem_init(&leave_chair,0,0);
	sem_init(&payment,0,0);
	sem_init(&receipt,0,0);
}
int cnt = 0;
int cut = 0;
int* seat_sofa;
int* getup_sofa;
int* seat_chair;
void * customer(void * arg)
{

    int* customer_id = (int*)arg;
    printf("I am Customer %d\n",customer_id);
    sem_wait(&empty1);
    printf("Enter room customer number %d\n",customer_id);
    shop.push(customer_id);
    //sleep(1);

    pthread_mutex_lock(&lock2);

    sem_wait(&empty2);
    seat_sofa = shop.front();
    sofa.push(seat_sofa);
    printf("Customer seat sofa %d\n",customer_id);
    shop.pop();
    sem_wait(&empty3);
    pthread_mutex_lock(&lock3);
    getup_sofa = sofa.front();
    chair.push(getup_sofa);
    sofa.pop();
    pthread_mutex_unlock(&lock3);
    printf("Get up from sofa %d\n",customer_id);
    pthread_mutex_unlock(&lock2);

    //sem_post(&empty3);





    printf("Seat in barber chair %d\n",customer_id);
    pthread_mutex_lock(&lock9);

    seat_chair = chair.front();
    sem_post(&barber_ready);
    sem_wait(&finished);
    printf("leave barber chair %d\n",customer_id);
    //sem_post(&leave_chair);

    pthread_mutex_unlock(&lock5);
    pthread_mutex_lock(&lock8);
    printf("make payment %d\n",customer_id);
    payment_id=customer_id;
    sem_post(&payment);
    pthread_mutex_lock(&lock6);
    sem_wait(&receipt);
    printf("exit from shop %d\n",customer_id);

    pthread_mutex_unlock(&lock6);
    sem_post(&empty1);

}



void * barber(void * arg)
{
    int* barber_id = (int*)arg;
	while(true){

            sem_wait(&barber_ready);
            printf("Barber %d cutting hair %d\n",barber_id,chair.front());
            chair.pop();
            pthread_mutex_unlock(&lock9);
            sem_post(&finished);
            //sem_wait(&leave_chair);
            sem_post(&empty2);
	}
}



void * cashier(void * arg)
{

	while(true)
	{
        pthread_mutex_lock(&lock5);
        sem_wait(&payment);
        printf("Accept payments from %d\n",payment_id);
        sem_post(&empty3);
        pthread_mutex_unlock(&lock8);
        pthread_mutex_unlock(&lock5);
        pthread_mutex_unlock(&lock6);
        sem_post(&receipt);
	}

}


int main(void)
{
    printf("\t\t\t\tGroup: 8\n");
	printf("\t\t\t\tName: Md Saiful\n");
	printf("\t\t\t\tID: 2019-2-60-040\n");

    ////
	pthread_t thread1[250];
	pthread_t thread2[3];
	pthread_t thread3;
    int x[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
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

