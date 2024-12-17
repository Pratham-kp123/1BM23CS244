#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE] = {0};

void insert() { 
    int key, index, i, hkey; 
    printf("\nEnter a value to insert into hash table: "); 
    scanf("%d", &key); 
    hkey = key % TABLE_SIZE; 

    for (i = 0; i < TABLE_SIZE; i++) {      
        index = (hkey + i) % TABLE_SIZE;     
        if (h[index] == 0) {  
            h[index] = key;         
            printf("No of probes for %d is %d\n", key, i + 1);
            return;     
        }    
    }    

    printf("\nElement cannot be inserted: Table is full\n");
}

void search() { 
    int key, index, i, hkey;
    printf("\nEnter search element: "); 
    scanf("%d", &key); 
    hkey = key % TABLE_SIZE; 

    for (i = 0; i < TABLE_SIZE; i++) {    
        index = (hkey + i) % TABLE_SIZE; 
        if (h[index] == key) {      
            printf("Value is found at index %d\n", index);    
            return;   
        }  
    }  

    printf("\nValue is not found\n");
}

void display() {  
    int i;  
    printf("\nElements in the hash table are:\n"); 
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("At index %d \t value = %d\n", i, h[i]);
    }
}

int main() {  
    int opt; 
    while (1) {        
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n");  
        scanf("%d", &opt);    
        switch (opt) {           
            case 1: insert(); break;           
            case 2: display(); break;           
            case 3: search(); break;            
            case 4: exit(0);        
            default: printf("Invalid option! Try again.\n");
        }    
    }
    return 0;
}
/* Output: 

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
1

Enter a value to insert into hash table: 11
No of probes for 11 is 1

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
1

Enter a value to insert into hash table: 12
No of probes for 12 is 1

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
1

1Enter a value to insert into hash table: 3
No of probes for 3 is 1

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
1

Enter a value to insert into hash table: 13
No of probes for 13 is 2

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
2

Elements in the hash table are:
At index 0 	 value = 0
At index 1 	 value = 11
At index 2 	 value = 12
At index 3 	 value = 3
At index 4 	 value = 13
At index 5 	 value = 0
At index 6 	 value = 0
At index 7 	 value = 0
At index 8 	 value = 0
At index 9 	 value = 0

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
3

Enter search element: 0
Value is found at index 0

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
3

Enter search element: 13
Value is found at index 4

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
5
Invalid option! Try again.

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
4


=== Code Execution Successful ===
*/
