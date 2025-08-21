#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
sem_t A;
sem_t B;
sem_t finish;
int id,glass;
pthread_mutex_t lock1;//amon ekta jinis jetar kaj hoitase lock mane ki
void *Theater_function(void *);
void *student_ID_function(void *studentId);
int Flag = 0,count=0;


void *student_ID_function(void *studentId){
    int num = *(int *)studentId;
    printf("Student%d Arrives\n", num);
    sleep(1);//thik thak student
    if(count>=glass){// student 4 == 4 glass
        printf("Student%d is waiting  for a 3D glass.\n", num);
    }


    // 2
    sem_wait(&A);//
    pthread_mutex_lock(&lock1);
    count++;
    pthread_mutex_unlock(&lock1);
    printf("Student %d have a 3D glass and entering to theater.\n", num);

    sleep(1);
    pthread_mutex_lock(&lock1);
    id=num;
    sem_post(&B);
    //sleep(1);
    sem_wait(&finish);
    printf("Student %d has finished watching movie.\n", num);
    sleep(1);
    printf("Student%d returning 3D glass.\n", num);
    sem_post(&A);
}
void *Theater_function(void *userInput)
{

    while (!Flag)
    {
         sem_wait(&B);
        if (!Flag)
        {
            printf("Student%d is watching movie.\n",id);
            sem_post(&finish);
            pthread_mutex_unlock(&lock1);
        }
        else
        {
            printf("All of the students finished watching movie.\n");
            break;
        }
    }
}

int main()
{
    pthread_t Movie_Thread;
    pthread_t *st_id;

    int i,numStudents,numGlass;


    printf("Number of students:\n");

    scanf("%d",&numStudents); /// taking number of students

    printf("3D Glasses:\n");

    scanf("%d",&numGlass);///taking number of 3d glasses
    glass=numGlass;

    int Number[numStudents];
    st_id= (pthread_t*) malloc(sizeof(pthread_t)*numStudents); /// Dynamic memory allocation

    for (i = 0; i < numStudents; i++)
    {
        Number[i] = i+1;
    }


    sem_init(&A, 0, numGlass);
    sem_init(&B, 0, 0);
    sem_init(&finish, 0, 0);
    pthread_mutex_init(&lock1,0);


    pthread_create(&Movie_Thread, NULL, Theater_function, NULL); /// parameter as NUll


    for (i = 0; i < numStudents; i++)
    {
        pthread_create(&st_id[i], NULL,student_ID_function, (void *)&Number[i]); ///Sending number parameter as id
    }

    for (i = 0; i < numStudents; i++)
    {
        pthread_join(st_id[i],NULL);///Sending parameter as NUll
    }


    Flag = 1;

    sem_post(&B);
    pthread_join(Movie_Thread,NULL);
    return 0;
}
