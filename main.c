#include <stdio.h>
#include <stdlib.h>
#include "simplelist.h"

int main(int argc, char const *argv[])
{
    node * head = create_node(1,NULL);
    
    for(int i  = 2 ; i<8;i++){
        head = add_tail(head,i);
    }

    print_list(head);
    printf("\n");
    head = add_head(head,0);

    print_list(head);
    printf("\n");

    head = add_pos(head,0,-1);
    print_list(head);

    return 0;
}
