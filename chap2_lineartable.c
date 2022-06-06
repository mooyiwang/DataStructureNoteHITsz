//线性表定义
    //有序，前驱后继，相同数据类型的数据元素
//存储
    //顺序存储，顺序表
        //静态分配
        typedef int elementtype;
        #define MAXSIZE 10
        typedef struct{
            elementtype data[MAXSIZE];
            int last;  //当前表长
        }Seqlist;
        typedef int position;
        //动态分配
        #define LIST_INIT_SIZE 100 //初始分配空间
        #define LISTINCREMENET 10 //分配增量
        typedef struct{
            elementtype *elem; //元素空间
            int length; //表的长度
            int listsize; //当前容量
        }AqList; 
        //操作
            //i位置插入，i位置起到以后的元素向后移，再插入，更新长度
            int insert_seqlist(Seqlist* L, int i, elementtype e){
                if(L->last==MAXSIZE){return 0;}
                for(int j=L->last-1; j>=i; j--){
                    L->data[j+1] = L->data[j];
                }
                L->data[i]=e;
                L->last++;
                return 1;
            }
            //i位置删除，后面的元素往前移
            int delete_seqlist(Seqlist* L, int i, elementtype *e){};
            //按位置查找元素，找前驱后继地址，O1时间
            //按值查找（顺序查找
    //链式存储 链表
        //单链表
        typedef struct node{
            elementtype data;
            struct node* next;
        }LinkNode, *LinkedList;
        //操作，带头结点
        //注意指针赋值的顺序,最好自己画图理解
            //建表
            LinkedList init_linkedlist(){
                LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
                head->next = NULL;
                return head;
            }
            //头插建表
            void inserthead(LinkedList L, elementtype e){
                LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
                node->data = e;
                node->next = L->next;
                L->next = node;
            }
            //尾插建表
            //查找，找i位置，找值，找前驱，找表尾都只能从头开始遍历，
                //找后继直接next
            //插入，插在第i位置，对p指针结点插入前插后插
            //删除，第i个结点，删除后继的一个结点
           
            //头结点：表头处的插入，删除和其他地方一样
        //单链表应用
            //双指针
            //链表反转

        //双链表
        typedef struct node{
            elementtype data;
            struct node *next,*prior;
        }LinkNode, *LinkedList;
            //插入，删除等操作最好画图
        //单向循环链表
            //用表尾指针标识链表，就相当于尾结点是之前的空头结点
        //双向循环链表

        //应用