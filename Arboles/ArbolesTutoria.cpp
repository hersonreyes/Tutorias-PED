#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};


void
printInorder (struct Node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder (node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    printInorder (node->right);
}

void
postOrder (struct Node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    postOrder (node->left);

    /* now recur on right child */
    postOrder (node->right);

    /* then print the data of node */
    cout << node->data << " ";
}

Node *
insert (Node * t, int d)
{
    if (t == NULL)
    {
        return new Node (d);
    }

    if (d < t->data)
    {
        t->left = insert (t->left, d);
    }
    else
    {
        t->right = insert (t->right, d);
    }

    return t;

}

struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node* maxValueNode(struct Node* node)
{
    struct Node* current = node;

    while (current && current->right != NULL)
        current = current->right;

    return current;
}




Node * search (Node * t, int k)
{
    if(t==NULL){
        cout<<"Numero no encontrado"<<endl;
        return NULL;
    }

    if (t->data == k)
    {
        return t;
    }

    if (k < t->data)
    {
        return search (t->left, k);
    }
    else
    {
        return search (t->right, k);
    }
}



int main()
{
    struct Node* root = NULL;
    int array[]={5,3,7,2,1};
    int i;
    int n = sizeof (array) / sizeof (array[0]);

    for(i=0;i<n;i++){
        root=insert(root,array[i]);
    }

    root = insert(root,100);
    cout<<root->data<<endl;




    return 0;
}
