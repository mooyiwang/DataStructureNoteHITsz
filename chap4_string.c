//串的概念
    //注意空格，空串，空格串
    //index从1开始
//串的存储
    //定长存储：
    #define MAX_STRLEN 255
    typedef struct{ 
        char str[MAX_STRLEN] ;
        int length;
    } StringType; 
    typedef char str[MAX_STRLEN+1];
        //联结，求子串
    
    //堆分配存储，动态分配
    typedef struct{ 
        char *ch; /* 若非空，按长度分配，否则为NULL */
        int length; /* 串的长度 */
    } HString ;
        //每次使用就开新的空间
    //链表存储（块链
    #define BLOCK_SIZE 4
    typedef struct node{
        char data[BLOCK_SIZE] ;
        struct node *next;
    }Bnode ; 
    typedef Bnode *STRING2 ;
    STRING2 str2 ;
//模式匹配，匹配子串
    //朴素枚举 Brute-Force  平均n+m；最坏n*m
        //i=i-j+2，j=1
        int Index_BF ( char* S, char* T, int pos)
        {                                   /* S为主串，T为模式，串采用顺序存储结构 */
            i = pos; j = 1; // 从第一个位置开始比较
            while (i<=S.length && j<=T.length) {
                if (S[i] == T[j]) {++i; ++j;} // 继续比较后继字符
                else {i = i - j + 2; j = 1;} // 指针后退重新开始匹配
            }
            if (j > T.length) return i- T.length;
            else
            return 0;
        }
    //KMP
        //j=next[j],next数组的求法
        //当j=1时，next[j]=0；当j>1 时，next[j]的值为：模式串的位置从1到j-1构成的串中所出现的最长相等的前后缀长度加1
        int Index_KMP ( char* S, char* T, int next[])
        { /* S为主串，T为模式，串采用顺序存储结构 */
            int i = 1;
            int j = 1; // 从第一个位置开始比较
            while (i<=S.length && j<=T.length) {
                if (j==0 || S[i] == T[j]) {++i; ++j;} // 继续比较后继字符
                else { j=next[j]; } // 指针后退重新开始匹配
            }
            if (j > T.length) return i- T.length;
            else
            return 0;
        }

