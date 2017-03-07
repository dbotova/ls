/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dirent_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:58:59 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/01 20:59:00 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void swap(t_content *cont, int left, int right)
{
	struct dirent tmp;

	tmp = cont->arr[left];
	cont->arr[left] = cont->arr[right];
	cont->arr[right] = tmp;
}

static int partition(int left, int right, int pivot, t_content *cont) 
{
	struct stat statbuf;
	int left_pointer;
	int right_pointer;

	left_pointer = left - 1;
	right_pointer = right;

   while(42) 
   {
   		stat(cont->arr[++left_pointer].d_name, &statbuf);
		while(statbuf.st_mtime < pivot) 
			stat(cont->arr[++left_pointer].d_name, &statbuf);
		stat(cont->arr[--right_pointer].d_name, &statbuf);
		while(right_pointer > 0 && statbuf.st_mtime > pivot) 
			stat(cont->arr[--right_pointer].d_name, &statbuf);
		if(left_pointer >= right_pointer) 
			break ;
		else
			swap(cont, left_pointer, right_pointer);
   }
   swap(cont, left_pointer, right);
   return (left_pointer);
}

static void q_sort(int left, int right, t_content *cont) 
{
	int partition_point;
	int pivot;
	struct stat statbuf;

   if(right-left <= 0)
      return ;   
   else 
   {
   		stat(cont->arr[right].d_name, &statbuf);
   		pivot = statbuf.st_mtime;
   		partition_point = partition(left, right, pivot, cont);
   		q_sort(left, partition_point - 1, cont);
   		q_sort(partition_point + 1, right, cont);
   }        
}

void	sort_dirent_array(t_content *cont)
{
	q_sort(0, cont->size - 1, cont);
}
