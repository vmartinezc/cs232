/*
    Busy Bakeshop: 
    This assignment explores concurrency and semaphores.
    The program runs several different threads. 
    The concurrent threads use semaphores to coordinate the resources in a simple bakery


    @author: Valeria Martínez Castro (vam6)
    @date: 11 April 2020
    CS232 @ Calvin University

 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>



/*
    SPECS

    - Only one baker
    - Only 5 customers at a time 
    - If no one @ the cash register -> Baker can bake bread
    - If no bread when customer arrives, customer waits in the shop until more loaves
      are baked and one loaf of bread is obtained
    - Customer obtains a loaf, they pay at the cash register and wait for receipt
    - Baker receives a payment, baker issues a receipt
    - Customer can only exit after receiving a receipt

 */



//threads
pthread_t bakerBakingThread;
pthread_t bakerCashingThread;
pthread_t customerThread[10]; //max customers -> 10

//semaphores
sem_t semBaker;
sem_t semCustomers;
sem_t semStoreCapacity;

//global vars
int customersAllowed = 5;
int totalCustomers = 10;
int checkoutLine[10];

int loavesAvailable = 0;
int loavesBaked = 0;
int loavesCheckedOut = 0;

int inStore = 0;
int customersCheckedOut = 0;


void *bakingBread(){

    struct timespec tim;

    while (loavesBaked < 10){
        tim.tv_sec = 1;
        tim.tv_nsec = 0; //for some reason, i also need nano seconds???
       
        
        sem_wait(&semBaker);
        fprintf(stderr, "*** Baker: Here I am baking a loaf of bread *****\n");
        loavesBaked++;
        loavesAvailable++;
        fprintf(stderr, "\n *** Baked loaves: %d\n *** Available loaves: %d\n", loavesBaked, loavesAvailable);

        sem_post(&semBaker);
        nanosleep(&tim, &tim);
    }

    fprintf(stderr, "Ten loaves baked!\n");
}

void *buying(){
     struct timespec tim;

    tim.tv_sec = 1;
    tim.tv_nsec = 0; //for some reason, i also need nano seconds???

    while (customersCheckedOut < totalCustomers){
        if(loavesCheckedOut > customersCheckedOut){


            fprintf(stderr, "Customer %d currently waiting to get checkout out \n", checkoutLine[customersCheckedOut]);
            sem_wait(&semCustomers);
            sem_wait(&semBaker);


            fprintf(stderr, "Baker is at the cash register\n");
            fprintf(stderr, "Customer %d has paid\n", checkoutLine[customersCheckedOut]);

            nanosleep(&tim,&tim);
            fprintf(stderr, "Customer %d has paid\n", checkoutLine[customersCheckedOut]);
           // fprintf(stderr,"Customer %d has received their bread... \n", customerId);
            customersCheckedOut++;

            sem_post(&semCustomers);
            sem_post(&semBaker);
            fprintf(stderr, "I am the Baker and I'm going back to baking\n");
            nanosleep(&tim, &tim);
        }

    
        //checkout every customer in queue as long as there are still loaves available
    }
}

void* gettingBread(void* customerId){
    
    struct timespec tim;
    tim.tv_sec = 1;
    tim.tv_nsec = 0; //for some reason, i also need nano seconds???

    sem_wait(&semStoreCapacity);
    sem_wait(&semCustomers);
    inStore++;
    fprintf(stderr,"Customer %d has entered the store.\n", customerId);
    fprintf(stderr, "There are currently %d customers in the store.\n", inStore);
    sem_post(&semCustomers);


    while(1){
        sem_wait(&semBaker);
        nanosleep(&tim, &tim);
        

        while(loavesAvailable == 0){
            nanosleep(&tim, &tim);
        }

        if (loavesAvailable > 0){
             loavesAvailable --;
             fprintf(stderr,"Customer %d has received their bread... \n", customerId);
             loavesCheckedOut++;
             //nanosleep(&tim, &tim);
             checkoutLine[loavesCheckedOut-1] = customerId;
             sem_post(&semCustomers); //release the semaphore
             break;
        }
       // sem_post(&semBaker);

    }

    nanosleep(&tim,&tim);
    sem_wait(&semCustomers);
    inStore--;
    fprintf(stderr, "Customer %d has left the store. \n", customerId);
    sem_post(&semCustomers);
    sem_post(&semStoreCapacity);
    nanosleep(&tim,&tim);

}

int main(){
    sem_init(&semCustomers, 0,1);
    sem_init(&semBaker, 0, 1);
    sem_init(&semStoreCapacity,0, customersAllowed);

   // fprintf(stderr, " ***   semaphores initialized    *** ");
    fprintf(stderr, "\n -- Busy Bakeshop starting --  \n");

    // baking and cashing 
    pthread_create(&bakerBakingThread, NULL, bakingBread, NULL); //function bakingBread executed by baker thread
    pthread_create(&bakerCashingThread, NULL,buying, NULL);

    // customer threads
    for (int customerId = 1; customerId <= totalCustomers; customerId++){
       // inStore++;
        pthread_create(&customerThread[customerId], NULL, gettingBread, (void*)customerId);
    }


  //  fprintf(stderr, "customer thread done");
    pthread_exit(NULL); //main doesn't exit until all threads have exited
    fprintf(stderr, "\n --Baking done. Clients served ---- \n");
    exit(0);

}





