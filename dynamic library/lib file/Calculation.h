#pragma once

#ifdef CALCULATION_EXPORTS
#define CALCULATION_API __declspec(dllexport)
#else
#define CALCULATION_API __declspec(dllimport)
#endif // CALCULATION_EXPORTS

extern "C" CALCULATION_API double Add(double a, double b);
extern "C" CALCULATION_API double Sub(double a, double b);
extern "C" CALCULATION_API double Multiply(double a, double b);
extern "C" CALCULATION_API double Division(double a, double b);
