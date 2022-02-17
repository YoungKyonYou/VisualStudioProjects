//#include<stdio.h>
//#include<stdlib.h>
//#define cQ_SIZE 8//사이즈 정하기
//typedef int element;
//typedef struct
//{
//	element queue[cQ_SIZE];//데이터를 넣어줄 배열 선언
//	int front, rear;
//}QueueType;
//QueueType* createQueue()//원형 큐 동적 할당
//{
//	QueueType* cQ;
//	cQ = (QueueType*)malloc(sizeof(QueueType));
//	cQ->front = 0;//머리와 꼬리가 똑같은 것을 가리키게 끔 만듬
//	cQ->rear = 0;
//	return cQ;
//}
//int isEmpty(QueueType* cQ)//안에 데이터가 있는 지 없는 지 확인해줄 함수
//{
//	if (cQ->front == cQ->rear)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//int isFull(QueueType* cQ)//데이터가 차있으면 1 반환 아니면 0반환
//{
//	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front)
//	{
//		printf("Cricular Queue is full!\n");
//		return 1;
//	}
//	else
//		return 0;
//}
//void enQueue(QueueType* cQ, element item)//데이터를 넣어주는 함수
//{
//	if (isFull(cQ))//꽉 차있다면 함수 종료
//		return;
//	else
//	{
//		cQ->rear=(cQ->rear+1)%cQ_SIZE;//원형 큐를 구현하는데 핵심인 나머지 연산자 이용
//		cQ->queue[cQ->rear] = item;
//	}
//}
//element deQueue(QueueType* cQ)
//{
//	if (isEmpty(cQ))//데이터가 없으면 종료
//		exit(1);
//	else
//	{
//		cQ->front = (cQ->front + 1) % cQ_SIZE;
//		return cQ->queue[cQ->front];
//	}
//}
//element peek(QueueType* cQ)//현재 front가 가르키고있는 데이터 반환해주는 함수
//{
//	if (isEmpty(cQ))
//		exit(1);
//	else
//		return cQ->queue[(cQ->front + 1) % cQ_SIZE];
//}
//void printQ(QueueType *cQ) //현재 큐에 있는 모든 데이터 출력
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
//int main(void) {//cQ_SIZE 는 4이지만 실직적으로 데이터는 3개 밖에 안 들어간다. 한 원소를 비워놔야됨.
//	QueueType *cQ = createQueue();  // 큐 생성
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
//		if (ticket < 0)
//			break;
//		enQueue(cQ, ticket);
//	}
//	while (!isEmpty(cQ))
//	{
//		total_ticket += deQueue(cQ);
//	}
//	printf("\n당일 매출: %d매 판매, 이익 %d원\n", total_ticket, total_ticket*price);
//	return 0;
//}
////실행