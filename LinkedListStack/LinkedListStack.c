#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
    /*
        linkedliststack크기만큼 메모리에 할당하고
        list, top 값을 null로 지정한다
        stack의 값이 **인 이유는 메모리에 할당을 해야하기 때문이다
     */
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
    while (!LLS_IsEmpty(Stack))
    {
        Node* Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }

    free(Stack);
    /*
        stack안의 값이 비지 않았다면 pop을 반복하여
        pop된 노드들의 메모리를 해제하고
        해제가 완료되었다면
        stack 자체도 해제한다
     */
}

Node* LLS_CreateNode(char* NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = (char*)malloc(strlen(NewData) + 1);

    strcpy(NewNode->Data, NewData);

    NewNode->NextNode = NULL;

    return NewNode;
    /*
        node의 크기만큼 메모리를 할당
        node에 들어갈 data의 크기도 할당
        node의 data주소에 newdata 값 넣기
        다음노드는 null
     */
}

void LLS_DestroyNode(Node* Node)
{
    free(Node->Data);
    free(Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
    if (Stack->List == NULL)
    {
        Stack->List = NewNode;
    }
    else
    {
        Stack->Top->NextNode = NewNode;
    }

    Stack->Top = NewNode;
    /*
        첫 노드가 없으면 새 노드를 첫 노드로 함
        첫 노드가 있으면 stack의 끝 다음을 새 노드로 함
        끝 노드를 새 노드로 함
     */
}

Node* LLS_Pop(LinkedListStack* Stack)
{
    Node* TopNode = Stack->Top;
    // 삭제되는 노드를 지정

    if (Stack->List == Stack->Top)
    {
        Stack->List = NULL;
        Stack->Top = NULL;
        // 첫 노드가 삭제되는 노드라면 비움
    }
    else
    {
        Node* CurrentTop = Stack->List;
        while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
        {
            CurrentTop = CurrentTop->NextNode;
        }
        // 첫 노드부터 탑노드 직전으로 옮김

        Stack->Top = CurrentTop;
        // 직전노드를 탑노드로
        Stack->Top->NextNode = NULL;
        // 탑노드가 된 직전노드의 탑노드를 없앰
    }

    return TopNode;
    // 이전의 탑노드를 반환
    // ? 탑노드를 반환하면 제거를 시켜줘야 하는데 받고 제거??
    // 뭔가 비효율적이다 제거를 시켜준 쪽에서 메모리를 해제해야함
}

Node* LLS_Top(LinkedListStack* Stack)
{
    return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack)
{
    int Count = 0;
    Node* Current = Stack->List;
    // 첫노드 잡고

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }
    // null이 아닐 때까지 한칸씩 올려보며 개수 세기

    return Count;
    // count 값 return
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
   return (Stack->List == NULL);
   // size를 얻어온 후 값이 0인지 확인해도 좋을듯
}