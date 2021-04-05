/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:25:01 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/05 12:52:03 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void *test_func(void *a)
{
	printf("hello ==> |%d|\n", *((int *)a));
	sleep(2);
	printf("see ya ==> |%d|\n", *((int *)a));
	void *v;
	return v;
}


int main(int argc, char const *argv[])
{
	fork();
	puts("Hello World!");
	
	return 0;
}
