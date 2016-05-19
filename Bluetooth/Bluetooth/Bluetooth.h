#pragma once

#include "resource.h"
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "cmd_def.h"

void Output(uint8 len1, uint8* data1, uint16 len2, uint8* data2);
int readMessage();
void printHelp();
