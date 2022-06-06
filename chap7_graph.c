//图的存储
    //邻接矩阵
    #define MaxVertexNum 100
    typedef char VertexType;
    typedef int EdgeType;
    typedef struct{
        VertexType vex[MaxVertexNum];
        EdgeType edge[MaxVertexNum][MaxVertexNum];
        int vexnum, edgenum;
    }MGragh;

    //邻接表（边来表示
    #define MaxVertexNum 100
    typedef struct ArcNode{
        int adjvex;
        struct ArcNode* next;
        int weight;
    }ArcNode;
    typedef struct VexNode{
        VertexType data;
        ArcNode* firstedge;
    }VexNode, AdjList[MaxVertexNum];
    typedef struct{
        AdjList vertices;
        int vexnum, edgenum;
    }AdjGraph;

    //十字链表，有向，边结点
    //邻接多重链表，无向，边结点

//图的遍历
    //广度优先BFS 队列
    int visited[MaxVertexNum];
    void BFSTraverse(AdjGraph G){
        int i;
        for(i=0; i<G.vexnum; i++){
            visited[i] = 0;
        }
        for(i=0; i<G.vexnum; i++){
            if(!visited[i]){
                BFS(G, i);
            }
        }
    }
        
        typedef struct{
            int *Queue;
            int front, rear;
        }Queue;
        void InitQueue(Queue *Q){};
        int isQueueEmpty(Queue Q){};
        void EnQueue(Queue *Q, int k){};
        int DeQueue(Queue *Q){};
        //邻接表实现 V+E
        void BFS(AdjGraph *G, int k){
            Queue Q;
            InitQueue(&Q);
            visited[k] = 1;
            EnQueue(&Q, k);
            while(!isQueueEmpty(Q)){
                int i=DeQueue(&Q);
                VexNode vex = G->vertices[i];
                for(ArcNode* edge=vex.firstedge; edge; edge=edge->next){
                    if(visited[edge->adjvex]==0){
                        visited[edge->adjvex]=1;
                        EnQueue(&Q, edge->adjvex);
                    }
                }
            }
        }
            
        //邻接矩阵 V**2
        void BFS(MGragh *G, int k){
            Queue Q;
            InitQueue(&Q);
            visited[k] = 1;
            EnQueue(&Q, k);
            while(!isQueueEmpty(Q)){
                int i=DeQueue(&Q);
                for(int j=0; j<G->vexnum; j++){
                    if(visited[j]==0 && G->edge[i][j]==1){
                        visited[j]=1;
                        EnQueue(&Q, j);
                    }
                }
            }
        }

    //深度优先DFS 栈
    int visited[MaxVertexNum];
    void DFSTraverse(AdjGraph G){
        int i;
        for(i=0; i<G.vexnum; i++){
            visited[i] = 0;
        }
        for(i=0; i<G.vexnum; i++){
            if(!visited[i]){
                DFS(G, i);
            }
        }
    }
        //递归算法
            //邻接表
            void DFS(AdjGraph *G, int k){
                visited[k] = 1;
                VexNode vex = G->vertices[k];
                for(ArcNode* edge=vex.firstedge; edge; edge=edge->next){
                    if(visited[edge->adjvex]==0){
                        DFS(G, edge->adjvex);
                    }
                }
            }
            //邻接矩阵
            void DFS(MGragh *G, int k){
                visited[k] = 1;
                for(int j=0; j<G->vexnum; j++){
                    if(visited[j]==0 && G->edge[k][j]==1){
                        DFS(G, j);
                    }
                }
            }
        //非递归
        typedef struct{
            int *Stack;
            int top;
        }Stack;
        void InitStack(Stack *S){};
        int isStackEmpty(Stack S){};
        void push(Stack *S, int k){};
        int pop(Stack *S){};
        void DFS(AdjGraph *G, int k){
            Stack S;
            InitStack(&S);
            visited[k] = 1;
            push(&S, k);
            while(!isStackEmpty(S)){
                int i = pop(&S);
                VexNode vex = G->vertices[i];
                for(ArcNode *edge=vex.firstedge; edge; edge=edge->next){
                    if(visited[edge->adjvex]==0){
                        visited[edge->adjvex]=1;
                        push(&S, edge->adjvex);
                    }
                }
            }
        }
    //利用遍历判断连通
    //连通图，生成树；非连通图，生产森林
    //Traverse方法中循环次数

//图的应用
    //最小生成树
        //Prim   V**2 收点
        #define max_dis 10000;
        int* Prim(MGragh *G){
            int dist[G->vexnum];         
            int collected[G->vexnum];      
            int res[G->vexnum];
            for(int i=0; i<G->vexnum; i++){
                dist[i] = max_dis;
                collected[i] = 0;
                res[i] = 0;
            }
            dist[0] = 0;
            res[0] = 0;
            int collectednum = 0;
            while(collectednum < G->vexnum){
                int min = findmin(dist, collected);
                collected[min] = 1;
                collectednum++;
                for(int j=0; j<G->vexnum; j++){
                    if(G->edge[min][j]<dist[j] && collected[j]==0){
                        dist[j] = G->edge[min][j];
                        res[j] = min;
                    }
                }
            }
            return res;
        }
        //Kruskal  依次选最小边 E*logE,收边
    //最短路径
        //dijkstra 非负权图单源最短路  V**2
        int *dijkstra(MGragh *G, int start){
            int dist[G->vexnum];
            int collected[G->vexnum];
            int path[G->vexnum];
            for(int i=0; i<G->vexnum; i++){
                dist[i] = max_dis;
                collected[i] = 0;
                path[i] = 0;
            }
            int collectednum = 0;
            dist[start] = 0;
            path[start] = start;
            while(collectednum < G->vexnum){
                int min = findmin(dist, collected);
                collected[min] = 1;
                for(int j=0; j<G->vexnum; j++){
                    if(dist[min]+G->edge[min][j]<dist[j] && collected[j]==0){
                        dist[j] = dist[min]+G->edge[min][j];
                        path[j] = min;
                    }
                }
            }
        }
            //单目标：边取反；顶点对，多顶点
        
        //Floyd 多源最短路径 V**3 允许有负边，但负边不能在回路中
            void floyd(MGragh *G, int **dist, int **path){
                for(int i=0; i<G->vexnum; i++){
                    for(int j=0; j<G->vexnum; j++){
                        dist[i][j] = G->edge[i][j];
                        path[i][j] = -1;
                    }
                }
                for(int k=0; k<G->vexnum; k++){
                    for(int i=0; i<G->vexnum; i++){
                        for(int j=0; j<G->vexnum; j++){
                            if(dist[i][k]+dist[k][j]<dist[i][j]){
                                dist[i][j] = dist[i][k]+dist[k][j];
                                path[i][j] = k;
                            }
                        }
                    }
                }
            }
    //DAG有向无环图
        //描述表达式 从原子项开始排
        
        //拓扑排序 AOV 队列实现BFS拓扑/栈实现DFS拓扑，选入度为0的，更新入度表
            //邻接表好实现 V+E
            typedef struct{
            int *Queue;
            int front, rear;
            }Queue;
            void InitQueue(Queue *Q){};
            int isQueueEmpty(Queue Q){};
            void EnQueue(Queue *Q, int k){};
            int DeQueue(Queue *Q){};
            void initIndegree(AdjGraph *G, int *indegree);
            
            void topo_sort(AdjGraph *G){
                int indegree[G->vexnum];
                initIndegree(G, indegree);
                Queue Q;
                InitQueue(&Q);
                for(int i=0; i<G->vexnum; i++){
                    if(indegree[i]==0){
                        EnQueue(&Q, i);
                    }
                }
                while(!isQueueEmpty(Q)){
                    int vex = DeQueue(&Q);
                    VexNode vexnode = G->vertices[vex];
                    for(ArcNode* edge=vexnode.firstedge; edge; edge=edge->next){
                        indegree[edge->adjvex]--;
                        if(indegree[edge->adjvex]==0){
                            visited[edge->adjvex]=1;
                            EnQueue(&Q, edge->adjvex);
                        }
                    }
                }
            }
            //逆拓扑
        //关键路径 AOE
            //最早开始时间，最晚开始时间
