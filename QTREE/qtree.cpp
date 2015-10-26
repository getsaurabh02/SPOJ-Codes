///Random

struct node {

    int data;
    struct node * left;
    struct node * right;
};

int height (struct node * pNode)
{
    if (node == NULL)
        return 0;

    int lheight = height (pNode->left);
    int rheight = height (pNode->right);

    if (lheight > rheight) {

        return (lheight + 1);
    } else { 
        return (rheight + 1);
    }


}
