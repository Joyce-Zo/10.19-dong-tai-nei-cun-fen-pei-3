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
	int* p = realloc(NULL, 40);// ��ʱrealloc���õȼ���malloc(40);
	return 0;
}

				��̬�ڴ�ռ�Ĵ�����

		4.ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����
 
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
	 �ͷſռ�
	free(p);	��ʱp�������++�Ѿ��仯��ָ���41���ֽڵĿռ䣬δ�����٣���ʱfree��Խ��
									ָ���м�Ҳ���У�ֻ��һ����
	p = NULL;
	return 0;
}

		5.��ͬһ�鶯̬�ڴ�ռ����ͷ�

int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		return 0;
	}
	free(p);
	p = NULL;
	free(p);	// �ٴ��ͷţ��������
	 ����������P=NULL����free�������κβ���
	return 0;
}

        6.�Զ�̬���ٿռ������ͷ� - �ڴ�й©

int main()
{
	while (1)
	{
		malloc(1);
	}// δ�ͷţ�һֱռ��
	return 0;
}

					������

    ��һ��
    �ķ�1
void GetMemory(char* *p)	// ��Ϊ������str����Ϊchar*�����Դ��str�ĵ�ַӦ����char* *str
{
	*p = (char*)malloc(100);// �ú������غ󣬶�̬�ڴ�ռ�p��δ�ͷţ����޷��ҵ�
}
void Test(void)
{
	char* str = NULL; 
	GetMemory(&str);	// 1.�˴���ֵ����������ȥstr��ֵ����pֻ�ں����ڲ���Ч
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

    �ķ�2
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