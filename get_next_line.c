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
#include <stdio.h>

char *ft_realloc(char *ptr, size_t size)
{
  char *dst;

  if (!ptr)
    return (NULL);
  dst = (char*)malloc((size + 1) * sizeof(char));
  if (!dst)
    {
      printf("realloc failed");
	return NULL;
    }
  ft_memcpy(dst, ptr, size - BUFF_SIZE);
  return (dst);
}

void ft_strccat(char *dst, const char *src, char c, int readbytes)
{
  int i;
  int dstsize;
  
  i = 0;
  dst += ft_strlen(dst);
  if (!ft_memchr(src, c, readbytes))
    {
      ft_memcpy(dst, src, readbytes);
      dst += readbytes;
      *dst = '\0';
    }
}

int get_next_line(const int fd, char **line)
{
  char buff[BUFF_SIZE];
  size_t size;
  int i;
  int j;


  if(fd < 0)
    return -1;
  size = BUFF_SIZE;
  if(!line || !*line)
    return -1;
  *line = "";
  while(1)
    {
      *line = ft_realloc(*line, size);
      if(!(*line))
	{
	  printf("aqui\n");
	  return -1;
	}
      i = 0;
      while(i < BUFF_SIZE)
	{
	  if(read(fd, &(buff[i]), 1) != 1 || buff[i] == '\n')
	    break;
	  i++;
	}
      j = (buff[i] && buff[i] == '\n') ? i : i + 1;
      //    while(j < BUFF_SIZE)
      //	buff[j++] = '\0';
      ft_strccat(*line, buff, '\n', i);
      if (buff[i] == '\n')
	  return 1; 
      if (i != BUFF_SIZE)
	{
	  return 0;
	}
      size += BUFF_SIZE;
    }
  return -1;
}
/*
int main(void)
{
  int fp = open("testfile", O_RDONLY);
  char *oi;
  get_next_line(fp, &oi);
    printf("%s\n", oi);
  return 0;
}

int main(void)
{
  char *a = malloc (30);
  char b[] = "heey";

  a[0] = 'u';
  a[1] = 'a';
  a[2] = 'b';
  a[3] = '\0';
  printf("string = %s\n", a);
  ft_strccat(a, b, '\n', 4);
  printf("%s", a);
  return 0;
}
*/
