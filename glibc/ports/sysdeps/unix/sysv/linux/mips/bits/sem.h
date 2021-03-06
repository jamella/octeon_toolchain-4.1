/* Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#ifndef _SYS_SEM_H
# error "Never include <bits/sem.h> directly; use <sys/sem.h> instead."
#endif

#include <sys/types.h>

/* Flags for `semop'.  */
#define SEM_UNDO	0x1000		/* undo the operation on exit */

/* Commands for `semctl'.  */
#define GETPID		11		/* get sempid */
#define GETVAL		12		/* get semval */
#define GETALL		13		/* get all semval's */
#define GETNCNT		14		/* get semncnt */
#define GETZCNT		15		/* get semzcnt */
#define SETVAL		16		/* set semval */
#define SETALL		17		/* set all semval's */


#if !defined (__OCTEON__) || __WORDSIZE != 32
/* Data structure describing a set of semaphores.  */
struct semid_ds
{
  struct ipc_perm sem_perm;		/* operation permission struct */
  __time_t sem_otime;			/* last semop() time */
  __time_t sem_ctime;			/* last time changed by semctl() */
  /* Add placeholders to match the struct defined by kernel in
     include/linux/sem.h. */
  unsigned long int __unused1;
  unsigned long int __unused2;
  unsigned long int __unused3;
  unsigned long int __unused4;
  unsigned short sem_nsems;            /* number of semaphores in set */
};
#else  /* defined (__OCTEON__) && __WORDSIZE == 32 */
  /*  For n32 glibc kernel is n64 on Octeon.  Turn long or pointer
      fields either into long long or pad them to match the layout of
      the kernel struct.  __time_t is different for n64 and n32.  */
struct semid_ds
{
  struct ipc_perm sem_perm;     /* structure describing operation permission */
  unsigned int __pad1;
  __time_t sem_otime;                  /* last semop() time */
  unsigned int __pad2;
  __time_t sem_ctime;                  /* last time changed by semctl() */
  /* Add placeholders to match the struct defined by kernel in
     include/linux/sem.h. */
  unsigned long long __unused1;
  unsigned long long __unused2;
  unsigned long long __unused3;
  unsigned long long __unused4;
  unsigned short sem_nsems;            /* number of semaphores in set */
};
#endif /* !defined (__OCTEON__) || __WORDSIZE != 32 */

/* The user should define a union like the following to use it for arguments
   for `semctl'.

   union semun
   {
     int val;				<= value for SETVAL
     struct semid_ds *buf;		<= buffer for IPC_STAT & IPC_SET
     unsigned short int *array;		<= array for GETALL & SETALL
     struct seminfo *__buf;		<= buffer for IPC_INFO
   };

   Previous versions of this file used to define this union but this is
   incorrect.  One can test the macro _SEM_SEMUN_UNDEFINED to see whether
   one must define the union or not.  */
#define _SEM_SEMUN_UNDEFINED	1

#ifdef __USE_MISC

/* ipcs ctl cmds */
# define SEM_STAT 18
# define SEM_INFO 19

struct  seminfo
{
  int semmap;
  int semmni;
  int semmns;
  int semmnu;
  int semmsl;
  int semopm;
  int semume;
  int semusz;
  int semvmx;
  int semaem;
};

#endif /* __USE_MISC */
