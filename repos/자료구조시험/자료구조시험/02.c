//#include<stdio.h>
//#include<malloc.h>
//typedef int element;
//typedef struct QNode
//{
//	element data;//������ �־��� ����
//	struct QNode* link;//��峢�� ���� �̾��� �ڱ����� ����ü ����
//}QNode;
//typedef struct
//{
//	QNode *front, *rear;//�Ӹ��� ������ �������� ������ ����
//}LQueueType;
//LQueueType* createLinkedQueue()//���� ����Ʈ��� ť�� �����Ҵ�
//{
//	LQueueType* LQ;
//	LQ = (LQueueType*)malloc(sizeof(LQueueType));
//	LQ->front = NULL;
//	LQ->rear = NULL;
//	return LQ;
//}
//int isEmpty(LQueueType* LQ)//����ִ��� Ȯ�����ִ� �Լ�
//{
//	if (LQ->front == NULL)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//void enQueue(LQueueType* LQ, element item)//��带 ���� ����
//{
//	QNode* newNode = (QNode*)malloc(sizeof(QNode));//��� �����Ҵ�
//	newNode->data = item;//������ �ֱ�
//	newNode->link = NULL;
//	if (LQ->front == NULL)//��尡 ���ٸ�
//	{
//		LQ->front = newNode;
//		LQ->rear = newNode;
//	}
//	else//ù ��� �������� 
//	{
//		LQ->rear->link = newNode;
//		LQ->rear = newNode;
//	}
//}
//element deQueue(LQueueType* LQ)//��� �������� �Լ�
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
//element peek(LQueueType* LQ)//���� �Ӹ� �����Ͱ� ����Ű�� �մ� ����� �����͸� ������� �Լ�
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
//	LQueueType *LQ = createLinkedQueue();  // ���� ť ����
//	element data;
//	int ticket = 0;
//	int price = 9000;
//	int total_price = 0;
//	int cnt = 1;
//	int total_ticket = 0;
//	while (1)
//	{
//		printf("%02d��° �մ� ǥ ���� ����:",cnt++);
//		scanf("%d", &ticket);
//		if (ticket < 0)				break;
//		enQueue(LQ, ticket);
//	}
//	while (!isEmpty(LQ))
//	{
//		total_ticket += deQueue(LQ);
//	}
//	printf("\n���� ����: %d�� �Ǹ�, ���� %d��\n", total_ticket, total_ticket*price);
//	return 0;
//}
////����