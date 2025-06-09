/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void create_node(struct ListNode** inicio, struct ListNode** fim, int value){
    struct ListNode* new = (struct ListNode*) malloc(sizeof(struct ListNode));

    new->val = value;
    new->next = NULL;
    if(*inicio == NULL){
        *inicio = new;
        *fim = new;
    } else{
        (*fim)->next = new;
        *fim = new;
    }
    *fim = new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* inicio = NULL;
    struct ListNode* fim = NULL;

    int sum, res, carry = 0;

    while(l1 || l2){
        if(l1 && !l2)
            sum = l1->val;
        else if(!l1 && l2)
            sum = l2->val;
        else
            sum = l1->val + l2->val;

        if(carry == 1){
            sum += 1;
            carry = 0; 
        }


        if(sum < 10)
            create_node(&inicio, &fim, sum);
        else{
            create_node(&inicio, &fim, sum%10);
            carry = 1;
        }

        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;

    }

    if(carry == 1)
        create_node(&inicio, &fim, 1);


    return inicio;
}

