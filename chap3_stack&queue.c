typedef int elementtype;
//栈
    //定义：先进后出FILO，栈顶，栈底
        //ADT
        InitStack(&S) 
        DestroyStack(&S) 
        Push(&S, e)
        Pop(&S, &e) 
        GetTop(S, &e)
        StackEmpty(S) 
        StackLength(S)
    //存储
        //顺序存储
            //静态分配
            #define MAXSIZE 100
            typedef struct{
                elementtype data[MAXSIZE];
                int top;
            }SqStack;
                //操作
                    //top指向当前栈顶元素，初始时top=-1
                    void InitStack(SqStack* s){
                        s->top = -1;
                    }
                    判栈空
                    int StackEmpty(SqStack* s){
                        return s->top==-1;
                    }
                    判栈满
                    int StackFull(SqStack* s){
                        return s->top==MAXSIZE-1;
                    }
                    进栈
                    void Push(SqStack* s, elementype x){
                        if(StackFull(s)) error("overflow");
                        s->top++;
                        s->data[s->top] = x;
                    }
                    出栈
                    elementtype Pop(SqStack* s){
                        if(StackEmpty(s)) error("underflow")
                        elementtype x = s->data[s->top];
                        s->top--;
                        return x;
                    }
            //动态分配，malloc， realloc
                #define STACK_INIT_SIZE 100
                #define STACK_INCREMENT 10
                typedef struct{
                    elementtype* base;
                    elementtype* top;  //元素指针
                    int stacksize;
                }SqStack;
                //操作
                Status Push (SqStack &S, SElemType e) {
                    if (S.top - S.base >= S.stacksize) //栈满，追加存储空间
                        { 
                            S.base = (ElemType *) realloc ( S.base,(S.stacksize + STACKINCREMENT) * sizeof (ElemType));
                            if (!S.base) exit (OVERFLOW); //存储分配失败
                            S.top = S.base + S.stacksize;
                            S.stacksize += STACKINCREMENT;
                        }
                    S.top = e; S.top++; //先传数据再移动指针
                    return OK;
                }
            //链栈（单链表， 链表头插入删除，不含头结点，头插头删
                typedef struct StackNode{
                    elementtype data;
                    struct StackNode* next;
                }StackNode;
                typedef struct{
                    StackNode* headnode;
                    int size;
                }LinkedStack;

                int Push(LinkedStack *S, elementtype e){
                    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
                    node->data = e;
                    node->next = S->headnode;
                    S->headnode = node;
                    S->size++;
                    return 1;
                }
        //栈的应用
            //进制转换 除留余数法，先压栈再出栈
            //括号匹配
            //行编辑
            //表达式求值
                //后缀表达式处理，在后缀表达式中，变量（操作数）出现的顺序与中缀表达式顺序相同。② 后缀表达式中不需要括弧（界限符）定义计算顺序，而由运算（操作符）的位置来确定运算顺序。
                //中缀到后缀转换，人工，机器栈辅助存运算符和括号
                    //遇到运算符。考虑当前栈的情况：
                    // a.栈空或者栈顶元素为“（”，运算符直接入栈；
                    // b.栈顶元素为运算符：依次弹出栈中优先级高于或等于当前运算符的所有运
                    // 算符，并加入后缀表达式，若碰到“(” 或栈空则停止。之后再把当前运算符入栈。
                    // ③遇到界限符。遇到“(”直接入栈；遇到“)”则依次弹出栈内运算符并加入后缀表
                    // 达式，直到弹出“(”为止。注意：“(”不加入后缀表达式。

                //后缀计算，人工左往右，机器栈辅助存操作数
                        // ①从左往右扫描下一个元素，直到处理完所有元素
                        // • ②若扫描到操作数则压入栈，并回到①；否则执行③
                        // • ③若扫描到运算符，则弹出两个栈顶元素，执行相应运算，运算结果压回
                        // 栈顶，回到①
        //栈与递归函数的实现
            //函数调用栈可称为“递归工作栈” ，参数、局部变量和返回地址
            //分析递归函数的空间复杂度要考虑
            //hanoi塔问题
        //满足后进先出原则的

//队列
    //先进先出，front出，rear进
        InitQueue(&Q) //初始化队列
        DestroyQueue(&Q) //销毁队列
        EnQueue(&Q, e) //入队列
        DeQueue(&Q, &e) //出队列
        GetHead(Q, &e) //取队头元素
        QueueEmpty(Q) //判队列是否空
        QueueLength(Q) 
    //存储实现
        //顺序队列  rear,front加1
        #define MAXQSIZE 10
        typedef struct{
            elementtype base[MAXQSIZE];
            int front;
            int rear;
        }SqQueue;
            
        //循环队列 rear,front加1取模
            bool InitQueue(SqQueue &Q){
                Q.front = Q.rear = 0;
                return true;
            }
            //判断是否为空
            bool QueueEmpty(SqQueue &Q){
                if(Q.front == Q.rear){
                    return true;
                }
                return false;
            }
            //入队列
            bool EnQueue(SqQueue &Q, elementtype e){
                if((Q.rear+1)%MAXQSIZE==Q.front) return false;   
                Q.base[Q.rear] = e;
                Q.rear= (Q.rear+1)%MAXQSIZE;
                return true;
            }
            //出队列
            bool DeQueue(SqQueue &Q, elementtype *e){
                if(QueueEmpty(Q)) return false;
                *e = Q.base[Q.front];
                Q.front = (Q.front+1)%MAXQSIZE;
                return true;
            }
            int QueueLength(SqQueue Q){
                return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
            }
            //有一个空间用不上
                //解决1：加tag，删除置1，增加置0
                bool EnQueue(SqQueue &Q, elementtype e){
                    if(Q.rear==Q.front && Q.tag==1) return false;   
                    Q.base[Q.rear] = e;
                    Q.rear= (Q.rear+1)%MAXQSIZE;
                    Q.tag =1
                    return true;
                }
                bool DeQueue(SqQueue &Q, elementtype *e){
                    if(Q.rear==Q.front && Q.tag==0) return false;
                    *e = Q.base[Q.front];
                    Q.front = (Q.front+1)%MAXQSIZE;
                    Q.tag = 0;
                    return true;
                }
                //解决2.加size，记录当前个数，入队列就加1，出队列减1
        //链式存储 带头结点的链表，front在表头，rear在表尾 尾插头删
        typedef struct QNode{
            elementtype data;
            struct QNode* next;
        }QNode;
        typedef struct{
            QNode *front, *rear; //front指向头结点，rear指向最后一个结点
        }LinkedQueue;
            bool InitQueue(LinkedQueue *Q){
                QNode* head =(QNode*)malloc(sizeof(QNode));
                Q->front = Q->rear = head;
                head->next = NULL;
                return true;
            }
            bool EnQueue(LinkedQueue *Q, elementtype e){
                QNode* node =(QNode*)malloc(sizeof(QNode));
                node->data = e;
                node->next = NULL;
                Q->rear->next = node;
                Q->rear = node;
                return true;
            }
            bool DeQueue(LinkedQueue *Q, elementtype *e){
                if(!Q->front->next) return false;
                QNode* p = Q->front->next;
                *e = p->data;
                Q->front->next = p->next;
                if(Q->rear==p) Q->rear=Q->front;  //删除最后一个结点时
                free(p);
                return true;
            }
    //队列的应用：满足先进先出原则的
//多项式表示
    //一般数组
    //结构体数组
    //链表

        



