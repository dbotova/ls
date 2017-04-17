//headet

#include "../ft_ls.h"

int					compare_name(t_items *arr, int pointer, t_items *pivot)
{
	return (ft_strcmp(arr[pointer].item.d_name, pivot->item.d_name));
}

int					compare_name_rev(t_items *arr, int pointer, t_items *pivot)
{
	return (ft_strcmp(pivot->item.d_name, arr[pointer].item.d_name));
}

int					compare_mtime(t_items *arr, int pointer, t_items *pivot)
{
	if (arr[pointer].mtime.tv_sec > pivot->mtime.tv_sec)
		return (-1);
	if (arr[pointer].mtime.tv_sec < pivot->mtime.tv_sec)
		return (1);
	else
	{
		if (arr[pointer].mtime.tv_nsec > pivot->mtime.tv_nsec)
			return (-1);
		if (arr[pointer].mtime.tv_nsec < pivot->mtime.tv_nsec)
			return (1);
	}
	return (compare_name(arr, pointer, pivot));
}

int					compare_mtime_rev(t_items *arr, int pointer, t_items *pivot)
{
	if (arr[pointer].mtime.tv_sec < pivot->mtime.tv_sec)
		return (-1);
	if (arr[pointer].mtime.tv_sec > pivot->mtime.tv_sec)
		return (1);
	else
	{
		if (arr[pointer].mtime.tv_nsec < pivot->mtime.tv_nsec)
			return (-1);
		if (arr[pointer].mtime.tv_nsec > pivot->mtime.tv_nsec)
			return (1);
	}
	return (compare_name_rev(arr, pointer, pivot));
}

int					compare_atime(t_items *arr, int pointer, t_items *pivot)
{
	if (arr[pointer].atime.tv_sec > pivot->atime.tv_sec)
		return (-1);
	if (arr[pointer].atime.tv_sec < pivot->atime.tv_sec)
		return (1);
	else
	{
		if (arr[pointer].atime.tv_nsec > pivot->atime.tv_nsec)
			return (-1);
		if (arr[pointer].atime.tv_nsec < pivot->atime.tv_nsec)
			return (1);
	}
	return (compare_name(arr, pointer, pivot));
}

int					compare_atime_rev(t_items *arr, int pointer, t_items *pivot)
{
	if (arr[pointer].atime.tv_sec < pivot->atime.tv_sec)
		return (-1);
	if (arr[pointer].atime.tv_sec > pivot->atime.tv_sec)
		return (1);
	else
	{
		if (arr[pointer].atime.tv_nsec < pivot->atime.tv_nsec)
			return (-1);
		if (arr[pointer].atime.tv_nsec > pivot->atime.tv_nsec)
			return (1);
	}
	return (compare_name_rev(arr, pointer, pivot));
}

int					compare_ctime(t_items *arr, int pointer, t_items *pivot)
{
	if (arr[pointer].ctime.tv_sec > pivot->ctime.tv_sec)
		return (-1);
	if (arr[pointer].ctime.tv_sec < pivot->ctime.tv_sec)
		return (1);
	else
	{
		if (arr[pointer].ctime.tv_nsec > pivot->ctime.tv_nsec)
			return (-1);
		if (arr[pointer].ctime.tv_nsec < pivot->ctime.tv_nsec)
			return (1);
	}
	return (compare_name(arr, pointer, pivot));
}

int					compare_ctime_rev(t_items *arr, int pointer, t_items *pivot)
{
	if (arr[pointer].mtime.tv_sec< pivot->mtime.tv_sec)
		return (-1);
	if (arr[pointer].mtime.tv_sec > pivot->mtime.tv_sec)
		return (1);
	else
	{
		if (arr[pointer].mtime.tv_nsec< pivot->mtime.tv_nsec)
			return (-1);
		if (arr[pointer].mtime.tv_nsec > pivot->mtime.tv_nsec)
			return (1);
	}
	return (compare_name_rev(arr, pointer, pivot));
}