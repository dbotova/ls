//headet

#include "../ft_ls.h"

void				swap(t_items *arr, int left, int right)
{
	t_items	tmp;

	tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

void				partition(int left, int right, t_content *cont,
					int(*compare)(t_items*, int, t_items*))
{
	int				partition_point;

	if (right - left <= 0)
		return ;
	else
	{
		partition_point = t_items_qsort(left, right, cont->arr, compare);
		partition(left, partition_point - 1, cont, compare);
		partition(partition_point + 1, right, cont, compare);
	}
}

int					t_items_qsort(int left, int right,
					t_items *arr, int(*compare)(t_items*, int, t_items*))
{
	int				left_pointer;
	int				right_pointer;
	t_items			*pivot;

	left_pointer = left - 1;
	right_pointer = right;
	pivot = &arr[right];
	while (42)
	{
		while (left_pointer <= right && compare(arr, ++left_pointer, pivot) < 0) ;
		while (right_pointer > 0 && compare(arr, --right_pointer, pivot) > 0) ;
		if (left_pointer >= right_pointer)
			break ;
		else
			swap(arr, left_pointer, right_pointer);
	}
	swap(arr, left_pointer, right);
	return (left_pointer);
}