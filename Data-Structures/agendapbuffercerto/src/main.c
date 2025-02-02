/*schedule without using variables 
    menu: 1 - Add person
          2 - Remove person
          3 - Search person
          4 - List all
          5 - Exit
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //memory allocation for temporary inputs

    /*
    [select (4)][counter (4)][name (50)][age (4)][email (50)][search (50)] = 162 bytes]
    */
    void *pBuffer = malloc( 
      sizeof( int ) //select
      + sizeof( int ) //counter
     + 50 //name
      + (sizeof( int )) //age (will be used as an index)
     + 50 //email
     + 50); //search


      //check if it allocated successfully 
    if(!pBuffer){
        printf("failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    //setting the pointers to different parts of the buffer
    void *select = pBuffer;
    void *counter = (char *)select + sizeof(int);
    void *tempName = (char *)counter + sizeof(int);
    void *tempAge = (char *)tempName + 50;
    void *tempEmail = (char *)tempAge + sizeof(int);
    void *search = (char *)tempEmail + 50 ;
    void *data = (char *)search + 50;
    
    //initialize counter

    memset(counter, 0, sizeof(int));

//menu 
for(;;){
    printf("select an option: \n 1) Add Person \n 2) Remove Person \n 3) Search Person \n 4) List all \n 5) Exit  \n ");
    scanf("%d", ( int * ) select);

    switch ( * ( int* ) select ){
        //add person
            case 1: {
                printf("Enter name: ");
                scanf("%49s", (char *)tempName);
                printf("Enter age: ");
                scanf("%d", (int *)tempAge);
                printf("Enter email: ");
                scanf("%49s", (char *)tempEmail);


                // resize the buffer to one more person (each person is using 104 bytes)
                void *newBuffer = realloc(pBuffer, ((char *)data - (char *)pBuffer) + (*(int *)counter + 1) * 104);

                if (!newBuffer) {
                    printf("Memory reallocation failed\n");
                    free(pBuffer);
                    exit(EXIT_FAILURE);
                }
                pBuffer = newBuffer;

                // Update pointers after reallocation
                select = pBuffer;
                counter = (char *)select + sizeof(int);
                tempName = (char *)counter + sizeof(int);
                tempAge = (char *)tempName + 50;
                tempEmail = (char *)tempAge + sizeof(int);
                search = (char *)tempEmail + 50;
                data = (char *)search + 50;

                //copies the data into the allocated memory for the new person 
                memcpy((char *)data + (*(int *)counter) * 104, tempName, 50);
                memcpy((char *)data + (*(int *)counter) * 104 + 50, tempAge, sizeof(int));
                memcpy((char *)data + (*(int *)counter) * 104 + 54, tempEmail, 50);
                
                //increments counter
                
                (*(int *)counter)++;
                
                break;
            }

        //remove a person
        case(2) : {
            if(*(int *) counter == 0 ){
                printf("There is no person to remove \n");
                break;
               
            }

            printf("\nEnter the name you want to remove: \n");
            scanf("%49s", (char * ) search);

            //using tempAge as an index inside the buffer (i did this because whenever i tried to create a new pointer to an index the code stopped working and i got lazy...)
            *( int * )tempAge = 0;
            
            //loop through the buffer comparing names. when it's found it uses memove to shift data and remove the person
            while((* ( int *)tempAge) < ( * ( int * ) counter ) ){
                if (strcmp((char *) data +(* ( int *)tempAge) * 104, (char *)search)){

                    ( * (int* )tempAge )++;

                    continue;
                    
        }
                // Shift remaining people and remove found person's data
            memmove((char * ) data + ( * ( int  *) tempAge) * 104,
            (char * ) data + ( * ( int  * ) tempAge + 1) * 104,
            ( * ( int  * ) counter - * ( int  * ) tempAge - 1) * 104);      

                //resize the buffer
               void *newBuffer = realloc(pBuffer, ((char *)data - (char *)pBuffer) + (*(int *)counter - 1) * 104);
                    if (newBuffer) {
                        pBuffer = newBuffer;
                        select = pBuffer;
                        counter = (char *)select + sizeof(int);
                        tempName = (char *)counter + sizeof(int);
                        tempAge = (char *)tempName + 50;
                        tempEmail = (char *)tempAge + sizeof(int);
                        search = (char *)tempEmail + 50;
                        data = (char *)search + 50;
                    }
                    //decrements counter
                    (*(int *)counter)--;
                    printf("Person removed\n");
                    *(char *)search = 1;
                    break;
        }
             if (*(char *)search != 1) printf("Person not found\n");
                *(char *)search = 0;
                break;

        }

        
        break;
        //search name
        case(3): {
           if (*(int *)counter == 0) {
                    printf("No Person to search\n");
                    break;
                }

                printf("Enter name to search: ");
                scanf("%49s", (char *)search);

                //using tempAge as and index again
                * ( int * ) tempAge = 0;

                //loops through the list to find the chosen name and if found, print it

                while (*(int *)tempAge < *(int *)counter) {
                    if (!strcmp((char *)data + (*(int *)tempAge) * 104, (char *)search)) {
                        printf("Found:\nName: %s\nAge: %d\nEmail: %s\n",
                               (char *)data + (*(int *)tempAge) * 104,
                               *(int *)((char *)data + (*(int *)tempAge) * 104 + 50),
                               (char *)data + (*(int *)tempAge) * 104 + 54);
                        *(char *)search = 1;

                        break;
                    }
                    (*(int *)tempAge)++;
                }
                if (*(char *)search != 1) printf("Person not found\n");
                *(char *)search = 0;
                break;
            }

        break;
        
        //list everyone
        case(4): {
                if (*(int *)counter == 0) {
                    printf("No Person to list\n");
                    break;
                }

                //tempAge as an index :thumbup:
                *(int *)tempAge = 0;
                while (*(int *)tempAge < *(int *)counter) {
                    printf("Person %d:\nName: %s\nAge: %d\nEmail: %s\n\n",
                           *(int *)tempAge + 1,
                           (char *)data + (*(int *)tempAge) * 104,
                           *(int *)((char *)data + (*(int *)tempAge) * 104 + 50),
                           (char *)data + (*(int *)tempAge) * 104 + 54);
                    (*(int *)tempAge)++;
                }
                break;
            }
        //exit
        case(5): {
            free(pBuffer);
            
        exit(0);
        }
        break;
        

    default: 
    printf("Invalid option. \n");
    break;
    }
    }

    return 0;
}
