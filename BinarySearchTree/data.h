/**
 * This class creates defines variables and methods for data.c
 *
 * @author Ahmed Attar, 250726961
 */

typedef struct {
    char *name;
    int id;
} Key; //defining a data-type called "Key"

typedef struct {
    Key *key;
    int data;
} Node; //defining a data-type called "Node"


/*------FUNCTIONS TO IMPLEMENT----*/

Key *key_construct(char *in_name, int in_id); //Returns a pointer of type Key (key pointer)

int key_comp(Key key1, Key key2);

void print_key(Key *key);

void print_node(Node node);

int intcmp(const int *int1, const int *int2);