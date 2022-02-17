//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<time.h>
//typedef char element;
//typedef struct treeNode
//{
//	char key;
//	int idx;
//	struct treeNode* left;
//	struct treeNode* right;
//}treeNode;
//treeNode* searchBST(treeNode* root, int idx)
//{
//	treeNode* p;
//	p = root;
//	while (p != NULL)
//	{
//		if (idx < p->idx)
//			p = p->right;
//		else if (idx == p->idx)
//			return p;
//		else
//			p = p->left;
//	}
//	printf("\n\n>>>>>��!!!!!<<<<<\n\n");
//	return p;
//}
//treeNode* insertNode(treeNode* p, char x,int idx)
//{
//	treeNode* newNode;
//	if (p == NULL)
//	{
//		newNode = (treeNode*)malloc(sizeof(treeNode));
//		newNode->key = x;
//		newNode->idx = idx;
//		newNode->left = NULL;
//		newNode->right = NULL;
//		return newNode;
//	}
//	else if (x < p->key)
//		p->right = insertNode(p->right, x,idx);
//	else if (x > p->key)
//		p->left = insertNode(p->left, x,idx);
//	else
//		printf("\n�̹� ���� Ű�� �ֽ��ϴ�!\n");
//	return p;
//}
//void deleteNode(treeNode* root, element key,int idx)
//{
//	treeNode *parent, *p = NULL, *succ, *succ_parent;
//	treeNode* child;
//	parent = NULL;
//	p = root;
//	while ((p != NULL) && (p->key != key))
//	{
//		parent = p;
//		if (key < p->key)
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
//			root = NULL;
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
//			succ_parent->left = succ->left;
//		else
//			succ_parent->right = succ->left;
//		p->key = succ->key;
//		p = succ;
//	}
//	free(p);
//}
//void displayInorder(treeNode* root) {
//	if (root) 
//	{
//		displayInorder(root->left);
//		printf("%c_", root->key);
//		displayInorder(root->right);
//	}
//}
//
//void menu() {
//	printf("\n*---------------------------*");
//	printf("\n\t1 : Ʈ�� ���");
//	printf("\n\t2 : ���� ����");
//	printf("\n\t3 : ���� ����");
//	printf("\n\t4 : ���� �˻�");
//	printf("\n\t5 : ����");
//	printf("\n*---------------------------*");
//	printf("\n�޴��Է� >> ");
//}
//
//int main() {
//	treeNode* root = NULL;
//	treeNode* foundedNode = NULL;
//	char key;
//	int num;
//	FILE* fp;
//	int count = 1;
//	FILE* al;
//	fp = fopen("Dictionary.txt", "w");
//	int random;
//	int cnt = 0;//�� ��Ʈ�� ����� ���� Ƚ�� ���� ����
//	char open[30]=" notepad.exe ";
//	char type[10] = ".txt";
//	char print[20];
//	char s[30];
//	char s2[30];
//	char alpha[2];
//	char alphabet[9];
//	alphabet[1] = 'A';
//	alphabet[2] = 'B';
//	alphabet[4] = 'C';
//	alphabet[8] = 'D';
//	int total = 0;//�� ���� Ƚ�� ���� ����
//	srand((int)time(NULL));
//	root = insertNode(root, alphabet[1],1);//root�����ϱ�
//	insertNode(root, alphabet[2],2);//B�� 2 �ֱ� ���⼭ 2�� ���ĺ��� �������� ����
//	insertNode(root, alphabet[4],4);
//	insertNode(root, alphabet[8],8);
//	printf("##### -��Ʈ ������ ����- #####\n\n");
//	while (1)
//	{
//		random = rand() % 9;
//		printf("��Ʈ ������ (1)�� �Է�\n");
//		printf("����(2)�� �Է�\n");
//		printf("�Է�: ");
//		scanf("%d", &num);
//		printf("\n*****%d�� �¾ҽ��ϴ�!!*****\n", random);
//		if (num == 2)
//		{
//			printf("����\n");
//			break;
//		}
//		if (foundedNode = searchBST(root, random))//�������� ���� ���� ã��
//		{
//			printf("\n\n��÷!!!!!\n\n");
//			alpha[0] = foundedNode->key;//strcat�� ���ֱ� ���� ���ڿ��� ���ڿ� �迭���ٰ� ������ �ϴ� ����
//			alpha[1] = '\0';
//			strupr(alpha);//�ش� ���ĺ��� �ҹ��ڷ� ġȯ
//			strcpy(s, alpha);//s��� ���ڿ� �迭�� copy�ϱ� s�� ������ �̸��� Ȯ���ڸ� �ִ� �迭��
//			strcat(s, type);//���ĺ� �ڿ��ٰ� .txt�ٿ���
//			strcpy(s2, s);//s2��� ������ fopen�� ���ؼ� ���� ��� s.txt �̷������� ������ ����
//			strcat(s, open);//s.txt notepad.exe ��� ���ڿ��� ��� ����
//			system(s);//�ش��ϴ� ���ĺ��� ������ ����.
//			al = fopen(s2, "r");//s.txt�� �б� ���� ���� (�� �����Ͱ� al)
//			while (!feof(al))//��÷�� ���ĺ��� �ܾ����� �ܾ ��� �о���� ������
//			{
//				fscanf(al, "%s", print);//s.txt�� �ִ� ���� �ܾ print���ٰ� ����
//				fprintf(fp, "%02d %s\n",count++,print);//��Ʈ�� ������ ��÷�� ���ĺ��� �ܾ��忡 �ܾ���� ��ȣ�� �Űܼ�
//				//���� ��� 01 ~ 02~ 03~�̷������� ���ʴ�� fp �����Ͱ� ����Ű�� �ִ� �޸��忡 �Է�
//			}
//			fclose(al);//��÷�� ���ĺ��� �ܾ����� ����Ű�� ������ �ݱ�
//			cnt++;//��Ʈ�� ���ĺ��� ��÷�� ��� �� ����
//
//			printf("\n\n �θ� ���:%c\n", foundedNode->key);
//			if (foundedNode->left != NULL)
//				printf("%c�� ���� �ڽ� ���:%c\n", foundedNode->key, foundedNode->left->key);
//			else if (foundedNode->left == NULL)
//				printf("%c�� ���� ����\n", foundedNode->key);
//			if (foundedNode->right != NULL)
//				printf("%c�� ������ �ڽ� ���:%c\n", foundedNode->key, foundedNode->right->key);
//			else if (foundedNode->right == NULL)
//				printf("%c�� ������ ����\n", foundedNode->key);
//			printf("\n\n");
//
//		}
//		total++;//��ü ��Ʈ ���� �� ����
//		memset(s2, 0,sizeof(s2));//s2�� �ٽ� �ʱ�ȭ
//	}
//
//
//	//���Ͽ� ��µ� ��¹�
//	fprintf(fp, "\n�� ���� Ƚ��:%d\n", total);
//	fprintf(fp, "�� ��÷ Ƚ��:%d\n", cnt);
//	fprintf(fp, "�� �� Ƚ��:%d\n", total-cnt);
//	fprintf(fp, "�� ���� Ȯ��:%.2lf �ۼ�Ʈ\n", (((double)cnt / total) * 100));
//	fprintf(fp,"�� ������ Ȯ��:%.2lf �ۼ�Ʈ\n", 100 - (((double)cnt / total) * 100));
//
//
//	//�ܼ�â�� ��µ� ��¹�
//	printf("�� ���� Ƚ��:%d\n", total);
//	printf("�� ���� Ƚ��:%d\n", cnt);
//	printf("�� �� Ƚ��:%d\n", total - cnt);
//	printf("�� ���� Ȯ��:%.2lf �ۼ�Ʈ\n", (((double)cnt / total) * 100));
//	printf("�� ������ Ȯ��:%.2lf �ۼ�Ʈ\n",100-(((double)cnt / total) * 100));
//	fclose(fp);
//
//	system("notepad.exe Dictionary.txt");
//	return 0;
//}
////����
