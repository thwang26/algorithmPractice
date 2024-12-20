//
// Created by htw12 on 12 / 20 / 금.
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
  ElementType Data;
} Node;

typedef struct tagArrayStack
{
  int Capacity; // 용량
  int Top; // top의 인덱스 값
  Node* Nodes; // 스택이 들어가는 배열의 맨 앞 주소
} ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
  (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
  (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);

  (*Stack)->Capacity = Capacity;
  (*Stack)->Top = -1;
}
// 스택의 정보를 담은 arraystack의 메모리 할당
// 스택의 값이 들어가는 nodes 할당
// capacity값 할당
// top 위치 초기화

void AS_DestroyStack(ArrayStack* Stack)
{
  free(Stack->Nodes);
  free(Stack);
}
// 스택의 nodes 메모리 할당 해제
// 스택정보 메모리 할당 해제

void AS_Push(ArrayStack* Stack, ElementType Data)
{
  Stack->Top++;
  Stack->Nodes[Stack->Top].Data = Data;
}
// 스택의 top 위치 올리기
// node 배열에서 top 위치의 data값 할당

ElementType AS_Pop(ArrayStack* Stack)
{
  int Position = Stack->Top--;
  return Stack->Nodes[Position].Data;
}
// top 위치내린 후 data 리턴

ElementType AS_Top(ArrayStack* Stack)
{
  return Stack->Nodes[Stack->Top].Data;
}
// top data가져오기

int AS_GetSize(ArrayStack* Stack)
{
  return Stack->Top+1;
}
// 현재 스택크기 가져오기

int AS_IsEmpty(ArrayStack* Stack)
{
  return (Stack->Top == -1);
}
// top의 값이 -1인지 확인

int AS_IsFull(ArrayStack* Stack)
{
  if (Stack->Top == Stack->Capacity - 1)
  {
    return 1;
  }
    return 0;
}

int main(void)
{
  int i = 0;
  ArrayStack* Stack = NULL;

  AS_CreateStack(&Stack, 10);

  for (int i = 0; i < 20; i++)
  {
    if (AS_IsFull(Stack))
    {
      printf("Stack is Full.\n");
    }
    else
    {
      AS_Push(Stack, i);
      printf("Pushed %d.\n", i);
    }
  }


  printf("Capacity: %d, Sizd: %d, Top: %d\n\n",
         Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

  for (i = 0; i < 4; i++)
  {
    if (AS_IsEmpty(Stack))
      break;

    printf("Popped: %d.", AS_Pop(Stack));

    if (!AS_IsEmpty(Stack))
      printf("Current Top: %d\n", AS_Top(Stack));
    else
      printf("Stack Is Empty.\n");
  }

  AS_DestroyStack(Stack);

  return 0;
}