//#include<stdio.h>
//#include<stdlib.h>
//
//// 노드 구조체 선언
//typedef struct node {
//	int data;
//	struct node* next;
//}Node;   
//typedef struct ListNode {
//	Node* head;
//	Node* cur;
//	int numOfData;
//} ListNode;
//
//// 맨 앞에 노드 추가
//ListNode* insert_first(ListNode* plist, int data) {
//	plist = (ListNode*)malloc(sizeof(ListNode));
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	newNode->next = NULL;
//	plist->head = newNode;
//	plist->numOfData = 1;
//	return plist;
//}
//
//// 언하는 위치에 노드 추가
//ListNode* insert(ListNode* plist, int pos, int data) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	int i;
//	newNode->data = data;
//	plist->cur = plist->head;
//	if (plist->numOfData+1<pos) {
//		printf("오류\n");
//		free(newNode);
//		return plist;
//	}
//	else {
//		for (i = 0; i < pos-2; i++) {
//			plist->cur = plist->cur->next;
//		}
//		newNode->next = plist->cur->next;
//		plist->cur->next=newNode;
//		plist->numOfData++;
//	}
//	return plist;
//}
//ListNode* delete_first(ListNode* plist) {
//	plist->cur = plist->head;
//	plist->cur = plist->cur->next;
//	free(plist->head);
//	plist->head = plist->cur;
//	plist->numOfData--;
//	return plist;
//}
//ListNode* delete(ListNode* plist, int pos) {
//	Node* delNode;
//	plist->cur = plist->head;
//	delNode = plist->head;
//	for (int i = 0; i < pos - 1; i++) {
//			delNode = delNode->next;
//	}
//	for (int i = 0; i < pos - 2; i++) {
//		plist->cur = plist->cur->next;
//	}
//	if (delNode->next == NULL) {
//		free(delNode);
//		plist->cur->next = NULL;
//	}
//	else {
//		plist->cur->next = delNode->next;
//		free(delNode);
//	}
//	plist->numOfData--;
//	return plist;
//}
//void print_list(ListNode* plist) {
//	plist->cur = plist->head;
//	for (int i = 0; i < plist->numOfData; i++)
//	{
//		printf("%d->", plist->cur->data);
//		plist->cur = plist->cur->next;
//	}
//	printf("NULL");
//	printf("\n");
//}
//void get_entry(ListNode* plist, int pos) {
//	plist->cur = plist->head;
//	for (int i = 0; i < pos - 1; i++)
//		plist->cur = plist->cur->next;
//	printf("%d번째 값은 %d 입니다.\n", pos, plist->cur->data);
//}
//ListNode* clear(ListNode* plist) {
//	plist->cur = plist->head;
//	for (int i = 0; i < plist->cur!= NULL; i++) {
//		plist->cur = plist->cur->next;
//		free(plist->head);
//		plist->head = plist->cur;
//	}
//	plist->numOfData = 0;
//}
//int is_empty(ListNode* plist) {
//	if (plist->numOfData == 0)
//		return 1;
//	else
//		return 0;
//}
//
//int main(void) {
//	ListNode *head = NULL;
//	head = insert_first(head, 10);
//	print_list(head);
//	head = insert(head, 2, 20);
//	print_list(head);
//	head = insert(head, 3, 30); 
//	print_list(head);
//	head = insert(head, 4, 40);
//	print_list(head);
//	head = insert(head, 5, 50); 
//	print_list(head);
//	head = insert(head, 8, 60); 
//	print_list(head);
//	//head = insert(head, 3, 99);
//	//print_list(head);
//	/*head = delete_first(head);*/
//	head = delete(head, 3);
//	print_list(head);
//	head = delete(head, 4);
//	print_list(head);
//	get_entry(head, 3);
//	head = clear(head);
//	if (is_empty(head)) printf("리스트가 비어있습니다.\n");
//	return 0;
//}