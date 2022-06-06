typedef int elementtype;
//插入排序
    //直接插入
    void insert_sort(elementtype a[], int n){
        int i, j;
        for(i=2; i<=n; i++){
            if(a[i]<a[i-1]){
                a[0] = a[i];
            }
            for(j=i-1; a[0]<a[j]; j--){  //边移边找，移位子
                a[j+1] = a[j];
            }
            a[j+1] = a[0];
        }
    }
    //折半插入
    void insert_sort(elementtype a[], int n){
        int i, j, low, high, mid;
        for(i=2; i<=n; i++){
            a[0]=a[i];
            low = 0;
            high = i-1;
            while(low <= high){         //先找后移
                mid = (low+high)/2;
                if(a[mid]>a[0]) high = mid-1;
                else high = mid+1;
            }
            for(j=i-1; j>=high+1; j--){
                a[j+1] = a[j];
            }
            a[high+1] = a[0];
        }
    }
    //希尔排序   dk增量分组
    void insert_sort(elementtype a[], int n){
        int i, j, dk;
        for(dk=n/2; dk>=1; dk/=2){
            for(i=dk+1; i<=n; i++){
                if(a[i]<a[i-dk]){
                    a[0] = a[i];
                    for(j=i-dk; j>0 && a[j]>a[0]; j-=dk){
                        a[j+dk] = a[j];
                    }
                    a[j+dk] = a[0];
                }
            }
        }
    }
//交换排序
    //冒泡排序
    void bubble_sort(elementtype a[], int n){
        for(int i=0; i<n-1; i++){   //轮数
            int isSwap = 0;
            for(int j=n-1; j>i; j--){
                if(a[j-1]>a[j]) swap(a[j-1], a[j]);
                isSwap = 1;
            }
            if(isSwap == 0){
                return;
            }
        }
    }
    //快速排序
    int partition(elementtype a[], int low, int high){
        elementtype pivot = a[low];
        while(low<high){
            while(low<high && a[high]>=pivot) high--;
            a[low] = a[high];
            while(low<high && a[low]<=pivot) low++;
            a[high] = a[low];
        }
        a[low] = pivot;
        return low;

        // elementtype pivotkey = a[high];
        // int i=high;
        // for(int j=high-1; j>=low; j--){
        //     if(a[j]>=pivotkey){
        //         i--;
        //         swap(a[i], a[j]);
        //     }
        // }
        // i--;
        // swap(a[i], a[high]);

    }
    void quick_sort(elementtype a[], int low, int high){
        if(low<high){ //元素个数大于1
            int pivotpos = partition(a, low, high);
            quick_sort(a, low, pivotpos-1);
            quick_sort(a, pivotpos+1, high);
        }
    }

//选择排序
    //简单选择
    void select_sort(elementtype a[], int n){
        for(int i=1; i<=n-1; i++){
            int min=i, j;
            for(j=i; j<=n; j++){
                if(a[j]<a[min]) min=j;
            }
            if(min!=j) swap(a[min], a[i]);
        }
    }
    //树型选择排序
    //堆排序
    void BuildMaxHeap(elementtype a[], int len){
        for(int i=len/2; i>0; i--){
            HeapAdjust(a, i, len);
        }
    }

    void HeapAdjust(elementtype a[], int k, int len){
        int i;
        a[0] = a[k];
        for(i=2*k; i<=len;){
            if(i<len && a[i]<a[i+1]){
                i++;
            }
            if(a[0]>=a[i]) break;
            else{
                a[k] = a[i];
                k = i;
                i = 2*k;
            }
        }
        a[k] = a[0];
    }

    void heap_sort(elementtype a[], int len){
        BuildMaxHeap(a, len);
        int i;
        for(i=len; i>i; i--){
            swap(a[i], a[1]);
            HeapAdjust(a, 1, i-1);
        }
    }

    void InsertHeap(elementtype a[], elementtype item, int len){
        int i = ++len;
        for(; a[i/2]<a[i]; i/=2){
            a[i] = a[i/2];
        }
        a[i] = item;
    }

//归并排序    
    elementtype *b = (elementtype*)malloc((n+1)*sizeof(elementtype));
    void merge(elementtype a[], int low, int mid, int high){
        for(int i=low; i<=high; i++){
            b[i] = a[i];
        }
        int i,j,k;
        for(i=low,j=mid+1,k=low; i<=mid && j<=high; k++){
            if(b[i] < b[j]){
                a[k] = b[i++];
            }
            else{
                a[k] = b[j++];
            }
        }
        while(i<=mid) a[k++] = b[i++];
        while(j<=high) a[k++] = b[j++];
    }

    void merge_sort(elementtype a[], int low, int high){
        if(low<high){
            int mid = (low+high)/2;
            merge_sort(a, low, mid);
            merge_sort(a, mid+1, high);
            merge(a, low, mid, high);
        }
    }

    //非递归算法

//基数排序
    //多关键字，对于数来说其每位就是关键字
    //桶：链队列实现