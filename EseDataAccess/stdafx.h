#pragma once
#define WIN32_LEAN_AND_MEAN		
#include <stdio.h>
#include <tchar.h>

#include "stdlib.h"
#include <vector>
#include <string>

#include "windows.h"
#include "esent.h"

using std::vector;
using std::string;
using std::wstring;

typedef unsigned int uint;

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&);                 \
void operator=(const TypeName&)