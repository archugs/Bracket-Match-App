using namespace std;
#include <iostream>
#include <limits>
#include <cmath>

typedef char Stack_entry;

enum Error_code { success, fail, range_error, underflow, overflow, fatal, not_present, duplicate_error, entry_inserted, entry_found, internal_error };
