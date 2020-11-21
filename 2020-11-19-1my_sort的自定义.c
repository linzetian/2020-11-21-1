//my_sort的自定义
////void qsort (void* base, size_t num, size_t size,int (*compar)(const void*, const void*))
////int compar (const void* p1, const void* p2);
#include<stdio.h>
void Swap(char* p1, char* p2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tem;
		tem = *p1;
		*p1 = *p2;
		*p2 = tem;
		p1++;
		p2++;
	}
}
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1-*(int*)e2;
}

void my_qsort(void* base,int sz,int width, int (*cmp)(const void* p1, const void* p2))//my_qsort自定义函数的形参格式
//1、首元素的地址则为指针，不知道什么类型的指针，所以设置为空指针
//2、数组元素个数，为int
//3、每个元素字节的大小，为int型
//4、函数指针的表达
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)//第i倘，类似于冒泡排序
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//（char*)base + j * width, (char*)base + (1 + j) * width//强制转换为char*，因为要利用j * width访问地址
			if (cmp((char*)base + j * width, (char*)base + (1 + j) * width) > 0)//比较两个数的大小，如果为大于0，交换两数，大于0返回1，升序
				Swap((char*)base + j * width, (char*)base + (1 + j) * width,width);//width传过去（因为强制转换为char*，所以swap是一个字节一个字节的交换，故需要循环width次），
		}
	}
}
void test1()
{
	int i = 0;
	int arr[] = {1,5,2,6,78,62,12};
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr,sz,sizeof(arr[0]),cmp_int);//实参传递，第四个为函数
	for(i=0;i<sz;i++)//打印结果
	printf("%d ",arr[i]);
}
int main()
{
	test1();
	return 0;
}
