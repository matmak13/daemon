#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <utime.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

enum
{
	DEFAULT,
	RECURSIVE
} mode = DEFAULT;

int is_directory(const struct dirent* dir);
// Sprawdza czy podany plik jest zwykym plikiem
int is_regular_file(const char* path);

char* concat_path(const char* source, const char* file);
int skip_location(const char* name);

long compare_files_times(const char* file1, const char* file2);

void copy_file_dates(const char* from, const char* to);
void copy_file(const char* from, const char* to, ssize_t buffor, ssize_t large_file_size_limit);
void delete_file(const char* path);
void delete_directory(const char* path);

void copy_and_delete_all_files(const char* source_path, const char* destination_path, ssize_t buffor_size, ssize_t large_file_size_limit);