//
//  apue.h
//  Apue
//
//  Created by Haizhen Lee on 03/04/2017.
//  Copyright © 2017 banxi1988. All rights reserved.
//

#ifndef apue_h
#define apue_h

#define _POSIX_C_SOURCE 200809L

#include <sys/types.h> /* some systems still require this*/
#include <sys/stat.h>
#include <sys/termios.h> /* for winsize*/

#if defined(MACOS) || !defined(TIOCGWINSZ)
#include <sys/ioctl.h>
#endif

#include <stdio.h> /* for convenience */
#include <stdlib.h> /* for convenience */
#include <stddef.h> /* for offsetof */
#include <string.h> /* for convenience */
#include <unistd.h> /* for convenience */
#include <signal.h> /* for convenience */

#define MAXLINE 4096 /* max line length */

/**
 * Default file access permissions for new files
 */
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXOTH)

typedef void Sigfunc(int); /* for signal handlers*/

#define min(a,b) ((a) < (b) ? (a):(b))
#define max(a,b) ((a) > (b) ? (a):(b))

void err_msg(const char *, ...); /* Appendix B*/
void err_dump(const char *, ...) __attribute__((noreturn));
void err_quit(const char *, ...) __attribute__((noreturn));
void err_exit(int,const char *, ...) __attribute__((noreturn));
void err_sys(const char *, ...) __attribute__((noreturn));
void err_cont(int,const char *, ...);
void err_ret(const char *, ...);


void log_msg(const char *, ...); /* Appendix B */
void log_open(const char *,int,int);
void log_quit(const char *, ...) __attribute__((noreturn));
void log_ret(const char *, ...);
void log_sys(const char *, ...) __attribute__((noreturn));
void log_exit(int, const char *, ...) __attribute__((noreturn));

/* for file io */

/**
 * flags are file status flags to turn on
 */
void set_fl(int fd, int flags);

/*for compat */
#ifndef __APPLE__
int futimens(int fd, const struct timespec times[2]);
#endif


#endif /* apue_h */
