/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 14:42:06 by fschuber          #+#    #+#             */
/*   Updated: 2014/12/01 14:56:35 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

void *ft_realloc(void *ptr, size_t size){
  static size_t size;
  void *dst;

  if (!ptr)
    return NULL;
  if (!size)
    size = 0;
  size += BUFF_SIZE;
  dst = (void*)malloc(size);
  if (!dst)
    return NULL;
  ft_memcpy(dst, ptr, size - BUFF_SIZE);
  free(ptr);
  return dst;
}

int get_next_line(const int fs, char **line)
{
  int i;
  char *ptr;
  size_t size;


  while( )
    {
    }
}
