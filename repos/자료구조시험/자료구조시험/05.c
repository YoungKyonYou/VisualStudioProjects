//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define MAX(a,b) ((a>b)?a:b)
//typedef char* element;
//typedef struct treeNode
//{
//	char name[20];
//	int age;
//	double grade;
//	char ID[30];
//	char introduction[100];
//	struct treeNode* left;
//	struct treeNode* right;
//}treeNode;
//treeNode* LL_rotate(treeNode* parent)
//{
//	treeNode* child = parent->left;
//	parent->left = child->right;
//	child->right = parent;
//	return child;
//}
//treeNode* RR_rotate(treeNode* parent)
//{
//	treeNode* child = parent->right;
//	parent->right = child->left;
//	child->left = parent;
//	return child;
//}
//treeNode* LR_rotate(treeNode* parent)
//{
//	treeNode* child = parent->left;
//	parent->left = RR_rotate(child);
//	return LL_rotate(parent);
//}
//treeNode* RL_rotate(treeNode* parent)
//{
//	treeNode* child = parent->right;
//	parent->right = LL_rotate(child);
//	return RR_rotate(parent);
//}
//int getHeight(treeNode* p)
//{
//	int height = 0;
//	if (p != NULL)
//		height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
//	return height;
//}
//int getBF(treeNode* p)
//{
//	if (p == NULL)
//		return 0;
//	return getHeight(p->left) - getHeight(p->right);
//}
//treeNode* rebalance(treeNode** p)
//{
//	int BF = getBF(*p);
//	if (BF > 1)
//	{
//		if (getBF((*p)->left) > 0)
//			*p = LL_rotate(*p);
//		else
//			*p = LR_rotate(*p);
//	}
//	else if (BF < -1)
//	{
//		if (getBF((*p)->right) < 0)
//			*p = RR_rotate(*p);
//		else
//			*p = RL_rotate(*p);
//	}
//	return *p;
//}
//treeNode* insert_AVL_Node(treeNode** root, int a, double g, char* n, char* id, char* introduction)
//{
//	if (*root == NULL)
//	{
//		*root = (treeNode*)malloc(sizeof(treeNode));
//		(*root)->age=a;
//		(*root)->grade = g;
//		strcpy((*root)->ID, id);
//		strcpy((*root)->introduction, introduction);
//		strcpy((*root)->name, n);
//		(*root)->left = NULL;
//		(*root)->right = NULL;
//	}
//	else if (atoi(id) < atoi((*root)->ID))
//	{
//		(*root)->left = insert_AVL_Node(&((*root)->left), a,g,n,id,introduction);
//		*root = rebalance(root);
//	}
//	else if(atoi(id) > atoi((*root)->ID))
//	{
//		(*root)->right = insert_AVL_Node(&((*root)->right), a, g, n, id, introduction);
//		*root = rebalance(root);
//	}
//	else
//	{
//		printf("\n�̹� ���� Ű�� �ֽ��ϴ�.\n");
//		return;
//	}
//	return *root;
//}
//treeNode* insert_BST_Node(treeNode* p, int a, double g, char* n, char* id, char* introduction)
//{
//	treeNode* newNode;
//	if (p == NULL)
//	{
//		newNode = (treeNode*)malloc(sizeof(treeNode));
//		newNode->age = a;
//		newNode->grade = g;
//		strcpy(newNode->name, n);
//		strcpy(newNode->ID, id);
//		strcpy(newNode->introduction, introduction);
//		newNode->left = NULL;
//		newNode->right = NULL;
//		return newNode;
//	}
//	else if (atoi(id) < atoi(p->ID))
//		p->left = insert_BST_Node(p->left, a, g, n, id, introduction);
//	else if (atoi(id) > atoi(p->ID))
//		p->right = insert_BST_Node(p->right, a, g, n, id, introduction);
//	else
//	{
//		printf("\n�̹� ���� Ű�� �ֽ��ϴ�!\n");
//		return NULL;
//	}
//	return p;
//}
//treeNode* searchBST(treeNode* root, char* x)
//{
//	treeNode* p;
//	p = root;
//	while (p != NULL)
//	{
//		if (atoi(x)<atoi(p->ID))
//			p = p->left;
//		else if (atoi(x) == atoi(p->ID))
//			return p;
//		else
//			p = p->right;
//	}
//	printf("\nã�� �й��� �����ϴ�.\n");
//	return NULL;
//}
//void displayInorder(treeNode* root) {
//	if (root) {
//		displayInorder(root->left);
//		printf("�й�: %s\n", root->ID);
//		printf("�̸�: %s\n", root->name);
//		printf("����: %d\n", root->age);
//		printf("����: %.2lf\n", root->grade);
//		printf("�ڱ�Ұ�: %s\n", root->introduction);
//		printf("\n");
//		displayInorder(root->right);
//	}
//}treeNode* searchTree(treeNode* root, element x)
//{
//	treeNode* p;
//	int count = 0;
//	p = root;
//	while (p != NULL)
//	{
//		count++;
//		if (atoi(x)<atoi(p->ID))
//			p = p->left;
//		else if (atoi(x) == atoi(p->ID))
//		{
//			//	printf("%3d�� °�� Ž�� ����\n", count);
//			return 1;
//		}
//		else p = p->right;
//	}
//	count++;
//	printf("! ã�� Ű�� �����ϴ�!\n");
//	return NULL;
//}
//
//void whoPrecede(double d1, double d2,element data)
//{
//	if (d1 < d2)
//	{
//		printf("AVL Ʈ���� %lf�� ����\n", d2-d1);
//	}
//	else if (d1 > d2)
//	{
//		printf("BST Ʈ���� %lf�� ����\n",d1 - d2);
//	}
//	else if (d1 == d2)
//	{
//		printf("%s�� ã�� ��� : ����\n",data);
//	}
//}
//double AVL_TREE_IOT(treeNode* root ,FILE* fp1, element data)
//{
//	//FILE* fp1;
//	treeNode* root_AVL = root;
//	int i;
//	static int cnt = 1;//�޸��忡�ٰ� Ž�� �Ѱ� ��ȣ 01 ~ 02~ �ϱ� ���� ����
//	double duration=0;
//	clock_t start, finish;
//
//
//	start = clock();
//	if (searchTree(root_AVL, data)!=NULL)
//	{
//		finish = clock();
//		duration = (double)(finish - start) / (CLOCKS_PER_SEC);
//		fprintf(fp1, "%02d %s : %.6lf��\n", cnt++, data, duration);
//		return duration;
//	}
//	return -1;
//}
//double BST_TREE_IOT(treeNode* root ,FILE* fp2,element data)
//{
//	//FILE* fp2;
//	treeNode* root_BST = root;
//	int i;
//	static int cnt = 1;//�޸��忡�ٰ� Ž�� �Ѱ� ��ȣ 01 ~ 02~ �ϱ� ���� ����
//	double duration2=0;
//	clock_t start2, finish2;
//
//
//
//	start2 = clock();
//	if (searchTree(root_BST, data)!=NULL)
//	{
//		finish2 = clock();
//		duration2 = (double)(finish2 - start2) / (CLOCKS_PER_SEC);
//		fprintf(fp2, "%02d %s : %.6lf��\n", cnt++, data, duration2);
//		return duration2;
//	}
//	return -1;
//}
//int main() 
//{
//	FILE* fp1;
//	FILE* fp2;
//	double d1=0, d2=0;
//	fp1 = fopen("AVL.txt", "w");
//	fp2 = fopen("BST.txt", "w");
//	treeNode* root = NULL;
//	treeNode* root2 = NULL;
//	treeNode* foundedNode = NULL;
//	FILE* fp4 = NULL;
//	int choice, key;
//	char name[20];
//	char introduction[100];
//	int age;
//	double grade;
//	char ID[30];
//	char delID[30];
//	char* type = "notepad.exe ";
//	char* type2 = ".txt ";
//	FILE* fp = NULL;
//	double duration;
//	int i;
//	clock_t start, finish;
//	root = insert_AVL_Node(&root, 20, 2.5, "�չ���", "2019130323", "F �ȵſ�~");
//	insert_AVL_Node(&root, 21, 4.5, "������", "2018152011", "F �ȵſ�~");
//	insert_AVL_Node(&root, 21, 3.5, "�����", "2018152017", "F �ȵſ�~");
//	insert_AVL_Node(&root, 19, 3.0, "�ְ���", "2019130044", "F �ȵſ�~");
//	insert_AVL_Node(&root, 23, 2.5, "�۽¿�", "2017130042", "F �ȵſ�~");
//	insert_AVL_Node(&root, 24, 2.5, "������", "2016140323", "F �ȵſ�~");
//	insert_AVL_Node(&root, 25, 4.5, "������", "2015152011", "F �ȵſ�~");
//	insert_AVL_Node(&root, 21, 3.5, "����ȯ", "2018153017", "F �ȵſ�~");
//	insert_AVL_Node(&root, 23, 3.0, "��õ��", "2017130045", "F �ȵſ�~");
//	insert_AVL_Node(&root, 20, 2.5, "�̻�ö", "2019101042", "F �ȵſ�~");
//
//	root2 = insert_BST_Node(root2, 20, 2.5, "�չ���", "2019130323", "F �ȵſ�~");
//	insert_BST_Node(root2, 21, 4.5, "������", "2018152011", "F �ȵſ�~");
//	insert_BST_Node(root2, 21, 3.5, "�����", "2018152017", "F �ȵſ�~");
//	insert_BST_Node(root2, 19, 3.0, "�ְ���", "2019130044", "F �ȵſ�~");
//	insert_BST_Node(root2, 23, 2.5, "�۽¿�", "2017130042", "F �ȵſ�~");
//	insert_BST_Node(root2, 24, 2.5, "������", "2016140323", "F �ȵſ�~");
//	insert_BST_Node(root2, 25, 4.5, "������", "2015152011", "F �ȵſ�~");
//	insert_BST_Node(root2, 21, 3.5, "����ȯ", "2018153017", "F �ȵſ�~");
//	insert_BST_Node(root2, 23, 3.0, "��õ��", "2017130045", "F �ȵſ�~");
//	insert_BST_Node(root2, 20, 2.5, "�̻�ö", "2019101042", "F �ȵſ�~");
//
//	while (1)
//	{
//		printf("*****�й� Ž��*****\n");
//		printf("���� 1�� �Է�:\n");
//		printf("Ž���� �й� �Է�:");
//		scanf("%s", ID);
//		if (atoi(ID) == 1)
//			break;
//		d1=BST_TREE_IOT(root,fp1, ID);
//		d2=AVL_TREE_IOT(root,fp2, ID);
//		if (d1 == -1 || d2 == -1)
//		{
//			continue;
//		}
//		whoPrecede(d1, d2, ID);
//		printf("\n\n");
//	}
//
//	fclose(fp1);
//	fclose(fp2);
//	return 0;
//
//}
////����