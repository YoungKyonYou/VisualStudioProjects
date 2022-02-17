//#include<stdio.h>
//#include<malloc.h>
//typedef int element;
//typedef struct QNode
//{
//	element data;//데이터 넣어줄 변수
//	struct QNode* link;//노드끼리 서로 이어줄 자기참조 구조체 변수
//}QNode;
//typedef struct
//{
//	QNode *front, *rear;//머리와 꼬리를 가리켜줄 포인터 변수
//}LQueueType;
//LQueueType* createLinkedQueue()//연결 리스트기반 큐의 동적할당
//{
//	LQueueType* LQ;
//	LQ = (LQueueType*)malloc(sizeof(LQueueType));
//	LQ->front = NULL;
//	LQ->rear = NULL;
//	return LQ;
//}
//int isEmpty(LQueueType* LQ)//비어있는지 확인해주는 함수
//{
//	if (LQ->front == NULL)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//void enQueue(LQueueType* LQ, element item)//노드를 만들어서 삽입
//{
//	QNode* newNode = (QNode*)malloc(sizeof(QNode));//노드 동적할당
//	newNode->data = item;//데이터 넣기
//	newNode->link = NULL;
//	if (LQ->front == NULL)//노드가 없다면
//	{
//		LQ->front = newNode;
//		LQ->rear = newNode;
//	}
//	else//첫 노드 다음부터 
//	{
//		LQ->rear->link = newNode;
//		LQ->rear = newNode;
//	}
//}
//element deQueue(LQueueType* LQ)//노드 삭제해줄 함수
//{
//	QNode* old = LQ->front;
//	element item;
//	if (isEmpty(LQ))
//		return 0;
//	else
//	{
//		item = old->data;
//		LQ->front = LQ->front->link;
//		if (LQ->front == NULL)
//			LQ->rear = NULL;
//		free(old);
//		return item;
//	}
//}
//element peek(LQueueType* LQ)//현재 머리 포인터가 가리키고 잇는 노드의 데이터를 출력해줄 함수
//{
//	element item;
//	if (isEmpty(LQ))
//		return 0;
//	else
//	{
//		item = LQ->front->data;
//		return item;
//	}
//}
//void printLQ(LQueueType *LQ) {
//	QNode *temp = LQ->front;
//	printf(" Linked Queue : [");
//	while (temp) {
//		printf("%3c", temp->data);
//		temp = temp->link;
//	}
//	printf(" ] ");
//}
//
//int main(void) {
//	LQueueType *LQ = createLinkedQueue();  // 연결 큐 생성
//	element data;
//	int ticket = 0;
//	int price = 9000;
//	int total_price = 0;
//	int cnt = 1;
//	int total_ticket = 0;
//	while (1)
//	{
//		printf("%02d번째 손님 표 구매 개수:",cnt++);
//		scanf("%d", &ticket);
//		if (ticket < 0)				break;
//		enQueue(LQ, ticket);
//	}
//	while (!isEmpty(LQ))
//	{
//		total_ticket += deQueue(LQ);
//	}
//	printf("\n당일 매출: %d매 판매, 이익 %d원\n", total_ticket, total_ticket*price);
//	return 0;
//}
////실행