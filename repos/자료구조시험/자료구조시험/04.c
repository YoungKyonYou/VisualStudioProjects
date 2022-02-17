//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<time.h>
//typedef char element;
//typedef struct student
//{
//	char name[20];
//	int age;
//	double grade;
//	char ID[30];
//	char introduction[100];
//}STU;
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
//treeNode* insertNode(treeNode* p, int a, double g, char* n, char* id, char* introduction)
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
//		p->left = insertNode(p->left, a, g, n, id, introduction);
//	else if (atoi(id) > atoi(p->ID))
//		p->right = insertNode(p->right, a, g, n, id, introduction);
//	else
//	{
//		printf("\n�̹� ���� Ű�� �ֽ��ϴ�!\n");
//		return NULL;
//	}
//	return p;
//}
//void deleteNode(treeNode** root, char* key)
//{
//	treeNode* pVRoot = (treeNode*)malloc(sizeof(treeNode));
//	pVRoot->left = NULL;
//	pVRoot->right = NULL;
//
//	treeNode *parent = pVRoot;
//	treeNode *p = *root;
//	treeNode *succ, *succ_parent;
//	treeNode* child = NULL;
//	pVRoot->right = *root;
//	while ((p != NULL) && (atoi(p->ID) != atoi(key)))
//	{
//		parent = p;
//		if (atoi(key) < atoi(p->ID))
//			p = p->left;
//		else
//			p = p->right;
//	}
//	if (p == NULL)
//	{
//		printf("\nã�� Ű�� ���� Ʈ���� �����ϴ�.!!\n");
//		return;
//	}
//	if ((p->left == NULL) && (p->right == NULL))
//	{
//		if (parent != NULL)
//		{
//			if (parent->left == p)
//				parent->left = NULL;
//			else
//				parent->right = NULL;
//		}
//		else
//			*root = NULL;
//		//		printf("%d\n", *root);
//	}
//	else if ((p->left == NULL) || (p->right == NULL))
//	{
//		if (p->left != NULL)
//			child = p->left;
//		else
//			child = p->right;
//		if (parent->left == p)
//			parent->left = child;
//		else
//			parent->right = child;
//	}
//	else
//	{
//		succ_parent = p;
//		succ = p->left;
//		while (succ->right != NULL)
//		{
//			succ_parent = succ;
//			succ = succ->right;
//		}
//		if (succ_parent->left == succ)
//			succ_parent->left = succ->left;//NULL 
//		else
//			succ_parent->right = succ->left;
//		strcpy(p->ID, succ->ID);
//		p->grade = succ->grade;
//		p->age - succ->age;
//		strcpy(p->name, succ->name);
//		strcpy(p->introduction, succ->introduction);
//		p = succ;
//	}
//	if (pVRoot->right != *root)
//		*root = pVRoot->right;
//	free(p);
//}
//
//void menu() {
//	printf("\n*---------------------------*");
//	printf("\n\t1 : Ʈ�� ���");
//	printf("\n\t2 : �й� ����");
//	printf("\n\t3 : �й� ����");
//	printf("\n\t4 : �й� �˻�");
//	printf("\n\t5 : ����");
//	printf("\n*---------------------------*");
//	printf("\n�޴��Է� >> ");
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
//}
//
//void FileInsert(int age, double grade, char* name, char* id, char* introduction, FILE* fp) 
//{
//	char ID[40];
//	char* type = ".txt";
//	strcpy(ID, id);
//	strcat(ID, type);
//	fp = fopen(ID, "w");
//	fprintf(fp, "�й�: %s\n", id);
//	fprintf(fp, "�̸�: %s\n", name);
//	fprintf(fp, "����: %d\n", age);
//	fprintf(fp, "����: %.2lf\n", grade);
//	fprintf(fp, "�ڱ�Ұ�: %s\n", introduction);
//	fclose(fp);
//}
//void printInfo(int a, double g, char* n, char* id, char* introduction)
//{
//	printf("\n\n");
//	printf("�й�: %s\n", id);
//	printf("�̸�: %s\n", n);
//	printf("����: %d\n", a);
//	printf("����: %.2lf\n", g);
//	printf("�ڱ�Ұ�: %s\n", introduction);
//	printf("\n\n");
//}
//int main() {
//	treeNode* root = NULL;
//	treeNode* foundedNode = NULL;
//	FILE* fp4=NULL;
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
//	root = insertNode(root, 20, 2.5, "�չ���", "2019130323", "F �ȵſ�~");
//	insertNode(root, 21, 4.5, "������", "2018152011", "F �ȵſ�~");
//	insertNode(root, 21, 3.5, "�����", "2018152017", "F �ȵſ�~");
//	insertNode(root, 19, 3.0, "�ְ���", "2019130044", "F �ȵſ�~");
//	insertNode(root, 23, 2.5, "�۽¿�", "2017130042", "F �ȵſ�~");
//	insertNode(root, 24, 2.5, "������", "2016140323", "F �ȵſ�~");
//	insertNode(root, 25, 4.5, "������", "2015152011", "F �ȵſ�~");
//	insertNode(root, 21, 3.5, "����ȯ", "2018153017", "F �ȵſ�~");
//	insertNode(root, 23, 3.0, "��õ��", "2017130045", "F �ȵſ�~");
//	insertNode(root, 20, 2.5, "�̻�ö", "2019101042", "F �ȵſ�~");
//
//	FileInsert(20, 2.5, "�չ���", "2019130323", "F �ȵſ�~",fp4);
//	FileInsert(21, 4.5, "������", "2018152011", "F �ȵſ�~",fp4);
//	FileInsert(21, 3.5, "�����", "2018152017", "F �ȵſ�~",fp4);
//	FileInsert(19, 3.0, "�ְ���", "2019130044", "F �ȵſ�~",fp4);
//	FileInsert(23, 2.5, "�۽¿�", "2017130042", "F �ȵſ�~",fp4);
//	FileInsert(24, 2.5, "������", "2016140323", "F �ȵſ�~",fp4);
//	FileInsert(25, 4.5, "������", "2015152011", "F �ȵſ�~",fp4);
//	FileInsert(21, 3.5, "����ȯ", "2018153017", "F �ȵſ�~",fp4);
//	FileInsert(23, 3.0, "��õ��", "2017130045", "F �ȵſ�~",fp4);
//	FileInsert(20, 2.5, "�̻�ö", "2019101042", "F �ȵſ�~",fp4);
//	while (1)
//	{
//		menu();
//		scanf(" %d", &choice);
//		if (choice == 1)
//		{
//			displayInorder(root);
//		}
//		else if (choice == 2)
//		{
//			printf("�й��� �Է��ϼ���: ");
//			scanf(" %s", ID);
//			if (root != NULL)
//			{
//				foundedNode=searchBST(root, ID);
//				if (foundedNode != NULL)
//				{
//					printf("�̹� �ߺ��� �й��� �ֽ��ϴ�. �ٽ� �Է����ּ���!\n");
//					continue;
//				}
//			}
//			printf("�̸��� �Է��ϼ���: ");
//			scanf(" %s", name);
//			printf("���̸� �Է��ϼ���: ");
//			scanf(" %d", &age);
//			printf("������ �Է��ϼ���: ");
//			scanf(" %lf", &grade);
//			printf("�ڱ�Ұ��� �Է��ϼ���: ");
//			rewind(stdin);
//			gets(introduction);
//			printInfo(age, grade, name, ID, introduction);
//			if (root == NULL)
//				root = insertNode(root, age, grade, name, ID, introduction);
//			else
//				insertNode(root, age, grade, name, ID, introduction);
//			FileInsert(age, grade, ID, name, introduction, fp);
//
//		}
//		else if (choice == 3)
//		{
//			printf("������ �й� �Է�:");
//			scanf("%s", delID);
//			deleteNode(&root, delID);
//		}
//		else if (choice == 4)
//		{
//			printf("ã�� �й� �Է�: ");
//			scanf("%s", ID);
//			start = clock();
//			foundedNode = searchBST(root, ID);
//			if (foundedNode == NULL)
//				continue;
//			strcat(ID, type2);
//			strcat(ID, type);
//			system(ID);
//			finish = clock();
//			duration = (double)(finish - start) / (CLOCKS_PER_SEC);
//			printf("\n�˻� �ð�:%lf\n", duration);
//		}
//		else if (choice == 5)
//		{
//			printf("����\n");
//			break;
//		}
//	}
//
//	return 0;
//
//}
////�����