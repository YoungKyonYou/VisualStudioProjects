//#include<stdio.h>
//#include<stdlib.h>
//int numOfData = 0;
//typedef struct ListNode {    // 노드 타입
//	int data;
//	struct ListNode *next;
//} ListNode;
//ListNode* insert_first(ListNode* plist, int data) {
//	printf("1번째에 %d를 삽입합니다.\n", data);
//	ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
//	newNode->data = data;
//	plist = newNode;
//	newNode->next = plist;
//	numOfData++;
//	return plist;
//}
//void print_list(ListNode* plist) {
//	ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
//	newNode = plist;
//	for (int i = 0; i < numOfData; i++, newNode = newNode->next) {
//		printf("%d->", newNode->data);
//	}
//	printf("\n");
//}
//ListNode* insert_last(ListNode* plist, int data) {
//	printf("마지막에 %d을 삽입합니다.\n", data);
//	ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
//	ListNode* cur = plist;
//	for (int i = 0; i < numOfData - 1; i++)
//		cur = cur->next;
//	newNode->data = data;
//	newNode->next = cur->next;
//	cur->next = newNode;
//	newNode->next = plist;
//	numOfData++;
//	return plist;
//}
//ListNode* insert(ListNode* plist, int pos, int data) {
//	ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
//	ListNode* cur = plist;
//	printf("%d번째에 %d을 삽입합니다.\n", pos, data);
//	if (pos == 1)
//		insert_first(plist, data);
//	else if (pos - 1 >= numOfData)
//		insert_last(plist, data);
//	else {
//		for (int i = 0; i < pos - 2; i++) {
//			cur = cur->next;
//		}
//		newNode->data = data;
//		newNode->next = cur->next;
//		cur->next = newNode;
//		numOfData++;
//		return plist;
//	}
//}
//ListNode* delete_first(ListNode* plist) {
//	ListNode* cur;
//	if (plist == NULL) return NULL;
//	cur = plist;
//	while (cur->next!= plist) {
//		cur = cur->next;
//	}
//	cur->next= plist->next;
//	cur = cur->next;
//	free(plist);
//	plist = cur;
//	numOfData--;
//	return plist;
//}
//
//ListNode* delete(ListNode* plist, int pos) {
//	printf("%d 번째를 삭제합니다.\n", pos);
//	ListNode* cur1;
//	ListNode* cur2;
//	if (plist == NULL)
//		return NULL;
//	cur1 = plist;
//	cur2 = plist;
//	if (pos == 1)
//	{
//		plist = plist->next;
//		while (cur1->next != plist) {
//			cur1 = cur1->next;
//		}
//		cur1->next = cur2->next;
//		free(cur2);
//		numOfData--;
//		return plist;
//	}
//	for (int i = 0; i < pos - 1; i++) {
//		cur1 = cur1->next;
//	}
//	for (int i = 0; i < pos-2; i++) {
//		cur2 = cur2->next;
//	}
//	cur2->next = cur1->next;
//	free(cur1);
//	numOfData--;
//	return plist;
//}
//
//// 원하는 위치의 값을 반환
//void get_entry(ListNode* plist, int pos) {
//	ListNode* cur;
//	if (is_empty(plist)) {
//		printf("리스트가 비어있습니다.");
//		return;
//	}
//	cur = plist;
//		for (int i = 0; i < pos-1; i++) {
//			cur = cur->next;
//		}
//		printf("%d번째 값은 %d입니다.\n", pos, cur->data);
//}
//// 리스트 초기화
//ListNode* clear(ListNode* plist) {
//	ListNode* cur;
//	cur = plist;
//	for (int i = 0; i < numOfData - 1; i++) {
//		cur = cur->next;
//		free(plist);
//		plist = cur;
//	}
//	printf("리스트를 초기화합니다.\n");
//	numOfData = 0;
//	return plist;
//}
////리스트가 비었는지 확인
//int is_empty(ListNode* plist) {
//	if (numOfData == 0)
//		return 1;
//	else
//		return 0;
//}
//void search(ListNode* plist, int data) {
//	ListNode* cur;
//	cur = plist;
//	for (int i = 0; i < numOfData - 1; i++) {
//		if (cur->data==data) {
//			printf("%d를 찾았습니다.\n", cur->data);
//			return;
//		}
//		cur = cur->next;
//	}
//	printf("값을 찾지 못했습니다.\n");
//}
//int main(void) {
//	ListNode *head = NULL;
//	head = insert_first(head, 10); print_list(head);
//	head = insert(head, 2, 20); print_list(head);
//	head = insert(head, 3, 30); print_list(head);
//	head = insert(head, 4, 40); print_list(head);
//	head = insert(head, 5, 50); print_list(head);
//	head = insert(head, 8, 60); print_list(head);
//	head = insert_last(head, 70); print_list(head);
//	printf("첫번째에 노드를 삭제합니다.\n");
//	head = delete_first(head); print_list(head);
//	head = delete(head, 1); print_list(head);
//	search(head, 30);
//	get_entry(head, 3);
//	head = clear(head);
//	if (is_empty(head)) printf("리스트가 비어있습니다.\n");
//	return 0;
//}