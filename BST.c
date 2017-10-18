#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <string.h>		/* for string */
#include <assert.h>             /* for assert */
#include "BST.h"		

int llDoCheck = 1;		/* set true for paranoid consistency checking */

#define doCheck(_lp) (llDoCheck && llCheck(_lp))

/* create a new list */
BST *createTree()
{
  BST *tree = (BST *)malloc(sizeof(BST));//memory for new tree
  tree->first = tree->last = 0;
  doCheck(tree);
  return tree;
}

/*add new node*/
void addName(BST *Tree, char *fName, char *lName)
{
  Node new = Node(*fName, *lName);
	     
}

/* recycle a list, discarding all items it contains */
void freeMemory(BST *tree)
{
  doCheck(tree);
  llMakeEmpty(tree);
  free(tree);
}

/* Delete all elements off of the list */
void emptyTree(BST *tree)
{
  Node *current = tree->first, *next;
  doCheck(tree);
  while (current) {
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  tree->first = tree->last = 0;	/* list is empty */
  doCheck(tree);
}
  
/* append a copy of str to end of list */
void placeStringAtEnd(BST *tree, char *s)
{
  int len;
  char *scopy;
  BST *i;

  doCheck(tree);
  /* w = freshly allocated copy of putWord */
  for (len = 0; s[len]; len++) /* compute length */
    ;
  scopy = (char *)malloc(len+1);
  for (len = 0; s[len]; len++) /* copy chars */
    scopy[len] = s[len];
  scopy[len] = 0;			/* terminate copy */


  /* i = new item containing s */
  i = (BST *)malloc(sizeof(Node));
  i->str = scopy;
  i->next = 0;

  /* append to end of list */
  if (tree->last) {			/* list not empty */
    tree->last->next = i;
  } else {			/* list empty */
    tree->first = i;
  }

  /* new item is last on list */
  tree->last = i;
  doCheck(tree);
}

/* print list membership.  Prints default mesage if message is NULL */
void llPrint(BST *tree, char *msg)
{
  BST *temp;
  int count = 1;
  doCheck(tree);
  puts(msg ? msg :" List contents:");
  for (temp = tree->first; temp; temp = temp->next) {
    printf("  %d: <%s>\n", count, temp->str);
    count++;
  }
}

/* check llist consistency */
int BSTCheck(BST *tree)
{
  BST *temp;
  temp = tree->first;
  if (!temp) 
    assert(temp->last == 0);
  else {
    for (; temp->next; temp = temp->next);
    assert(temp == tree->last);
  }
  return 0;
}
