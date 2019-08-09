/*
程序要求：使用C语言打印杨辉三角形
实现方法：
1.使用数组：
triangle_1()

2.直接输出：
triangle_2()
*/
#include <stdio.h>
int h[10][10];
int i,j,s;
void triangle_1();//声明triangle_1()函数
void triangle_2();//声明triangle_2()函数

int main()
{
	triangle_1();//输出杨辉三角形
	triangle_2();//输出杨辉三角形

	return 0;
}

void triangle_1(){//定义triangle_1函数
	for(i=0;i<10;i++){//第一列和对角线元素值为1
		h[i][0]=1;
		h[i][i]=1;
	}

	for(i=2;i<10;i++){//其余元素值为：前一行对应列元素值与前一行前一列元素值之和
		for(j=1;j<i;j++){
			h[i][j]=h[i-1][j-1]+h[i-1][j];
		}
	}
	for(i=0;i<10;i++){//遍历输出
		for(s=0;s<9-i;s++){//注释掉这个for循环即可输出直角三角形格式的杨辉三角形
			printf("  ");
		}
		for(j=0;j<=i;j++){
			printf("%4d",h[i][j]);	
		}
		printf("\n");
	}
}


void triangle_2(){//定义triangle_2()函数
	int row,value;
	printf("请输入杨辉三角形的列数:");
	scanf("%d",&row);
	for(i=0;i<row;i++){
		for(s=0;s<row-i;s++){//注释掉这个for循环即可输出直角三角形格式的杨辉三角形
			printf(" ");
		}
		for(j=0; j <= i; j++){//第n行的数字有n项，所以j<=i
            //第一行第一列元素值为1，第一列元素值为1
            if (j==0 || i==0)
                value = 1;
            else
                value = value*(i-j+1)/j;//最后一个每一行i=j,倒数第二行（value=j）等于列数，
            printf("%4d", value);
		}
		printf("\n");
	}
}
