/*
 * Shell Simulator
 * 2010.08.21 by alex
 */

#include "shell/MergeSort.h"

MergeSort::MergeSort()
{
}

MergeSort::~MergeSort()
{
}

void MergeSort::sort(int *arrary, int length)
{
	sort(arrary, 0, length - 1);
}

void MergeSort::sort(int *arrary, int start, int end)
{
	int n = end - start + 1;
    int i1, j1, i2, j2;
	int size = 1;
	while (size < n)
	{
        i1 = 0;  
        while (i1 + size < n)
		{				               //��i1+size<n����˵���������������У����������ϲ�
		    i2 = i1 + size;                
  	        j1 = i2 - 1;               //ȷ��������1���Ͻ�
            if (i2 + size - 1 > n - 1) 
			{
				j2 = n-1;              //����2���������в���size��Ԫ�أ�����������2���Ͻ�j2=n-1
			}
		    else 
			{
				j2=i2+size-1;          //������size������j2=i2+size-1
			}
			merge(arrary, i1, j1, i2, j2);  //�ϲ���������������
			i1 = j2 + 1;               //ȷ����һ�κϲ���һ�������е��½�
		 } 
		size *= 2;                    //Ԫ�ظ�������һ��
	}

}

void MergeSort::sort(Vector<int> &arrary, int length)
{
	sort(arrary, 0, length - 1);
}

void MergeSort::sort(Vector<int> &arrary, int start, int end)
{
	int n = end - start + 1;
    int i1, j1, i2, j2;
	int size = 1;
	while (size < n)
	{
        i1 = 0;  
        while (i1 + size < n)
		{				               //��i1+size<n����˵���������������У����������ϲ�
		    i2 = i1 + size;                
  	        j1 = i2 - 1;               //ȷ��������1���Ͻ�
            if (i2 + size - 1 > n - 1) 
			{
				j2 = n-1;              //����2���������в���size��Ԫ�أ�����������2���Ͻ�j2=n-1
			}
		    else 
			{
				j2=i2+size-1;          //������size������j2=i2+size-1
			}
			merge(arrary, i1, j1, i2, j2);  //�ϲ���������������
			i1 = j2 + 1;               //ȷ����һ�κϲ���һ�������е��½�
		 } 
		size *= 2;                    //Ԫ�ظ�������һ��
	}

}

void MergeSort::merge(Vector<int> &arrary,int i1,int j1,int i2,int j2)   
{										// i1,j1��������1���¡��Ͻ磬i1,j2��������2���¡��Ͻ�
	Vector<int> Temp(j2 - i1 + 1);       //�����ܴ�����������е���ʱ����
	int i = i1, j = i2, k = 0;          //i,j�����������е��ζ�ָ�룬k��Temp���ζ�ָ��
    while (i <= j1 && j <= j2)          //�����������ж����գ���ѭ��
	{
	    if (arrary[i] <= arrary[j])
		{
			Temp[k++] = arrary[i++];        //��A[i]��A[j]�н�С�Ĵ���Temp[k]
		}
		else
		{
			Temp[k++] = arrary[j++];
		}
	}
	while (i <= j1) 
	{
		Temp[k++] = arrary[i++];            //����һ���������л���ʣ��ľʹ���Temp
	}
    while (j <= j2)
	{
		Temp[k++] = arrary[j++];            //���ڶ����������л���ʣ��ľʹ���Temp
	}
	for (i = 0; i < k; i++) 
	{
		arrary[i1++] = Temp[i];			   //����ʱ�����е�Ԫ�ص���A
	}
                     
}

void MergeSort::merge(int *arrary,int i1,int j1,int i2,int j2)   
{										// i1,j1��������1���¡��Ͻ磬i1,j2��������2���¡��Ͻ�
	int *Temp = new int[j2 - i1 + 1];       //�����ܴ�����������е���ʱ����
	int i = i1, j = i2, k = 0;          //i,j�����������е��ζ�ָ�룬k��Temp���ζ�ָ��
    while (i <= j1 && j <= j2)          //�����������ж����գ���ѭ��
	{
	    if (arrary[i] <= arrary[j])
		{
			Temp[k++] = arrary[i++];        //��A[i]��A[j]�н�С�Ĵ���Temp[k]
		}
		else
		{
			Temp[k++] = arrary[j++];
		}
	}
	while (i <= j1) 
	{
		Temp[k++] = arrary[i++];            //����һ���������л���ʣ��ľʹ���Temp
	}
    while (j <= j2)
	{
		Temp[k++] = arrary[j++];            //���ڶ����������л���ʣ��ľʹ���Temp
	}
	for (i = 0; i < k; i++) 
	{
		arrary[i1++] = Temp[i];			   //����ʱ�����е�Ԫ�ص���A
	}
	delete [] Temp;                       
}