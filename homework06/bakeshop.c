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


int customersAllowed = 5;
int totalCustomers = 10;

//threads
pthread_t bakerBakingThread;
pthread_t bakerCashingThread;
pthread_t customerThread[10] //max customers -> 10

//semaphores
sem_t semBaker;
sem_t semCustomers;
sem_t semStoreCapacity;


void* bakingBread(){
    //to-do
}

void* buying(){
//to-do

}


int main(){
    //to-do

    pthread_exit(NULL); //main doesn't exit until all threads have exited
}





