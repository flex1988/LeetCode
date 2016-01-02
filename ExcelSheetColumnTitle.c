char* convertToTitle(int n) {
    char* ret=calloc(100,sizeof(char));

    int index=0;
    while(n>0){
        int t=(n-1)%26;
        n=(n-1)/26;
        ret[index++]=t+'A';
    }
    char* arr=calloc(index+1,sizeof(char));
    
    for(int i=0;i<index;i++){
        *(arr+i)=ret[index-i-1];
        
    }

    arr[index]='\0';
    printf("%c\n",arr[0]);
    return arr;
}
