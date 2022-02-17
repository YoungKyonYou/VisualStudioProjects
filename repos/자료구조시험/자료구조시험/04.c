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
//	printf("\n찾는 학번이 없습니다.\n");
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
//		printf("\n이미 같은 키가 있습니다!\n");
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
//		printf("\n찾는 키가 이진 트리에 없습니다.!!\n");
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
//	printf("\n\t1 : 트리 출력");
//	printf("\n\t2 : 학번 삽입");
//	printf("\n\t3 : 학번 삭제");
//	printf("\n\t4 : 학번 검색");
//	printf("\n\t5 : 종료");
//	printf("\n*---------------------------*");
//	printf("\n메뉴입력 >> ");
//}
//void displayInorder(treeNode* root) {
//	if (root) {
//		displayInorder(root->left);
//		printf("학번: %s\n", root->ID);
//		printf("이름: %s\n", root->name);
//		printf("나이: %d\n", root->age);
//		printf("학점: %.2lf\n", root->grade);
//		printf("자기소개: %s\n", root->introduction);
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
//	fprintf(fp, "학번: %s\n", id);
//	fprintf(fp, "이름: %s\n", name);
//	fprintf(fp, "나이: %d\n", age);
//	fprintf(fp, "학점: %.2lf\n", grade);
//	fprintf(fp, "자기소개: %s\n", introduction);
//	fclose(fp);
//}
//void printInfo(int a, double g, char* n, char* id, char* introduction)
//{
//	printf("\n\n");
//	printf("학번: %s\n", id);
//	printf("이름: %s\n", n);
//	printf("나이: %d\n", a);
//	printf("학점: %.2lf\n", g);
//	printf("자기소개: %s\n", introduction);
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
//	root = insertNode(root, 20, 2.5, "왕범근", "2019130323", "F 안돼요~");
//	insertNode(root, 21, 4.5, "김지성", "2018152011", "F 안돼요~");
//	insertNode(root, 21, 3.5, "박흥민", "2018152017", "F 안돼요~");
//	insertNode(root, 19, 3.0, "최강인", "2019130044", "F 안돼요~");
//	insertNode(root, 23, 2.5, "송승우", "2017130042", "F 안돼요~");
//	insertNode(root, 24, 2.5, "김정민", "2016140323", "F 안돼요~");
//	insertNode(root, 25, 4.5, "박정협", "2015152011", "F 안돼요~");
//	insertNode(root, 21, 3.5, "마정환", "2018153017", "F 안돼요~");
//	insertNode(root, 23, 3.0, "오천수", "2017130045", "F 안돼요~");
//	insertNode(root, 20, 2.5, "이상철", "2019101042", "F 안돼요~");
//
//	FileInsert(20, 2.5, "왕범근", "2019130323", "F 안돼요~",fp4);
//	FileInsert(21, 4.5, "김지성", "2018152011", "F 안돼요~",fp4);
//	FileInsert(21, 3.5, "박흥민", "2018152017", "F 안돼요~",fp4);
//	FileInsert(19, 3.0, "최강인", "2019130044", "F 안돼요~",fp4);
//	FileInsert(23, 2.5, "송승우", "2017130042", "F 안돼요~",fp4);
//	FileInsert(24, 2.5, "김정민", "2016140323", "F 안돼요~",fp4);
//	FileInsert(25, 4.5, "박정협", "2015152011", "F 안돼요~",fp4);
//	FileInsert(21, 3.5, "마정환", "2018153017", "F 안돼요~",fp4);
//	FileInsert(23, 3.0, "오천수", "2017130045", "F 안돼요~",fp4);
//	FileInsert(20, 2.5, "이상철", "2019101042", "F 안돼요~",fp4);
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
//			printf("학번을 입력하세요: ");
//			scanf(" %s", ID);
//			if (root != NULL)
//			{
//				foundedNode=searchBST(root, ID);
//				if (foundedNode != NULL)
//				{
//					printf("이미 중복된 학번이 있습니다. 다시 입력해주세요!\n");
//					continue;
//				}
//			}
//			printf("이름을 입력하세요: ");
//			scanf(" %s", name);
//			printf("나이를 입력하세요: ");
//			scanf(" %d", &age);
//			printf("학점을 입력하세요: ");
//			scanf(" %lf", &grade);
//			printf("자기소개를 입력하세요: ");
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
//			printf("삭제할 학번 입력:");
//			scanf("%s", delID);
//			deleteNode(&root, delID);
//		}
//		else if (choice == 4)
//		{
//			printf("찾을 학번 입력: ");
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
//			printf("\n검색 시간:%lf\n", duration);
//		}
//		else if (choice == 5)
//		{
//			printf("종료\n");
//			break;
//		}
//	}
//
//	return 0;
//
//}
////실행됨