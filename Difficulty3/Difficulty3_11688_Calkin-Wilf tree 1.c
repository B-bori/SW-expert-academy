#include <stdio.h>
#include <stdlib.h>


typedef struct Node_{
    int numerator;    // 분자
    int denominator;  // 분모
    struct Node_* rightChild;
    struct Node_* leftChild;
}Node;

Node InitNode(){
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->numerator=1;
    newNode->denominator=1;
    newNode->rightChild = NULL;
    newNode->leftChild = NULL;

    return *newNode;
}

void createNode(Node* A, char str[], int i){
    if (str[i]!='\0'){
        Node* tmpRightChild = (Node*) malloc(sizeof(Node));
        Node* tmpLeftChild = (Node*) malloc(sizeof(Node));

        tmpRightChild -> numerator = A->numerator + A->denominator;
        tmpRightChild -> denominator = A->denominator;
        tmpRightChild -> rightChild = NULL;
        tmpRightChild -> leftChild = NULL;

        tmpLeftChild -> numerator = A->numerator;
        tmpLeftChild -> denominator = A->numerator + A->denominator;
        tmpLeftChild -> rightChild = NULL;
        tmpLeftChild -> leftChild = NULL;

        A -> rightChild = tmpRightChild;
        A -> leftChild = tmpLeftChild;

        i++;

        createNode(A->rightChild, str, i);
        createNode(A->leftChild, str, i);
    }
}

void print_Tree(char str[], Node A){

    Node tmpNode;

    for(int i=0; str[i]!='\0'; i++){
        tmpNode = A;
        if (str[i]=='R')
            A = *A.rightChild;
        else
            A = *A.leftChild;
    }

    printf("%d %d\n",A.numerator, A.denominator);
}

void deleteNode(Node* A){

    if (A == NULL)
        return ;

    deleteNode(A->rightChild);
    deleteNode(A->leftChild);

    free(A);
}

void getAnswer(char str[]){
    int a=1,b=1;
    for (int i=0; str[i]!='\0'; i++){
        if (str[i]=='R')
            a=a+b;
        else
            b=a+b;
    }
    printf("%d %d\n", a,b);
}

int main(void)
{
	int test_case;
	int T;
//	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
        char str[31];

        scanf("%s", str);

// 구조체를 이용한 풀이는 결과는 잘 나오지만 runtime error 발생 (sol1)
/*
        Node Calkin_Wilf_Tree = InitNode();

        createNode(&Calkin_Wilf_Tree, str, 0);
        printf("#%d ", test_case);
        print_Tree(str, Calkin_Wilf_Tree);
        deleteNode(&Calkin_Wilf_Tree);
*/
        printf("#%d ", test_case);

// 단순 반복문을 사용하도록 한 풀이로 runtime error 해결 (sol2)
        getAnswer(str);
	}
	return 0;
}
