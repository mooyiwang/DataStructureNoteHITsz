//数组
    //（下标，值）序对，相同元素
    //顺序存储多维数组的地址计算
        //行序，列序
    //数组压缩存储
        //对称矩阵
        //三角阵， 常量存在n(n+1)/2
        //带状矩阵
        //稀疏矩阵 （三元组）/链式
            //转置操作 转置后的位置，按照之前列的升序
            void FastTransposMatrix( TSMatrix M，TSMatrix &T )
                    { T.mu = M.nu; T.nu = M.mu; T.tu = M.tu;
                    if ( T.tu )
                    { for ( col = 1; col <= M.nu; ++col ) num[ col ] = 0 ;
                    for ( t = 1; t <= M.tu; ++t ) ++num[ M.data[ t ].j ] ;
                    cpot [ 1 ] = 1 ；
                    for(col=2;col<M.nu;col++) 
                    cpot [ col ] = cpot[ col –1 ] + num[ col – 1 ] ;
                    for ( p = 1; p <= M.tu; ++p )
                    { col = M.data[ p ].j ; q = cpot[ col ] ;
                    T.data[ q ].i = M.data[ p ].j ;
                    T.data[ q ].j = M.data[ p ].i ;
                    T.data[ q ].e = M.data[ p ].e ;
                    ++cpot[ col ] ;
                    }
                    }
            }
//广义表
    //定义
        //递归定义的
        //长度：第一层元素个数；深度：括弧对数
        //head，tail
    //存储
            typedef enum{ATOM,LIST} ElemTag;
            typedef struct GLNode{
                ElemTag tag;  //0原子，1子表
                union{
                    AtomType atom;
                    struct {struct GLNode *hp,*tp;}ptr;
                }
            }*Glist;
        //表头表尾分析，表头+表尾
        //子表分析法，第一层全看做子表，子表再递归

