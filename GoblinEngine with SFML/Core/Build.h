#pragma once

#ifdef _EXPORTING
   #define DLLEXPORT    __declspec(dllexport)
#else
   #define DLLEXPORT    __declspec(dllimport)
#endif