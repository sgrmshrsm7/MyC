#include <stdio.h>
#include <stdlib.h>

typedef struct iboNode{
        int ibo_id, level, items[5], mentoring_score, sale_score, childs;
        struct iboNode *child0, *child1, *child2;
} iboNode;

int nextiboid = 1;

iboNode *malloc_child(int id, int i0, int i1, int i2, int i3, int i4)
{
        iboNode *A;
        A = (iboNode *)malloc(sizeof(iboNode));
        int i;
        A -> ibo_id = id;
        A -> level = -1;
        A -> items[0] = i0;
        A -> items[1] = i1;
        A -> items[2] = i2;
        A -> items[3] = i3;
        A -> items[4] = i4;
        A -> mentoring_score = 0;
        A -> sale_score = 10 * i0 + 20 * i1 + 30 * i2 + 40 * i3 + 50 * i4;
        A -> childs = 0;
        A -> child0 = NULL;
        A -> child1 = NULL;
        A -> child2 = NULL;
        return A;
}

void increase10(iboNode *ibo, int level)
{
        if(ibo -> level < level)
        {
                ibo -> mentoring_score += 10;
                if(ibo -> child0 != NULL)
                        increase10(ibo -> child0, level);
                if(ibo -> child1 != NULL)
                        increase10(ibo -> child1, level);
                if(ibo -> child2 != NULL)
                        increase10(ibo -> child2, level);
        }
}

int increasebonus(iboNode *ibo)
{
        int bonus = 0, i;
        if(ibo -> child0 != NULL)
        {
                for(i = 0 ; i < 5 ; ++i)
                        bonus += (i + 1) * ibo -> child0 -> items[i];
                bonus += increasebonus(ibo -> child0);
        }
        if(ibo -> child1 != NULL)
        {
                for(i = 0 ; i < 5 ; ++i)
                        bonus += (i + 1) * ibo -> child1 -> items[i];
                bonus += increasebonus(ibo -> child1);
        }
        if(ibo -> child2 != NULL)
        {
                for(i = 0 ; i < 5 ; ++i)
                        bonus += (i + 1) * ibo -> child2 -> items[i];
                bonus += increasebonus(ibo -> child2);
        }
        ibo -> sale_score = 0;
        for(i = 0 ; i < 5 ; ++i)
                ibo -> sale_score += ibo -> items[i] * 10 * (i + 1);
        ibo -> sale_score += bonus;
        return bonus;
}

void insert_IBO(iboNode **ibo, iboNode *mentor, iboNode *A)
{
        if(*ibo == NULL)
        {
                A -> level = 0;
                *ibo = A;
        }
        else if(mentor != NULL && (mentor -> childs < 3))
        {
                A -> level = mentor -> level + 1;
                increase10(*ibo, A -> level);
                if(mentor -> childs < 2)
                        mentor -> mentoring_score += 90;
                else mentor -> mentoring_score += 190;
                if(mentor -> child0 == NULL)
                        mentor -> child0 = A;
                else if(mentor -> child1 == NULL)
                        mentor -> child1 = A;
                else mentor -> child2 = A;
                mentor -> childs += 1;
                increasebonus(*ibo);
        }
        else
        {
                printf("Node cannot be inserted in the tree");
                free(A);
                A = NULL;
        }
}

iboNode *createTree()
{
        iboNode *ibo = NULL;
        iboNode *A;
        A = malloc_child(nextiboid++, 2, 0, 2, 2, 0);
        insert_IBO(&ibo, NULL, A);
        A = malloc_child(nextiboid++, 1, 1, 1, 1, 1);
        insert_IBO(&ibo, ibo, A);
        A = malloc_child(nextiboid++, 0, 3, 1, 0, 3);
        insert_IBO(&ibo, ibo, A);
        A = malloc_child(nextiboid++, 0, 0, 0, 0, 1);
        insert_IBO(&ibo, ibo, A);
        A = malloc_child(nextiboid++, 2, 1, 0, 0, 1);
        insert_IBO(&ibo, ibo -> child0, A);
        A = malloc_child(nextiboid++, 0, 2, 0, 2, 2);
        insert_IBO(&ibo, ibo -> child0, A);
        A = malloc_child(nextiboid++, 0, 3, 1, 1, 1);
        insert_IBO(&ibo, ibo -> child0, A);
        A = malloc_child(nextiboid++, 1, 1, 0, 1, 2);
        insert_IBO(&ibo, ibo -> child1, A);
        A = malloc_child(nextiboid++, 1, 0, 1, 0, 0);
        insert_IBO(&ibo, ibo -> child1, A);
        A = malloc_child(nextiboid++, 1, 0, 3, 2, 1);
        insert_IBO(&ibo, ibo -> child2, A);
        return ibo;
}

void traverse(iboNode *ibo)
{
        int i;
        printf("\n\nIBO ID = %d", ibo -> ibo_id);
        printf("\nIBO Level = %d", ibo -> level);
        for(i = 0 ; i < 5 ; ++i)
                printf("\nQuantity for item%d = %d", i, ibo -> items[i]);
        printf("\nMentoring Score = %d", ibo -> mentoring_score);
        printf("\nSale Score = %d", ibo -> sale_score);
        printf("\nNumber of childs = %d", ibo -> childs);
        if(ibo -> childs > 0)
        {
                printf("\nChild IDs :");
                if(ibo -> child0 != NULL)
                        printf(" %d", ibo -> child0 -> ibo_id);
                if(ibo -> child1 != NULL)
                        printf(" %d", ibo -> child1 -> ibo_id);
                if(ibo -> child2 != NULL)
                        printf(" %d", ibo -> child2 -> ibo_id);
        }
        if(ibo -> child0 != NULL)
                traverse(ibo -> child0);
        if(ibo -> child1 != NULL)
                traverse(ibo -> child1);
        if(ibo -> child2 != NULL)
                traverse(ibo -> child2);
}

iboNode *searchmentor(iboNode *ibo, int mID)
{
        iboNode *retval = NULL;
        if(ibo -> ibo_id == mID)
                retval = ibo;
        else
        {
                if(ibo -> child0 != NULL)
                        retval = searchmentor(ibo -> child0, mID);
                if(ibo -> child1 != NULL && retval == NULL)
                        retval = searchmentor(ibo -> child1, mID);
                if(ibo -> child2 != NULL && retval == NULL)
                        retval = searchmentor(ibo -> child2, mID);
        }
        return retval;
}

void highestscorer(iboNode *ibo, int A[15][2])
{
        if(ibo -> mentoring_score + ibo -> sale_score > A[ibo -> level][0])
        {
                A[ibo -> level][0] = ibo -> mentoring_score + ibo -> sale_score;
                A[ibo -> level][1] = ibo -> ibo_id;
        }
        if(ibo -> child0 != NULL)
                highestscorer(ibo -> child0, A);
        if(ibo -> child1 != NULL)
                highestscorer(ibo -> child1, A);
        if(ibo -> child2 != NULL)
                highestscorer(ibo -> child2, A);
}

int maximumdescendant(iboNode *ibo, int A[15][2])
{
        int d = ibo -> childs;
        if(ibo -> child0 != NULL)
                d += maximumdescendant(ibo -> child0, A);
        if(ibo -> child1 != NULL)
                d += maximumdescendant(ibo -> child1, A);
        if(ibo -> child2 != NULL)
                d += maximumdescendant(ibo -> child2, A);
        if(A[ibo -> level][0] < d)
        {
                A[ibo -> level][0] = d;
                A[ibo -> level][1] = ibo -> ibo_id;
        }
        return d;
}

void childgreaterthanmentor(iboNode *ibo)
{
        if(ibo -> child0 != NULL)
        {
                if(ibo -> mentoring_score + ibo -> sale_score < ibo -> child0 -> mentoring_score + ibo -> child0 -> sale_score)
                        printf("\nIBO with ID %d has more score than mentor", ibo -> child0 -> ibo_id);
                childgreaterthanmentor(ibo -> child0);
        }
        if(ibo -> child1 != NULL)
        {
                if(ibo -> mentoring_score + ibo -> sale_score < ibo -> child1 -> mentoring_score + ibo -> child1 -> sale_score)
                        printf("\nIBO with ID %d has more score than mentor", ibo -> child1 -> ibo_id);
                childgreaterthanmentor(ibo -> child1);
        }
        if(ibo -> child2 != NULL)
        {
                if(ibo -> mentoring_score + ibo -> sale_score < ibo -> child2 -> mentoring_score + ibo -> child2 -> sale_score)
                        printf("\nIBO with ID %d has more score than mentor", ibo -> child2 -> ibo_id);
                childgreaterthanmentor(ibo -> child2);
        }
}

iboNode *searchdelete(iboNode *ibo, int id)
{
        iboNode *retval = NULL;
        if((ibo -> child0 != NULL && ibo -> child0 -> ibo_id == id) || (ibo -> child1 != NULL && ibo -> child1 -> ibo_id == id) || (ibo -> child2 != NULL && ibo -> child2 -> ibo_id == id))
                retval = ibo;
        else
        {
                if(ibo -> child0 != NULL)
                        retval = searchdelete(ibo -> child0, id);
                if(ibo -> child1 != NULL && retval == NULL)
                        retval = searchdelete(ibo -> child1, id);
                if(ibo -> child2 != NULL && retval == NULL)
                        retval = searchdelete(ibo -> child2, id);
        }
        return retval;
}

void leveldecrease(iboNode *ibo)
{
        ibo -> level -= 1;
        if(ibo -> child0 != NULL)
                leveldecrease(ibo -> child0);
        if(ibo -> child1 != NULL)
                leveldecrease(ibo -> child1);
        if(ibo -> child2 != NULL)
                leveldecrease(ibo -> child2);
}

iboNode *delete_IBO(iboNode *ibo, int id)
{
        if(ibo == NULL)
                printf("\nTree is empty!");
        else if(ibo -> ibo_id == id)
        {
                if(ibo -> child0 == NULL && ibo -> child1 == NULL && ibo -> child2 == NULL)
                {
                        free(ibo);
                        ibo = NULL;
                        printf("\nIBO with ID %d deleted successfully!", id);
                }
                else
                        printf("\nNo mentor for root IBO");
        }
        else
        {
                iboNode *temp, *temp1, *temp11;
                int i = 0;
                temp = searchdelete(ibo, id);
                if(temp == NULL)
                        printf("\nIBO with given ID not found!");
                else
                {
                        if(temp -> child0 != NULL && temp -> child0 -> ibo_id == id)
                                temp1 = temp -> child0;
                        else if(temp -> child1 != NULL && temp -> child1 -> ibo_id == id)
                                temp1 = temp -> child1;
                        else if(temp -> child2 != NULL && temp -> child2 -> ibo_id == id)
                                temp1 = temp -> child2;
                        printf("\n%d %d\n",temp->ibo_id,temp1 -> ibo_id);
                        if(temp1 -> childs == 0)
                        {
                                if(temp -> child0 == temp1)
                                        temp -> child0 = NULL;
                                else if(temp -> child1 == temp1)
                                        temp -> child1 = NULL;
                                else if(temp -> child2 == temp1)
                                        temp -> child2 = NULL;
                                temp -> sale_score += temp1 -> sale_score;
                                temp -> mentoring_score += temp1 -> mentoring_score;
                                for(i = 0 ; i < 5 ; ++i)
                                        temp -> items[i] += temp1 -> items[i];
                                temp -> childs -= 1;
                        }
                        else if(temp1 -> childs == 1)
                        {
                                if(temp1 -> child0 != NULL)
                                        temp11 = temp1 -> child0;
                                else if(temp1 -> child1 != NULL)
                                        temp11 = temp1 -> child1;
                                else if(temp1 -> child2 != NULL)
                                        temp11 = temp1 -> child2;
                                if(temp -> child0 == temp1)
                                        temp -> child0 = temp11;
                                else if(temp -> child1 == temp1)
                                        temp -> child1 = temp11;
                                else if(temp -> child2 == temp1)
                                        temp -> child2 = temp11;
                                temp -> sale_score += temp1 -> sale_score;
                                temp -> mentoring_score += temp1 -> mentoring_score;
                                for(i = 0 ; i < 5 ; ++i)
                                        temp -> items[i] += temp1 -> items[i];
                        }
                        else if(temp1 -> childs == 2 && temp -> childs < 3)
                        {
                                temp11 = NULL;
                                if(temp -> child0 != NULL && temp -> child0 != temp1)
                                        temp11 = temp -> child0;
                                else if(temp -> child1 != NULL && temp -> child0 != temp1)
                                        temp11 = temp -> child1;
                                else if(temp -> child2 != NULL && temp -> child0 != temp1)
                                        temp11 = temp -> child2;
                                temp -> child0 = temp1 -> child0;
                                temp -> child1 = temp1 -> child1;
                                if(temp1 -> child2 != NULL)
                                {
                                        if(temp -> child0 == NULL)
                                                temp -> child0 = temp1 -> child2;
                                        else
                                                temp -> child1 = temp1 -> child2;
                                }
                                temp -> child2 = temp11;
                                temp -> childs += 1;
                                temp -> sale_score += temp1 -> sale_score;
                                temp -> mentoring_score += temp1 -> mentoring_score;
                                for(i = 0 ; i < 5 ; ++i)
                                        temp -> items[i] += temp1 -> items[i];
                        }
                        else if(temp1 -> childs == 3 && temp -> childs == 1)
                        {
                                temp -> child0 = temp1 -> child0;
                                temp -> child1 = temp1 -> child1;
                                temp -> child2 = temp1 -> child2;
                                temp -> childs = 3;
                                temp -> sale_score += temp1 -> sale_score;
                                temp -> mentoring_score += temp1 -> mentoring_score;
                                for(i = 0 ; i < 5 ; ++i)
                                        temp -> items[i] += temp1 -> items[i];
                        }
                        else
                        {
                                printf("\nIBO deletion failed! Because number of child to the mentor exceeds 3");
                                i = -1;
                        }
                        if(i != -1)
                        {
                                printf("\nIBO with ID %d deleted successfully!", id);
                                leveldecrease(temp1);
                                free(temp1);
                        }
                }
        }
        return ibo;
}

int main()
{
        iboNode *ibo, *temp, *tempmentor;
        int A[15][2], i, choice = 1, c, i0, i1, i2, i3, i4, mID;
        ibo = createTree();
        traverse(ibo);
        while(choice)
        {
                printf("\n\nEnter 1 for insertion");
                printf("\nEnter 2 for displaying highest scorer in each level");
                printf("\nEnter 3 for displaying IBO with maximum number of descendant in each level");
                printf("\nEnter 4 for IBO having more points than his mentor");
                printf("\nEnter 5 for deletion");
                printf("\nEnter 6 to display tree elements");
                printf("\nChoice : ");
                scanf("%d", &c);
                switch(c)
                {
                        case 1: printf("\n\nGenerated IBO ID : %d", nextiboid);
                                printf("\nEnter Quantity for item 1 : ");
                                scanf("%d", &i0);
                                printf("Enter Quantity for item 2 : ");
                                scanf("%d", &i1);
                                printf("Enter Quantity for item 3 : ");
                                scanf("%d", &i2);
                                printf("Enter Quantity for item 4 : ");
                                scanf("%d", &i3);
                                printf("Enter Quantity for item 5 : ");
                                scanf("%d", &i4);
                                printf("Enter Mentor ID : ");
                                scanf("%d", &mID);
                                temp = malloc_child(nextiboid++, i0, i1, i2, i3, i4);
                                tempmentor = searchmentor(ibo, mID);
                                insert_IBO(&ibo, tempmentor, temp);
                                break;
                        case 2: printf("\n");
                                if(ibo != NULL)
                                {
                                        for(i = 0 ; i < 15 ; ++i)
                                                A[i][0] = -1;
                                        highestscorer(ibo, A);
                                        for(i = 0 ; i < 15 && A[i][0] != -1 ; ++i)
                                                printf("\n%d ID number IBO has highest price in level %d", A[i][1], i);
                                }
                                else
                                        printf("\nTree is empty!");
                                break;
                        case 3: printf("\n");
                                if(ibo != NULL)
                                {
                                        for(i = 0 ; i < 15 ; ++i)
                                                A[i][0] = -1;
                                        maximumdescendant(ibo, A);
                                        for(i = 0 ; i < 15 && A[i][0] != -1 ; ++i)
                                                printf("\n%d ID number IBO has maximum number of descendent in level %d", A[i][1], i);
                                }
                                else
                                        printf("\nTree is empty!");
                                break;
                        case 4: printf("\n");
                                childgreaterthanmentor(ibo);
                                break;
                        case 5: printf("\n\nEnter ID number of IBO to be deleted : ");
                                scanf("%d", &i);
                                ibo = delete_IBO(ibo, i);
                                break;
                        case 6: traverse(ibo);
                                break;
                        default: printf("\nInvalid Choice!");
                }
                printf("\n\nEnter 0 to quit or any other number to continue : ");
                scanf("%d", &choice);
        }
        return 0;
}