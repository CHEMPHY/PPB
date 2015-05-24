/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include files */
#include "rt_nonfinite.h"
#include "PPB_ann.h"
#include "main.h"
#include "PPB_ann_terminate.h"
#include "PPB_ann_initialize.h"

/* Function Declarations */
static void argInit_16x1_real_T(double result[16]);
static double argInit_real_T(void);
static void main_PPB_ann(void);

/* Function Definitions */
static void argInit_16x1_real_T(double result[16])
{
  int b_j0;

  /* Loop over the array to initialize each element. */
  for (b_j0 = 0; b_j0 < 16; b_j0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[b_j0] = argInit_real_T();
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_PPB_ann(void)
{
  double dv0[16];
  double b_y1;

  /* Initialize function 'PPB_ann' input arguments. */
  /* Initialize function input argument 'x1'. */
  /* Call the entry-point 'PPB_ann'. */
  argInit_16x1_real_T(dv0);
  b_y1 = PPB_ann(dv0);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  PPB_ann_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_PPB_ann();

  /* Terminate the application.
     You do not need to do this more than one time. */
  PPB_ann_terminate();
  return 0;
}

/* End of code generation (main.c) */
