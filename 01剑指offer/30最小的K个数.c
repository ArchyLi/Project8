void AdjustHeap(int* const arr, const int length){
    for(int i = length / 2 - 1; i >= 0; i--){
        int temp = arr[i];
        int k = 0;
        for(int j = i * 2 + 1; j < length; j = k * 2 + 1){
            k = j;
            if(j + 1 < length)
                k = arr[j] > arr[j + 1] ? j : j + 1;
 
            if(arr[k] > arr[i]){
                arr[(j - 1) / 2] = arr[k];
                arr[k] = temp;
            }
            else
                break;
        }
    }
}
 
int* GetKMin(int* const arr, const int length, const int K){
    if(K <= 0) return NULL;
    int* KMin = new int[K];
    for(int i = 0; i < length; i++){
        if(i <= K)
            KMin[i] = arr[i];
        if(i == K)
            AdjustHeap(KMin, K);
        if(i > K)
            if(arr[i] < KMin[0]){
                KMin[0] = arr[i];
                AdjustHeap(KMin, K);
            }
    }
    return KMin;
}
