// https://medium.com/codex/hash-tables-with-singly-linked-lists-in-c-efc3c0166065
// Singly Linked_List 
node *head = hash_table[hash_value];

newnode->next = hash_table[hash_value];
hash_table[hash_value] = newnode;

node *tmp;
node *cursor;
for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            cursor = table[i];
            while (cursor != NULL)
            {
                tmp = cursor;
                cursor = cursor->next;
                free(tmp);
            }
}
}