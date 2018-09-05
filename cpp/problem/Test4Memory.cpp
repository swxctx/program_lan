#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct _Test
{
	int value;
	char name[32];
}Test;
typedef struct Value 
{
	Test d;
	int a;
	short b;
	char c[28];
	
}Value;

/************************************************************************
* ����ǿ������ת������������Ĺ��ڵ�ַѰ�ҵ�С���⡣
* ���飬���к󣬶������ֲ鿴��
*
* �����У�(5)�������ܹ����ֳ��������ڣ���������Ϊ�ٽ�˼��������ע�͵�
* 
************************************************************************/

void main()
{
	Value v;
	Test t;
	/************************************************************************/
	/*(1)���Ի����������ʹ�С                                                 */
	/************************************************************************/
	printf("int struct size:%d\n", sizeof(int));
	printf("char struct size:%d\n", sizeof(char));
	printf("short struct size:%d\n", sizeof(short));
	printf("long struct size:%d\n", sizeof(long));
	printf("Test struct size:%d\n", sizeof(Test));	//36
	printf("Test float size:%d\n", sizeof(float));
	printf("Test double size:%d\n", sizeof(double));
	printf("v.d size:%d\n", sizeof(v.d));
	printf("v.a size:%d\n", sizeof(v.a));
	printf("v.b size:%d\n", sizeof(v.b));
	printf("v.c size:%d\n", sizeof(v.c));
	printf("Value struct size:%d\n", sizeof(Value));
	printf("-------------------------------\n");


	/************************************************************************/
	/*(2) ��ʼ���ṹ��                                                         */
	/************************************************************************/
	//��ֵ
	v.a = 10;
	v.b = 2;
	strcpy(v.c, "aaa");
	v.d.value = 30;
	strcpy(v.d.name, "bbb");


	/************************************************************************/
	/* (3)ǿ������ת���󣬸�������ָ���׵�ַ����ͬ                             */
	/************************************************************************/
	printf("%d\n", &v);						   //δת��ǰv��ռ�ռ����ʼ				   
	printf("%d\n", (char*)&v);			       //��������ת���󣬷�����ת��ǰ��ʼ��ַһ����
	printf("%d\n", (int*)&v);
	printf("%d\n", (long*)&v);
	printf("%d\n", (short*)&v);
	printf("%d\n", (float*)&v);
	printf("%d\n", (double*)&v);
	printf("-------------------------------\n");


	/************************************************************************/
	/* (4)ָ�����ͣ���С��Ϊ4�ֽ�                                              */
	/************************************************************************/
	printf("%d\n", sizeof(&v));
	printf("%d\n", sizeof((char*)&v));		   //ָ����ռ�ڴ��С��int��long������ͬ
	printf("sizeof(char*) = %d\n", sizeof(char*));
	printf("-------------------------------\n");


	/************************************************************************
	* (5)ǿ��ת���ɸ�������ָ�룬���ֵ�ַ���ܶ�(������int* �Ͳ�4��short*�Ͳ�2) 
	*���⣺��ν�����������
	*
	************************************************************************/
	printf("&v addrr: %d\n", &v + sizeof(Test));		   
	printf("(char*)&v addrr: %d\n", (char*)&v + sizeof(Test));  //ͬ��3�����׵�ַ���36
	printf("(int*)&v addrr: %d\n", (int*)&v + sizeof(Test));	//ͬ��3�����׵�ַ���144
	printf("(long*)&v addrr: %d\n", (long*)&v + sizeof(Test));	//ͬ��3�����׵�ַ���144
	printf("(short*)&v addrr: %d\n", (short*)&v + sizeof(Test));	//ͬ��3�����׵�ַ���72
	printf("(float*)&v  addrr: %d\n", (float*)&v + sizeof(Test));	//ͬ��3�����׵�ַ���144
	printf("(double*)&v  addrr: %d\n", (double*)&v + sizeof(Test)); //ͬ��3�����׵�ַ���288

	/************************************************************************/
	/*(6)���ֻ����������ͣ����׵�ַ                                         */
	/************************************************************************/
	printf("-------------------------------\n");
	char aa;
	printf("char addr:%d\n", &aa);
	int bb;
	printf("int addr:%d\n", &bb);
	long cc;
	printf("long addr:%d\n", &cc);
	short dd;
	printf("short addr:%d\n", &dd);
	float ee;
	printf("float addr:%d\n", &ee);
	double ff;
	printf("double addr:%d\n", &ff);

	/************************************************************************
	* (7)ǿ������ת����Value�ṹ��ǿת��Test�ṹ�塣
	* �ܹ�����Test�еı���������Value�е�Test���ͱ��������λ����������
	************************************************************************/
	printf("-------------------------------\n");
	//ȡֵ
	Test *test = (Test*)&v;//ǿ������ת��������ʲô������ȡ��ʲô�����ڴ��
	printf("Test value = %d, name = %s\n", test->value, test->name);


	/************************************************************************
	*(8) v.a���Է���Value�г�Ա������
	*   �ṩ����Value�г�Ա�����ĵײ�ʵ��ԭ��                                                                    
	************************************************************************/
	//����ƫ����������ṹ��������������ַ
	//v.a
	int a = *(int *)((char*)&v + sizeof(Test));
	printf("v.a = %d\n", a);
	//v.b
	short b = *(short*)((char*)&v + sizeof(Test) + sizeof(int));
	printf("v.b = %d\n", b);
	//v.c
	char* c = ((char*)&v + sizeof(Test) + sizeof(int) + sizeof(short));
	printf("v.c = %s\n", c);

	

}