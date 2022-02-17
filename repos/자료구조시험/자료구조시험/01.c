//#include<stdio.h>
//#include<stdlib.h>
//#define cQ_SIZE 8//������ ���ϱ�
//typedef int element;
//typedef struct
//{
//	element queue[cQ_SIZE];//�����͸� �־��� �迭 ����
//	int front, rear;
//}QueueType;
//QueueType* createQueue()//���� ť ���� �Ҵ�
//{
//	QueueType* cQ;
//	cQ = (QueueType*)malloc(sizeof(QueueType));
//	cQ->front = 0;//�Ӹ��� ������ �Ȱ��� ���� ����Ű�� �� ����
//	cQ->rear = 0;
//	return cQ;
//}
//int isEmpty(QueueType* cQ)//�ȿ� �����Ͱ� �ִ� �� ���� �� Ȯ������ �Լ�
//{
//	if (cQ->front == cQ->rear)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//int isFull(QueueType* cQ)//�����Ͱ� �������� 1 ��ȯ �ƴϸ� 0��ȯ
//{
//	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front)
//	{
//		printf("Cricular Queue is full!\n");
//		return 1;
//	}
//	else
//		return 0;
//}
//void enQueue(QueueType* cQ, element item)//�����͸� �־��ִ� �Լ�
//{
//	if (isFull(cQ))//�� ���ִٸ� �Լ� ����
//		return;
//	else
//	{
//		cQ->rear=(cQ->rear+1)%cQ_SIZE;//���� ť�� �����ϴµ� �ٽ��� ������ ������ �̿�
//		cQ->queue[cQ->rear] = item;
//	}
//}
//element deQueue(QueueType* cQ)
//{
//	if (isEmpty(cQ))//�����Ͱ� ������ ����
//		exit(1);
//	else
//	{
//		cQ->front = (cQ->front + 1) % cQ_SIZE;
//		return cQ->queue[cQ->front];
//	}
//}
//element peek(QueueType* cQ)//���� front�� ����Ű���ִ� ������ ��ȯ���ִ� �Լ�
//{
//	if (isEmpty(cQ))
//		exit(1);
//	else
//		return cQ->queue[(cQ->front + 1) % cQ_SIZE];
//}
//void printQ(QueueType *cQ) //���� ť�� �ִ� ��� ������ ���
//{
//	int i, first, last;
//	first = (cQ->front + 1) % cQ_SIZE;
//	last = (cQ->rear + 1) % cQ_SIZE;
//	printf(" Circular Queue : [");
//	i = first;
//	while (i != last) {
//		printf("%3c", cQ->queue[i]);
//		i = (i + 1) % cQ_SIZE;
//	}
//	printf(" ] ");
//}
//
//int main(void) {//cQ_SIZE �� 4������ ���������� �����ʹ� 3�� �ۿ� �� ����. �� ���Ҹ� ������ߵ�.
//	QueueType *cQ = createQueue();  // ť ����
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
//		if (ticket < 0)
//			break;
//		enQueue(cQ, ticket);
//	}
//	while (!isEmpty(cQ))
//	{
//		total_ticket += deQueue(cQ);
//	}
//	printf("\n���� ����: %d�� �Ǹ�, ���� %d��\n", total_ticket, total_ticket*price);
//	return 0;
//}
////����