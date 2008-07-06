/*
1.build binary serch tree
2.inorder tree traversal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree_t
{
	char* word;
	struct tree_t* llink;
	struct tree_t* rlink;
};

struct tree_t* root=NULL;
struct tree_t* ptr;
struct tree_t *current, *prev;

void insert_tree(char* str)
{

	ptr = (struct tree_t*) malloc(sizeof(struct tree_t));
	ptr->word = (char*) malloc( sizeof(struct tree_t) * (strlen(str)+1) );
	strcpy(ptr->word, str);
	ptr->llink = NULL;
	ptr->rlink = NULL;

	if(root == NULL)
		root = ptr;
	else
	{
		current = root;
		while(current!=NULL)
		{
			if(strcmp(current->word, str)==0)
				return;

			prev = current;
			if(strcmp(ptr->word, current->word)<0)
				current = current->llink;
			else
				current = current->rlink;
		}
		if(strcmp(ptr->word, prev->word)<0)
			prev->llink = ptr;
		else
			prev->rlink = ptr;
	}


}

void inorder(struct tree_t* node)
{
	if(node!=NULL)
	{
		inorder(node->llink);
		printf("%s\n", node->word);
		inorder(node->rlink);
	}
}


int main()
{
	//char buf[210];
	char line[200];
	char ch;
	int j=0;
	//int length;

	while(scanf("%c", &ch)!=EOF)
	//while(scanf("%s", buf)!=EOF)
	{
		//標點符號、大小寫處理
		//是字母就當作字處理  串上字串
		if( 'a'<=ch && ch<='z' || 'A'<=ch && ch<='Z')
			line[j++] = ch | 0x20;	//轉小寫
		else if(j!=0)
		{
			line[j] = '\0';	//結束字串
			j=0;
			//插入到樹中
			insert_tree(line);
		}
		
		/*for(i=0; i<length; i++)
		{
			if( buf[i] >= 'A' && buf[i] <= 'Z' )
				line[j++] = buf[i]+32;
			else if( buf[i] >= 'a' && buf[i] <= 'z' ) 
				line[j++] = buf[i];
		}
		line[j] = '\0';*/
	}
	//inorder輸出
	inorder(root);

	return 0;
}