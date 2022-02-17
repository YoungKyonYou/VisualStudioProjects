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
//	printf("\n\n>>>>>꽝!!!!!<<<<<\n\n");
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
//		printf("\n이미 같은 키가 있습니다!\n");
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
//	printf("\n\t1 : 트리 출력");
//	printf("\n\t2 : 문자 삽입");
//	printf("\n\t3 : 문자 삭제");
//	printf("\n\t4 : 문자 검색");
//	printf("\n\t5 : 종료");
//	printf("\n*---------------------------*");
//	printf("\n메뉴입력 >> ");
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
//	int cnt = 0;//총 다트가 제대로 맞힌 횟수 담을 변수
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
//	int total = 0;//총 던진 횟수 담을 변수
//	srand((int)time(NULL));
//	root = insertNode(root, alphabet[1],1);//root설정하기
//	insertNode(root, alphabet[2],2);//B와 2 넣기 여기서 2는 알파벳의 순서상의 숫자
//	insertNode(root, alphabet[4],4);
//	insertNode(root, alphabet[8],8);
//	printf("##### -다트 돌리기 게임- #####\n\n");
//	while (1)
//	{
//		random = rand() % 9;
//		printf("다트 돌리기 (1)번 입력\n");
//		printf("종료(2)번 입력\n");
//		printf("입력: ");
//		scanf("%d", &num);
//		printf("\n*****%d에 맞았습니다!!*****\n", random);
//		if (num == 2)
//		{
//			printf("종료\n");
//			break;
//		}
//		if (foundedNode = searchBST(root, random))//랜덤으로 뽑힌 숫자 찾기
//		{
//			printf("\n\n당첨!!!!!\n\n");
//			alpha[0] = foundedNode->key;//strcat를 써주기 위해 문자여도 문자열 배열에다가 저장을 하는 것임
//			alpha[1] = '\0';
//			strupr(alpha);//해당 알파벳을 소문자로 치환
//			strcpy(s, alpha);//s라는 문자열 배열에 copy하기 s가 파일의 이름과 확장자를 넣는 배열임
//			strcat(s, type);//알파벳 뒤에다가 .txt붙여줌
//			strcpy(s2, s);//s2라는 변수는 fopen를 위해서 예를 들어 s.txt 이런식으로 저장할 변수
//			strcat(s, open);//s.txt notepad.exe 라는 문자열을 담고 있음
//			system(s);//해당하는 알파벳의 파일을 연다.
//			al = fopen(s2, "r");//s.txt를 읽기 모드로 연다 (그 포인터가 al)
//			while (!feof(al))//당첨된 알파벳의 단어장의 단어를 모두 읽어들일 때까지
//			{
//				fscanf(al, "%s", print);//s.txt에 있는 영어 단어를 print에다가 저장
//				fprintf(fp, "%02d %s\n",count++,print);//다트를 던져서 당첨된 알파벳의 단어장에 단어들을 번호를 매겨서
//				//예를 들어 01 ~ 02~ 03~이런식으로 차례대로 fp 포인터가 가르키고 있는 메모장에 입력
//			}
//			fclose(al);//당첨된 알파벳의 단어장을 가리키던 포인터 닫기
//			cnt++;//다트가 알파벳을 당첨한 경우 수 증가
//
//			printf("\n\n 부모 노드:%c\n", foundedNode->key);
//			if (foundedNode->left != NULL)
//				printf("%c의 왼쪽 자식 노드:%c\n", foundedNode->key, foundedNode->left->key);
//			else if (foundedNode->left == NULL)
//				printf("%c의 왼쪽 없음\n", foundedNode->key);
//			if (foundedNode->right != NULL)
//				printf("%c의 오른쪽 자식 노드:%c\n", foundedNode->key, foundedNode->right->key);
//			else if (foundedNode->right == NULL)
//				printf("%c의 오른쪽 없음\n", foundedNode->key);
//			printf("\n\n");
//
//		}
//		total++;//전체 다트 돌린 수 증가
//		memset(s2, 0,sizeof(s2));//s2를 다시 초기화
//	}
//
//
//	//파일에 출력될 출력문
//	fprintf(fp, "\n총 던진 횟수:%d\n", total);
//	fprintf(fp, "총 당첨 횟수:%d\n", cnt);
//	fprintf(fp, "총 꽝 횟수:%d\n", total-cnt);
//	fprintf(fp, "총 맞은 확률:%.2lf 퍼센트\n", (((double)cnt / total) * 100));
//	fprintf(fp,"총 빗맞은 확률:%.2lf 퍼센트\n", 100 - (((double)cnt / total) * 100));
//
//
//	//콘솔창에 출력될 출력문
//	printf("총 던진 횟수:%d\n", total);
//	printf("총 맞은 횟수:%d\n", cnt);
//	printf("총 꽝 횟수:%d\n", total - cnt);
//	printf("총 맞은 확률:%.2lf 퍼센트\n", (((double)cnt / total) * 100));
//	printf("총 빗맞은 확률:%.2lf 퍼센트\n",100-(((double)cnt / total) * 100));
//	fclose(fp);
//
//	system("notepad.exe Dictionary.txt");
//	return 0;
//}
////실행
