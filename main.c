#include <stdio.h>
#include <stdio.h>
#include<math.h>
int begintoend(int begin,int end,int number){
    int i=1;
    int sum=0;
    while( number > 0) {
        sum=sum+(number%10)*i;
        number=number/10;
        i=i*begin;

    }

    i=0;
    int new=0;
    while(sum!=0){
        new=new+(sum%end)*pow(10,i);
        i++;
        sum=sum/end;
    }
    return new;

}
int numberofdigits(int ournum){
    int i2=0;
    while(ournum!=0){
        ournum=ournum/10;
        i2=i2+1;
    }
    return i2;
}
int numbertobase10(int beginbase,int number){
    int sum=0;
    int i=1;
    while( number > 0) {
        sum=sum+(number%10)*i;
        number=number/10;
        i=i*beginbase;
    }
    return sum;
    
}
int main(){
    int number ,begin ,end ,sum;
    scanf("%d %d %d",&begin,&end,&number);
    int newnum= begintoend(begin,end,number);
    int i2= numberofdigits(newnum);
    //printf("%d\t",num);
    if(i2%2==1){
        newnum=newnum*10;
        i2=i2+1;
    }
    int x=pow(10,i2/2);
    int y=pow(10,i2);
    int firstpart=(newnum%x);
    int secondpart=((newnum%y)-firstpart)/x;
    int final1= numbertobase10(end,firstpart);
    int final2= numbertobase10(end,secondpart);
    int final= begintoend(10,end,final1+final2);
    printf("%d",final);
    // printf("%d\t%d\t%d\t%d\t%d\t%d\t%d",final,final1,final2,firstpart,secondpart,newnum,i2);

    return 0;
}


