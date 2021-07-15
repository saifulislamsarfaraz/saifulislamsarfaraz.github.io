void findInterSections(int a[],int as, int b[], int bs,int c[]){
    int inda = 0,indb = 0,indc = 0;

    while (inda < as && indb < bs )
    {
        if(a[inda]==b[indb]){
            c[indc] = a[inda];
            indc++;
            inda++;
            indb++;
        }else if (a[inda]>b[indb]){
            indb++;
        }else{
            inda++;
        }
    }
    
}