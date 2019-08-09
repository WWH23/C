/*
程序要求：实现输入指定数目的数字，进行排序输出
实现方法：
1.冒泡法 void bubble()
2.选择法 void selection()
*/
#include <stdio.h>
#include <stdlib.h>
void set_array();//声明set_array()函数
void bubble();//声明bubble()函数
void selection();//声明selection()函数

int *a;
int count;

int main(){

	bubble();//调用函数
	selection();//调用函数
	
	return 0;
}

void set_array(){//定义set_array()函数
	int i;
	printf("请输入需要排序的数字数目：");
	scanf("%d",&count);
	a=(int*)calloc(count,sizeof(int));//动态分配内存空间
	printf("请输入需要排序的数字：");
	for (i=0;i<count;i++){//遍历赋值
		scanf("%d",&a[i]);
	}
}

void bubble(){//定义bubble()函数
	int i,j,t;
	printf("冒泡法\n");
	set_array();//调用set_array()函数
	for(i=0;i<count-1;i++){//比较count-1趟
		for(j=0;j<count-1-i;j++){//每趟比较count-1-i次
			if(a[j]>a[j+1]){//该数比后边的元素值大，就交换数值
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("bubble()从小到大排序：");//遍历输出
	for (i=0;i<count;i++){
		printf("%d  ",a[i]);
	}
	printf("\n");
}




void selection(){//定义selection()函数
	int i,j,k,temp;
	printf("选择法\n");
	set_array();//调用set_array()函数
	for(i=0;i<count;i++){
		k=i;//默认下标为i的元素值为最大值
		for(j=i+1;j<count;j++){//与下标在i之后的元素值进行比较
			if (a[k]>a[j]){//该元素值比后边的元素值大，就交换元素值
				k=j;	
			}
		}
		if(k!=i){//比较k与i的关系，若不相等就交换元素值
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
	}
	printf("selection()从小到大排序：");//遍历输出
	for (i=0;i<count;i++){
		printf("%d  ",a[i]);
	}
	printf("\n");
}


