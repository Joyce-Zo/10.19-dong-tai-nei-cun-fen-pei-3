#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		return 0;
	}
	int* p2 = realloc(p, 80);
	if(p2!=NULL)
	{
		p = p2;
	}
	int* p = realloc(NULL, 40);// 此时realloc作用等价于malloc(40);
	return 0;
}

				动态内存空间的错误案例

		4.使用free释放一块动态开辟内存的一部分
 
int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		return 0;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*p++ = i;
	}
	 释放空间
	free(p);	此时p经上面的++已经变化，指向第41个字节的空间，未被开辟，此时free将越界
									指向中间也不行，只是一部分
	p = NULL;
	return 0;
}

		5.对同一块动态内存空间多次释放

int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		return 0;
	}
	free(p);
	p = NULL;
	free(p);	// 再次释放，程序崩溃
	 如果上面加上P=NULL，则free不进行任何操作
	return 0;
}

        6.对动态开辟空间忘记释放 - 内存泄漏

int main()
{
	while (1)
	{
		malloc(1);
	}// 未释放，一直占用
	return 0;
}

					笔试题

    第一题
    改法1
void GetMemory(char* *p)	// 因为传过来str类型为char*，所以存放str的地址应该是char* *str
{
	*p = (char*)malloc(100);// 该函数返回后，动态内存空间p尚未释放，且无法找到
}
void Test(void)
{
	char* str = NULL; 
	GetMemory(&str);	// 1.此处传值操作，传过去str的值，且p只在函数内部有效
	strcpy(str, "hello world"); 
	printf(str);
	free(str);
	str = NULL;
}
int main()
{
	Test(); 
	return 0;
}

    改法2
char* GetMemory(char* p)	
{
	p = (char*)malloc(100);
	return p;
}
void Test(void)
{
	char* str = NULL;
	str = GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
	free(str);
	str = NULL;
}
int main()
{
	Test();
	return 0;
}