typedef int elementtype, keytype, ElementType;

//线性查找
    //一般表
    typedef struct{
        elementtype *elem;
        int len
    }sstable;
    
    int seq_search(sstable st, elementtype key){
        st.elem[0] = key;
        int i;
        for(i=st.len; st.elem[i]!=key; i--);
        return i;
    }
    //有序表

//折半查找
    int bin_search(sstable st, elementtype key){
        int low=1, high=st.len, mid;
        while(low<=high){
            mid = (low+high)/2;
            if(st.elem[mid]==key) return mid;
            else if(st.elem[mid]>key) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }

//分块查找（块有序

//BST
     typedef struct TreeNode* BinTree;
    struct TreeNode
    {
        ElementType Data;
        BinTree Left;
        BinTree Right;
    };
    typedef BinTree Position;


    //查找//
    Position Find1( ElementType X, BinTree BST)
    {
        if(!BST) return NULL;
        if(X > BST->Data)
            return Find1( X, BST->Right);
        else if(X < BST->Data)
            return Find1( X, BST->Left);
        else 
            return BST;
    }
  //尾递归都可以用循环来实现 查找效率与树的高度有关//
    Position Find2( ElementType X, BinTree  BST)
    {
        while (BST)
        {
            if(X > BST->Data) BST = BST->Right;
            else if(X < BST->Data) BST = BST->Left;
            else return BST;
        }
        return NULL;
    }

//找最大和最小值//
 //迭代//
 Position FindMin(BinTree BST)
 {
     while(BST->Left){
         BST = BST->Left;
     }
     return BST;
 }

  Position FindMax(BinTree BST)
 {
     while(BST->Right){
         BST = BST->Right;
     }
     return BST;
 }
 //递归//
 Position FindMin2(BinTree BST)
 {
     if(!BST) return NULL;
     else if(!BST->Left) return BST;
     else return FindMin2(BST->Left);
 }

 //BST插入//
 BinTree Insert(ElementType X, BinTree BST)
 {
     if(BST){
        if(X > BST->Data && BST->Right){
             return Insert( X, BST->Right);
        }
        else if(X > BST->Data && !BST->Right){
            BinTree BT;
            BT = (BinTree)malloc(sizeof(struct TreeNode));
            BT->Data = X;
            BT->Left = BT->Right = NULL;
            BST->Right = BT;
            return BST;
        }
        if(X < BST->Data && BST->Left){
            return Insert( X, BST->Left);
        }
        else if(X < BST->Data && !BST->Left){
            BinTree BT;
            BT = (BinTree)malloc(sizeof(struct TreeNode));
            BT->Data = X;
            BT->Left = BT->Right = NULL;
            BST->Left = BT;
            return BST;   
     }
     else{
            BinTree BT;
            BT = (BinTree)malloc(sizeof(struct TreeNode));
            BT->Data = X;
            BT->Left = BT->Right = NULL;
            return BT;
     }
     return BST;
 }

  //更好的//
BinTree Insert2(ElementType X, BinTree BST)
   {
       if(!BST){
            BST = (BinTree)malloc(sizeof(struct TreeNode));
            BST->Data = X;
            BST->Left = BST->Right = NULL;
            return BST;
       }
       else{
            if(X > BST->Data)
                BST->Right = Insert2(X, BST->Right);
            else if(X < BST->Data)
                BST->Left = Insert2(X, BST->Left);
       }
       return BST;  
   }

//删除//
BinTree Delete( ElementType X, BinTree BST)
{
    Position tmp;
    if(!BST) printf("not found the element you want!");
    else if( X < BST->Data)
        BST->Left = Delete( X, BST->Left) ;
    else if( X > BST->Data)
        BST->Right = Delete( X, BST->Right);
    else{
        if( BST->Left && BST->Right ){
            tmp = FindMin(BST->Right);
            BST->Data = tmp->Data;
            BST->Right = Delete(tmp->Data,BST->Right);
        }
        else{
            tmp = BST;
            if(!BST->Left){
                BST = BST->Right;
            }
            else if(!BST->Right){
                BST = BST->Left;
            }
            free(tmp);
            }
            return BST;
        }  
    }
}
