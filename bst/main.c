#include <stdio.h>
#include <stdlib.h>

typedef struct bst
{
    int data;
    struct bst *right;
    struct bst *left;
} Tree;

Tree *create_node(int data)
{
    Tree *new = malloc(sizeof(Tree));
    new->right = NULL;
    new->left = NULL;
    new->data = data;
    return new;
}

Tree *insert(Tree *root, int data)
{
    if (root == NULL)
        return create_node(data);

    if (root->data > data)
        root->left = insert(root->left, data);

    if (root->data < data)
        root->right = insert(root->right, data);

    return root;
}

Tree *find_min(Tree *root)
{
    if (root->left == NULL)
        return root;

    return find_min(root->left);
}

Tree *find_node(Tree *root, int data)
{
    if (root == NULL || root->data == data)
        return root;

    return root->data > data ? find_node(root->left, data) : find_node(root->right, data);
}

Tree *delete_node(Tree *root, int data)
{
    if (root == NULL)
        return root;
    else if (root->data > data)
        root->left = delete_node(root->left, data);
    else if (root->data < data)
        root->right = delete_node(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        else if (root->left == NULL)
        {
            Tree *temp = root;
            root = root->right;
            free(temp);
            temp = NULL;
            return root;
        }
        else if (root->right == NULL)
        {
            Tree *temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
            return root;
        }
        else
        {
            Tree *min = find_min(root->right);
            root->data = min->data;
            root->right = delete_node(root->right, min->data);
            free(min);
            min = NULL;
        }
    }
    return root;
}

int node_count(Tree *root)
{
    if (root == NULL)
        return 0;

    return 1 + node_count(root->left) + node_count(root->right);
}

void print_inorder(Tree *root)
{
    if (root != NULL)
    {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    Tree *root = NULL;
    root = insert(root, 20);
    root = insert(root, 16);
    root = insert(root, 60);
    root = insert(root, 85);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 18);
    root = insert(root, 17);
    root = insert(root, 19);

    print_inorder(root);

    puts("");

    printf("Count of nodes : %d\n", node_count(root));

    Tree *deneme = find_node(root, 70);
    if (deneme == NULL)
        printf("aranan node agacta yok!\n");
    else
        printf("aranan node bulundu -> %d", deneme->data);

    puts("");

    root = delete_node(root, 16);
    print_inorder(root);

    return 0;
}
