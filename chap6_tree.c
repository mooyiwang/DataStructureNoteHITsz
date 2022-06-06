typedef int DataType;
//树的概念
    //定义
    //术语
    //树的性质、
//二叉树
    //概念：有序树，有左右之分
    //性质：关键 n0 = n2+1
    //存储
        //顺序存储 完全/满二叉树,下标之间有关系
        //链表存储 二叉链表
            typedef struct BinNode{
                DataType data;
                struct BinNode *lch, *rch;
            }BinTreeNode, *BinTree;
            //三叉 再加parent指针域
    //遍历
        //层序 队列 BFS
            typedef struct{
            BinTreeNode* Queue[];
            int front, rear;
            }Queue;
            Queue* InitQueue(){};
            int isQueueEmpty(Queue Q){};
            void EnQueue(Queue *Q, BinTreeNode* k){};
            BinTreeNode* DeQueue(Queue *Q){};

            void LevelTraverse(BinTree T){
                if(T){
                    visit(T);
                    Queue *Q = InitQueue();
                    EnQueue(Q, T);
                    while(!isQueueEmpty(*Q)){
                        BinTreeNode* node = DeQueue(Q);
                        if(node->lch){
                            visit(node->lch);
                            EnQueue(Q, node->lch);
                        }
                        if(node->rch){
                            visit(node->rch);
                            EnQueue(Q, node->rch);
                        }
                    }
                }
            }
        //先序，中序，后序
            //波兰式，，逆波兰式
            //递归
            void pre(BinTree T){
                if(T){
                    visit(T);
                    pre(T->lch);
                    pre(T->rch);
                }
            }
            void in(BinTree T){
                if(T){
                    in(T->lch);
                    visit(T);
                    in(T->rch);
                }
            }
            void post(BinTree T){
                if(T){
                    post(T->lch);
                    post(T->rch);
                    visit(T);
                }
            }
            //非递归
            typedef struct{
                BinTree *Stack;
                int top;
            }Stack;
            void InitStack(Stack *S){};
            int isStackEmpty(Stack S){};
            void push(Stack *S, BinTree k){};
            BinTree pop(Stack *S){};
            BinTree getTop(Stack S){};

            void preorder(BinTree T){
                Stack *S;
                InitStack(S);
                BinTree p = T;
                while(p || isStackEmpty(*S)){
                    if(p){
                        visit(p);
                        push(S, p);
                        p = p->lch;
                    }
                    else{
                        p = pop(S);
                        p = p->rch;
                    }
                }
            }

            void inorder(BinTree T){
                Stack *S;
                InitStack(S);
                BinTree p = T;
                while(p || isStackEmpty(*S)){
                    if(p){
                        push(S, p);
                        p = p->lch;
                    }
                    else{
                        p = pop(S);
                        visit(p);
                        p = p->rch;
                    }
                }
            }
            //还可用于搜索路径
            void postorder(BinTree T){
                Stack *S;
                InitStack(S);
                BinTree p = T,r;
                while(p || isStackEmpty(*S)){
                    if(p){
                        push(S, p);
                        p = p->lch;
                    }
                    else{
                        p = getTop(*S);
                        if(p->rch && p->rch!=r){
                            p = p->rch;
                            push(S, p);
                            p = p->lch;
                        }
                        else{
                            p = pop(S);
                            visit(p);
                            r = p;
                            p = NULL;
                        }
                    }
                }
            }
        //遍历的应用 递归思想
            //建树 遍历的逆序
                //已知先序建树
                BinTree createTreePreorder(){
                    DataType data = getData();
                    if(data == -1){return NULL;}
                    BinTree BT = (BinTree)malloc(sizeof(BinTreeNode));
                    BT->data = data;
                    BT->lch = createTreePreorder();
                    BT->rch = createTreePreorder();
                    return BT;
                }
                //层序建树
                TreeNodePtr createTreeWithLevelOrder(int *data, int size) {
                    TreeNodePtr root = NULL;
                    if(size == 0) return root;
                    QueuePtr Queue = InitQueue();
                    int i = 0;
                    if(data[i]!=-1){
                        root = createTreeNode(data[i], NULL, NULL);
                        EnQueue(Queue, root);
                        i++;
                    }
                    else return root;
                    while(!QueueEmpty(Queue)){
                        TreeNodePtr node = GetHead(Queue);
                        DeQueue(Queue);
                        if(i<size){
                                TreeNodePtr lnode = createTreeNode(data[i], NULL, NULL);
                                node->left = lnode;
                                EnQueue(Queue, lnode);
                            i++;
                        }
                        if (i<size){
                                TreeNodePtr rnode = createTreeNode(data[i], NULL, NULL);
                                node->right = rnode;
                                EnQueue(Queue, rnode);
                            i++;
                        }
                    }
                    return root;
                }
                //已知遍历序列建树，先中，中后，层中
                //按表达式建树，紧靠运算符的两个操作数
                    //后缀表达式，从左到右
                    //前缀，右左
            //递归处理：求叶子数，树深度，相似树，等价树，树翻转
    //线索二叉树:用n+1个空链域来存线索
        //线索链表
        typedef struct ThreadNode{
            DataType data;
            struct ThreadNode *lch,*rch;
            int ltag,rtag;
        }ThreadNode, *ThreadTree;
        //线索化，
        //使用一个pre指针记录当前访问的前驱, p没有lch，就指向pre；pre存在且没有右孩子，就指向p
        //处理最后一个pre
            //中序
            ThreadNode* pre; //最好是全局变量
            void InThread(ThreadTree p){
                if(p){
                    InThread(p->lch);
                    if(!p->lch){
                        p->lch = pre;
                        p->ltag = 1;
                    }
                    if(pre && !pre->rch){
                        pre->rch = p;
                        pre->rtag = 1;
                    }
                    pre = p;
                    InThread(p->rch);
                }
            };
            void createInThread(ThreadTree T){
                pre = NULL;
                if(T){
                    InThread(T);
                    pre->rch = NULL;
                    pre->rtag=1;
                }
            }
            //先序，后序，就改一下InThread递归次序
                //先序注意转圈
                ThreadNode* pre; //最好是全局变量re
                void PreThread(ThreadTree p){
                    if(p){
                        if(!p->lch){
                            p->lch = pre;
                            p->ltag = 1;
                        }
                        if(pre && !pre->rch){
                            pre->rch = p;
                            pre->rtag = 1;
                        }
                        pre = p;
                        if(p->ltag==0){
                            PreThread(p->lch);
                        }
                        PreThread(p->rch);
                    }
                };
                void createPreThread(ThreadTree T){
                    pre = NULL;
                    if(T){
                        PreThread(T);
                        pre->rch = NULL;
                        pre->rtag=1;
                    }
                } 
        //线索遍历
            //中序线索树遍历，现在有了前驱和后继线索，依照线索来找
                //找后继：没有右子树；有右子树，右边的最左边
                ThreadNode* firstNode(ThreadNode* p){
                    while(p->ltag==0) p=p->lch;
                    return p;
                };
                ThreadNode* lastNode(ThreadNode* p){
                    while(p->rtag==0) p=p->rch;
                    return p;
                }
                //中序后继
                ThreadNode* nextNode(ThreadNode* p){  
                    if(p->rtag==1) return p->rch;
                    else return firstNode(p->rch);
                };
                //中序前驱
                ThreadNode* forwardNode(ThreadNode* p){
                    if(p->ltag==1) return p->lch;
                    else return lastNode(p->lch);
                }
                void InorderWithInThread(ThreadTree T){
                    for(ThreadNode *p=firstNode(T); p; p=nextNode(p)){
                        visit(p);
                    }
                }    
                //先序线索二叉树无法找到任意结点的先序遍历前驱
                //后序线索二叉树无法找到任意结点的后序遍历后继

//树和森林
    //树的存储
        //双亲表示法 顺序存储，连续空间
        #define MAX_SIZE 100
        typedef struct{ //结点结构
            DataType data;
            int parent;
        }PTNode;

        typedef struct{
            PTNode nodes[MAX_SIZE];
            int root, num;
        }*PTree;
        
        //孩子链表（类似邻接表
        typedef struct CNode{
            int child;
            struct CNode* next;
        }*ChildPtr;
        typedef struct{
            DataType data;
            ChildPtr firstchild;
        }Node;
        typedef struct{
            Node nodes[MAX_SIZE];
            int num, root;
        }*CTree;
        //双亲孩子表示 在node里再加双亲域

        //孩子兄弟表示：第一个孩子和右边第一个兄弟
        typedef struct CSNode{
            DataType data;
            struct CSNode *firstchild,*nextsibling;
        };
    
    //树、森林的二叉转换
        //树转化二叉树在所有兄弟结点之间加一条连线；（2）对每个结点，除了保留与其长子的连线外，去掉该结点与其它孩子的连线
        //森林转化二叉树：先每棵树转化，再连起来各二叉树的根结点视为兄弟连在一起
        //二叉树转化为树
        //任何一棵与树对应的二叉树,其右子树必为空
    //树和森林的遍历
        //树：先根遍历；后根遍历；层次遍历
        //森林：先序遍历；中序遍历（第一颗树的根

//huffleman树，huffleman编码（前缀码
