/*
 * Implementation of a doubly linked List with multiple features of list manipulation
 * @author Adam Makaoui
 *
 * Expected output:
 * Intial list: 2 3 4 5 8 11 14 14
 * list size: 8
 * Delete element with value 8: 2 3 4 5 11 14 14
 * Insert 12 after 11 by reverse search: 2 3 4 5 11 12 14 14
 * Swap 3 and 12: 2 12 4 5 11 3 14 14
 * Swap 4 and 5: 2 12 5 4 11 3 14 14
 * Swap again 4 and 5: 2 12 4 5 11 3 14 14
 * Reverse the list: 14 14 3 11 5 4 12 2
 * Push 55 and then reverse the list again: 55 2 12 4 5 11 3 14 14
 * Create another list: 7 15 30 60 120
 * Concatenate two lists: 55 2 12 4 5 11 3 14 14 7 15 30 60 120
 * Revese the new list: 120 60 30 15 7 14 14 3 11 5 4 12 2 55
 * Insert one 3 and two 7 after 15: 120 60 30 15 3 7 7 7 14 14 3 11 5 4 12 2 55
 * Apply unique function to the list: 120 60 30 15 3 7 14 3 11 5 4 12 2 55
 * Shift left 3 times: 15 3 7 14 3 11 5 4 12 2 55
 * Rotate left 2 times: 7 14 3 11 5 4 12 2 55 15 3
 * Distance between 14 and 15: 8
 * Distance between 15 and 14: -8
 * Distance between 5 and 4: 1
 * Distance between 5 and 5: 0
 * Distance between begin and end: 10
 * list size: 11
 * Create new list from array: 11 5 4 12 2
 * New list is included in the other one: Yes
 * Free up the memory!
ote
 *
 */

#include<stdbool.h> // bool
#include<stdio.h> // printf()
#include<stdlib.h> // malloc()

struct node* pop_front(struct node* ref);


struct node  {
    int data;
    struct node* next;
    struct node* prev;
};

/*!
 * \brief create Allocates memory and create new single node
 * \param elem - The value of node
 * \return node - Pointer to the new node
 */
struct node* create(int elem) {
    struct node* newNode
            = (struct node*)malloc(sizeof(struct node));

    newNode->data = elem;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
/**
 *
 * @param ref - the node to reference (memory)
 * @return data - data value of the given reference node
 */
int value(struct node* ref) {
    return ref->data;
}

/**
 *
 * @param ref - the node to reference (memory)
 * @return node next - the ref's --> next node
 */
struct node* next(struct node* ref) {
    return ref->next;
}

/**
 *
 * @param ref - the node to reference (memory)
 * @return node prev - the ref's --> prev node
 */
struct node* prev(struct node* ref) {
    return ref->prev;
}

/*!
 * \brief begin Traverse the linked-list to the head of it
 * \param ref A node from list
 * \return head of list
 */
struct node* begin(struct node* ref) {
    while(ref->prev) {
        ref = prev(ref);
    }
    return ref;
}

/*!
 * \brief end Traverse the linked-list to the tail of it
 * \param ref A node from list
 * \return tail of list
 */
struct node* end(struct node* ref) {
    while(ref->next) {
        ref = next(ref);
    }
    return ref;
}

/*!
 * \brief erase Remove single given node and free allocated memory
 * \param ref Node to remove
 * \return Next node the newly removed node
 */
struct node* erase(struct node* ref) {
    struct node* nx = next(ref); // pointing to ref (target) node's next (nx)
    struct node* px = prev(ref); // pointing to ref (target) node's previous (px)

    free(ref);

    if(nx) {
        nx->prev = px;
    }

    if(px) {
        px->next = nx;
    }

    return nx;
}

/*!
 * \brief clear Removes all the nodes of list and free all allocated memory
 * \param ref A node from list
 */
void clear(struct node* ref) {
    ref = begin(ref);
    while((ref = erase(ref)) != NULL);
}

/*!
 * \brief push_back Append new node to the end of list
 * \param ref A node from list
 * \param newElem Value of new element
 * \return The tail of list
 */
struct node* push_back(struct node* ref, int newElem) {

    struct node* tail = end(ref);

    struct node* newNode = create(newElem);

    tail->next = newNode;
    newNode->prev = tail;

    return newNode;
}

/*!
 * \brief push_front Insert a new node to the front of list
 * \param ref A node from list
 * \param newElem Value of new element
 * \return The head of list
 */
struct node* push_front(struct node* ref, int newElem) {

    struct node* head = begin(ref);

    struct node* newNode = create(newElem);

    head->prev = newNode;
    newNode->next = head;

    return newNode;
}

/*!
 * \brief pop_back Removes a node from tail of list
 * \param ref A node from list
 * \return New tail of list
 */
struct node* pop_back(struct node* ref) {

    struct node* tail = end(ref);

    struct node* newTail = prev(tail);

    erase(tail);

    return newTail;
}

/*!
 * \brief pop_front Removes a node from head of list
 * \param ref A node from list
 * \return New head of list
 */
struct node* pop_front(struct node* ref) {

    struct node* head = begin(ref);

    return erase(head);
}

unsigned int size(struct node* ref) {
    unsigned int sz = 1;
    struct node* head = begin(ref);
    while((head = next(head))!=NULL) {
        sz++;
    }
    return sz;
}

/*!
 * \brief createFromArray create a list from an array
 * \param arr pointer to the array
 * \param size size of the array
 * \return
 */
struct node* createFromArray(const int arr[], unsigned int size) {
    struct node* list;
    for(unsigned int i = 0; i < size; i++) {
        if(i==0) {
            list = create(arr[i]);
            continue;
        }
        list = push_back(list, arr[i]);
    }
    return list;
}

/*!
 * \brief insert Insert a node after given node
 * \param ref Given node
 * \param newElem Value of new node
 * \return Pointer to the newly inserted node
 */
struct node* insert(struct node* ref, int newElem) {

    struct node* nx = next(ref);

    struct node* newNode = create(newElem);

    if(nx) {
        nx->prev = newNode;
    }

    newNode->next = nx;
    newNode->prev = ref;

    ref->next = newNode;

    return newNode;
}

/*!
 * \brief ffind Froward search and find an element in the list
 * \param ref Given node to start the search
 * \param elem Value to be searched in the list
 * \return First node containing the element if not found will return NULL
 */
struct node* ffind(struct node* ref, int elem) {
    while(ref != NULL && ref->data != elem) {
        ref = next(ref);
    }
    return ref;
}

/*!
 * \brief ffind Reverse (backward) search and find an element in the list
 * \param ref Given node to start the search
 * \param elem Value to be searched in the list
 * \return First node containing the element if not found will return NULL
 */
struct node* rfind(struct node* ref, int elem) {
    while(ref != NULL && ref->data != elem) {
        ref = prev(ref);
    }
    return ref;
}

/**
 *\brief checks to see if two nodes are adjacent
 * @param A - first node
 * @param B - second node
 * @return  1 or 0 (True or False)
 */
int isAdjacent(struct node *A,struct node *B) {
    return ( A->next == B && B->prev == A ) || ( A->prev == B && B->next == A );
}

int AtoB(struct node *A,struct node *B) {
    return ( A->next == B && B->prev == A );
}
int BtoA(struct node *A,struct node *B) {
    return ( B->prev == A && A->next == B );
}

void refreshOuterPointers(struct node* A) {
    if (A->prev != NULL)
        A->prev->next = A;

    if (A->next != NULL)
        A->next->prev = A;
}

/*!
 * \brief swap Swap position of two nodes with each other within one list
 * \param ref1 A node from list
 * \param ref2 A node from list
 */
void swap(struct node* A, struct node* B) {

    struct node* swapperVector[4];
    struct node* temp;

    if (A == B) return;

    if (B->next == A) {
        temp = A;
        A = B;
        B = temp;
    }

    swapperVector[0] = A->prev;
    swapperVector[1] = B->prev;
    swapperVector[2] = A->next;
    swapperVector[3] = B->next;

    if (isAdjacent(A,B)) {
        A->prev = swapperVector[2];
        B->prev = swapperVector[0];
        A->next = swapperVector[3];
        B->next = swapperVector[1];
    } else {
        A->prev = swapperVector[1];
        B->prev = swapperVector[0];
        A->next = swapperVector[3];
        B->next = swapperVector[2];
    }

    refreshOuterPointers(A);
    refreshOuterPointers(B);
}


/*!
 * \brief reverse Reverse the elements order of list
 * \param ref A node from list
 */
void reverse(struct node* ref) {
    struct node* head = begin(ref); // finding head of the list
    struct node* tail = end(ref); // finding tail of the list

    while(head != tail) { // Stop condition for list with odd elements
        struct node* nx = next(head);
        struct node* px = prev(tail);

        swap(head, tail);

        if(tail == nx) { // Stop condition for list with even elements
            break;
        }

        head = nx;
        tail = px;
        
    }
}

/*! Recursive implementation of concat
 * \brief concat Concatenate two list with each other
 * \param ref1 A node from list 1
 * \param ref2 A node from list 2
 * \return Pointer to the head of concatenated list
 */
struct node* concat(struct node* ref1, struct node* ref2) {
    /* Your code here */

    ref1 = end(ref1);
    ref2 = begin(ref2);

    ref1->next = ref2;
    ref2->prev = ref1;

   return begin(ref1); //
}

bool compare(struct node* node1, struct node* node2) {

    // not true as default
    bool boolVal = false;

    if(node1->data = node2->data) {
        if(node1->next = node2->next) {
            if(node1->prev = node2->prev){
                boolVal = true;
            }
        }
    }
    // true value of comparing node1 and node2
    return boolVal;
}

void printNode(struct node* node1) {
    if (node1 != NULL) {
        printf("%d %s", node1->data, "Current Node': ");
        printf("%d %s", node1->next->data, "Next Node : ");
        printf("%d %s", node1->next->data, "Prev Node: ");

    }
}

/*!
 * \brief distance Returns the number of hops from ref1 to ref2.
 * \param ref1
 * \param ref2
 * \return distance is positive if ref1 appears before ref2 and negative if ref2 appears before ref1
 */
int distance(struct node* ref1, struct node* ref2) {

    int dist = 0;
    int refOneIndex = 0;
    int refTwoIndex = 0;
    int currentIndex = 0;

    //printNode(ref1);
   // printNode(ref2);

    struct node *tempStartNode;
    tempStartNode =  begin(ref1);
    /* Your code here */

    //
    if(ref1 == ref2) {
        return 0;
    }

    // loop as long as node is not null (not end or bad node given)
    while(tempStartNode!=NULL) {

        // check if we find ref1
        if (tempStartNode == ref1) {
            refOneIndex = currentIndex;
        }

        // check if we find ref1
        if (tempStartNode == ref2) {
            refTwoIndex = currentIndex;
        }
        // inc current index in DDL
        currentIndex++;
        // move node forward
        tempStartNode = tempStartNode->next;
    }

    dist =  refTwoIndex - refOneIndex;

    return dist;
}

/*!
 * \brief unique Eliminates all but the first element from every consecutive group of equivalent elements from the list
 * \param ref A node form list
 * \return The head of the list
 */
struct node* unique(struct node* ref) {
    struct node* head = begin(ref);
    struct node *current, *index;

    /* Your code here */

    while ( head->next != NULL ){

        if ( head->data == head->next->data ) {

            while ( head->data == head->next->data ) {

                struct node* temp = head->next->next;

                free(head->next);

                head->next = temp;

            }

            head->next->prev = head;

        }else{

            head = head->next;

        }
    }

    return head;
}


/*!
 * \brief rotate_left Performs a left rotation on list.
 * Swaps the elements in the list in such a way that the
 * element n_first becomes the first element of the
 * new list and n_first - 1 becomes the last element.
 * \param ref A node from list
 * \param n The number of positions to rotate
 * \return The head (begin) of the list
 */
struct node* rotate_left(struct node* ref, int n) {
    struct node* head = begin(ref);
    struct node* tail = end(ref);

    /* Your code here */
    struct node *popped = NULL;
    struct node *pushed = NULL;


    struct node * tempHead = head;

    for (int i = 0; i<n; i++) {
        // push head to the back
        push_back(head, head->data);

        // pop head
        pop_front(head);

        // move head from null to its next non null after popping
        head = head->next;
    }
    return head;
}

/*!
 * \brief shift_left Shifts the elements towards the beginning of the range.
 * \param ref A node from list
 * \param n The number of positions to shift
 * \return
 */
struct node* shift_left(struct node* ref, int n) {
    /* Your code here */
    for(int i = 0; i<n; i++) {
        if(ref!= NULL) {
            pop_front(ref);
        }
    }

    return begin(ref);
}

/*!
 * \brief minmax Returns the lowest and the greatest of the given list.
 * \param ref A node from list
 * \param min Minimum returned value
 * \param max Maximum returned value
 */
void minmax(struct node* ref, int* min, int* max) {
    /* Your code here */

    int minValue = *min;
    int maxValue = *max;

    for (ref = ref->next; ref != NULL; ref = ref->next) {
        if (ref->data > maxValue)
            erase(ref);;
        if (ref->data < minValue)
            erase(ref);

        printf("Min given was 5, max 50 from two integer, used AND symbol to insert as memory addr. instead of int. The Largest value in the list is: %d  The Smallest value in the list is: %d\n", maxValue, minValue);
        return;

    }

}

/*!
 * \brief includes Returns true if the list starting from ref2 node is a subset of the list starting from ref1.
 * \param ref1
 * \param ref2
 * \return
 */
bool includes(struct node* ref1, struct node* ref2) {
    /* Your code here */

    while ( ref1->next != NULL ){


        if ( ref2 == NULL ){
            return true;
        }

        if ( ref2->data == ref1->data ){

            ref2 = ref2->next;

            //printf("\ntesting\n");

        } else {

            ref2 = begin(ref2);
        }

        //printf("\ntesting2\n");

        ref1 = ref1->next;

    }

    return false;


    return false;
}



/*!
 * \brief print Print all elements of list following a new line
 * \param ref A node from list
 */
void print(struct node* ref) {
    struct node* n = begin(ref);

    do {
        printf("%d ",n->data);
    } while((n = next(n)) != NULL);
    printf("\n");
}


int main() {

    struct node* list = create(3);

    push_back(list, 4);

    push_front(list, 2);

    for(int i = 5; i < 15; i+=3) {
        list = push_back(list, i);
    }

    push_back(list, 14);

    printf("Intial list: ");
    print(list);

    printf("list size: %d\n", size(list));


    printf("Delete element with value 8: ");
    erase(ffind(begin(list), 8));
    print(list);

    printf("Insert 12 after 11 by reverse search: ");
    insert(rfind(end(list), 11), 12);
    print(list);

    printf("Swap 3 and 12: ");
    swap(ffind(begin(list), 3), rfind(end(list), 12));
    print(list);

    printf("Swap 4 and 5: ");
    swap(ffind(begin(list), 4), ffind(begin(list), 5));
    print(list);

    printf("Swap again 4 and 5: ");
    swap(ffind(begin(list), 4), ffind(begin(list), 5));
    print(list);


    printf("Reverse the list: ");
    reverse(list);
    print(list);

    printf("Push 55 and then reverse the list again: ");
    push_back(list, 55);
    reverse(list);
    print(list);


    printf("Create another list: ");
    struct node* list2 = create(120);
    for(int i = 60; i > 5; i/=2) {
        list2 = push_front(list2, i);
    }
    print(list2);


    printf("Concatenate two lists: ");
    list = concat(list, list2);
    print(list);

    printf("Reverse the new list: ");
    reverse(list);
    print(list);


    printf("Insert one 3 and two 7 after 15: ");
    struct node* newNode = insert(ffind(begin(list), 15), 3);
    newNode = insert(newNode, 7);
    insert(newNode, 7);
    print(list);

    printf("Apply unique function to the list: ");
    unique(list);
    print(list);


    printf("Shift left 3 times: ");
    shift_left(list, 3);
    print(list);


    printf("Rotate left 2 times: ");
    rotate_left(list, 2);
    print(list);

    list = begin(list);
    printf("Distance between 14 and 15: %d\n", distance(ffind(list, 14), ffind(list, 15)));
    printf("Distance between 15 and 14: %d\n", distance(ffind(list, 15), ffind(list, 14)));
    printf("Distance between 5 and 4: %d\n", distance(ffind(list, 5), ffind(list, 4)));
    printf("Distance between 5 and 5: %d\n", distance(ffind(list, 5), ffind(list, 5)));
    printf("Distance between begin and end: %d\n", distance(begin(list), end(list)));
    printf("list size: %d\n", size(list));

    printf("Create new list from array: ");
    int arr[] = {11, 5, 4, 12, 2};
    struct node* list3 = createFromArray(arr, sizeof arr/sizeof(int));
    print(list3);

    printf("New list is included in the other one: %s\n", includes(begin(list), begin(list3)) ? "Yes" : "No");

    int min = 5;
    int max = 50;
    minmax(list,&min,&max);

    printf("Free up the memory!\n");
    clear(list);
    clear(list3);

    return 0;
}
