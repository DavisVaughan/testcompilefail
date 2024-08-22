#define R_NO_REMAP
// NOTE: Uncomment this and it magically works!
// #include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <stdbool.h> // for bool
#include <R_ext/Rdynload.h>

SEXP test() {
  return R_NilValue;
}

extern "C" {

// .Call entries
static const R_CallMethodDef CallEntries[] = {
  {"test", (DL_FUNC) &test, 0},
  {NULL, NULL, 0}
};

void R_init_testcompilefail(DllInfo *dll) {
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}

} // extern "C"
