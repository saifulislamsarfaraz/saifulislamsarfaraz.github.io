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
//Name :Md Jekrul Islam
//ID : 2019-2-60-046
/* Problem
    William Stallings presents a more complicated version of the barbershop problem, which he
    attributes to Ralph Hilzer at the California State University at Chico.
    Our barbershop has three chairs, three barbers, and a waiting area that can accommodate four
    customers on a sofa and that has standing room for additional customers. Fire codes limit the total
    number of customers in the shop to 20.
    A customer will not enter the shop if it is filled to capacity with other customers. Once inside, the
    customer takes a seat on the sofa or stands if the sofa is filled. When a barber is free, one of the
    customers from the sofa is served (whoever gets to the chair first) and, if there are any standing
    customers, one of them takes a seat on the sofa whoever gets the chance first. When a customer’s
    haircut is finished, any barber can accept payment, but because there is only one cash register,
    payment is accepted for one customer at a time. The barbers divide their time among cutting hair,
    accepting payment, and sleeping in their chair waiting for a customer.

In other words, the following synchronization constraints apply:

 Customers do the following functions in order: enter the Shop, sit on sofa, sit in the
    barber chair, pay, exit shop.

 Barbers do the following: they cut hair and accept payment.

 Customers cannot enter the shop if the shop is at capacity.

 If the sofa is full, an arriving customer cannot sit on the sofa until one of the customers
    on the sofa sits in the barber chair.

 If all three barber chairs are busy, an arriving customer cannot sit in the barber chair until
    one of the customers in a chair pays for the hair cut.

 The customer has to pay before the barber can accept payment.

 The barber must accept payment before the customer can exit shop.

Write code that enforces the synchronization constraints for Hilzer’s barbershop.*/

sem_t empty1; //using for shop
sem_t empty2; //using for sofa
sem_t empty3; //using for chair
sem_t barber_ready; // using for barber ready to hair cut
sem_t finished; // using haircut is complete
sem_t payment; // Customer pay bill
sem_t receipt; //receipt for payment

queue<int> shop; //  Enter all customer
queue<int> sofa; //  Enter 4 customer seat sofa at a time
queue<int> chair;//  Enter 3 customer seat chair at a time
queue<int> barbr;//  Enter 3 customer seat chair at a time
queue<int> paymnt;// Enter 1 Customer payment at a time


pthread_mutex_t lock1; //using lock for avoid critical section
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
	sem_init(&barber_ready,0,3);
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
void * customer(void * arg){

    int* customer_id = (int*)arg;
    printf("I am Customer %d\n",customer_id);
    sem_wait(&empty1);
    printf("Enter room customer number %d\n",customer_id);
    cnt++;
    shop.push(cnt);//Enter all customer

    sem_wait(&empty2);
    sleep(1);
    pthread_mutex_lock(&lock1);
    int push_sofa=shop.front();
    sofa.push(push_sofa);//Push sofa
    shop.pop();
    printf("Customer seat sofa %d\n",push_sofa);
    pthread_mutex_unlock(&lock1);
    sleep(1);

    sem_wait(&empty3);
    pthread_mutex_lock(&lock2);
    int push_chair=sofa.front();
    printf("Get up from sofa %d\n",push_chair);
    chair.push(push_chair);
    sofa.pop();
    pthread_mutex_unlock(&lock2);
    sleep(1);

    pthread_mutex_lock(&lock3);
    int push_customer=chair.front();
    barbr.push(push_customer);
    chair.pop();
    printf("Seat in barber chair %d\n",push_customer);
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
            sleep(2);
            pthread_mutex_lock(&lock4);
            int cutHairCustomer=barbr.front();
            paymnt.push(cutHairCustomer);
            barbr.pop();
            printf("Barber %d cutting hair %d\n",barber_id, cutHairCustomer);
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
	printf("\t\t\t\tName: Md Jekrul Islam\n");
	printf("\t\t\t\tID: 2019-2-60-046\n");

	pthread_t thread1[20];
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
