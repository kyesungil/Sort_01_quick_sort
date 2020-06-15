#include<stdio.h>

#define MAX 10


void swap(int* a, int* b);
int partition(int data[], int start, int end);
void quick_sort(int data[], int start, int end);


int main()
{
	int my_ary[MAX] = { 25,42,17,9,3,82,23,58,67,30 };

	int size = sizeof(my_ary) / sizeof(my_ary[0]);

	printf("정렬 전\n");
	for (int i = 0; i < MAX; i++)
		printf("%d, ", my_ary[i]);
	printf("\n\n");

	quick_sort(my_ary, 0, size - 1);

	printf("정렬 후\n");
	for (int i = 0; i < MAX; i++)
		printf("%d, ", my_ary[i]);

	return 0;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*******************************************************************
*								  
* @NAME	    : partition						  
* @FUNTION  : 피벗보다 작은요소들은 왼쪽,큰 요소들은 오른쪽으로 분할   
*	      1. 리스트의 마지막 요소를 피벗(pivot)지정.		
*	      2. 피벗보다 배열의 요소가 크면, left+1과 right 자리바꿈  
*		 left++, right++				   
*	      3. 피벗보다 배열의 요소가 작으면, right++			   
*	      4. right == end이면 pivot과 right 자리바꿈			   
* @PARMETER : 배열, 첫번째 index, 마지막 index					   
* @RETURN   : (int) pivot의 index								   
*																   
********************************************************************/
int partition(int data[], int start, int end)
{
	int left = start - 1; int right = start;	// pivot > left, pivot < right
	int pivot = data[end];

	while (right < end)
	{
		if (pivot < data[right])
			right++;
		else
		{
			swap(&data[left + 1], &data[right]);
			left++;  right++;
		}
	}
	swap(&data[left + 1], &data[right]);
	
	return left + 1;
}


/*******************************************************************
*																   
* @NAME	    : quick_sort										   
* @FUNTION  : 피벗보다 작은요소들은 왼쪽,큰 요소들은 오른쪽으로 분할	   
*	      순환 호출 을 통하여 나누었던 2개의 배열 (피벗보다 작은 배열, 큰 배열)을 다시 분할 한다.		   
* @PARMETER : 배열, 첫번째 index, 마지막 index					   
* @RETURN   : 없음			    			 					   
*																   
********************************************************************/
void quick_sort(int data[], int start, int end)
{
	if (start < end)
	{
		int pivot = partition(data, start, end);
		quick_sort(data, start, pivot - 1);
		quick_sort(data, pivot + 1, end);
	}
}
