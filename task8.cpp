#include <iostream>
#include <stdio.h>
#define Q_SIZE 50

typedef struct Node {
  int id;
  struct Node* next;
}Node;

typedef struct {
  int nVertices;  //顶点数
  Node** vertices;//顶点数组
}Graph;

typedef struct {
  int* elems;
  int front;
  int end;
  int size;
}Queue;

void init(Graph &g, int nVertices){ //初始化图
  g.nVertices = nVertices;
  g.vertices = (Node**)malloc(nVertices *sizeof(Node*));
  for(int i = 0; i < nVertices; i++){
    g.vertices[i] = NULL;
  }
}

void addEdge(Graph &g, int u, int v){
  Node* n = (Node *)malloc(sizeof(Node));
  n->id = v;
  n->next = NULL;
  if(g.vertices[u] == NULL){  //链表中没有其他结点
    g.vertices[u] = n;
  } else {  //链表中有其他结点，遍历找到最后再添加
    Node *p = g.vertices[u];
    while(p->next != NULL){
      p = p->next;
    }
    p->next = n;
  }
}

void biEdge(Graph &g, int u, int v){  //无向图
  addEdge(g, u, v);
  addEdge(g, v, u);
}

void createGraph(Graph &g){
  biEdge(g, 0, 1);
  biEdge(g, 0, 2);
  biEdge(g, 1, 3);
  biEdge(g, 1, 4);
  biEdge(g, 3, 7);
  biEdge(g, 4, 7);
  biEdge(g, 2, 5);
  biEdge(g, 2, 6);
  biEdge(g, 5, 6);
}

void initQue(Queue &q){//初始化队列
  q.elems = (int *)malloc(Q_SIZE * sizeof(int));
  q.front = 0;
  q.end = 0;
  q.size = Q_SIZE;
}

void enq(Queue &q, int id){ //入队
  int newEnd = (q.end + 1) % q.size;  //循环队列
  if( newEnd == q.front){ //满队
    return; //不做操作
  } else {
    q.elems[q.end] = id;
    q.end = newEnd;
  }
}

int deq(Queue &q){ //出队
  int id = q.elems[q.front];
  q.front = (q.front + 1) % q.size;
  return id;
}

int isEmpty(Queue &q){//队列是否为空
  return q.front == q.end;
}

void BFSvisit(Graph &g, int id, int* visited){
  Queue q;
  initQue(q);
  enq(q, id);//第一个结点入队
  while(!isEmpty(q)){//队列不为空时循环
    int n = deq(q);
    if(!visited[n]){  //若出队结点未访问则访问
      printf("%d ", n);
      visited[n] = 1;
    }
    for(Node *p = g.vertices[n]; p != NULL; p = p->next){
      if(!visited[p->id]){
        enq(q, p->id);//未访问则入队
      }
    }
  }
}

void DFSvisit(Graph &g, int id, int* visited){
  printf("%d ", id);  //打印结点的id
  visited[id] = 1;  //已访问
  for(Node *p = g.vertices[id]; p != NULL; p = p->next){
    if(!visited[p->id]){  //遍历该结点的所有邻接结点看否访问过 若未访问则访问
      DFSvisit(g, p->id, visited);  //递归调用
    }
  }
}

void Traverse(Graph &g, int id, void (*fun)(Graph &g, int id, int* visited)){
  int* visited = (int *)malloc(g.nVertices * sizeof(int));  //新建一个容量为顶点数的数组，存储已访问的结点
  for(int i = 0; i < g.nVertices; i++){
    visited[i] = 0; //初始化为0：均未访问
  }
  (*fun)(g, id, visited); //访问结点（第一个）
  for(int i = 0; i < g.nVertices; i++){
    if(!visited[i]){  //遍历每个顶点，如果未被访问则访问
      (*fun)(g, i, visited);
    }
  }
}

int main(){
  Graph g;
  init(g, 8);
  createGraph(g);  //构建题中的图
  printf("BFS遍历结果：\n");
  Traverse(g, 0, BFSvisit);
  printf("\n-------------\nDFS遍历结果：\n");
  Traverse(g, 0, DFSvisit);

  return 0;
}